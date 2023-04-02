/*
** EPITECH PROJECT, 2022
** pushswap
** File description:
** stack_b.c
*/

#include <stddef.h>
#include <unistd.h>
#include "include/my.h"
#include "include/stacking.h"

int my_printf(char* format, ...);
void add_operation(char* const str, int len, double_stack_t* stacks);


void push_b(double_stack_t* stacks)
{
    stack_t* new_head = stacks->stack_a->next;
    stacks->stack_a->next = stacks->stack_b;
    stacks->stack_b = stacks->stack_a;
    stacks->stack_a = new_head;
    add_operation("pb", 2,stacks);
}

void rotate_left_b(double_stack_t* stacks)
{
    stack_t* first = stacks->stack_b;
    stack_t* stack_b = stacks->stack_b;
    stack_t* new_head = stack_b->next;
    while (stack_b->next != NULL)
        stack_b = stack_b->next;
    stack_b->next = first;
    first->next = NULL;
    stacks->stack_b = new_head;
    add_operation("rrb", 3, stacks);
}

void swap_b(double_stack_t* stacks)
{
    stack_t* first = stacks->stack_b;
    stack_t* second = stacks->stack_b->next;
    first->next = second->next;
    second->next = first;
    stacks->stack_b = second;
    add_operation("sb", 3, stacks);
}
