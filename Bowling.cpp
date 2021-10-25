#include "Bowling.h"

Bowling::Bowling() { }

Bowling::Bowling(int x, int y, int w, int h) : Base(x, y, w, h, 4, 10, 0, 0) {
	dx = (gcnew System::Random())->Next(3, 7);
}

Bowling::~Bowling() { }