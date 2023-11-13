/***********************************************************************
// OOP244 Workshop #6 lab : tester program
//
// File  HealthCard.h
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

#ifndef SDDS_HEALTHCARD_H
#define SDDS_HEALTHCARD_H

#include <iostream>
#include <limits> 
#include <iomanip>

using namespace std;
namespace sdds {
   const int MaxNameLength = 55;
   class HealthCard {
      char* m_name{};
      long long m_number;
      char m_vCode[3];
      char m_sNumber[10];

      // Validation methods - Private
      bool validID(const char* name, long long number, const char vCode[], const char sNumber[]) const;
      void setEmpty();
      void allocateAndCopy(const char* name);
      void extractChar(istream& istr, char ch) const;
      std::ostream& printIDInfo(std::ostream& ostr) const;
      void set(const char* name, long long number, const char vCode[], const char sNumber[]);

   public:
       HealthCard();
       HealthCard(const char* name, long long number, const char vCode[], const char sNumber[]);
       
       // Rule of Three Section
       HealthCard(const HealthCard& hc);
       HealthCard& operator=(const HealthCard& hc);
       ~HealthCard();

       operator bool() const;

       std::ostream& print(std::ostream& ostr, bool toFile = true) const;
       std::istream& read(std::istream& istr);


   };
   ostream& operator<<(std::ostream& ostr, const HealthCard& hc);
   std::istream& operator>>(std::istream& istr, HealthCard& hc);
}
#endif // !SDDS_HealthCard_H


