#ifndef PUTVOXEL_H
#define PUTVOXEL_H

#include "FiguraGeometrica.h"
#include "sculptor.h"


class putVoxel: public FiguraGeometrica{
protected:
   int x,y,z;
public:
   putVoxel(int x, int y, int z);
   ~putVoxel();
   void draw(Sculptor &t);
    
    


};




#endif // PUTVOXEL_H