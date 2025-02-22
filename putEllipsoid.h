#ifndef PUTELLIPSOID_H
#define PUTELLIPSOID_H

#include "FiguraGeometrica.h"
#include "sculptor.h"


class putEllipsoid: public FiguraGeometrica{
protected:
   int xcenter, ycenter, zcenter, rx, ry, rz;
   float r,  g,  b,  a;
public:
   putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz, float r, float g, float b, float a);

   void draw(Sculptor &t);
    
   ~putEllipsoid();

};





#endif // PUTELLIPSOID_H