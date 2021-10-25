#include "Controladora.h"

Controladora::Controladora() {
	int nEle = 10 + rand() % 20;
	for (int i = 0; i < nEle; i++) {
		if (i % 2 == 0) arreglo.push_back(new Playa(1 + rand() % 100, 1 + rand() % 200, 10, 10));
		if (i % 3 == 0) arreglo.push_back(new Bowling(1 + rand() % 100, 1 + rand() % 200, 10, 10));
		if (i % 5 == 0) arreglo.push_back(new Futbol(1 + rand() % 100, 1 + rand() % 200, 10, 10));
		if (i % 7 == 0) arreglo.push_back(new Basket(1 + rand() % 100, 1 + rand() % 200, 10, 10));
	}
	objMonigote = new Monigote(45, 85, 20, 20);
}

Controladora::~Controladora() { 
	delete objMonigote;
	for (int i = 0; i < arreglo.size(); i++)
		delete arreglo.at(i);
	arreglo.clear();
}

void Controladora::dibujarPelota(Graphics^ g, Bitmap^ bmp) {
	for (Base* pelota : arreglo) {
		pelota->dibujarDesdeImg(g, bmp);
		pelota->mover(g);
	}
}

void Controladora::dibujarMonigote(Graphics^ g, Bitmap^ bmp) {
	objMonigote->dibujarDesdeImg(g, bmp);
	objMonigote->mover(g);
}

void Controladora::desplazarMonigote(direccion d) {
	objMonigote->desplazamiento(d);
	colision();
}

bool Controladora::colision() {
	bool colision = false;
	Rectangle r1 = objMonigote->getRectangle();

	for (Base* pelota : arreglo) {
		Rectangle r2 = pelota->getRectangle();
		if (r1.IntersectsWith(r2)) {
			pelota->setDy(pelota->getDy() * -1);
			pelota->setDx(pelota->getDx() * -1);
			colision = true;
			break;
		}
	}

	return colision;
}