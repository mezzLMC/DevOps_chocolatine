/*
** EPITECH PROJECT, 2022
** bs_pushswap
** File description:
** stacking.h
*/

#ifndef _STACKING_H_
    #define _STACKING_H_

        typedef struct stack {
            long data;
            struct stack* next;
        } stack_t;

        typedef struct step {
            char* data;
            int len;
            struct step* next;
        } step_t;

        typedef struct my_string {
            char* string;
            unsigned long long str_len;
            unsigned long long mem_len;
            int is_first_write;
        } string_t;

        typedef struct double_stack {
            stack_t* stack_a;
            stack_t* stack_b;
            string_t* steps;
        } double_stack_t;



    //rotate l_a toward the beginning, the first element will become the last.
    void rotate_left_a(double_stack_t* stacks);
    //rotate l_a toward the end, the last element will become the first.
    void rotate_right_a(double_stack_t* stacks);
    //first from stack_b to first of stack_a
    void push_a(double_stack_t* stacks);
    //swap the first two elements of stack_a
    void swap_a(double_stack_t* stacks);
    //rotate l_b toward the beginning, the first element will become the last.
    void rotate_left_b(double_stack_t* stacks);
    //first from stack_a to first of stack_b
    void push_b(double_stack_t* stacks);
    //swap the first two elements of l_b
    void swap_b(double_stack_t* stacks);

#endif
