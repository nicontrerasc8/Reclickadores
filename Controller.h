#pragma once
#include <vector>
#include "Player.h"
#include "Garbage.h"

using namespace std;

class Controller {
private:
	vector <Base*> garbageBags;
	Player* player;
public:
	Controller() {
		int cant = 5;
		while(cant--) {
			garbageBags.push_back(new Garbage(1 + rand() % 100, 1 + rand() % 200, 10, 10));
		}
		player = new Player(45, 85, 20, 20);
	}
	~Controller() {
		delete player;
		for (int i = 0; i < garbageBags.size(); i++)
			delete garbageBags.at(i);
		garbageBags.clear();
	}
	
	void dibujarPlayer(Graphics^ g, Bitmap^ bmp) {
		player->dibujarDesdeImg(g, bmp);
		player->mover(g);
	}
	void dibujarGarbage(Graphics^ g, Bitmap^ bmp) {
		for (Base* garbage : garbageBags) {
			garbage->dibujarDesdeImg(g, bmp);
			garbage->mover(g);
		}
	}
	void desplazarPlayer(direccion d) {
		player->desplazamiento(d);
		//colision(); on controller
	}
	
};