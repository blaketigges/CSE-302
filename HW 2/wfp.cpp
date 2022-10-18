#include <iostream>
#include "StackType.h"

int WellFormedParExp(std::string exp) {
    StackType <char> stack;
    int i = 0;
    int c = 0;
    while (exp[i] != '\0') {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{') {
            stack.Push(exp[i]);
        } else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}') {
            if (stack.IsEmpty()) {
                return -1;
            } else if (exp[i] == ')' && stack.Peek() == '(') {
                stack.Pop();
                c++;
            } else if (exp[i] == ']' && stack.Peek() == '[') {
                stack.Pop();
                c++;
            } else if (exp[i] == '}' && stack.Peek() == '{') {
                stack.Pop();
                c++;
            } else {
                return -1;
            }
        }
        i++;
    }
    if (stack.IsEmpty()) {
        return c;
    } else {
        return -1;
    }
}