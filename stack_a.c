/*
** EPITECH PROJECT, 2022
** pushswap
** File description:
** stack_a.c
*/

#include <stddef.h>
#include <unistd.h>
#include "include/my.h"
#include "include/stacking.h"

int my_printf(char* format, ...);
char** array_append(char** array, char* const str);
void show_operation(char const str, double_stack_t* stacks);
void add_operation(char* const str, int len, double_stack_t* stacks);

void rotate_left_a(double_stack_t* stacks)
{
    stack_t* first = stacks->stack_a;
    stack_t* stack_a = stacks->stack_a;
    stack_t* new_head = stack_a->next;
    if (stack_a->next == NULL)
        return;
    while (stack_a->next != NULL)
        stack_a = stack_a->next;
    stack_a->next = first;
    first->next = NULL;
    stacks->stack_a = new_head;
    add_operation("ra", 2 ,stacks);
}

void rotate_right_a(double_stack_t* stacks)
{
    stack_t* first = stacks->stack_a;
    stack_t* stack_a = stacks->stack_a;
    stack_t *last, *before_last = first;
    if (first->next == NULL)
        return;
    while (before_last->next->next != NULL)
        before_last = before_last->next;
    last = before_last->next;
    before_last->next = NULL;
    last->next = first;
    stacks->stack_a = last;
    add_operation("rra", 3,stacks);
}

void push_a(double_stack_t* stacks)
{
    stack_t* new_head = stacks->stack_b->next;
    stacks->stack_b->next = stacks->stack_a;
    stacks->stack_a = stacks->stack_b;
    stacks->stack_b = new_head;
    add_operation("pa", 2, stacks);
}

void swap_a(double_stack_t* stacks)
{
    stack_t* first = stacks->stack_a;
    stack_t* second = stacks->stack_a->next;
    first->next = second->next;
    second->next = first;
    stacks->stack_a = second;
    add_operation("sa", 2, stacks);
}
