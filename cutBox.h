#ifndef CUTBOX_H
#define CUTBOX_H

#include "FiguraGeometrica.h"
#include "sculptor.h"


class cutBox: public FiguraGeometrica{
protected:
   int x,y,z;
public:
   cutBox(int x0, int x1, int y0, int y1, int z0, int z1);

   void draw(Sculptor &t);
    
    ~cutBox();


};





#endif // CUTBOX_H