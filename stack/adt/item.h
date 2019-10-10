#ifndef ITEM_H
#define ITEM_H
#include <stdbool.h>

typedef struct item
{
    int number;
} item;

typedef item* p_item;

p_item item_create(const int number);
bool item_delete(p_item i);

#endif