/***********************************************************************
// OOP244 Workshop #5 DIY (part 2): tester program
//
// File  Portfolio.h
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
Workshop 5 - DIY - Portfolio.h
Date : 10/16/2023
 */


#ifndef SDDS_Portfolio_H_
#define SDDS_Portfolio_H_
#include <iostream>
using namespace std;
namespace sdds {

   class Portfolio {
      double m_value = 0;
      char m_stock[16];
      char m_type;

   public:

       Portfolio();
       Portfolio(double value, const char* stock, char type);
       void emptyPortfolio();
       void dispPortfolio() const;
       ostream& display() const;
       operator double() const;
       operator const char* () const;
       operator char() const;
       operator bool() const;
       Portfolio& operator +=(const double value);
       Portfolio& operator -=(const double value);
       bool operator ~() const;
       Portfolio& operator << (Portfolio& move);
       Portfolio& operator >> (Portfolio& move);
   };

   // Declared as Helper functions
   double operator +(const Portfolio& val1, const Portfolio& val2);
   double& operator +=(double& value, Portfolio& portfolio);

}
#endif // SDDS_Portfolio_H_