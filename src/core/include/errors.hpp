/*
** EPITECH PROJECT, 2021
** Arcade
** File description:
** errors
*/

#ifndef ERRORS_HPP_
#define ERRORS_HPP_

#include <exception>
#include <iostream>
#include <fstream>
#include <sstream>

class ErrNumberOfArg : public std::exception {
    private:
        std::string _message;
    public:
    ErrNumberOfArg(std::string message) : _message(message) {};
    ~ErrNumberOfArg() {};
    const char *what() const throw () {
        return (_message.c_str());
    }
};

class ErrSharedLib : public std::exception {
    private:
        std::string _message;
    public:
    ErrSharedLib(std::string message) : _message(message) {};
    ~ErrSharedLib() {};
    const char *what() const throw () {
        return (_message.c_str());
    }
};

class ErrBadArg : public std::exception {
    private:
        std::string _message;
    public:
    ErrBadArg(std::string message) : _message(message) {};
    ~ErrBadArg() {};
    const char *what() const throw () {
        return (_message.c_str());
    }
};

class ErrMapNotFound : public std::exception {
    private:
    public:
    ErrMapNotFound() {};
    ~ErrMapNotFound() {};
    const char *what() const throw () {
        return ( "Error : map Not Found : assets/maps/pacmanMap.txt");
    }
};

class ErrUnknowBlock : public std::exception {
    private:
        std::string _message;
    public:
    ErrUnknowBlock(std::string message) : _message(message) {};
    ~ErrUnknowBlock() {};
    const char *what() const throw () {
        return (_message.c_str());
    }
};

void handleArguments(int argc, char **argv);
std::string getUsage();
#endif /* !ERRORS_HPP_ */