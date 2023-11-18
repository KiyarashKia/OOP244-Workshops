/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Student : Kiarash Kia
Student ID: 108688235
Email: kkia2@myseneca.ca
Workshop 8 - Lab - LblShape.h
Date : 11/17/2023
 */
#ifndef SDDS_LBLSHAPE_H
#define SDDS_LBLSHAPE_H

#include <iostream>
#include "Shape.h"

namespace sdds {

	class LblShape : public Shape {
	private:

		char* m_label;

	protected:

		const char* label() const;

	public:

		LblShape();
		LblShape(const char* label);
		~LblShape();

		LblShape(const LblShape& src) = delete;
		LblShape& operator=(const LblShape& src) = delete;

		void getSpecs(std::istream& is) override;


	};

}

#endif // SDDS_LBLSHAPE_H
