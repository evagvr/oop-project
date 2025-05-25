
#ifndef EXCEPTII_H
#define EXCEPTII_H
#include <exception>
#include <string>



class ExceptieSkillLevel: public std::exception {
    public:
    const char* what() const noexcept override {
        return "SkillLevel-ul nu poate fi mai mare decat 10";
    }
};
class ExceptiePopularitateNegativa: public std::exception {
public:
    const char* what() const noexcept override {
        return "Popularitatea a luat valori negative, jocul se incheie aici";
    }
};
class ExceptieEpuizareAni: public std::exception {
public:
    const char* what() const noexcept override {
        return "Ai epuizat cei 20 de ani disponibili, jocul s-a incheiat";
    }
};





#endif
