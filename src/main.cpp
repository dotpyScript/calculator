#include <iostream>
#include <string>
#include "../include/calculator.h"

int main() {
    double a, b;
    char op;
    std::string error;

    std::cout << "Enter expression (e.g., 2, 3): ";
    std::cin >> a >> op >> b;
    double result = calculate(a, b, op, error);
    if(error.empty()) {
        std::cout << "Result: " << result << std::endl;
    } else {
        std::cout << error << std::endl;
    }
    return 0;
}