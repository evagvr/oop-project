#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <string>
#include <vector>
#include <iostream>
#include <limits>
class InputHandler {
public:
    InputHandler() = default;
    ~InputHandler() = default;


    std::string getStringInput(const std::vector<std::string>& validOptions) {
        std::string input;
        while (true) {
            std::getline(std::cin, input);
            

            input.erase(0, input.find_first_not_of(" \t"));
            input.erase(input.find_last_not_of(" \t") + 1);
            
            if (input.empty()) {
                std::cout << "Input cannot be empty. Please try again.\n";
                continue;
            }
            for (const auto& option : validOptions) {
                if (input == option) {
                    return input;
                }
            }
            
            std::cout << "Invalid input. Valid options are: ";
            for (const auto& option : validOptions) {
                std::cout << option << " ";
            }
            std::cout << "\n";
        }
    }

    int getIntInput(int min, int max) {
        int value;
        while (true) {
            if (!(std::cin >> value)) {
                clearInputBuffer();
                std::cout << "Invalid input. Please enter a number.\n";
                continue;
            }
            if (value >= min && value <= max) {
                return value;
            }
            std::cout << "Number must be between " << min << " and " << max << "\n";
        }
    }

private:
    void clearInputBuffer() {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
};

#endif