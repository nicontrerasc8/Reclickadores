#include "Base.h"

Base::Base() { 
	dx = 0;
	dy = 0;
	eliminar = false;
	orientacion = direccion::none;
}

Base::Base(int x, int y, int w, int h) {
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
	dx = 0;
	dy = 0;
	eliminar = false;
	orientacion = direccion::none;
}

Base::Base(int x, int y, int w, int h, int maxFil, int maxCol, int fil, int col) {
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
	dx = 0;
	dy = 0;
	eliminar = false;
	orientacion = direccion::none;
	this->maxFil = maxFil;
	this->maxCol = maxCol;
	this->fil = fil;
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
	h = bmp->Height / maxFil;
	Rectangle porcion = Rectangle(col * w, fil * w, w, h);
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

	if (orientacion == direccion::up) { dy = - (h / fraccionMovY); fil = 2; }
	else if (orientacion == direccion::down) { dy = h / fraccionMovY; fil = 3; }
	else if (orientacion == direccion::left) { dx = - (w / fraccionMovX); fil = 0; }
	else if (orientacion == direccion::right) { dx = w / fraccionMovX; fil = 1; }
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

void Base::setMaxFil(int f) {
	maxFil = f;
}

void Base::setMaxCol(int c) {
	maxCol = c;
}

void Base::setFil(int f) {
	fil = f;
}

void Base::setCol(int c) {
	col = c;
}

void Base::setEliminar(bool e) {
	this->eliminar = e;
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

int Base::getMaxFil() {
	return maxFil;
}

int Base::getMaxCol() {
	return maxCol;
}

int Base::getFil() {
	return fil;
}

int Base::getCol() {
	return col;
}

bool Base::getEliminar() {
	return eliminar;
}

int Base::getFraccionMovY() {
	return fraccionMovX;
}

int Base::getFraccionMovX() {
	return fraccionMovX;
}

Rectangle Base::getRectangle() {
	return Rectangle(x, y, w, h);
}