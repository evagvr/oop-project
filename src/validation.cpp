
#include "../include/validation.h"
#include "../include/exceptii.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

int Validation::validatingInt(int min, int max) {
  std::string line;
  int value;

  std::getline(std::cin, line);
  while (line.empty()){
    std::getline(std::cin, line);
  }
  std::stringstream ss(line);

  if (!(ss >> value) || !(ss.eof())) {
    throw ExceptionInvalidInput("Inputul oferit nu este valid! Mai incearca: ");
  }
  if (value < min || value > max) {
    throw ExceptionInvalidInput("Numarul oferit este inafara limitelor permise! Mai incearca: ");
  }
  return value;
}
std::string Validation::validatingString(const std::vector<std::string>& inputOptions) {
  std::string line;

  std::getline(std::cin, line);
  while (line.empty()){
    std::getline(std::cin, line);
  }

  line.erase(0, line.find_first_not_of(" \t"));
  line.erase(line.find_last_not_of(" \t") + 1);

  if (std::find(inputOptions.begin(), inputOptions.end(), line) == inputOptions.end()) {
    throw ExceptionInvalidInput("Textul introdus nu este valid! Mai incearca:");
  }

  return line;
}