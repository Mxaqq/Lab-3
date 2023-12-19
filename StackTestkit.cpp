#include "TFormula.h"
#include <iostream>
#include <cstring>

int main() {
    setlocale(LC_ALL, "Russian");
    char expression[100];
    std::cout << "Введите арифметическое выражение: ";
    std::cin.getline(expression, 100);

    TFormula formula(expression);

    int success = formula.FormulaConverter();

    if (success) {
        std::cout << "Постфиксная форма: " << formula.GetPostfixForm() << std::endl;

        double result = formula.FormulaCalculator();
        std::cout << "Результат: " << result << std::endl;
    }
    else {
        std::cerr << "Ошибка при преобразовании формулы в постфиксную форму." << std::endl;
    }

    return 0;
}