#include "item.h"
#include "stack.h"
#include <stdio.h>

#define STACK_SIZE 4

void push_pop(void)
{
    printf("Init => Push => Pop => Delete\n");

    printf("Init: size %d ", STACK_SIZE);
    p_stack client_stack = stack_init(STACK_SIZE);
    printf("Done!\n");
    printf("Stack size = %d\n", client_stack->size);
    printf("Stack top = %d\n", client_stack->top_offset);

    printf("Push: %d frames ", STACK_SIZE);
    for (int i = 0; i < STACK_SIZE; i++)
    {
        p_item new_item = item_create(i);
        stack_push(client_stack, new_item);
    }
    printf("Done!\n");
    printf("Stack top = %d\n", client_stack->top_offset);

    printf("Pop: %d frames\n", STACK_SIZE - 1);
    for (int i = 0; i < STACK_SIZE - 1; i++)
    {
        p_item popped_item = stack_pop(client_stack);
        printf("%d pop item: %d\n", i, popped_item->number);
        item_delete(popped_item);
    }
    printf("Done!\n");

    printf("Empty: top %d ", client_stack->top_offset);
    stack_empty(client_stack);
    printf("Done!\n");
    printf("Current top: %d\n", client_stack->top_offset);

    printf("Delete: ");
    stack_delete(client_stack);
    printf("Done!\n");
}

void stack_overflow(void)
{
    printf("Stack Overflow Test:\n");
    printf("Init: size %d ", STACK_SIZE);
    p_stack client_stack = stack_init(STACK_SIZE);
    printf("Done!\n");
    printf("Stack size = %d\n", client_stack->size);
    printf("Stack top = %d\n", client_stack->top_offset);

    printf("Push: %d frames ", STACK_SIZE + 1);
    bool stack_not_overflow = true;
    for (int i = 0; i < STACK_SIZE + 1; i++)
    {
        p_item new_item = item_create(i);
        stack_not_overflow &= stack_push(client_stack, new_item);
    }
    if (stack_not_overflow)
        printf("Done!\n");
    else
        printf("Stack Overflow detected!\n");
    printf("Stack top = %d\n", client_stack->top_offset);

    printf("Delete: ");
    stack_delete(client_stack);
    printf("Done!\n");
}
int main(void)
{
    printf("============================================\n");
    push_pop();
    printf("============================================\n");
    stack_overflow();
    printf("============================================\n");
    return 0;
}