/*
** EPITECH PROJECT, 2022
** my_sokoban
** File description:
** my_arrcpy.c
*/

#include "my.h"

char** my_arrcpy(char **dest, char **src)
{
    int i = 0;
    for (i = 0; src[i] != 0; i++) {
        my_strcpy(dest[i], src[i]);
    }
    dest[i] = 0;
    return dest;
}
