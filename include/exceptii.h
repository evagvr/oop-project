
#ifndef EXCEPTII_H
#define EXCEPTII_H
#include <exception>
#include <stdexcept>
#include <string>


class ExceptieBugetInsuficient: public std::exception {
public:
  const char* what () const noexcept override {
     return "Buget insuficient pentru executarea acestei actiuni!";
  }
};
class ExceptieSkillLevel: public std::exception {
    public:
    const char* what () const noexcept override {
        return "SkillLevel-ul nu poate fi mai mare decat 10";
    }
};
class ExceptieMembruDuplicat : public std::runtime_error {
public:
    explicit ExceptieMembruDuplicat() : std::runtime_error("Acest membru a fost deja selectat!") {}
};
class ExceptionGameOver : public std::runtime_error {
public:
    explicit ExceptionGameOver(const std::string& message) : std::runtime_error(message) {}
};
class ExceptionVictory : public std::runtime_error {
public:
    explicit ExceptionVictory(const std::string& message) : std::runtime_error(message) {}
};
class ExceptieInputInvalid : public std::exception {
    std::string msg;
public:
    explicit ExceptieInputInvalid(const std::string& message) : msg(message) {}
    const char* what () const noexcept override {
        return msg.c_str();
    }
};






#endif
