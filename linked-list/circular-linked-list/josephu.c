#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
    int item;
    struct node* next;

} node;

typedef node *link;

int main(void)
{
    int total_number, step_length;
    scanf("%d %d", &total_number, &step_length);

    link head = (link)malloc(sizeof(node));
    head->item = 1;
    head->next = head;

    link current = head;

    for (int i = 2; i <= total_number; i++)
    {
        // create new node
        link brand_new = (link)malloc(sizeof(node));
        brand_new->item = i;
        brand_new->next = head;

        // move to next node
        current->next = brand_new;
        current = brand_new;
    }

    // now "current" points at the tail

    while (current != current->next)
    {
        for (int i = 1; i < step_length; i++)
            current = current->next;

        link temp = current->next;
        current->next = current->next->next;
        
        free(temp);
        temp = NULL;

        total_number--;
    }

    printf("%d\n", current->item);
    
    free(current);
    current = NULL;
    
    return 0;
}