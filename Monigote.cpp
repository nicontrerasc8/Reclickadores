#include "Monigote.h"

Monigote::Monigote() {
	
}

Monigote::Monigote(int x, int y, int w, int h) : Base(x, y, w, h, 4, 5, 0, 0) {
	dx = 1;
	fraccionMovY = 5; // No quiere decir que hay desplazamiento en Y
	fraccionMovX = 5; // No quiere decir que hay desplazamiento en X
	desplazamiento(direccion::right); // Aquí se coloca el movimiento
}

Monigote::~Monigote() { }

void Monigote::mover(Graphics^ g) {
	if (x + dx < 1 || x + w + dx > g->VisibleClipBounds.Width) dx = 0;
	if (y + dy < 1 || y + h + dy > g->VisibleClipBounds.Height) dy = 0;
	x += dx;
	y += dy;
}