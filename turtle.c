#include "turtle.h"

void initTurtle(Turtle *T, Point pos, FILE *fp)
{
   T->Position.X = pos.X;
   T->Position.Y = pos.Y;
   T->Position.Z = pos.Z;

   initList(&T->Points);

   T->OutStream = fp;
}

void makeStep(Turtle *T, Axle ax)
{
   Vector v = axles[ax];
   v = multiplyPoint(v, u);

   T->Position = addVectorToPoint(v, T->Position);
   insert(&T->Points, T->Position);
}

void moveTo(Turtle *T)
{
   insert(&T->Points, T->Position);
}

void makeList3D(Turtle *T, int n, Axle X, Axle Y, Axle Z)
{
   if(n == 0)
      return;

   makeList3D(T, n-1, Z, X, Y);
   makeStep(T, opposite(Y));
   makeList3D(T, n-1, Y, Z, X);
   makeStep(T, opposite(X));
   makeList3D(T, n-1, Y, Z, X);
   makeStep(T, Y);
   makeList3D(T, n-1, opposite(X), opposite(Y), Z);
   makeStep(T, opposite(Z));
   makeList3D(T, n-1, opposite(X), opposite(Y), Z);
   makeStep(T, opposite(Y));
   makeList3D(T, n-1, Y, opposite(Z), opposite(X));
   makeStep(T, X);
   makeList3D(T, n-1, Y, opposite(Z), opposite(X));
   makeStep(T, Y);
   makeList3D(T, n-1, opposite(Z), X, opposite(Y));
}

void flushTurtle(Turtle *T)
{
   Point tmp;

   double dx, dy;
   tmp = T->Points->Elem[0];

   dx = ((d)/(tmp.Z + d)) * tmp.X;
   dy = ((d)/(tmp.Z + d)) * tmp.Y;

   fprintf(T->OutStream, "%6.2lf %6.2lf moveto\n", dx, dy);

   for(int i = 1; i < T->Points->npos; ++i)
   {
      tmp = T->Points->Elem[i];

      dx = ((d)/(tmp.Z + d)) * tmp.X;
      dy = ((d)/(tmp.Z + d)) * tmp.Y;

      fprintf(T->OutStream, "%6.2lf %6.2lf lineto\n", dx, dy);
   }
}

void moveByVector(Turtle *T, Vector origin)
{
   for(int i = 0; i < T->Points->npos; ++i)
      T->Points->Elem[i] = addVectorToPoint(origin, T->Points->Elem[i]);
}

void rotateAll(Turtle *T, double angleX, double angleY)
{
   for(int i = 0; i < T->Points->npos; ++i)
      T->Points->Elem[i] = rotateOX(T->Points->Elem[i], angleX);
   for(int i = 0; i < T->Points->npos; ++i)
      T->Points->Elem[i] = rotateOY(T->Points->Elem[i], angleY);
}

