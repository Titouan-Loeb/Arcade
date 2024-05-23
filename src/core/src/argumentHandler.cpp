/*
** EPITECH PROJECT, 2021
** Arcade
** File description:
** argument_handler
*/

#include <iostream>
#include <fstream>
#include "errors.hpp"

std::string getUsage()
{
    std::ifstream file("./conf/usage.txt", std::ifstream::in);
    std::stringstream stream;

    if (file.good()) {
        stream << file.rdbuf();
        file.close();
        return (stream.str().c_str());
    } else
        return ("Error : one Argument needed");
}

void handleArguments(int argc, char **argv)
{
    if (argc != 2)
        throw ErrNumberOfArg("Error: Bad number of arguments\n\n" + getUsage());
}