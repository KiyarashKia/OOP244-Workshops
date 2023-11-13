/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Student : Kiarash Kia
Student ID: 108688235
Email: kkia2@myseneca.ca
Workshop 4 - Lab - Header File
Date : 10/07/2023
 */

#ifndef CarInventory_h
#define CarInventory_h

namespace sdds {

	class CarInventory {

		char* m_type;
		char* m_brand;
		char* m_model;
		int m_year;
		int m_code;
		double m_price;

		void resetInfo();

	public:

		CarInventory(); // Constructor
		~CarInventory(); // Destructor

		CarInventory(const char* type, const char* brand, const char* model, int year = 2022, int code = 100, double price = 1.0);

		CarInventory& setInfo(const char* type, const char* brand, const char* model, int year, int code, double price);

		void printInfo() const;

		bool isValid() const;

		bool isSimilarTo(const CarInventory& car) const;

		


	};
	// Global scope function
	int find_similar(CarInventory car[], const int num_cars);


}


#endif // !CarInventory.h
