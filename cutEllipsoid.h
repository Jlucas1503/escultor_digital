#ifndef CUTELLIPSOID_H
#define CUTELLIPSOID_H

#include "FiguraGeometrica.h"
#include "sculptor.h"


class cutEllipsoid: public FiguraGeometrica{
protected:
   int x,y,z;
public:
   cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);

   void draw(Sculptor &t);
    
    ~cutEllipsoid();

};





#endif // CUTELLIPSOID_H