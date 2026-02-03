#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <iostream>
using namespace std;


class OperationError: public std::exception {
private:
    std::string message;
public:
    OperationError(const std::string& msg) : message(msg) {}
    virtual const char* what() const noexcept override {
        return message.c_str();
    }
};

class MemoryError: public std::exception {
private:
    std::string message;
public:
    MemoryError(const std::string& msg) : message(msg) {}
    virtual const char* what() const noexcept override {
        return message.c_str();
    }
};

class DividebyZero: public std::exception {
private:
    std::string message;
public:
    DividebyZero(const std::string& msg) : message(msg) {}
    virtual const char* what() const noexcept override {
        return message.c_str();
    }
};
#endif