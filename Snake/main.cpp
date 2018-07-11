#include <stdio.h>
#include <stdlib.h>

#include "sl.h"
#include "snake_h.h"

using namespace std;

int main(void) {
	int key;
	bool active;
	int speed = 10;
	Snake * head = new Snake(START_X + SIZE / HALF, START_Y + SIZE / HALF, SIZE);
	Snake * tail = head;
	Snake * tmp;
	Goal * goal = new Goal(RADIUS);
	slWindow(WIDTH, HEIGHT, "Snake", false);
	slRectangleFill(head->getX(), head->getY(), head->getSize(), head->getSize());
	slRender();


	while ( !slShouldClose() ) {
		
		/* react to keypress, otherwise continue direction */
		if (slGetKey(SL_KEY_UP)) {
			head->move(SL_KEY_UP, slGetDeltaTime() * speed);
		} else if (slGetKey(SL_KEY_DOWN)) {
			head->move(SL_KEY_DOWN, slGetDeltaTime() * speed);
		} else if (slGetKey(SL_KEY_LEFT)) {
			head->move(SL_KEY_LEFT, slGetDeltaTime() * speed);
		} else if (slGetKey(SL_KEY_RIGHT)) {
			head->move(SL_KEY_RIGHT, slGetDeltaTime() * speed);
		} else {
			head->move( head->getDirection(), slGetDeltaTime() * speed);
		}

		/* check for goal overlap */
		if (head->overlap(goal)) {
			tail = tail->pushToSnake();
			goal->newLocation();
			//speed++;
		}

		/* check for self overlap */
		if (head->collision()) {
			printf("Collision\n");
		}

		/* check for out-of-bounds */
		if (head->getX() + head->getSize() / HALF > WIDTH ||
			head->getX() - head->getSize() / HALF < 0 ||
			head->getY() + head->getSize() / HALF > HEIGHT ||
			head->getY() - head->getSize() / HALF < 0) {
			printf("Out of Bounds");
		}

		slCircleFill(goal->getX(), goal->getY(), goal->getSize(), GOAL_RES);
	
		tmp = head;
		while (tmp) {
			slRectangleFill(tmp->getX(), tmp->getY(), tmp->getSize(), tmp->getSize());
			tmp = tmp->next;
		}


		slRender();
		
	}

	slClose();
	return 0;
} 