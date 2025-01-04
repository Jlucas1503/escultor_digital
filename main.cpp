#include <iostream>
#include "sculptor.h"

int main() {
    // Inicializa um objeto Sculptor com dimensões 20x20x2 (uma moeda fina)
    Sculptor moeda(20, 20, 2);

    // Define a cor atual para dourado com transparência total
    moeda.setColor(1.0, 0.84, 0.0, 1.0);

    // Adiciona um cilindro de voxels para representar a moeda
    for (int z = 0; z < 2; z++) {
        moeda.putEllipsoid(10, 10, z, 9, 9, 0);
    }

    // Salva o resultado em um arquivo OFF
    moeda.writeOFF("moeda.off");


    return 0;
}