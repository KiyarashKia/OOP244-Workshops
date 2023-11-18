/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Student : Kiarash Kia
Student ID: 108688235
Email: kkia2@myseneca.ca
Workshop 8 - Lab - Line.cpp
Date : 11/17/2023
 */
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "Line.h"

using namespace std;
namespace sdds {


	Line::Line() {
		m_length = 0;
	}

	Line::Line(const char* string, int length) 
		: LblShape(string), m_length(length) {}

	void Line::getSpecs(istream& is) {
		LblShape::getSpecs(is);
		is >> m_length;
		is.ignore(1000, '\n');

	}

	void Line::draw(ostream& os) const {
		if (m_length > 0 && label() != NULL)
		{
			os << label() << endl;
			for (int i = 0; i < m_length; i++)
			{
				os << "=";
			}
		}
	}



}