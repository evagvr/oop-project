#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <string>
#include <vector>
#include <iostream>
#include <limits>
#include <sstream>
#include "exceptii.h"



class InputHandler {
public:
    InputHandler() = default;
    ~InputHandler() = default;

    std::string getStringInput(const std::vector<std::string>& validOptions) const {
        std::string input;
        while (true) {
            try {
                std::getline(std::cin, input);
                
                input.erase(0, input.find_first_not_of(" \t"));
                input.erase(input.find_last_not_of(" \t") + 1);
                
                if (input.empty()) {
                    throw ExceptieInputInvalid("Inputul dat este gol, insa nu poate fi gol.");
                }

                for (const auto& option : validOptions) {
                    if (input == option) {
                        return input;
                    }
                }
                
                std::string errorMsg = "Input invalid. Singurele optiuni valide sunt: ";
                for (const auto& option : validOptions) {
                    errorMsg += option + " ";
                }
                throw ExceptieInputInvalid(errorMsg);
            } catch (const ExceptieInputInvalid& e) {
                std::cerr << e.what() << std::endl;
            }
        }
    }

    int getIntInput(int min, int max) const {
        while (true) {
            try {
                std::string line;
                std::getline(std::cin, line);

                if (std::cin.eof()) {
                    throw ExceptieInputInvalid("S-a ajuns la EOF. Nu mai sunt date de citit.");
                }
                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    throw ExceptieInputInvalid("Eroare la citirea inputului.");
                }

                line.erase(0, line.find_first_not_of(" \t"));
                line.erase(line.find_last_not_of(" \t") + 1);

                if (line.empty()) {
                    throw ExceptieInputInvalid("Inputul nu poate fi gol, trebuie sa inserezi un numar.");
                }

                std::stringstream ss(line);
                int value;
                if (!(ss >> value) || !ss.eof()) {
                    throw ExceptieInputInvalid("Input invalid. Insereaza un numar valid!");
                }

                if (value < min || value > max) {
                    throw ExceptieInputInvalid("Numarul trebuie sa fie cuprins intre " +
                        std::to_string(min) + " si " + std::to_string(max));
                }

                return value;
            } catch (const ExceptieInputInvalid& e) {
                std::cerr << e.what() << std::endl;
            }
        }
    }



};

#endif