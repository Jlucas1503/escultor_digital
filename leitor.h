#ifndef LEITOR_H
#define LEITOR_H

#include <vector>
#include <string>
#include "FiguraGeometrica.h"

using namespace std;

class leitor {
protected:
	int dimx, dimy, dimz;
	float r, g, b, a;
public:
	leitor();

	vector<FiguraGeometrica*> interpretador(string filename);

	int getDimx();
	int getDimy();
	int getDimz();

};

#endif // LEITOR_H