#include <iostream>
#include "sculptor.h"


Sculptor::Sculptor(int _nx, int _ny, int _nz){
    _nx = nx;
    _ny = ny;
    _nz = nz;
    std::cout << "construtor iniciado\n";
}

Sculptor::~Sculptor(){
    std::cout << "destrutor chamado\n";
}

