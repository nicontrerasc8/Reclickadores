#pragma once
#include <vector>
#include "Player.h"
#include "GarbageBags.h"

using namespace std;

class Controller {
private:
	GarbageBags* gBags;
	Player* player;
public:
	Controller() {
		player = new Player(45, 85, 20, 20);
		gBags = new GarbageBags(player->getArea());
	}
	~Controller() {
		delete player, gBags;
	}
	
	void dibujarPlayer(Graphics^ g, Bitmap^ bmp) {
		player->dibujarDesdeImg(g, bmp);
		player->mover(g);
	}
	void dibujarGarbage(Graphics^ g, Bitmap^ bmp) {
		gBags->dibujar(g, bmp);
	}
	void desplazarPlayer(direccion d) {
		// incomplete
		if (!gBags->colision(player->getNextArea())) {
			player->desplazamiento(d);
		}
	}
};