#include "Futbol.h"

Futbol::Futbol() { }

Futbol::Futbol(int x, int y, int w, int h) : Base(x, y, w, h, 4, 10, 2, 0) { 
	dx = (gcnew System::Random())->Next(5, 10);
	dy = (gcnew System::Random())->Next(5, 10);
}

Futbol::~Futbol() { }