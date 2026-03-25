#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <cctype>
#include "../include/calculator.h"

int main() {
    while(true) {

        std::string input;
        std::string error;

        std::cout << "\nEnter expression (e.g., 2, 3) or 'q' to quit: ";
        std::getline(std::cin, input);

        // convert to lowercase
        std::transform(input.begin(), input.end(), input.begin(), [](unsigned char c){return std::tolower(c);});

        // trim spaces (simple version)

        input.erase(0, input.find_first_not_of(" \t"));
        input.erase(input.find_last_not_of(" \n") + 1);

        // check for Quit command first 
        if (input == "q" || input == "quit") {
            break;
        }

        std::stringstream ss(input);

        double a, b;
        char op;

        if (!(ss >> a >> op >> b )) {
            std::cout << "invalid input\n";
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