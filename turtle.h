#ifndef TURTLE_H
#define TURTLE_H

#include <stdlib.h>
#include <stdio.h>
#include "world.h"
#include "list.h"

typedef struct {
   Point Position;
   List *Points;
   FILE *OutStream;
} Turtle;

extern const Vector axles[];
extern int u;
extern int d;

void initTurtle(Turtle *T, Point pos, FILE *fp);
void makeStep(Turtle *T, Axle ax);
void moveTo(Turtle *T);
void makeList3D(Turtle *T, int n, Axle X, Axle Y, Axle Z);
void flushTurtle(Turtle *T);
void moveByVector(Turtle *T, Vector origin);
void rotateAll(Turtle *T, double angleX, double angleY);

#endif // TURTLE_H
