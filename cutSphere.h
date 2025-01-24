#ifndef CUTSPHERE_H
#define CUTSPHERE_H

#include "FiguraGeometrica.h"
#include "sculptor.h"


class cutSphere: public FiguraGeometrica{
protected:
   int x,y,z;
public:
   cutSphere(int xcenter, int ycenter, int zcenter, int radius);

   void draw(Sculptor &t);
    
    ~cutSphere();


};





#endif // CUTSPHERE_H