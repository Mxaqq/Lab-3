#ifndef TFORMULA_H
#define TFORMULA_H

// Предполагаемая максимальная длина формулы и постфиксной формы
const int MemMaxSize = 255;

class TFormula {
private:
    char Formula[MemMaxSize];
    char PostfixForm[MemMaxSize];

public:
    const char* GetPostfixForm() const {
        return PostfixForm;
    }
    TFormula(const char* str);
    int FormulaConverter();
    double FormulaCalculator();
    bool isOperator(char c);
    bool hasHigherPrecedence(char op1, char op2);
};

#endif // TFORMULA_H