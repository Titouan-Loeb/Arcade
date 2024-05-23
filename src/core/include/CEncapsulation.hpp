/*
** EPITECH PROJECT, 2021
** Arcade
** File description:
** CEncapsulation
*/

#ifndef CENCAPSULATION_HPP_
#define CENCAPSULATION_HPP_

#include <string>
#include <dlfcn.h>
#include <sys/types.h>

class CEncapsulation {
    public:
        CEncapsulation();
        ~CEncapsulation();
        void *dlopenC(const char *filename, int flag);
        const char *dlerrorC(void);
        void *dlsymC(void *handle, const char *symbol);
        int dlcloseC(void *handle);
};

#endif /* !CENCAPSULATION_HPP_ */
