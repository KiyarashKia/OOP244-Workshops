/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Student : Kiarash Kia
Student ID: 108688235
Email: kkia2@myseneca.ca
Workshop 7 - Lab - Header File Container.h
Date : 11/13/2023
 */

#ifndef SDDS_CONTAINER_H
#define SDDS_CONTAINER_H

#include <iostream>


namespace sdds {
	// Declarations based on instructions
	class Container {
		char m_content[51];
		int m_capacity{};
		int m_contentVol{};

	protected:
		void setEmpty();
		int Capacity() const;
		int Volume() const;

	public:
		Container();
		Container(const char* content, int capacity, int volume = 0);

		int operator+=(int value);
		int operator-=(int value);

		operator bool() const;

		void clear(int capacity, const char* content);
		std::ostream& print(std::ostream& os) const;
		std::istream& read(std::istream& is);
	};

	std::ostream& operator<<(std::ostream& os, const Container& C);
	std::istream& operator>>(std::istream& is, Container& C);

}
#endif // !SDDS_CONTAINER_H

