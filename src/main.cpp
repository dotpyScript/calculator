#include <iostream>
#include <string>
#include "../include/calculator.h"

int main() {
    while(true) {
        double a, b;
        char op;
        std::string error;

        std::cout << "\nEnter expression (e.g., 2, 3) or 'q' to quit: ";

        // check for Quit command first 
        if (std::cin.peek() == 'q') {
            break;
        }

        if (!(std::cin >> a >> op >> b )) {
            std::cout << "invalid input\n";

            std::cin.clear(); // clear error state
            std::cin.ignore(1000, '\n'); // discard invalid input
            continue;
        }

        double result = calculate(a, b, op, error);
        if(error.empty()) {
            std::cout << "Result: " << result << std::endl;
        } else {
            std::cout << error << std::endl;
        }
    }
    std::cout << "Calculator exited.\n";
    return 0;
}

//   std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input