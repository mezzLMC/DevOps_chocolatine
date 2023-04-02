/*
** EPITECH PROJECT, 2022
** pushswap
** File description:
** array_append.c
*/

#include "my.h"

char** array_append(char** array, char* const str)
{
    int old_lenght = my_arraylen(array);
    char** new_arr = malloc(sizeof(char*) * (old_lenght + 2));
    char* dup_str = malloc(sizeof (char) * (my_strlen(str) + 1));
    my_strcpy(dup_str, str);
    for (int i = 0; array[i] != 0; i++) {
        new_arr[i] = malloc(sizeof(char) * (my_strlen(array[i]) + 1));
    }
    my_arrcpy(new_arr, array);
    new_arr[old_lenght] = dup_str;
    new_arr[++old_lenght] = 0;
    free(array);
    return new_arr;
}
