#include "world.h"
#include "list.h"
#include "turtle.h"

#include <stdio.h>
#include <stdlib.h>

Point objCentre;
int d;
int u;

const Vector axles[] = {
   {1,0,0},
   {0,1,0},
   {0,0,1},
   {-1,0,0},
   {0,-1,0},
   {0,0,-1}
};

int main(int argc, char **argv)
{
   Turtle T;
   FILE *fp;
   int n, s;
   double fi, psi;
   double x, y, z;

   const Point c = {0, 0, 0}; // środek ukł. wsp.
   fp = stdout;


   if(argc < 10)
      return 1;

   n = strtol(argv[1], NULL, 10);
   s = strtol(argv[2], NULL, 10);
   u = strtol(argv[3], NULL, 10);
   d = strtol(argv[4], NULL, 10);
   x = strtod(argv[5], NULL);
   y = strtod(argv[6], NULL);
   z = strtod(argv[7], NULL);
   objCentre = setPoint(x, y, z);
   fi  = strtod(argv[8], NULL);
   psi = strtod(argv[9], NULL);

   Vector translVector = { u/2, u/2, u/2 };

   // oblicz właściwą długość małych krawędzi
   u = u / (pow(2, n) - 1);

   fprintf(fp, "%%!PS-Adobe-2.0 EPSF-2.0\n");
   fprintf(fp, "%%%%BoundingBox: ");
   fprintf(fp, "%d %d %d %d\n", -s/2, -s/2, s/2, s/2);
   fprintf(fp, "newpath\n");

   initTurtle(&T, c, fp);
   // dodaj początek do listy
   moveTo(&T);
   // stwórz listę punktów w 3D
   makeList3D(&T, n, OX, OY, OZ);

   // przesuń na środek ukł. wsp. świata
   moveByVector(&T, translVector);

   // obróć, OX potem OY
   rotateAll(&T, fi, psi);
   // umieść bryłę w zadanym układzie
   moveByVector(&T, (Vector)objCentre);
   // wypisz wszystkie punkty po rzutowaniu na 2D
   flushTurtle(&T);

   fprintf(fp, ".4 setlinewidth\n");
   fprintf(fp, "stroke\nshowpage\n%%%%Trailer\n%%EOF\n");

   fclose(fp);
   return 0;
}

