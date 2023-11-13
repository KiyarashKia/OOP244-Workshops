/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Student : Kiarash Kia
Student ID: 108688235
Email: kkia2@myseneca.ca
Workshop 4 - DIY - HeaderFile LabelMaker
Date : 10/09/2023
 */

#ifndef LabelMaker_H
#define LabelMaker_H
#include "Label.h"


namespace sdds {

	class LabelMaker {
		int noOfLabels;
		Label* Labels;

	public:

		~LabelMaker();

		LabelMaker(int noOfLabels);
		void readLabels();
		void printLabels();
	};

}

#endif // !LabelMaker_H