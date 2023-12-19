#include "TFormula.h"
#include "TStack.h"
#include <cstring>
#include <cctype>
#include <cstdlib>

TFormula::TFormula(const char* str) {
    strncpy_s(Formula, str, MaxLength - 1);
    Formula[MaxLength - 1] = '\0';
    PostfixForm[0] = '\0';
}

int TFormula::FormulaConverter() {
    
    TStack opStack;
    int j = 0;
    for (int i = 0; Formula[i] != '\0'; ++i) {
        if (isdigit(Formula[i]) || Formula[i] == '.') {
            
            while (isdigit(Formula[i]) || Formula[i] == '.') {
                PostfixForm[j++] = Formula[i++];
            }
            PostfixForm[j++] = ' ';
            --i;
        }
        else if (Formula[i] == '(') {
            opStack.Put('(');
        }
        else if (Formula[i] == ')') {
            while (!opStack.IsEmpty() && opStack.Peek() != '(') {
                PostfixForm[j++] = opStack.Pop();
                PostfixForm[j++] = ' ';
            }
            if (!opStack.IsEmpty() && opStack.Peek() == '(')
                opStack.Pop();
        }
        else if (isOperator(Formula[i])) {
            while (!opStack.IsEmpty() && hasHigherPrecedence(opStack.Peek(), Formula[i])) {
                PostfixForm[j++] = opStack.Pop();
                PostfixForm[j++] = ' ';
            }
            opStack.Put(Formula[i]);
        }
    }

    while (!opStack.IsEmpty()) {
        PostfixForm[j++] = opStack.Pop();
        PostfixForm[j++] = ' ';
    }
    if (j > 0 && PostfixForm[j - 1] == ' ') {
        j--; 
    }
    PostfixForm[j] = '\0';

    return 1;
}
double TFormula::FormulaCalculator() {
    
    TStack calcStack;
    char* context = NULL;
    char* pch = strtok_s(PostfixForm, " ", &context);

    while (pch != nullptr) {
        if (isdigit(pch[0]) || (pch[0] == '-' && isdigit(pch[1]))) {
           
            calcStack.Put(atof(pch));
        }
        else {
            double val2 = calcStack.Pop();
            double val1 = calcStack.Pop();
            switch (pch[0]) {
            case '+':
                calcStack.Put(val1 + val2);
                break;
            case '-':
                calcStack.Put(val1 - val2);
                break;
            case '*':
                calcStack.Put(val1 * val2);
                break;
            case '/':
                calcStack.Put(val1 / val2);
                break;
            }
        }
        pch = strtok_s(nullptr, " ", &context);
    }

    return calcStack.Pop();
}