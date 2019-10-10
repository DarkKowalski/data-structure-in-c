#include "item.h"
#include <stdlib.h>
#include <stdio.h>

p_item item_create(const int number)
{
    p_item brand_new = (p_item)malloc(sizeof(item));
    brand_new->number = number;
    
    if (!brand_new)
    {
        fprintf(stderr, "%s", "Failed to alloc memory while creating a new item!\n");
        return NULL;
    }
    return brand_new;
}

bool item_delete(p_item i)
{
    if(i)
    {
        free(i);
        return true;
    }
    else
    {
        return false;
    }
    
}