#ifndef PUTELLIPSOID_H
#define PUTELLIPSOID_H

#include "FiguraGeometrica.h"
#include "sculptor.h"


class putEllipsoid: public FiguraGeometrica{
protected:
   int x,y,z;
public:
   putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);

   void draw(Sculptor &t);
    
    ~putEllipsoid();

};





#endif // PUTELLIPSOID_H