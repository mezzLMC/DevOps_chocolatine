/*
** EPITECH PROJECT, 2022
** my_ls
** File description:
** my_arraylen.c
*/

int my_arraylen(char** array)
{
    int i = 0;
    for (i; array[i] != 0; i++);
    return i;
}
