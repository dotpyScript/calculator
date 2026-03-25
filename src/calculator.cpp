#include <iostream>
#include "../include/calculator.h"

double calculate(double a, double b, char op, std::string &error) {
    error = ""; // reset error message
    switch (op) {
        case '+':
            return a + b;
        case '-': 
            return a - b;
        case '*':
            return a * b;
        case '/': 
            if (b == 0) {
                error = "Cant be divisible by 0";
                return 0;
            }
            return a / b;
        default: 
            error = "input a valid number";
            return 0;
    }
}