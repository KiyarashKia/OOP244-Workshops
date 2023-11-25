/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Student : Kiarash Kia
Student ID: 108688235
Email: kkia2@myseneca.ca
Workshop 9 - Lab - Student.cpp
Date : 11/25/2023
 */

#define _CRT_SECURE_NO_WARNINGS
#include "Student.h"
#include <cstring>
#include <iostream>

namespace sdds {

	Student::Student() {
		stName = nullptr;
		stAge = 0;
	}

	Student::Student(const char* name, int age) : stAge(age) {
		if (name)
		{
			stName = new char[strlen(name) + 1];
			strcpy(stName, name);
		}
		else
		{
			stName = nullptr;
		}

	}

	Student::Student(const Student& other) : stAge(other.stAge) {
		if (other.stName)
		{
			stName = new char[strlen(other.stName) + 1];
			strcpy(stName, other.stName);
		}
		else
		{
			stName = nullptr;
		}
	}

	Student& Student::operator=(const Student& other) {
		if (this != &other) {
			delete[] stName;
			stAge = other.stAge;
			if (other.stName) {
				stName = new char[strlen(other.stName) + 1];
				strcpy(stName, other.stName);
			}
			else {
				stName = nullptr;
			}
		}
		return *this;
	}


	Student::~Student() {
		delete[] stName;
	}

	void Student::display() const {
		std::cout << "Name: " << stName << std::endl;
		std::cout << "Age: " << stAge << std::endl;
	}
}

