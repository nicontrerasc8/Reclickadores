#pragma once
using namespace System::Drawing;
public enum direccion { up, down, left, right, none };

class Base {
protected:
	int x, y, w, h, dx, dy;
	int maxFil, maxCol, col, fil;
	int fraccionMovY, fraccionMovX;
	direccion orientacion;
	bool eliminar;
public:
	Base();
	Base(int x, int y, int w, int h);
	Base(int x, int y, int w, int h, int maxFil, int maxCol, int fil, int col);
	~Base();

	virtual void mover(Graphics^ g);
	void dibujar(Graphics^ g);
	void dibujarDesdeImg(Graphics^ g, Bitmap^ bmp);
	void borrar(Graphics^ g);
	void desplazamiento(direccion d);

	void setX(int x);
	void setY(int y);
	void setW(int w);
	void setH(int h);
	void setDx(int dx);
	void setDy(int dy);
	void setMaxFil(int f);
	void setMaxCol(int c);
	void setFil(int f);
	void setCol(int c);
	void setEliminar(bool e);
	void setFraccionMovY(int movY);
	void setFraccionMovX(int movX);

	int getX();
	int getY();
	int getW();
	int getH();
	int getDx();
	int getDy();
	int getMaxFil();
	int getMaxCol();
	int getFil();
	int getCol();
	bool getEliminar();
	int getFraccionMovY();
	int getFraccionMovX();
	Rectangle getRectangle();
};