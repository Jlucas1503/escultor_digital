
#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include "sculptor.h"


Sculptor::Sculptor(int _nx, int _ny, int _nz){
    this -> nx = _nx;
    this -> ny = _ny;
    this -> nz = _nz;
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
    float xnovo;
    float ynovo;
    float znovo;

    for(int x = 0; x < nx; x++){ 

        for(int y = 0; y < ny; y++){ 

            for(int z = 0; z < nz; z++){

                xnovo = ((float)(x-xcenter)*(float)(x-xcenter))/(rx * rx);
                ynovo = ((float)(y-ycenter)*(float)(y-ycenter))/(ry * ry);
                znovo = ((float)(z-zcenter)*(float)(z-zcenter))/(rz * rz);
                if((xnovo + ynovo + znovo) <= 1){ // se a equação da elipse for verdade, então faz o voxel
                putVoxel(x, y, z);
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
    float xnovo;
    float ynovo;
    float znovo;

    for(int x = 0; x < nx; x++){ 

        for(int y = 0; y < ny; y++){ 

            for(int z = 0; z < nz; z++){

                xnovo = ((float)(x-xcenter)*(float)(x-xcenter))/(rx * rx);
                ynovo = ((float)(y-ycenter)*(float)(y-ycenter))/(ry * ry);
                znovo = ((float)(z-zcenter)*(float)(z-zcenter))/(rz * rz);
                if((xnovo + ynovo + znovo) <= 1){ // se a equação da elipse for verdade, então desfaz o voxel
                cutVoxel(x, y, z);
                }
            }
        }
    }
}
void Sculptor::writeOFF(const char* filename){

  int quantvox = 0;
  int ref;
  std::ofstream Arqfinal;
  Arqfinal.open(filename);

  Arqfinal<<"OFF\n";

  // varre todos os voxel e analisa os que devem ser exibidos no .off
  for (int i = 0; i < nx; i++){
      for (int j = 0; j <ny; j++){
           for (int k = 0; k <nz; k++){
                if(v[i][j][k].show == true){
                quantvox++;
                }
           }
       }
  }
  Arqfinal<<quantvox * 8<<" "<<quantvox * 6 << " " << "0" << "\n"; // mostra a quantidade total de vertices, faces e arestas

  for (int a = 0; a < nx; a++){
      for (int b = 0; b < ny; b++){
           for (int c = 0; c < nz; c++){
                if(v[a][b][c].show == true){
                Arqfinal << a - 0.5 << " " << b + 0.5 << " " << c - 0.5 << "\n" << std::flush;
                Arqfinal << a - 0.5 << " " << b - 0.5 << " " << c - 0.5 << "\n" << std::flush;
                Arqfinal << a + 0.5 << " " << b - 0.5 << " " << c - 0.5 << "\n" << std::flush;
                Arqfinal << a + 0.5 << " " << b + 0.5 << " " << c - 0.5 << "\n" << std::flush;
                Arqfinal << a - 0.5 << " " << b + 0.5 << " " << c + 0.5 << "\n" << std::flush;
                Arqfinal << a - 0.5 << " " << b - 0.5 << " " << c + 0.5 << "\n" << std::flush;
                Arqfinal << a + 0.5 << " " << b - 0.5 << " " << c + 0.5 << "\n" << std::flush;
                Arqfinal << a + 0.5 << " " << b + 0.5 << " " << c + 0.5 << "\n" << std::flush;
                }
           }
      }
  }

  quantvox = 0;

  // descrever cada voxel
  for (int a= 0; a<nx; a++){
      for (int b = 0; b<ny; b++){
           for (int c= 0; c<nz; c++){
                if(v[a][b][c].show == true){
                ref = quantvox * 8;
                Arqfinal << std::fixed;

                // montar linha que realiza a construção das faces a partir do vertices e mostrar as propriedades rgba do voxel
                Arqfinal << "4" << " " << 0+ref << " " << 3+ref << " " << 2+ref << " " << 1+ref << " ";
                Arqfinal << std::setprecision(2)<<v[a][b][c].r << " " << std::setprecision(2)<<v[a][b][c].g <<" " << std::setprecision(2)<<v[a][b][c].b << " " << std::setprecision(2) << v[a][b][c].a << "\n";

                Arqfinal << "4" << " " << 4+ref << " " << 5+ref << " " << 6+ref << " " << 7+ref << " ";
                Arqfinal << std::setprecision(2)<<v[a][b][c].r << " " << std::setprecision(2)<<v[a][b][c].g <<" " << std::setprecision(2)<<v[a][b][c].b << " " << std::setprecision(2) << v[a][b][c].a << "\n";

                Arqfinal << "4" << " " << 0+ref << " " << 1+ref << " " << 5+ref << " " << 4+ref << " ";
                Arqfinal << std::setprecision(2)<<v[a][b][c].r << " " << std::setprecision(2)<<v[a][b][c].g <<" " << std::setprecision(2)<<v[a][b][c].b << " " << std::setprecision(2) << v[a][b][c].a << "\n";

                Arqfinal << "4" << " " << 0+ref << " " << 4+ref << " " << 7+ref << " " << 3+ref << " ";
                Arqfinal << std::setprecision(2)<<v[a][b][c].r << " " << std::setprecision(2)<<v[a][b][c].g <<" " << std::setprecision(2)<<v[a][b][c].b << " " << std::setprecision(2) << v[a][b][c].a << "\n";

                Arqfinal << "4" << " " << 3+ref << " " << 7+ref << " " << 6+ref << " " << 2+ref << " ";
                Arqfinal << std::setprecision(2)<<v[a][b][c].r << " " << std::setprecision(2)<<v[a][b][c].g <<" " << std::setprecision(2)<<v[a][b][c].b << " " << std::setprecision(2) << v[a][b][c].a << "\n";

                Arqfinal << "4" << " " << 1+ref << " " << 2+ref << " " << 6+ref << " " << 5+ref << " ";
                Arqfinal << std::setprecision(2)<<v[a][b][c].r << " " << std::setprecision(2)<<v[a][b][c].g <<" " << std::setprecision(2)<<v[a][b][c].b << " " << std::setprecision(2) << v[a][b][c].a << "\n";

                quantvox = quantvox + 1;
                }
           }
       }
  }
  Arqfinal.close();
}
