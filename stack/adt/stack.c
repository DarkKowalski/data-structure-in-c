#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

p_stack stack_init(const int size)
{
    stack_frame *stack_space = (stack_frame *)malloc(size * sizeof(stack_frame));

    if (!stack_space)
    {
        fprintf(stderr, "%s", "Failed to alloc memory while initializing a new stack!\n");
        return NULL;
    }

    p_stack brand_new = (p_stack)malloc(sizeof(stack));

    if (!brand_new)
    {
        fprintf(stderr, "%s", "Failed to alloc memory while initializing a new stack!\n");
        return NULL;
    }

    brand_new->stack_space = stack_space;
    brand_new->size = size;
    brand_new->top_offset = 0;

    return brand_new;
}

static inline bool stack_frame_delete(stack_frame f)
{
    bool delete_success = item_delete(f);
    return delete_success;
}

int stack_empty(p_stack s)
{
    int top = s->top_offset;
    for (int i = 0; i < top; i++)
    {
        stack_frame frame = s->stack_space[i];
        bool delete_success = stack_frame_delete(frame);
        if (delete_success)
            s->stack_space[i] = NULL;
    }

    s->top_offset = 0;
    return top;
}

void stack_delete(p_stack s)
{
    int size = s->size;

    // Delete all items
    for (int i = 0; i < size; i++)
    {
        stack_frame frame = s->stack_space[i];
        bool delete_success = stack_frame_delete(frame);
        if (delete_success)
            s->stack_space[i] = NULL;
        else
            break;
    }

    if (s->stack_space)
    {
        free(s->stack_space);
        s->stack_space = NULL;
    }
    if (s)
        free(s);

}

bool stack_push(p_stack s, stack_frame f)
{
    int size = s->size;
    int top_offset = s->top_offset;

    if (size <= top_offset)
    {
        fprintf(stderr, "%s", "Stack Overflow!\n");
        return false;
    }

    s->stack_space[top_offset] = f;
    s->top_offset++;

    return true;
}

stack_frame stack_pop(p_stack s)
{
    int top_offset = s->top_offset;
    stack_frame frame = s->stack_space[top_offset - 1];
    s->stack_space[top_offset - 1] = NULL;
    s->top_offset--;

    return frame;
    // Haven't deleted this item yet
}