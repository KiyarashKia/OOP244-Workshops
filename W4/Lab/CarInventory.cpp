/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Student : Kiarash Kia
Student ID: 108688235
Email: kkia2@myseneca.ca
Workshop 4 - Lab - Implementation File
Date : 10/07/2023
 */

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <cstring>
#include "CarInventory.h"

using namespace std;

namespace sdds {

	void CarInventory::resetInfo() {
		m_type = nullptr; 
		m_brand = nullptr;
		m_model = nullptr;
		m_year = 0;
		m_code = 0;
		m_price = 0;
}

	CarInventory::CarInventory() {
		resetInfo();
	}

	CarInventory::~CarInventory() {
		delete[] m_type;
		delete[] m_brand;
		delete[] m_model;
	}

	CarInventory::CarInventory(const char* type, const char* brand, const char* model, int year , int code, double price) {
		resetInfo();
		m_type = new char[strlen(type) + 1];
		strcpy(m_type, type);
		m_brand = new char[strlen(brand) + 1];
		strcpy(m_brand, brand);
		m_model = new char[strlen(model) + 1];
		strcpy(m_model, model);
		m_year = year;
		m_code = code;
		m_price = price;
	}

	CarInventory& CarInventory::setInfo(const char* type, const char* brand, const char* model, int year, int code, double price) {
		if (this->m_type)
		{
			delete[] this->m_type;
			this->m_type = nullptr;
		}
		if (this->m_brand)
		{
			delete[] this->m_brand;
			this->m_brand = nullptr;
		}
		if (this->m_model)
		{
			delete[] this->m_model;
			this->m_model = nullptr;
		}
		m_type = new char[strlen(type) + 1];
		strcpy(m_type, type);
		m_brand = new char[strlen(brand) + 1];
		strcpy(m_brand, brand);
		m_model = new char[strlen(model) + 1];
		strcpy(m_model, model);
		m_year = year;
		m_code = code;
		m_price = price;
		return *this;

	}

	void CarInventory::printInfo() const {
		cout << "| " << left << setw(10) << m_type << " ";
		cout << "| " << left << setw(16) << m_brand << " ";
		cout << "| " << left << setw(16) << m_model << " ";
		cout << "| " << setw(4) << m_year << " ";
		cout << "| " << right << setw(4) << m_code << " ";
		cout << "| " << right << setw(9) << fixed << setprecision(2) << m_price << " |" << endl;

	}

	bool CarInventory::isValid() const {

		if (m_type && m_brand && m_model && m_year >= 1900 && m_price > 0 && (m_code >= 100 && m_code <= 999))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool CarInventory::isSimilarTo(const CarInventory& car) const {
		if (m_type && car.m_type && m_brand && car.m_brand && m_model && car.m_model &&
			!strcmp(m_type, car.m_type) && !strcmp(m_brand, car.m_brand) && !strcmp(m_model, car.m_model) &&
			
			m_year == car.m_year) {
			
			return true;
		}
		return false;
	}


		int find_similar(CarInventory car[], const int num_cars) {
			
			for (int i = 0; i < num_cars; i++) {
				for (int j = i + 1; j < num_cars; j++) {
					if (car[i].isSimilarTo(car[j])) {
						return i;
					}
				}
			}
			return -1; // Return -1 as not found
		}


 }