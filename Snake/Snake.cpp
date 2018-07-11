#include "sl.h"
#include "snake_h.h"

using namespace std;

Snake::Snake( int xLoc, int yLoc, int s ) {
	x = xLoc;
	y = yLoc;
	size = s;
	direction = 0;
	pre = 0;
	next = 0;
}

void Snake::move( int key, double delta) {
	Snake * tmp = this;
	int tmpXPre = tmp->x;
	int tmpYPre = tmp->y;
	int tmpDirPre = tmp->direction;

	int tmpXNext;
	int tmpYNext;
	int tmpDirNext;

	switch (key) {
	case SL_KEY_UP:
		y += size;
		direction = SL_KEY_UP;
		break;
	case SL_KEY_DOWN:
		y -= size;
		direction = SL_KEY_DOWN;
		break;
	case SL_KEY_LEFT:
		x -= size;
		direction = SL_KEY_LEFT;
		break;
	case SL_KEY_RIGHT:
		direction = SL_KEY_RIGHT;
		x += size;
		break;
	}

	while (tmp->next) {
		tmp = tmp->next;

		tmpXNext = tmp->x;
		tmpYNext = tmp->y;
		tmpDirNext = tmp->direction;

		tmp->x = tmpXPre;
		tmp->y = tmpYPre;
		tmp->direction = tmpDirPre;

		tmpXPre = tmpXNext;
		tmpYPre = tmpYNext;
		tmpDirPre = tmpDirNext;
	}
}

Snake * Snake::pushToSnake() {
	Snake * snake = 0;
	switch (direction) {
	case SL_KEY_LEFT:
		snake = new Snake(x + size, y, size);
		break;
	case SL_KEY_UP:
		snake = new Snake(x, y - size, size);
		break;
	case SL_KEY_RIGHT:
		snake = new Snake(x - size, y, size);
		break;
	case SL_KEY_DOWN:
		snake = new Snake(x, y + size, size);
		break;
	}
	
	/* won't be called unless one of the four cases, but throws
	   warning if not there */
	if (!snake) {
		return 0;
	}

	next = snake;
	next -> pre = this;

	return snake;
}

double Snake::getX() {
	return x;
}

double Snake::getY() {
	return y;
}

int Snake::getDirection() {
	return direction;
}

int Snake::getSize() {
	return size;
}



/* return 0 for no overlap, 1 for overlap */
int Snake::overlap(Goal * g) {
	/* if they are in the same vertical plane*/
	if (x - size / HALF > g->getX() + g->getSize() ||
		x + size / HALF < g->getX() - g->getSize()) {
		return 0;
	}
	/* if they are in the same horizontal plane*/
	else if (y + size / HALF < g->getY() - g->getSize() ||
			 y - size / HALF > g->getY() + g->getSize()) {
		return 0;
	}

	return 1;
}

/* return 0 if no collision, returns 1 if there is one*/
int Snake::collision() {
	Snake * tmp = this;
	while ( tmp->next ) {
		tmp = tmp->next; 
		/* if they are in the different vertical planes */
		if (x - size / HALF >= tmp->x + size / HALF ||
			x + size / HALF <= tmp->x - SIZE / HALF) {
			continue;
		}
		/* if they are in different horizontal planes*/
		else if (y + size / HALF <= tmp->y - size / HALF ||
			y - size / HALF >= tmp->y + size / HALF) {
			continue;
		}
		return 1;
	}
	return 0;
}
