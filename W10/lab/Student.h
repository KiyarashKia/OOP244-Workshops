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
***********************************************************************/
/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Student : Kiarash Kia
Student ID: 108688235
Email: kkia2@myseneca.ca
Workshop 10 - Lab - Student.h - Provided
Date : 12/02/2023
 */

#include <iostream>
#ifndef SDDS_STUDENT_H_
#define SDDS_STUDENT_H_
#include "Displayable.h"
namespace sdds {
   class Student : public Displayable {
      int m_stno{};
      char m_name[41]{};
      double m_gpa{};
   public:
      Student() = default;
      Student(int stno, const char* name, double gpa);
      std::ostream& display(std::ostream& os)const;
      bool operator==(double gpa)const;
   };
}
#endif // !SDDS_STUDENT_H_

