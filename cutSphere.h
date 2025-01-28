#ifndef CUTSPHERE_H
#define CUTSPHERE_H

#include "FiguraGeometrica.h"
#include "sculptor.h"


class cutSphere: public FiguraGeometrica{
protected:
   int xcenter, ycenter, zcenter, radius;
public:
      cutSphere(int xcenter, int ycenter, int zcenter, int radius);
      ~cutSphere();

      void draw(Sculptor &t);
    
   


};





#endif // CUTSPHERE_H