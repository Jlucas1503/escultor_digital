#include "putVoxel.h"
#include "voxel.h"
#include <iostream>



putVoxel::putVoxel(int x, int y, int z){
    this->x = x;
    this->y = y;
    this->z = z;

}
void putVoxel::draw(Sculptor &t){
    t.setColor(r,g,b,a);
    t.putVoxel(x,y,z);
    
}