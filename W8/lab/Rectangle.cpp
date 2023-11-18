#define _CRT_SECURE_NO_WARNINGS

#include "Rectangle.h"
#include <iomanip>
#include <iostream>
#include <cstring> 

using namespace std;
namespace sdds {

	Rectangle::Rectangle() {
		m_width = 0;
		m_height = 0;
	}

	Rectangle::Rectangle(const char* label, int width, int height) 
		: LblShape(label), m_width(width), m_height(height)  {
		if (m_height < 3 || m_width < (int)strlen(label) + 2)
		{
			m_width = 0;
			m_height = 0;
		}
	}

	void Rectangle::getSpecs(istream& is) {
		LblShape::getSpecs(is);
		is >> m_width;
		is.ignore();
		is >> m_height;
		is.ignore(1000, '\n');
	}

	void Rectangle::draw(ostream& os) const {
		if (m_height >= 3 && m_width >= (int)(strlen(label())) + 2)
		{
			os << '+' << std::string(m_width - 2, '-') << '+' << std::endl;

			os << '|' << std::left << setw(m_width - 2) << label() << '|' << std::endl;

			for (int i = 0; i < m_height - 3; ++i) {
				os << '|' << std::string(m_width - 2, ' ') << '|' << std::endl;
			}

			os << '+' << std::string(m_width - 2, '-') << '+';
		}
	}


}