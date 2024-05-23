/*
** EPITECH PROJECT, 2021
** REPO
** File description:
** getLib
*/

#include "IArcade.hpp"
#include "CEncapsulation.hpp"
#include "errors.hpp"

std::string pathLibName(std::string lib)
{
    while (lib.find('/') != std::string::npos)
        lib = lib.substr(lib.find('/') + 1, lib.size());
    return (lib);
}

int IArcade::getLibIndex(const char *lib)
{
    std::string str = lib;

    if (pathLibName(str) == "arcade_sdl2.so")
        return 0;
    if (pathLibName(str) == "arcade_ncurses.so")
        return 1;
    if (pathLibName(str) == "arcade_sfml.so")
        return 2;
    return 0;
}

std::vector<ILib *> IArcade::getLibs()
{
    std::vector<ILib *> tmp;

    tmp.push_back(getLib("./lib/arcade_sdl2.so"));
    tmp.push_back(getLib("./lib/arcade_ncurses.so"));
    tmp.push_back(getLib("./lib/arcade_sfml.so"));
    return (tmp);
}

ILib *IArcade::getLib(const char *libname)
{
    CEncapsulation dlfunc;
    void *lib = dlfunc.dlopenC(libname, RTLD_LAZY);
    ILib* (*function)();

    if (!lib)
        throw ErrSharedLib(dlfunc.dlerrorC());
    dlfunc.dlerrorC();
    *(void **) (&function) = dlfunc.dlsymC(lib, "createLibrary");
    if (!function)
        throw ErrSharedLib(dlfunc.dlerrorC());
    ILib *tmp = (*function)();
    return (tmp);
}

void IArcade::handleLibChange()
{
    int tmp = _libIndex;

    if (_input.code == KeyF1) {
        _libIndex++;
        _lib->clearWindow();
    }
    if (_input.code == KeyF2) {
        _libIndex--;
        _lib->clearWindow();
    }
    if (_libIndex > 2)
        _libIndex = 0;
    if (_libIndex < 0)
        _libIndex = 2;
    if (tmp != _libIndex) {
        _lib->destroyWindow();
        _lib = _libs[_libIndex];
        _lib->init();
    }
}