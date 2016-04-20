#ifndef WORLD_H
#define WORLD_H

#include <math.h>

typedef struct {
   double X;
   double Y;
   double Z;
} Point;

typedef Point Vector;

typedef enum {
   OX = 0,
   OY,
   OZ,
   OX_R,
   OY_R,
   OZ_R
} Axle;

Point setPoint(double x, double y, double z);
Point addPoints(Point p1, Point p2);
Point multiplyPoint(Point p, double val);
Point addVectorToPoint(Vector v, Point p);
Point rotateOY(Point P, double angle);
Point rotateOX(Point P, double angle);
Axle opposite(Axle a);

#endif // WORLD_H
