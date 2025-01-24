#ifndef PUTSPHERE_H
#define PUTSPHERE_H

#include "FiguraGeometrica.h"
#include "sculptor.h"


class putSphere: public FiguraGeometrica{
protected:
   int x,y,z;
public:
   putSphere(int xcenter, int ycenter, int zcenter, int radius);

   void draw(Sculptor &t);
    
    ~putSphere();


};





#endif // PUTSPHERE_H