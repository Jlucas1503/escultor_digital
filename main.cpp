#include <iostream>
#include "sculptor.h"

int main() {
   
   Sculptor vaso(20,20,20);

    vaso.setColor(0.39,0.26,0.2 ,1.0);

    vaso.putBox(0,19,0,19,0,19);

    vaso.cutBox(1,18,1,19,1,18);

    vaso.writeOFF("vaso.off");


    Sculptor Bolas(100,100,100);

    Bolas.setColor(0.39, 0.26, 0.2,1.0); // marrom
    Bolas.putEllipsoid(25,25,25,15,25,15);
    Bolas.cutEllipsoid(25,25,25,13,23,13);

    Bolas.setColor(1.0, 1.0, 1.0, 1.0); // branco
    Bolas.putVoxel(25,25,41);
    Bolas.putVoxel(25,26,40);
    Bolas.putVoxel(25,27,40);
    Bolas.putBox(25,25, 28, 33, 40, 40);
    Bolas.putBox(25,25, 17, 24, 40, 40);
    Bolas.putBox(25,25, 13, 16, 39, 39);
    Bolas.putBox(25,25, 13, 16, 39, 39);
    Bolas.putBox(25,25, 34, 37, 39, 39);

    Bolas.putBox(23, 27, 25, 25, 40, 40);
    Bolas.putBox(23, 27, 23, 23, 40, 40);
    Bolas.putBox(23, 27, 21, 21, 40, 40);
    Bolas.putBox(23, 27, 19, 19, 40, 40);
    Bolas.putBox(23, 27, 17, 17, 40, 40);
    Bolas.putBox(23, 27, 15, 15, 39, 39);
    Bolas.putBox(23, 27, 13, 13, 39, 39);

    Bolas.putBox(23, 27, 27, 27, 40, 40); 
    Bolas.putBox(23, 27, 29, 29, 40, 40);
    Bolas.putBox(23, 27, 31, 31, 40, 40);
    Bolas.putBox(23, 27, 33, 33, 40, 40); 
    Bolas.putBox(23, 27, 35, 35, 39, 39);
    Bolas.putBox(23, 27, 37, 37, 39, 39);


    // bola de sinuca
    Bolas.setColor(1.0,1.0,1.0,1.0); // branco
    Bolas.putSphere(25, 75, 25, 7);

    Bolas.setColor(0.39, 0.26, 0.2,1.0); // marrom
    Bolas.putBox(1, 80 , 87, 87, 25 , 25);
    Bolas.setColor(0.0, 0.0, 0.0 ,0.0); // preto
    Bolas.putVoxel(0, 87 , 25);

    Bolas.writeOFF("Bola_americana.off");




    return 0;
}