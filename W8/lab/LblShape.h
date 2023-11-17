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
