#ifndef PUTBOX_H
#define PUTBOX_H

#include "FiguraGeometrica.h"
#include "sculptor.h"


class putBox: public FiguraGeometrica{
protected:
  int x0,  x1, y0, y1, z0, z1;
public:
   putBox(int x0, int x1, int y0, int y1, int z0, int z1);

   void draw(Sculptor &t);
    
    ~putBox();


};





#endif // PUTBOX_H