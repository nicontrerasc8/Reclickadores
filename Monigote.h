#pragma once
#include "Base.h"
class Monigote : public Base {
public:
	Monigote();
	Monigote(int x, int y, int w, int h);
	~Monigote();

	void mover(Graphics^ g);
};