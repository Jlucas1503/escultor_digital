#ifndef PUTSPHERE_H
#define PUTSPHERE_H

#include "FiguraGeometrica.h"
#include "sculptor.h"


class putSphere: public FiguraGeometrica{
protected:
   int xcenter, ycenter, zcenter, radius;
   float r, g, b, a;
public:
   putSphere(int xcenter, int ycenter, int zcenter, int radius, int r, int g, int b, int a);

   void draw(Sculptor &t);
    
    ~putSphere();


};





#endif // PUTSPHERE_H