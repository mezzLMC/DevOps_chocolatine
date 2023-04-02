/*
** EPITECH PROJECT, 2022
** pushswap
** File description:
** tools.c
*/

#include <stdlib.h>
#include <unistd.h>
#include "include/my.h"
#include "include/stacking.h"

void free_steps(double_stack_t* stacks);

void show_operations(double_stack_t* stacks)
{
    string_t* steps = stacks->steps;
    write(1, steps->string, steps->str_len);
    free(steps->string);
    stacks->steps->string = malloc(sizeof(char) * 3);
    stacks->steps->mem_len = 3;
    stacks->steps->str_len = 0;
}

double_stack_t* set_stack(long* array, int size)
{
    double_stack_t* stacks = malloc(sizeof(double_stack_t));
    stack_t *element, *stack = NULL;
    for (int i = size - 1; i >= 0; i--) {
        element = malloc(sizeof(stack_t));
        element->data = array[i];
        element->next = stack;
        stack = element;
    }
    stacks->stack_a = stack;
    stacks->stack_b = NULL;
    stacks->steps = malloc(sizeof(string_t));
    stacks->steps->string = malloc(sizeof(char) * 1000000);
    stacks->steps->mem_len = 1000000;
    stacks->steps->str_len = 0;
    stacks->steps->is_first_write = 0;
    return stacks;
}

void empty_string(double_stack_t* stacks)
{
    write(1, stacks->steps->string, stacks->steps->str_len);
    free(stacks->steps->string);
    stacks->steps->string = malloc(sizeof(char) * 1000000);
    stacks->steps->mem_len = 1000000;
    stacks->steps->str_len = 0;
}

void add_operation(char* const str, int len, double_stack_t* stacks)
{
    int i = 0, need_update = 0;
    string_t* string = stacks->steps;
    char *temp = string->string, *new_str;
    if (string->mem_len < string->str_len + len + 2) {
        need_update = 1;
        while (string->mem_len < string->str_len + len + 2)
            string->mem_len = string->mem_len * 2;
    }
    if (need_update) {
        new_str = malloc(sizeof(char) * (string->mem_len));
        string->string = new_str;
        my_strncpy(string->string, temp, string->str_len);
    }
    if (string->str_len != 0)
        string->string[string->str_len++ + i] = ' ';
    for (i = 0; str[i] != '\0'; i++) {
        string->string[string->str_len + i] = str[i];
    }
    string->string[string->str_len + i] = '\0';
    string->str_len = string->str_len + len;
}

stack_t* get_last(stack_t* stack)
{
    while (stack->next != NULL)
        stack = stack->next;
    return stack;
}
