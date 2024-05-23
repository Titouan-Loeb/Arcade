/*
** EPITECH PROJECT, 2021
** Arcade
** File description:
** CEncapsulation
*/

#include "CEncapsulation.hpp"

CEncapsulation::CEncapsulation()
{
}

CEncapsulation::~CEncapsulation()
{
}

void *CEncapsulation::dlopenC(const char *filename, int flag)
{
    return dlopen(filename, flag);
}

const char *CEncapsulation::dlerrorC(void)
{
    return dlerror();
}

void *CEncapsulation::dlsymC(void *handle, const char *symbol)
{
    return dlsym(handle, symbol);
}

int CEncapsulation::dlcloseC(void *handle)
{
    if (handle != NULL)
        return dlclose(handle);
    return 0;
}