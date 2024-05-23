/*
** EPITECH PROJECT, 2021
** Arcade
** File description:
** getGame
*/

#include "IArcade.hpp"
#include "CEncapsulation.hpp"
#include "errors.hpp"

IGames *IArcade::getGame(const char *libname)
{
    CEncapsulation dlfunc;
    void *lib = dlfunc.dlopenC(libname, RTLD_LAZY);
    IGames* (*function)();

    if (!lib)
        throw ErrSharedLib(dlfunc.dlerrorC());
    dlfunc.dlerrorC();
    *(void **) (&function) = dlfunc.dlsymC(lib, "createGame");
    if (!function)
        throw ErrSharedLib(dlfunc.dlerrorC());
    IGames *tmp = (*function)();
    return (tmp);
}