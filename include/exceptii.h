
#ifndef EXCEPTII_H
#define EXCEPTII_H
#include <exception>
#include <string>



class ExceptieSkillLevel: public std::exception {
    public:
    const char* what () const noexcept override {
        return "SkillLevel-ul nu poate fi mai mare decat 10";
    }
};





#endif
