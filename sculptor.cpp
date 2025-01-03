#include <iostream>
#include <fstream>

#include "sculptor.h"


Sculptor::Sculptor(int _nx, int _ny, int _nz){
    nx = _nx;
    ny = _ny;
    nz = _nz;
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
        for(int j = 0; j < ny; j++){
            delete[] v[i][j];
        }
    }

    for(int i =0; i< nx; i++){
        delete[] v[i];
    }

    delete[] v;
    
/*detalhe, se atentar ao colchete, pode dar erro!!!! */

}

void Sculptor::setColor(float r, float g, float b, float alpha){
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = alpha;
}

void Sculptor::putVoxel(int x, int y, int z){

    // a "instrução" .show está igual a true, para que o Voxel apareça na tela"
    v[x][y][z].show = true;
    v[x][y][z].r = r;
    v[x][y][z].g = g;
    v[x][y][z].b = b;

}
void Sculptor::cutVoxel(int x, int y, int z){
    v[x][y][z].show = false;
}

void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1){
    for(int x = x0; x <= x1; x++){
        for(int y = y0; y <= y1; y++){
            for(int z = z0; z <= z1; z++){
                v[x][y][z].show = true;
                v[x][y][z].r = r;
                v[x][y][z].g = g;
                v[x][y][z].b = b;
            }
        }
    } 
}

void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1){
    for(int x = x0; x <= x1; x++){
        for(int y = y0; y <= y1; y++){
            for(int z = z0; z <= z1; z++){
                v[x][y][z].show = false;
            }
        }
    } 
}
void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius){
    for(int x = xcenter - radius; x <= xcenter + radius; x++){ // x + raio = x0, ou seja, x= x0 - raio
        for(int y = ycenter - radius; y <= ycenter + radius; y++){ // y + raio = y0, ou seja, y= y0 - raio
            for(int z = zcenter - radius; z <= zcenter + radius; z++){ // z + raio = z0, ou seja, z= z0 - raio
                if((x - xcenter)*(x - xcenter) + (y - ycenter)*(y - ycenter) + (z - zcenter)*(z - zcenter) <= radius*radius){   // se a equação da esfera for verdadeira, então faz o voxel
                    v[x][y][z].show = true;
                    v[x][y][z].r = r;
                    v[x][y][z].g = g;
                    v[x][y][z].b = b;
                }
            }
        }
    } 
}

void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius){
    for(int x = xcenter - radius; x <= xcenter + radius; x++){ // x + raio = x0, ou seja, x= x0 - raio
        for(int y = ycenter - radius; y <= ycenter + radius; y++){ // y + raio = y0, ou seja, y= y0 - raio
            for(int z = zcenter - radius; z <= zcenter + radius; z++){ // z + raio = z0, ou seja, z= z0 - raio
                if((x - xcenter)*(x - xcenter) + (y - ycenter)*(y - ycenter) + (z - zcenter)*(z - zcenter) <= radius*radius){ // se a equação da esfera for verdadeira, então deleta o voxel
                    v[x][y][z].show = false;
                }
            }
        }
    } 
}

void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
    for(int x = xcenter - rx; x <= xcenter + rx; x++){ // x + raio = x0, ou seja, x= x0 - raio
        for(int y = ycenter - ry; y <= ycenter + ry; y++){ // y + raio = y0, ou seja, y= y0 - raio
            for(int z = zcenter - rz; z <= zcenter + rz; z++){ // z + raio = z0, ou seja, z= z0 - raio
                if((x - xcenter)*(x - xcenter)/(rx*rx) + (y - ycenter)*(y - ycenter)/(ry*ry) + (z - zcenter)*(z - zcenter)/(rz*rz) <= 1){ // se a equação da elipse for verdadeira, então faz o voxel
                    v[x][y][z].show = true;
                    v[x][y][z].r = r;
                    v[x][y][z].g = g;
                    v[x][y][z].b = b;
                }
            }
        }
    } 
}

void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
    for(int x = xcenter - rx; x <= xcenter + rx; x++){ // x + raio = x0, ou seja, x= x0 - raio
        for(int y = ycenter - ry; y <= ycenter + ry; y++){ // y + raio = y0, ou seja, y= y0 - raio
            for(int z = zcenter - rz; z <= zcenter + rz; z++){ // z + raio = z0, ou seja, z= z0 - raio
                if((x - xcenter)*(x - xcenter)/(rx*rx) + (y - ycenter)*(y - ycenter)/(ry*ry) + (z - zcenter)*(z - zcenter)/(rz*rz) <= 1){ // se a equação da elipse for verdadeira, então deleta o voxel
                    v[x][y][z].show = false;
                }
            }
        }
    }
}

void Sculptor::writeOFF(const char* filename){
    std::ofstream fout;

    int qvoxels = 0;
    int aux = 0;

    std::ofstream Arquivofinal;
    Arquivofinal.open(filename);

    if(!Arquivofinal.is_open()){
        std::cout << "Erro ao abrir o arquivo\n";
        exit(1);
    }

    Arquivofinal << "OFF\n";


    for(int i = 0; i < nx; i++){
        for(int j = 0; j < ny; j++){
            for(int k = 0; k < nz; k++){
                if(v[i][j][k].show == true){
                    qvoxels++;
                }
            }
        }
    }

Arquivofinal << 8*qvoxels << " " << 6*qvoxels << " 0\n";

for(int i = 0; i< nx; i++){
    for(int j = 0; j < ny; j++){
        for(int k = 0; k < nz; k++){
            if(v[i][j][k].show == true){
                Arquivofinal << i - 0.5 << " " << j + 0.5 << " " << k - 0.5 << "\n";
                Arquivofinal << i - 0.5 << " " << j - 0.5 << " " << k - 0.5 << "\n";
                Arquivofinal << i + 0.5 << " " << j - 0.5 << " " << k - 0.5 << "\n";
                Arquivofinal << i + 0.5 << " " << j + 0.5 << " " << k - 0.5 << "\n";
                Arquivofinal << i - 0.5 << " " << j + 0.5 << " " << k + 0.5 << "\n";
                Arquivofinal << i - 0.5 << " " << j - 0.5 << " " << k + 0.5 << "\n";
                Arquivofinal << i + 0.5 << " " << j - 0.5 << " " << k + 0.5 << "\n";
                Arquivofinal << i + 0.5 << " " << j + 0.5 << " " << k + 0.5 << "\n";
            }
        }
    }
}


for(int i = 0; i< nx; i++){
    for(int j = 0; j < ny; j++){
        for(int k = 0; k < nz; k++){
            if(v[i][j][k].show == true){
                if(v[i][j][k].show == true){
                    fout << 4 << " " << aux+0 << " " << aux + 3 << " " << aux + 2 << " " << aux + 1 << " "
                     << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << "\n";

                    fout << 4 << " " << aux+4 << " " << aux + 5 << " " << aux + 6 << " " << aux + 7 << " "
                    << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << "\n";

                    fout << 4 << " " << aux+0 << " " << aux + 1 << " " << aux + 5 << " " << aux + 4 << " "
                    << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << "\n";
                    
                    fout << 4 << " " << aux+0 << " " << aux + 4 << " " << aux + 7 << " " << aux + 3 << " "
                    << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << "\n";

                    fout << 4 << " " << aux+3 << " " << aux + 7 << " " << aux + 6 << " " << aux + 2 << " "
                    << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << "\n";

                    fout << 4 << " " << aux+1 << " " << aux + 2 << " " << aux + 6 << " " << aux + 5 << " "
                    << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << "\n";

                    aux = aux + 8;
                }
            }

    if(Arquivofinal.is_open()){
        std::cout << "Arquivo criado com sucesso\n";
    }
    else{
        std::cout << "Erro ao criar o arquivo\n";
    }

    Arquivofinal.close();
        }

    }

}
}