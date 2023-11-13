/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Student : Kiarash Kia
Student ID: 108688235
Email: kkia2@myseneca.ca
Workshop 4 - DIY - LabelMaker.cpp
Date : 10/09/2023
 */


#define _CRT_SECURE_NO_WARNINGS
#include "LabelMaker.h"
#include <cstring>

using namespace std;
namespace sdds {

	LabelMaker::~LabelMaker() {
		delete[] Labels;
	}

	LabelMaker::LabelMaker(int noOfLabels) {
		this->noOfLabels = noOfLabels;
		Labels = new Label[noOfLabels];
	}

	void LabelMaker::readLabels() {
		char temp[MAX_CHAR + 1];
		cout << "Enter " << noOfLabels << " labels:" << endl;
		for (int i = 0; i < noOfLabels; i++) {
			cout << "Enter label number " << i + 1 << endl << "> ";
			cin.getline(temp, MAX_CHAR + 1);

			Labels[i].text(temp);
		}
	}


	void LabelMaker::printLabels() {
		for (int i = 0; i < noOfLabels; i++) {
			Labels[i].printLabel();
			cout << endl;
		}

	}
}

