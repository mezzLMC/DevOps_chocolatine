/*
** EPITECH PROJECT, 2022
** pushswap
** File description:
** my_strdup.c
*/

#include <stdlib.h>
#include <string.h>
#include "my.h"

char* my_strdup(const char* str)
{
    char* dup = malloc(my_strlen(str) + 1);
    if (dup == NULL) {
        return NULL;
    }
    my_strcpy(dup, str);
    return dup;
}
