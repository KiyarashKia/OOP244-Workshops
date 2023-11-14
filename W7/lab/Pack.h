/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Student : Kiarash Kia
Student ID: 108688235
Email: kkia2@myseneca.ca
Workshop 7 - Lab - Header File Pack.h
Date : 11/13/2023
 */

#ifndef SDDS_PACK_H
#define SDDS_PACK_H
#include <iostream>
#include "Container.h"

namespace sdds {
	// Declarations based on the workshop instructions - Derived class

	class Pack : public Container {
		int m_unitSize{ 330 };

	public:
		Pack(const char* content, int size, int unitSize = 330, int noOfUnits = 0);

		int operator+=(int noOfUnits);
		int operator-=(int noOfUnits);

		int unit() const;
		int noOfUnits() const;
		int size() const;

		void clear(int size, int unitSize, const char* content);
		std::ostream& print(std::ostream& os) const;
		std::istream& read(std::istream& is);

	};

	std::ostream& operator<<(std::ostream& os, const Pack& P );
	std::istream& operator>>(std::istream& is, Pack& P);

}
#endif // !SDDS_PACK_H

