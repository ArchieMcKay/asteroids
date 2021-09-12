#ifndef ROCKET_H
#define ROCKET_H

#include "main.h"
#include "vector.h"

#define MAX_VELOCITY

class Rocket {
public:
	Rocket();
	Vector position;
	Vector velocity;
	Vector acceleration;
	double rotation;

public:
	Vector getDirection();

private:
};

#endif
