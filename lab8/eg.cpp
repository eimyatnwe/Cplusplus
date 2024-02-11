#include <iostream>
#include <string>

std::string extractNumericPart(const std::string& input) {
    std::string numericPart;
    for (char ch : input) {
        if (std::isdigit(ch)) {
            numericPart += ch;
        } else {
            break;  // Stop when a non-numeric character is encountered
        }
    }
    return numericPart;
}

int main() {
    while (true) {
        std::string userInput;

        std::cout << "Enter a string with numeric characters only: ";
        std::cin >> userInput;

        std::string numericPart = extractNumericPart(userInput);

        if (!numericPart.empty()) {
            int integer_value = std::stoi(numericPart);
            std::cout << "Extracted numeric part: " << numericPart << std::endl;
            std::cout << "Converted integer: " << integer_value << std::endl;
            break;  // Exit the loop if a valid integer is obtained
        } else {
            std::cout << "No valid integer found in the input. Please try again." << std::endl;
        }
    }

    return 0;
}
