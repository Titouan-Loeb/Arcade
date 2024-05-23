/*
** EPITECH PROJECT, 2021
** REPO
** File description:
** parseMap
*/

#include "IArcade.hpp"

std::string openReadFile(std::string filename)
{
    std::ifstream file(filename);
    std::stringstream stream;

    stream << file.rdbuf();
    file.close();
    return stream.str();
}

std::vector<std::string> strToWordArray(std::string buffer)
{
    std::vector<std::string> array;

    size_t pos = 0;
    int index = 0;

    while ((pos = buffer.find("\n")) != buffer.npos) {
        array.push_back(buffer.substr(0, pos));
        buffer.erase(0, pos + 1);
        index++;
    }
    if (buffer.length() != 0)
        array.push_back(buffer);
    return array;
}

std::vector<std::string> IArcade::parseFile(std::string filename)
{
    return (strToWordArray(openReadFile(filename)));
}