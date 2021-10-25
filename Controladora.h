#pragma once
#include <vector>
#include "Playa.h"
#include "Basket.h"
#include "Futbol.h"
#include "Bowling.h"
#include "Monigote.h"

using namespace std;

class Controladora {
private:
	vector <Base*> arreglo;
	Monigote* objMonigote;
public:
	Controladora();
	~Controladora();
	void dibujarPelota(Graphics^ g, Bitmap^ bmp);
	
	void dibujarMonigote(Graphics^ g, Bitmap^ bmp);
	void desplazarMonigote(direccion d);
	bool colision();
};