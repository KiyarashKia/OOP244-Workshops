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
