/*
** EPITECH PROJECT, 2022
** bs_pushswap
** File description:
** main.c
*/

//15, 8, 42, 4, 16, 23

#include <stdlib.h>
#include "include/my.h"

void my_array_sorter(long* array, int size);

int check_bad_arg(char* arg)
{
    if (arg[0] != '-' && !is_number(arg[0]))
        return 1;
    for (int i = 1; arg[i] != '\0'; i++) {
        if (!is_number(arg[i])) {
            return 1;
        }
    }
    return 0;
}

int main(int argc, char** argv)
{
    int i = 0;
    long* array;
    if (argc == 1) {
        return 84;
    }
    array = malloc(sizeof(long) * argc - 1);
    for (i = 1; i < argc; i++)
        if (check_bad_arg(argv[i]))
            return 84;
    if (argc == 2) {
        my_putchar('\n');
        return 0;
    }
    for (i = 1; i < argc; i++) {
        array[i - 1] = my_getnbr(argv[i]);
    }
    my_array_sorter(array, argc - 1);
    return 0;
}
