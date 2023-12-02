/***********************************************************************
// OOP244 Workshop # 10
//
// Version 1.0
// Date: 2023/11/25
// Author: Fardad Soleimanloo
// Description:
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
/////////////////////////////////////////////////////////////////
***********************************************************************//*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Student : Kiarash Kia
Student ID: 108688235
Email: kkia2@myseneca.ca
Workshop 10 - Lab - EmployeeOffice.cpp - Provided
Date : 12/02/2023
 */

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "EmployeeOffice.h"
namespace sdds {
   EmployeeOffice::EmployeeOffice(const char* name, int office) { 
      strcpy(m_name, name);
      m_office = office;
   }
   ostream& EmployeeOffice::display(ostream& os)const {
      return os << m_name << " (Office# " << m_office << ")";
   }
   bool EmployeeOffice::operator==(int office)const {
      return m_office == office;
   }
}
