/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Student : Kiarash Kia
Student ID: 108688235
Email: kkia2@myseneca.ca
Workshop 4 - DIY - HeaderFile Label
Date : 10/09/2023
 */

// Label.h
#include <iostream>
#ifndef Label_H
#define Label_H
#define MAX_CHAR 70
#define DEF_FRAME "+-+|+-+|"

namespace sdds {
	class Label {
		char* m_frameArg;
		char* m_content;
	public:
		Label();
		~Label();

		Label(const char* frameArg);
		Label(const char* frameArg, const char* content);
		std::istream& readLabel();
		std::ostream& printLabel() const;
		Label& text(const char* content);
		void SetFrame(const char* frameArg);
	};
}
#endif // !Label_H
