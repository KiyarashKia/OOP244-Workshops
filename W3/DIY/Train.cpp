/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Student : Kiarash Kia
Student ID: 108688235
Email: kkia2@myseneca.ca
Workshop 3 - DIY
Date : 10/03/2023
 */


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cstdio>
#include "Train.h"

using namespace std;

namespace sdds {

	void Train::initialize() {
		trainName = nullptr;
		numPassengers = -1;
		depTime = -1;

	}

	// Got help from Alejando Silva Juarez 
	bool Train::validTime(int value) const {


		return value >= MIN_TIME && value <= MAX_TIME && (value % 100) <= 59;

	}

	bool Train::validNoOfPassengers(int value) const {

		if (value > 0 && value <= MAX_NO_OF_PASSENGERS)
		{
			return true;
		}
		else
		{
			return false;
		}

	}

	void Train::set(const char* name) {
		delete[] trainName;
		trainName = nullptr;


		if (name && name[0] != '\0') {

			trainName = new char[strlen(name) + 1];
			strcpy(trainName, name);
		}
	}

	void Train::set(int noOfPassengers, int departure) {

		numPassengers = validNoOfPassengers(noOfPassengers) ? noOfPassengers : -1;

		depTime = validTime(departure) ? departure : -1;


	}


	void Train::set(const char* name, int noOfPassengers, int departure) {

		set(name);
		set(noOfPassengers, departure);

	}

	void Train::finalize() {

		delete[] trainName;

	}

	bool Train::isInvalid() const {

		if (numPassengers < 0 || depTime < 0 || trainName == nullptr)
		{
			return true;
		}
		else
		{
			return false;
		}

	}

	int Train::noOfPassengers() const {

		return numPassengers;
	}

	const char* Train::getName() const {

		return trainName;
	}

	int Train::getDepartureTime() const {

		return depTime;
	}

	void Train::display() const {
		if (!isInvalid()) {
			cout << "NAME OF THE TRAIN:    " << trainName << endl;
			cout << "NUMBER OF PASSENGERS: " << numPassengers << endl;
			cout << "DEPARTURE TIME:       " << depTime << endl;
		}
		else {
			cout << "Train in an invalid State!" << endl;
		}
	}



	bool Train::load(int& currentPassengers) {

		int newBoarding;

		cout << "Enter number of passengers boarding:\n> ";
		cin >> newBoarding;

		if (newBoarding + numPassengers <= MAX_NO_OF_PASSENGERS)
		{
			numPassengers += newBoarding;
			return true;
		}
		else
		{
			currentPassengers = (newBoarding + numPassengers) - MAX_NO_OF_PASSENGERS;
			numPassengers = MAX_NO_OF_PASSENGERS;
			return false;
		}

	}

	bool Train::updateDepartureTime()
	{
		int newDepTime;

		cout << "Enter new departure time:\n> ";
		cin >> newDepTime;

		if (validTime(newDepTime))
		{
			depTime = newDepTime;
			return true;
		}
		else
		{
			depTime = -1;
			return false;
		}

	}

	
	bool Train::transfer(const Train& otherTr) {
		if (isInvalid() || otherTr.isInvalid()) {
			return false;
		}


		int newSize = strlen(trainName) + strlen(", ") + strlen(otherTr.trainName) + 1;


		char* combinedName = new char[newSize];


		strcpy(combinedName, trainName);
		strcat(combinedName, ", ");
		strcat(combinedName, otherTr.trainName);


		delete[] trainName;
		trainName = combinedName;

		int totalPassengers = numPassengers + otherTr.numPassengers;

		if (totalPassengers <= MAX_NO_OF_PASSENGERS) {
			numPassengers = totalPassengers;
		}
		else {
			int leftBehind = totalPassengers - MAX_NO_OF_PASSENGERS;
			numPassengers = MAX_NO_OF_PASSENGERS;
			cout << "Train is full; " << leftBehind << " passengers of " << otherTr.trainName << " could not be boarded!" << endl;
		}

		return true;
	}

}
		
	
	


