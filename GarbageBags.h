#pragma once
#include "Garbage.h"

class GarbageBags {
private:
	vector <Garbage*> garbageBags;
public:
	GarbageBags(Rectangle obj) {	
		int cant = 5;
		while (cant--) {
			Garbage* gb = new Garbage(1 + rand() % 100, 1 + rand() % 200, 10, 10);
			if (!gb->getArea().IntersectsWith(obj)) {
				garbageBags.push_back(gb);
			} else {
				delete gb;
				cant++;
			}
		}
	}
	~GarbageBags() {
		for (int i = 0; i < garbageBags.size(); i++)
			delete garbageBags.at(i);
	}

	void dibujar(Graphics^ g, Bitmap^ bmp) {
		for (Base* garbage : garbageBags) {
			garbage->dibujarDesdeImg(g, bmp);
		}
	}
	bool colision(Rectangle obj) {
		for (Garbage* garbageBag : garbageBags) {
			if (garbageBag->getArea().IntersectsWith(obj)) {
				return true;
			}
		}
		return false;
	}
};