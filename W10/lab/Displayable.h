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
Workshop 10 - Lab - Displayable.h - Provided
Date : 12/02/2023
 */

#include <iostream>
#ifndef SDDS_READWRITE_H_
#define SDDS_READWRITE_H_
namespace sdds {
   class Displayable {
   public:
      virtual std::ostream& display(std::ostream& os)const = 0;
   };
   std::ostream& operator<<(std::ostream& os, const Displayable& c);
}
#endif // !SDDS_READWRITE_H_

