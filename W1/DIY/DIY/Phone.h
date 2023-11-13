/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Student : Kiarash Kia
Student ID: 108688235
Email: kkia2@myseneca.ca
Workshop 1 - DIY
Date : 9/18/2023
 */


#define _CRT_SECURE_NO_WARNINGS	

 // Compilation Safeguards
#ifndef SDDS_Phone_H 
#define SDDS_Phone_H


namespace sdds {

	struct phoneRecord {

		char name[50];
		char areaCode[4];
		char prefix[4];
		char number[5];
	};


	// Shows the program title
	void programTitle(const char* programtitle);

		
	// runs the phone directory application
	void phoneDir(const char* programtitle, const char* filename);

}
#endif