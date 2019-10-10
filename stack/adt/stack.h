#ifndef STACK_H
#define STACK_H
#include "item.h"
#include <stdbool.h>

typedef p_item stack_frame;

typedef struct stack
{
    stack_frame *stack_space;
    int size;
    int top_offset;
} stack;

typedef struct stack *p_stack;

p_stack stack_init(const int size);

int stack_empty(p_stack s);

stack_frame stack_pop(p_stack s);

bool stack_push(p_stack s, stack_frame f);

void stack_delete(p_stack s);

#endif