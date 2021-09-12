#ifndef VECTOR_H
#define VECTOR_H

#include "main.h"
#include <type_traits>

class Vector {
	public:
		Vector();
		Vector(double x, double y);
		void operator=(Vector coord);
		Vector operator+(Vector coord);
		Vector operator-(Vector coord);
		Vector operator*(double c);
		Vector operator/(double c);

		double getX();
		double getY();
		Vector normalize();

	private:
		double x, y;
};

#endif
