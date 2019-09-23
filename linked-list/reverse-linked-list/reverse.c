#include <stdlib.h>
#include <stdio.h>
#define TOTAL_NODE 10

typedef struct node
{
    int item;
    struct node *next;
} node;

typedef node *link;

link init_link(int length)
{   
    // initialize a linked list
    link head = (link)malloc(sizeof(node));
    head->item = 0;
    head->next = NULL;

    link current = head;
    for (int i = 1; i < length; i++)
    {
        link brand_new = (link)malloc(sizeof(node));
        brand_new->item = i;
        brand_new->next = NULL;

        current->next = brand_new;
        current = brand_new;
    }

    return head;
}

link reverse_link(link head)
{
    link next = NULL;
    link previous = NULL;
    link current = head;

    while (current)
    {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }

    link reversed_head = previous;
    return reversed_head;
}

void free_link(link head)
{
    link current = head;
    link next = NULL;

    while (current)
    {
        next = current->next;
        free(current);
        current = next;
    }

}

void print_link(link head)
{
    link current = head;
    link next = NULL;

    while (current)
    {
        printf("node item = %d\n", current->item);
        current = current->next;
    }
}

int main(void)
{
    link new_link = init_link(TOTAL_NODE);
    print_link(new_link);

    link reversed_link = reverse_link(new_link);
    print_link(reversed_link);

    free_link(reversed_link);
    reversed_link = NULL;
    new_link = NULL;

    return 0;

}