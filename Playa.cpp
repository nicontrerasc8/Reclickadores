#include "Playa.h"

Playa::Playa() { };

Playa::Playa(int x, int y, int w, int h) : Base(x, y, w, h, 4, 10, 1, 0) { 
	dy = (gcnew System::Random())->Next(3, 7);
}

Playa::~Playa() { }