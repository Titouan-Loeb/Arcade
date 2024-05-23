/*
** EPITECH PROJECT, 2021
** REPO
** File description:
** main
*/

#include "errors.hpp"
#include "IArcade.hpp"

int main(int argc, char **argv)
{
    try {
        handleArguments(argc, argv);
        IArcade *arcade = new IArcade(argv[1]);
        arcade->coreLoop();
    } catch (std::exception &err) {
        std::cerr << err.what() << std::endl;
        return (84);
    }
    return (0);
}