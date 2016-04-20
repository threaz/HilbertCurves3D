#include "world.h"

extern const Vector axles[];


Point setPoint(double x, double y, double z)
{
   Point p = {x, y, z};
   return p;
}

Point addPoints(Point p1, Point p2)
{
   Point tmp = {p1.X+p2.X, p1.Y+p2.Y, p1.Z+p2.Z};
   return tmp;
}

Point multiplyPoint(Point p, double val)
{
   Point pt = {p.X*val, p.Y*val, p.Z*val};
   return pt;
}

Point addVectorToPoint(Vector v, Point p)
{
   return addPoints((Point)v, p);
}

Point rotateOX(Point P, double angle)
{
   double angleRadian = angle * M_PI/180;

   double newX, newY, newZ;
   newX = P.X;
   newY = P.Y * cos(angleRadian) - P.Z * sin(angleRadian);
   newZ = P.Y * sin(angleRadian) + P.Z * cos(angleRadian);

   P.X = newX;
   P.Y = newY;
   P.Z = newZ;

   return P;
}

Point rotateOY(Point P, double angle)
{
   double angleRadian = angle * M_PI/180;

   double newX, newY, newZ;
   newX = P.X * cos(angleRadian) + P.Z * sin(angleRadian);
   newY = P.Y;
   newZ = (-1) * P.X * sin(angleRadian) + P.Z * cos(angleRadian);

   P.X = newX;
   P.Y = newY;
   P.Z = newZ;

   return P;
}


Axle opposite(Axle a)
{
   return (a + 3) % 6;
}
