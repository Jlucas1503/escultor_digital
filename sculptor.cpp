#include <iostream>
#include "sculptor.h"


Sculptor::Sculptor(int _nx, int _ny, int _nz){
    _nx = nx;
    _ny = ny;
    _nz = nz;
    std::cout << "construtor iniciado\n";

    r = 0.5;
    g = 0.5;
    b = 0.5;
    a = 0.5;

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
    
/*detalhe, se atentar ao colchete, pode dar erro!!!! */

}

void Sculptor::setColor(float r, float g, float b, float alpha){
    r = r;
    g = g;
    b = b;
    alpha = alpha;
}

void Sculptor::putVoxel(int x, int y, int z){
    x = x;
    y = y;
    z = z;
    // a "instrução" .show está igual a true, para que o Voxel apareça na tela"
    v[x][y][z].show = true;
    v[x][y][z].r = r;
    v[x][y][z].g = g;
    v[x][y][z].b = b;

}
void Sculptor::cutVoxel(int x, int y, int z){
    x = x;
    y = y;
    z = z;

    v[x][y][z].show = false;
}