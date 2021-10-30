#include "Base.h"

Base::Base() { 
	dx = 0;
	dy = 0;
	active = true;
	orientacion = direccion::none;
}

Base::Base(int x, int y, int w, int h) {
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
	dx = 0;
	dy = 0;
	active = true;
	orientacion = direccion::none;
}

Base::Base(int x, int y, int w, int h, int maxRow, int maxCol, int row, int col) {
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
	dx = 0;
	dy = 0;
	active = true;
	orientacion = direccion::none;
	this->maxRow = maxRow;
	this->maxCol = maxCol;
	this->row = row;
	this->col = col;
}

Base::~Base() { }

void Base::mover(Graphics^ g) {
	if (x + dx < 1 || x + dx + w > g->VisibleClipBounds.Width) dx *= -1;
	if (y + dy < 1 || y + dy + h > g->VisibleClipBounds.Height) dy *= -1;
	x += dx;
	y += dy;
}

void Base::dibujar(Graphics^ g) {

}

void Base::dibujarDesdeImg(Graphics^ g, Bitmap^ bmp) {
	w = bmp->Width / maxCol;
	h = bmp->Height / maxRow;
	Rectangle porcion = Rectangle(col * w, row * h, w, h);
	g->DrawImage(bmp, x, y, porcion, GraphicsUnit::Pixel);
	col++;
	if (col == maxCol) col = 0;
}

void Base::borrar(Graphics^ g) {

}

void Base::desplazamiento(direccion d) {
	orientacion = d;
	dx = 0;
	dy = 0;

	if (orientacion == direccion::up) { 
		dy = - (h / fraccionMovY); 
		row = 3; 
	} else if (orientacion == direccion::down) { 
		dy = h / fraccionMovY; 
		row = 0; 
	} else if (orientacion == direccion::left) { 
		dx = - (w / fraccionMovX); 
		row = 1; 
	} else if (orientacion == direccion::right) { 
		dx = w / fraccionMovX; 
		row = 2; 
	}
}

void Base::setX(int x) {
	this->x = x;
}

void Base::setY(int y) {
	this->y = y;
}

void Base::setW(int w) {
	this->w = w;
}

void Base::setH(int h) {
	this->h = h;
}

void Base::setDx(int dx) {
	this->dx = dx;
}
void Base::setDy(int dy) {
	this->dy = dy;
}

void Base::setMaxRow(int r) {
	maxRow = r;
}

void Base::setMaxCol(int c) {
	maxCol = c;
}

void Base::setRow(int r) {
	row = r;
}

void Base::setCol(int c) {
	col = c;
}

void Base::setActive(bool e) {
	active = e;
}

void Base::setFraccionMovY(int movY) {
	fraccionMovY = movY;
}

void Base::setFraccionMovX(int movX) {
	fraccionMovX = movX;
}

int Base::getX() {
	return x;
}

int Base::getY() {
	return y;
}

int Base::getW() {
	return w;
}
int Base::getH() {
	return h;
}

int Base::getDx() {
	return dx;
}

int Base::getDy() {
	return dy;
}

int Base::getMaxRow() {
	return maxRow;
}

int Base::getMaxCol() {
	return maxCol;
}

int Base::getRow() {
	return row;
}

int Base::getCol() {
	return col;
}

bool Base::getActive() {
	return active;
}

int Base::getFraccionMovY() {
	return fraccionMovX;
}

int Base::getFraccionMovX() {
	return fraccionMovX;
}

Rectangle Base::getArea() {
	return Rectangle(x, y, w, h);
}

Rectangle Base::getNextArea() {
	return Rectangle(x + dx, y + dy, w, h);
}