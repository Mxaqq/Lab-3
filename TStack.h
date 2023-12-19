#ifndef TSTACK_H
#define TSTACK_H

#include <iostream>

const int MaxLength = 255;

class TStack {
private:
    double Stack[MaxLength];
    int Top;

public:
    TStack();
    bool IsEmpty() const;
    bool IsFull() const;
    void Put(const double& Val);
    double Peek() const;
    double Pop();
};

bool hasHigherPrecedence(char op1, char op2);
bool isOperator(char op);

#endif 