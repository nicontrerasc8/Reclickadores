#pragma once
using namespace System::Drawing;
public enum direccion { up, down, left, right, none };

class Base {
protected:
	int x, y, w, h, dx, dy;
	int maxRow, maxCol, col, row;
	int fraccionMovY, fraccionMovX;
	direccion orientacion;
	bool active;
public:
	Base();
	Base(int x, int y, int w, int h);
	Base(int x, int y, int w, int h, int maxRow, int maxCol, int row, int col);
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
	void setMaxRow(int r);
	void setMaxCol(int c);
	void setRow(int r);
	void setCol(int c);
	void setActive(bool e);
	void setFraccionMovY(int movY);
	void setFraccionMovX(int movX);

	int getX();
	int getY();
	int getW();
	int getH();
	int getDx();
	int getDy();
	int getMaxRow();
	int getMaxCol();
	int getRow();
	int getCol();
	bool getActive();
	int getFraccionMovY();
	int getFraccionMovX();
	Rectangle getArea();
	Rectangle getNextArea();
};