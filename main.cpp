#include <iostream>
#include "sculptor.h"

int main() {
   // cria um escultor cuja matriz tem 10x10x10 voxels
  Sculptor trono(10,10,10);
  // para mudar a cor do voxel
  trono.setColor(0,0,1.0,0); // azul
  // ativa os voxels na faixa de [x,y,z] pertencendo a [0-9]
  trono.putBox(0,9,0,9,0,9);
  // desativa os voxels na faixa de [x,y,z] pertencendo a [0-9]
  trono.cutBox(1,8,1,9,1,9);
  // grava a escultura digital no arquivo "trono.off"
  trono.writeOFF("trono.off");


   Sculptor vaso(20,20,20);

    vaso.setColor(0.39,0.26,0.2 ,1.0);

    vaso.putBox(0,19,0,19,0,19);

    vaso.cutBox(1,18,1,19,1,18);

    vaso.writeOFF("vaso.off");







    return 0;
}