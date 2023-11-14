/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Student : Kiarash Kia
Student ID: 108688235
Email: kkia2@myseneca.ca
Workshop 7 - Lab - Container.cpp
Date : 11/13/2023

For some debugging and a bit of read method, I searched over web and tried to make solution by that
 */

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Container.h"

using namespace std;
namespace sdds {
	
	Container::Container() {
		setEmpty();
	}
	
	void Container::setEmpty() {
		m_content[0] = '\0';
		m_capacity = -1;
		m_contentVol = 0;

	}

	int Container::Capacity() const {
		return m_capacity;
	}

	int Container::Volume() const {
		return m_contentVol;
	}


	Container::Container(const char* content, int capacity, int volume) {
		if (content == nullptr || volume > capacity) {
			setEmpty();
		}
		else {
			m_contentVol = volume;
			clear(capacity, content);
		}
	}


	int Container::operator+=(int value) {

		int spaceLeft = Capacity() - Volume();
		
		if (spaceLeft >= value) {
			m_contentVol += value;
			return value;
		}
		else {
			m_contentVol += spaceLeft;
			return spaceLeft;
		}
	}


	int Container::operator-=(int value) {

		if (Volume() >= value) {
			m_contentVol -= value;
			return value;
		}
		else {
			int actualReduced = Volume();
			m_contentVol = 0;
			return actualReduced;
		}
	}


	Container::operator bool() const {
		return (Capacity() == -1);
	}

	void Container::clear(int capacity, const char* content) {
		if (capacity > 0 && content != nullptr )
		{
			m_capacity = capacity;
			strcpy(m_content, content);
		}
		else {
			setEmpty();
		}

	}

	ostream& Container::print(ostream& os) const {
		if (*this) { 
			os << "****: (**cc/***)"; 
		}
		else {
			os << m_content << ": (" << Volume() << "cc/" << Capacity() << ")";
		}
			return os;
	}

	istream& Container::read(istream& is) {
		if (*this)
		{
			cout << "Broken Container, adding aborted! Press <ENTER> to continue....";
			is.clear();
			is.ignore();
			is.get();
		}
		else {
			cout << "Add to ";
			print(cout) << endl << "> ";
			int add{};
			do {
				is >> add;
				if (is.fail()) {
					cout << "Invalid Integer, retry: ";
				}
				else if (add < 1 || add > 999) {
					cout << "Value out of range [1<=val<=999]: ";
				}
			} while (is.fail() || add < 1 || add > 999);

			cout << "Added " << (*this += add) << " CCs" << endl;
		}
		return is;
	}

	ostream& operator<<(ostream& os, const Container& C) {
		return C.print(os);
	}

	istream& operator>>(istream& is, Container& C) {
		return C.read(is);
	}

}

