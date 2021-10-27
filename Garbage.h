#pragma once
#include "Base.h"

class Garbage : public Base {
public:
	Garbage() { }
	Garbage(int x, int y, int w, int h) : Base(x, y, w, h, 1, 1, 0, 0) { }
	~Garbage() { }
};