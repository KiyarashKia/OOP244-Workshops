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
Workshop 10 - Lab - EmployeeOffice.h - Provided
Date : 12/02/2023
 */

#include <iostream>
#ifndef SDDS_EMPLOYEE_H_
#define SDDS_EMPLOYEE_H_
#include "Displayable.h"
namespace sdds {
   class EmployeeOffice : public Displayable {
      int m_office{};
      char m_name[41]{};
   public:
      EmployeeOffice() = default;
      EmployeeOffice(const char* name, int office);
      std::ostream& display(std::ostream& os)const;
      bool operator==(int office)const;
   };


}
#endif // !SDDS_EMPLOYEE_H_