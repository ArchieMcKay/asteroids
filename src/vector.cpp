#include "vector.h"

Vector::Vector() {
	this->x = 0;
	this->y = 0;
}

Vector::Vector(double x, double y) {
	this->x = x;
	this->y = y;
};

void Vector::operator=(Vector coord) {
	this->x = coord.x;
	this->y = coord.y;
}

Vector Vector::operator+(Vector coord) {
	return Vector(this->x + coord.getX(), this->y + coord.getY());
}

Vector Vector::operator-(Vector coord) {
	return Vector(this->x - coord.getX(), this->y - coord.getY());
}

Vector Vector::operator*(double c) {
	return Vector(this->x * c, this->y * c);
}
	
Vector Vector::operator/(double c) {
	return Vector(this->x / c, this->y / c);
}

double Vector::getX() {
	return this->x;
}

double Vector::getY() {
	return this->y;
}

Vector Vector::normalize() {
	double scale = sqrt(this->x * this->x + this->y * this->y);
	return Vector(this->x / scale, this->y / scale);
}
