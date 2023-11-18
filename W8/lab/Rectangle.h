/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Student : Kiarash Kia
Student ID: 108688235
Email: kkia2@myseneca.ca
Workshop 8 - Lab - Rectangle.h
Date : 11/17/2023
 */
#ifndef SDDS_RECTANGLE_H
#define SDDS_RECTANGLE_H

#include "LblShape.h"

namespace sdds {

	class Rectangle : public LblShape {
		
		int m_width, m_height;

	public:
		Rectangle();
		Rectangle(const char* label, int width, int height);

		void getSpecs(std::istream& is) override;
		void draw(std::ostream& os) const override;



	};


}

#endif // !RECTANGLE_H
