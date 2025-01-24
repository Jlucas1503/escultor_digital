#ifndef CUTVOXEL_H
#define CUTVOXEL_H

#include "FiguraGeometrica.h"
#include "sculptor.h"


class cutVoxel: public FiguraGeometrica{
protected:
   int x,y,z;
public:
   cutVoxel(int x, int y, int z);

   void draw(Sculptor &t);
    
    ~cutVoxel();


};





#endif // CUTVOXEL_H