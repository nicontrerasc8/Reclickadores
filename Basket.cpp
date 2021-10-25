#include "Basket.h"

Basket::Basket() { }

Basket::Basket(int x, int y, int w, int h) : Base(x, y, w, h, 4, 10, 3, 0) {
	dy = (gcnew System::Random())->Next(5, 10);
	dx = (gcnew System::Random())->Next(5, 10);
}

Basket::~Basket() { }