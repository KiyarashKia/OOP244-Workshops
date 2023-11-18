/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Student : Kiarash Kia
Student ID: 108688235
Email: kkia2@myseneca.ca
Workshop 8 - Lab - Line.h
Date : 11/17/2023
 */
#ifndef SDDS_LINE_H
#define SDDS_LINE_H

#include "LblShape.h"

namespace sdds {

	class Line : public LblShape {
		
		int m_length;
		
	public:
		Line();
		Line(const char* string, int length);

		void getSpecs(std::istream& is) override;
		void draw(std::ostream& os) const override;

	};


}

#endif // LINE_H
