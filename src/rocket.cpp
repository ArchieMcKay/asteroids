#include "rocket.h"

Rocket::Rocket() {
	this->position = Vector();
	this->velocity = Vector();
	this->velocity = Vector();
	this->rotation = 0;
};

Vector Rocket::getDirection() {
	return Vector(cos(this->rotation), sin(this->rotation));
}


