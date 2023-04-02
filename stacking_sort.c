/*
** EPITECH PROJECT, 2022
** bs_pushswap
** File description:
** stacking_sort.c
*/

#include <stdlib.h>
#include <unistd.h>
#include "include/my.h"
#include "include/stacking.h"

double_stack_t* set_stack(long* array, int size);
void show_stack(stack_t* stack);
void show_operations(double_stack_t* stacks);
stack_t* get_last(stack_t* stack);

stack_t* isolate_node(stack_t* node, double_stack_t* stacks)
{
    int i = 0, j = 0;
    for (i; stacks->stack_a != node && stacks->stack_a != NULL; i++)
        push_b(stacks);
    rotate_left_a(stacks);
    return node;
}

stack_t* my_insertion_sort(double_stack_t* stacks, stack_t* l_node)
{
    stack_t *stack_a = l_node, *head = stack_a;
    int has_changed = 0;
    if (l_node == NULL)
        return NULL;
    while (stack_a->next != NULL && !has_changed) {
        if (stack_a->data > stack_a->next->data)
            has_changed = 1;
        stack_a = stack_a->next;
    }
    if (!has_changed)
        return NULL;
    if (stacks->steps->is_first_write++)
        write (1, " ", 1);
    l_node = isolate_node(stack_a, stacks);
    while (stacks->stack_b != NULL && stacks->stack_b->data > l_node->data)
        push_a(stacks);
    rotate_right_a(stacks);
    while (stacks->stack_b != NULL)
        push_a(stacks);
    empty_string(stacks);
    return my_insertion_sort(stacks, l_node);
}

void my_array_sorter(long* array, int size)
{
    double_stack_t* stacks = set_stack(array, size);
    stack_t* stack_a, stack_b, next_a, next_b;
    if (stacks->stack_a->data > stacks->stack_a->next->data)
        swap_a(stacks);
    my_insertion_sort(stacks, stacks->stack_a);
    write(1, stacks->steps->string, stacks->steps->str_len);
    write(1, "\n", 1);
}
