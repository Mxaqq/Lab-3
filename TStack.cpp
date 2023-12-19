#include "TStack.h"
#include "TFormula.h"
TStack::TStack() : Top(-1) {}

bool TStack::IsEmpty() const {
    return Top == -1;
}

bool TStack::IsFull() const {
    return Top == MaxLength - 1;
}

void TStack::Put(const double& Val) {
    if (!IsFull()) {
        Stack[++Top] = Val;
    }
    else {
        std::cerr << "Stack overflow!" << std::endl;
    }
}

double TStack::Peek() const {
    if (!IsEmpty()) {
        return Stack[Top];
    }
    else {
        std::cerr << "Stack is empty!" << std::endl;
        return 0.0; 
    }
}

double TStack::Pop() {
    if (!IsEmpty()) {
        return Stack[Top--];
    }
    else {
        std::cerr << "Stack is empty!" << std::endl;
        return 0.0; 
    }
}

bool TFormula::hasHigherPrecedence(char op1, char op2) {
    if ((op1 == '*' || op1 == '/') && (op2 == '+' || op2 == '-'))
        return true;
    if ((op1 == op2) || (op1 == '+' || op1 == '-') && (op2 == '*' || op2 == '/'))
        return false;
    
    return op2 == '(' || op2 == ')';
}

bool TFormula::isOperator(char op) {
    return op == '+' || op == '-' || op == '*' || op == '/';
}