#pragma once
#include "Base.h"
class Player : public Base {
public:
	Player(){ }
	Player(int x, int y, int w, int h) : Base(x, y, w, h, 4, 4, 0, 0) {
		dx = 1;
		fraccionMovY = 5; 
		fraccionMovX = 5;
		desplazamiento(direccion::right);
	}
	~Player() { }

	void mover(Graphics^ g) {
		if (x + dx < 1 || x + w + dx > g->VisibleClipBounds.Width) dx = 0;
		if (y + dy < 1 || y + h + dy > g->VisibleClipBounds.Height) dy = 0;
		x += dx;
		y += dy;
	}
};