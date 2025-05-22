

#ifndef VALIDATION_H
#define VALIDATION_H
#include <string>
#include <vector>


class Validation {
public:
  static int validatingInt(int min, int max);
  static std::string validatingString(const std::vector<std::string>& inputOptions);
};



#endif 
