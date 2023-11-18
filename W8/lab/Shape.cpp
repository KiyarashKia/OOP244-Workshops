/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Student : Kiarash Kia
Student ID: 108688235
Email: kkia2@myseneca.ca
Workshop 8 - Lab - Shape.cpp
Date : 11/17/2023
 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Shape.h"

using namespace std;
namespace sdds {

	Shape::~Shape() {}

	ostream& operator<<(ostream& os, const Shape& shape) {
		shape.draw(os);
		return os;
	}


	istream& operator>>(istream& is, Shape& shape) {
		shape.getSpecs(is);
		return is;
	}


}