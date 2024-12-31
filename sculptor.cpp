#include <iostream>
#include "sculptor.h"


Sculptor::Sculptor(int _nx, int _ny, int _nz){
    _nx = nx;
    _ny = ny;
    _nz = nz;
    std::cout << "construtor iniciado\n";

    // criando agora nossa matriz 3d
    v = new Voxel**[nx];
    for(int i=0; i< nx; i++){
        v[i] = new Voxel*[ny];

        for(int j=0; j < ny; j++){
            v[i][j] = new Voxel[nz];

        }
}
}

Sculptor::~Sculptor(){
    std::cout << "destrutor chamado\n";
    for(int i =0; i< nx; i++){
        for(int j =0; i< ny; j++){
            delete v[i][j];
        }
    }

    for(int i =0; i< nx; i++){
        delete v[i];
    }

    delete v;
    


}

void setColor(float r, float g, float b, float alpha){
    r = r;
    g = g;
    b = b;
    alpha = alpha;
}