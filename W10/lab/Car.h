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
Workshop 10 - Lab - Car.h - Provided
Date : 12/02/2023
 */

#include <iostream>
#ifndef SDDS_CAR_H_
#define SDDS_CAR_H_
#include "Displayable.h"
namespace sdds {
   class Car : public Displayable {
      char m_plate[9]{};
      char m_makeModel[41]{};
   public:
      Car() = default;
      Car(const char* plate , const char* makeModel);
      std::ostream& display(std::ostream& os)const;
      bool operator==(const char* mmSubstr)const;
   };


}
#endif // !SDDS_CAR_H_
