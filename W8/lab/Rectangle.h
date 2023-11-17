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
