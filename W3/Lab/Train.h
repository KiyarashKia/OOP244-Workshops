/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Student : Kiarash Kia
Student ID: 108688235
Email: kkia2@myseneca.ca
Workshop 3 - Lab
Date : 9/30/2023
 */


#ifndef _TRAIN_H
#define _TRAIN_H
#include <iostream>
#include <string>

#define MIN_TIME 700
#define MAX_TIME 2300
#define MAX_NO_OF_PASSENGERS 1000

namespace sdds {
	
	// Class of Train
	class Train {
		char* trainName;
		int numPassengers;
		int depTime;

	public:
		void initialize();

		bool validTime(int value) const;

		bool validNoOfPassengers(int value) const;

		void set(const char* name);

		void set(int noOfPassengers, int departure);

		void set(const char* name, int noOfPassengers, int departure);

		void finalize();

		bool isInvalid() const;

		int noOfPassengers() const;

		const char* getName() const;

		int getDepartureTime() const;

		void display() const;

	};

}

#endif // !_TRAIN_H

