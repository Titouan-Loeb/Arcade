/*
** EPITECH PROJECT, 2021
** Arcade
** File description:
** ObjectInfo
*/

#ifndef OBJECTINFO_HPP_
#define OBJECTINFO_HPP_

#include <iostream>
#include <string>

typedef struct Rectangle_t
{
    int top;
    int left;
    int width;
    int height;
} Rectangle;

typedef struct Vect2i_t
{
    int x;
    int y;
} Vect2i;

typedef struct Vect2f_t
{
    float x;
    float y;
} Vect2f;

typedef struct Text_t
{
    std::string fontPath;
    std::string text;
    Vect2i intPos;
    Vect2f floatPos;
    int textID;
    int color;
    int size;
} Text;


#endif /* !OBJECTINFO_HPP_ */
