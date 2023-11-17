#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Shape.h"

using namespace std;
namespace sdds {

	ostream& operator<<(ostream& os, const Shape& shape) {
		shape.draw(os);
		return os;
	}


	istream& operator>>(istream& is, Shape& shape) {
		shape.getSpecs(is);
		return is;
	}


}