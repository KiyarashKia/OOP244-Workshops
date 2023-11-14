/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Student : Kiarash Kia
Student ID: 108688235
Email: kkia2@myseneca.ca
Workshop 7 - Lab - Pack.cpp
Date : 11/13/2023

For some debugging and a bit of read method, I searched over web and tried to make solution by that
 */

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Pack.h"


using namespace std;
namespace sdds {
	
	Pack::Pack(const char* contentDesc, int size, int UnitSize, int noOfUnits) {

		// constructr / Container
		Container();

		if (UnitSize > 0 && contentDesc != nullptr && noOfUnits * UnitSize <= size * UnitSize) {
			m_unitSize = UnitSize;
			Container::clear(size * UnitSize, contentDesc);
			*this += noOfUnits;
		}
		else {
			setEmpty();
		}
	}


	int Pack::operator+=(int noOfUnits) {
		int addedUnits = Container::operator+=(noOfUnits * m_unitSize) / m_unitSize;
		return addedUnits;
	}

	int Pack::operator-=(int noOfUnits) {
		int removedUnits = Container::operator-=(noOfUnits * m_unitSize) / m_unitSize;
		return removedUnits;
	}

	int Pack::unit() const {
		return m_unitSize;
	}

	int Pack::noOfUnits() const {
		return Container::Volume() / m_unitSize;
	}

	int Pack::size() const {
		return Container::Capacity() / m_unitSize;
	}

	void Pack::clear(int size, int unitSize, const char* content) {
		if (unitSize > 0) 
		{
			Container::clear(size * unitSize, content);
			m_unitSize = unitSize;
		}
		else
		{
			Container::setEmpty();
		}
	}


	std::ostream& Pack::print(std::ostream& os) const {
		Container::print(os);

		if (!Container::operator bool())
		{
			os << ", " << noOfUnits() << " in a pack of " << size();
		}
		return os;
	}

	std::istream& Pack::read(std::istream& is) {
		if (Container::operator bool()) 
		{
			cout << "Broken Container, adding aborted! Press <ENTER> to continue....";
			is.clear();
			is.get();
		}
		else {
			int spaceAvailable = size() - noOfUnits();
			if (spaceAvailable > 0) 
			{
				cout << "Add to ";
				print(cout) << endl << "> ";
				int add{};
				do {
					is >> add;
					if (is.fail()) {
						is.clear();
						is.ignore();
						cout << "Invalid Integer, retry: ";
					}
					else if (add < 1 || add > spaceAvailable) 
					{
						cout << "Value out of range [1<=val<=" << spaceAvailable << "]: ";
						is.clear();
						is.ignore();
					}
				} while (is.fail() || add < 1 || add > spaceAvailable);

				cout << "Added " << (*this += add) << endl;
			}

			else {
				cout << "Pack is full!, press <ENTER> to continue...";
				is.clear();
				is.ignore();
				is.get();
			}
		}
		return is;
	}

	std::ostream& operator<<(std::ostream& os, const Pack& P) {
		return P.print(os);
	}
	std::istream& operator>>(std::istream& is, Pack& P) {
		return P.read(is);
	}

	}





