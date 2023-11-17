#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include "LblShape.h"

using namespace std;
namespace sdds {

	const char* LblShape::label() const {
		return m_label;
	}

	LblShape::LblShape() {
		m_label = nullptr;
	}

	LblShape::LblShape(const char* label) {
		m_label = nullptr;
		m_label = new char[strlen(label) + 1];
		strcpy(m_label, label);
	}

	LblShape::~LblShape() {
		delete[] m_label;
	}


	void LblShape::getSpecs(istream& is) {
		char buffer[1000];
		is.getline(buffer, 1000, ',');
		delete[] m_label;
		m_label = new char[strlen(buffer) + 1];
		strcpy(m_label, buffer);
	}

}

