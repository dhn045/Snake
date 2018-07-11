#include <cstdlib>

#include "sl.h"
#include "snake_h.h"

using namespace std;

Goal::Goal(int s) {
	size = s;
	newLocation();
}

void Goal::newLocation() {
	x = rand() % WIDTH;
	y = rand() % HEIGHT;
}

double Goal::getX() {
	return x;
}

double Goal::getY() {
	return y;
}

int Goal::getSize() {
	return size;
}