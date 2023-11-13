/***********************************************************************
// OOP244 Workshop #5 lab (part 1): tester program
//
// File  Flight.cpp
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
Workshop 5 - Lab - Flight.CPP
Date : 10/13/2023
 */

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Flight.h"

using namespace std;
namespace sdds {

    void Flight::emptyPlane() {
        m_passengers = 0;
        m_fuel = 0;
        strcpy(m_title, "EmptyPlane");
    }

    // New Flight
    Flight::Flight() {
        emptyPlane();
    }
    Flight::Flight(int passengers, double fuel, const char* title) {
        emptyPlane();
        if (passengers > 0 && passengers <= Boen747Capacity && fuel >= 0 &&
            fuel <= FuelTankCapacity) {
            m_passengers = passengers;
            m_fuel = fuel;
            strcpy(m_title, title);
        }
    }
    std::ostream& Flight::display() const {

        if (*this) {
            cout << " Flight  |  Ready to Depart";
            cout << " ";
            cout.width(10);
            cout << std::string(*this);
            cout << " | ";
            cout << "Pass: ";
            cout.width(10);
            cout << int(*this);
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << double(*this);
            cout.unsetf(ios::right);
            cout << " Liters";
        }
        else if (~*this) {
            cout << " Flight  |  Empty Plane    ";
        }
        else {
            cout << " Flight  |  Low Fuel       ";
            cout << " ";
            cout.width(10);
            cout << (const char*)(*this);
            cout << " | ";
            cout << "Pass: ";
            cout.width(10);
            cout << int(*this);
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << double(*this);
            cout.unsetf(ios::right);
            cout << " Liters";
        }
        return cout;
    }

    Flight::operator bool() const {
        return (m_passengers > 0) && (m_fuel >= (m_passengers * 600));
    }

    Flight::operator int() const {
        return m_passengers;
    }

    Flight::operator double() const {
        return m_fuel;
    }

    Flight::operator const char* () const {
        return m_title;
    }

    bool Flight::operator~() const {
        return m_passengers == 0;
    }

    Flight& Flight::operator=(Flight& anotherFlight) {
        m_passengers = anotherFlight.m_passengers;
        m_fuel = anotherFlight.m_fuel;
        strncpy(m_title, anotherFlight.m_title, 16);
        anotherFlight.m_fuel = 0;
        anotherFlight.m_passengers = 0;
        strcpy(anotherFlight.m_title, "Empty Plane");
        return  *this;
    }

    Flight& Flight::operator=(int passengers) {
        if (passengers >= 0 && passengers <= Boen747Capacity) {
            m_passengers = passengers;
        }
        return *this;
    }

    Flight& Flight::operator=(double fuel) {
        if (fuel >= 0 && fuel <= FuelTankCapacity) {
            m_fuel = fuel;
        }
        return *this;
    }


    Flight& Flight::operator+=(double addfuel) {
        if (addfuel >= 0)
        {
            double remainingCapacity = FuelTankCapacity - m_fuel;
            m_fuel += addfuel;
        }
        else
        {
            m_fuel = FuelTankCapacity;
        }
        return *this;
    }

    Flight& Flight::operator+=(int addpassengers) {
        if (addpassengers > 0)
        {
            int remainingSeats = Boen747Capacity - m_passengers;
            if (addpassengers <= remainingSeats)
            {
                m_passengers += addpassengers;
            }
            else
            {
                m_passengers = Boen747Capacity;
            }
        }
        return *this;
    }

    Flight& Flight::operator-=(double reducefuel) {

        if (reducefuel > 0)
        {
            m_fuel -= reducefuel;
        }

        else
        {
            m_fuel = reducefuel;
        }
        return *this;
    }

    Flight& Flight::operator-=(int reducepassenger) {

        if (reducepassenger > 0)
        {
            m_passengers -= reducepassenger;
        }
        else
        {
            m_passengers = reducepassenger;
        }
        return *this;
    }

    Flight& Flight::operator<<(Flight& otherFlight) {
        int totalPassengers = m_passengers + otherFlight.m_passengers;
        if (totalPassengers <= Boen747Capacity)
        {
            m_passengers = totalPassengers;
            otherFlight.m_passengers = 0;
        }
        else
        {
            m_passengers = Boen747Capacity;
            otherFlight.m_passengers = totalPassengers - Boen747Capacity;
        }
        return *this;
    }

    Flight& Flight::operator>>(Flight& otherFlight) {
        int totalPassengers = m_passengers + otherFlight.m_passengers;
        if (totalPassengers <= Boen747Capacity)
        {
            otherFlight.m_passengers = totalPassengers;
            m_passengers = 0;
        }
        else
        {
            otherFlight.m_passengers = Boen747Capacity;
            m_passengers = totalPassengers - Boen747Capacity;
        }
        return *this;
    }

    int Flight::operator+(const Flight& flight) const {

        if (*this && flight) {
            return m_passengers + flight.m_passengers;
        }
        else {
            return 0;
        }

    }
    int operator+=(int& value, const Flight& flight)
    {
        value += int(flight);
        return value;
    }
}
