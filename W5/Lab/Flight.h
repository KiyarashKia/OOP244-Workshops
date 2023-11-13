/***********************************************************************
// OOP244 Workshop #5 lab (part 1): tester program
//
// File  Flight.h
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
Workshop 5 - Lab - Header Flight
Date : 10/13/2023
 */
#ifndef SDDS_FLIGHT_H
#define SDDS_FLIGHT_H
#include <iostream>

namespace sdds {

   const int Boen747Capacity = 388;
   const int FuelTankCapacity = 238840;


   class Flight {

      int m_passengers = 0;
      double m_fuel = 0;
      char m_title[16];
      void emptyPlane();

   public:
      Flight();
      Flight(int passengers, double fuel, const char* title);
      std::ostream& display()const;

      operator bool() const;
      operator int() const;

      operator double() const;

      operator const char* () const;

      bool operator~() const;

      Flight& operator=(Flight& anotherFlight);

      Flight& operator=(int passengers);

      Flight& operator=(double fuel);

      Flight& operator+=(double addfuel);

      Flight& operator+=(int addpassengers);
      Flight& operator-=(double reducefuel);

      Flight& operator-=(int reducepassenger);
      Flight& operator<<(Flight& otherFlight);

      Flight& operator>>(Flight& otherFlight);

      int operator+(const Flight& flight) const;

   };

   int operator+=(int& value, const Flight& flight);

}
#endif // SDDS_FLIGHT_H