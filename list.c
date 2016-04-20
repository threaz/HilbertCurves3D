#include "list.h"

void initList(List **l)
{
   if((*l = (List *)malloc(sizeof(List))) == NULL)
      return;

   List *lPtr = *l;

   if((lPtr->Elem = (Point *)malloc(sizeof(Point))) == NULL)
   {
      free(*l);
      *l = NULL;
      return;
   }

   lPtr->nelem = 1;
   lPtr->npos = 0;
}

void insert(List **l, Point e)
{
   List *kPtr = *l;

   // brak miejsca na lejny element
   if(kPtr->npos == kPtr->nelem)
   {
      Point *tmpPtr;
      // rozszerz tablicę
      if((tmpPtr = (Point *)realloc(kPtr->Elem, sizeof(Point) * kPtr->nelem * RESIZE_FACTOR)))
      {
         // sukces
         kPtr->Elem = tmpPtr;
      }
      else
         return;

      // aktualizuj wielkość tablicy
      kPtr->nelem = kPtr->nelem * RESIZE_FACTOR;
   }

   // wstaw element
   kPtr->Elem[kPtr->npos++] = e;
}
