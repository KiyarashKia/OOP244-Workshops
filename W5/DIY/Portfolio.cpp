/***********************************************************************
// OOP244 Workshop #5 DIY (part 2): tester program
//
// File  Portfolio.cpp
// Version 1.0
// Author   Asam Gulaid, revised by Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
***********************************************************************/
/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Student : Kiarash Kia
Student ID: 108688235
Email: kkia2@myseneca.ca
Workshop 5 - DIY - Portfolio.cpp
Date : 10/16/2023
 */


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Portfolio.h"
#include <cstring>

using namespace std;
namespace sdds {


    Portfolio::Portfolio() {
        emptyPortfolio();
    }

    void Portfolio::emptyPortfolio()
    {
        m_value = 0;
        m_stock[0] = 0;
        m_type = 'E';
    }
    Portfolio::Portfolio(double value, const char* stock, char type) {
        emptyPortfolio();
        if (value >= 0 && (type == 'V' || type == 'G' || type == 'I')) {
            m_value = value;
            m_type = type;
            strcpy(m_stock, stock);
        }
    }

    void Portfolio::dispPortfolio() const {
        cout << " ";
        cout.width(10);
        cout << (const char*)(*this);
        cout << " | ";
        cout << "Value: ";
        cout.width(10);
        cout << double(*this);
        cout << " | ";
        cout << " Type: ";
        cout << char(*this);
    }
    std::ostream& Portfolio::display() const {

        if (~*this) {
            cout << " Portfolio  |  Bad-NG |";
            dispPortfolio();
        }
        else if (*this) {
            cout << " Portfolio  |  Active |";
            dispPortfolio();

        }
        else {
            cout << " Portfolio  |  EMPTY  |";
            dispPortfolio();
        }
        return cout;
    }

    Portfolio::operator double() const {
        return m_value;
    }

    Portfolio::operator const char* () const {
        return m_stock;
    }

    Portfolio::operator char() const {
        return m_type;
    }

    Portfolio::operator bool() const {
        return m_type == 'G' || m_type == 'V' || m_type == 'I';
    }

    Portfolio& Portfolio::operator +=(const double value) {
        if (*this && value >= 0) {
            m_value += value;
        }
        else {
            m_value += 0;
        }
        return *this;

    }

    Portfolio& Portfolio::operator -=(const double value) {
        if (*this && value >= 0) {
            m_value -= value;
        }
        else {
            m_value -= 0;
        }
        return *this;

    }

    bool Portfolio::operator ~() const {
        return m_value < 0;
    }

    Portfolio& Portfolio::operator << (Portfolio& move) {
        if (this != &move && *this && move) { // Ensures that we are not moving to the same Portfolio
            m_value += move.m_value;
            move.emptyPortfolio(); // To clean up
        }
        return *this;
    }

    Portfolio& Portfolio::operator >> (Portfolio& move) {
        if (this != &move && *this && move) {
            move.m_value += m_value;
            emptyPortfolio();
        }
        return move;

    }

    double operator +(const Portfolio& val1, const Portfolio& val2) {
        if (val1 && val2) {
            double value = double(val1) + double(val2);
            return value;
        }
        else {
            return 0.0;
        }
    }

    double& operator +=(double& value, Portfolio& portfolio) {
        value += double(portfolio);
        return value;
    }


}