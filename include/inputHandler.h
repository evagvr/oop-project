#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <string>
#include <vector>
#include <iostream>
#include <limits>
#include <sstream>

class InputHandler {
public:
    InputHandler() = default;
    ~InputHandler() = default;

    std::string getStringInput(const std::vector<std::string>& validOptions) const {
        std::string input;
        while (true) {
            std::getline(std::cin, input);

            input.erase(0, input.find_first_not_of(" \t"));
            input.erase(input.find_last_not_of(" \t") + 1);

            if (input.empty()) {
                std::cout << "Inputul dat este gol, insa nu poate fi gol.\n";
                continue;
            }

            for (const auto& option : validOptions) {
                if (input == option) {
                    return input;
                }
            }

            std::cout << "Input invalid. Singurele optiuni valide sunt: ";
            for (const auto& option : validOptions) {
                std::cout << option << " ";
            }
            std::cout << "\n";
        }
    }

    int getIntInput(int min, int max) const {
        while (true) {
            std::string line;
            std::getline(std::cin, line);

            if (std::cin.eof()) {
                std::cout << "Nu mai sunt date de citit.\n";
                return -1;
            }

            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Eroare la citirea inputului.\n";
                continue;
            }

            line.erase(0, line.find_first_not_of(" \t"));
            line.erase(line.find_last_not_of(" \t") + 1);

            if (line.empty()) {
                std::cout << "Inputul nu poate fi gol, trebuie sa inserezi un numar.\n";
                continue;
            }

            std::stringstream ss(line);
            int value;
            if (!(ss >> value) || !ss.eof()) {
                std::cout << "Input invalid. Insereaza un numar valid!\n";
                continue;
            }

            if (value < min || value > max) {
                std::cout << "Numarul trebuie sa fie cuprins intre "<< min << " si " << max << ".\n";
                continue;
            }

            return value;
        }
    }
};

#endif










