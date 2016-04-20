#ifndef LIST_H
#define LIST_H

#include <stdlib.h>
#include "world.h"

#define RESIZE_FACTOR 2

typedef struct {
   Point *Elem;
   int nelem;
   int npos;
} List;

void initList(List **l);
void insert(List **l, Point e);


#endif // LIST_H
