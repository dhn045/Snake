#pragma once
#ifndef snake_h
#define snake_h

/* window size */
#define WIDTH	600
#define HEIGHT	600

/* starting location */
#define START_X	WIDTH/2
#define START_Y HEIGHT/2
#define SIZE	10
#define RADIUS	5
#define GOAL_RES	10

/* general constants */
#define HALF	2

class Goal {
public:
	Goal(int s);
	double getX();
	double getY();
	int getSize();
	void newLocation();
private:
	double x;
	double y;
	int size;

};

class Snake {
public:
	Snake(int xLoc, int yLoc, int s);
	void move(int key, double delta);
	Snake * pushToSnake();
	double getX();
	double getY();
	int getDirection();
	int getSize();
	int overlap(Goal * g);
	int collision();
	Snake * pre;
	Snake * next;

private:

	double x;
	double y;
	double size;
	int direction;
};

class Network {
public:
	Network(int * s);
	void gradientDescent();

	double sigmoid(double x);
	double sigmoid_prime(double x);

private:
	int numLayers;
	int * sizes;
	double ** bias;
	double ** weights;

};

#endif