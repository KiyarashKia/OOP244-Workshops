/***********************************************************************
// OOP244 Workshop #6 lab : tester program
//
// File  HealthCard.cpp
// Version 1.0
// Author
// Description
//			Name      : Kiarash Kia
//			Student ID: 108688235
//			Email     : kkia2@myseneca.ca
/			Date      : 05/11/2023
//
//			I have done all the coding by myself and only copied the code
//			 that my professor provided to complete my workshops and
//			 assignments.
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
***********************************************************************/


#define  _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "HealthCard.h"
#include <iomanip>
#include <cstring>


using namespace std;
namespace sdds {


	bool HealthCard::validID(const char* name, long long number, const char vCode[], const char sNumber[]) const {

		if (name == nullptr || strlen(name) == 0)
		{
			return false;
		}

		if (number < 1000000000 || number > 9999999999)
		{
			return false;
		}

		if (strlen(vCode) != 2)
		{
			return false;
		}

		if (strlen(sNumber) != 9)
		{
			return false;
		}

		return true;
	}

	void HealthCard::setEmpty() {

		if (m_name != nullptr)
		{
			delete[] m_name;
			m_name = nullptr;
		}

		// To ensure all the object is on empty form

		m_number = 0;
		m_vCode[0] = '\0';
		m_sNumber[0] = '\0';
	}


	void HealthCard::allocateAndCopy(const char* name) {

		if (m_name != nullptr)
		{
			delete[] m_name;
			m_name = nullptr;
		}

		m_name = new char[strlen(name) + 1];

		strcpy(m_name, name);
	}

	void HealthCard::extractChar(istream& istr, char ch) const {

		char next = istr.peek();

		if (next == ch)
		{
			istr.ignore();
		}
		else
		{
			istr.ignore(1000, ch);
			istr.setstate(ios::failbit);
		}
	}

	ostream& HealthCard::printIDInfo(std::ostream& ostr) const {

		ostr << m_number << "-" << m_vCode << ", " << m_sNumber;
		return ostr;
	}

	void HealthCard::set(const char* name, long long number, const char vCode[], const char sNumber[]) {
		if (validID(name, number, vCode, sNumber))
		{
			allocateAndCopy(name);
			m_number = number;
			strcpy(m_vCode, vCode);
			strcpy(m_sNumber, sNumber);
		}
		else
		{
			setEmpty();
		}

	}


	// rule of three part

	HealthCard::HealthCard() {

		setEmpty();

	}

	HealthCard::HealthCard(const char* name, long long number, const char vCode[], const char sNumber[]) {

		set(name, number, vCode, sNumber);

	}

	HealthCard::HealthCard(const HealthCard& hc) {

		m_name = nullptr;

		set(hc.m_name, hc.m_number, hc.m_vCode, hc.m_sNumber);

	}

	HealthCard& HealthCard::operator=(const HealthCard& hc) {

		if (this != &hc)
		{
			set(hc.m_name, hc.m_number, hc.m_vCode, hc.m_sNumber);
		}
		return *this;
	}


	HealthCard::~HealthCard() {

		delete[] m_name;

	}

	HealthCard::operator bool() const {

		return m_name != nullptr;
	}

	ostream& HealthCard::print(ostream& ostr, bool toFile) const {

		if (validID(m_name, m_number, m_vCode, m_sNumber))
		{
			if (toFile)
			{
				ostr << m_name << ",";
				printIDInfo(ostr) << endl;
			}
			else {

				ostr << left << setw(50) << setfill('.') << m_name << right;
				printIDInfo(ostr);
			}
		}
		return ostr;
	}

	istream& HealthCard::read(istream& istr) {

		char tempName[MaxNameLength + 1];
		long long tempNumber;
		char tempVCode[3];
		char tempSNumber[10];

		istr.clear();

		istr.get(tempName, MaxNameLength, ',');
		extractChar(istr, ',');
		istr >> tempNumber;
		extractChar(istr, '-');
		istr.get(tempVCode, 3, ',');
		extractChar(istr, ',');
		istr.get(tempSNumber, 10, '\n');
		extractChar(istr, '\n');

		if (istr) {
			set(tempName, tempNumber, tempVCode, tempSNumber);
		}
		else {
			istr.clear();
			istr.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		return istr;

	}

	ostream& operator<<(std::ostream& ostr, const HealthCard& hc) {
		if (hc) {
			hc.print(ostr, false);
		}
		else {
			ostr << "Invalid Health Card Record";
		}
		return ostr;
	}

	std::istream& operator>>(std::istream& istr, HealthCard& hc) {

		return hc.read(istr);
	}
}
