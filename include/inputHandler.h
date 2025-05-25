#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <string>
#include <vector>

class InputHandler {
public:
    InputHandler();
    ~InputHandler();

    void verificaStringInput(const std::vector<std::string>& validOptions) const;
    std::string getStringInput(const std::vector<std::string>& validOptions) const;
    int getIntInput(int min, int max) const;
};

#endif










