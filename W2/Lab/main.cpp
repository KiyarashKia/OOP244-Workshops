/***********************************************************************
// OOP244 Workshop #2 lab (part 1): tester program
//
// File  main.cpp
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
***********************************************************************/

/*
I have done almost all the coding by myself and only copied the code that my professor provided with minor guidance of searching (mentioned in File.cpp) to complete my workshops and assignments.
Student : Kiarash Kia
Student ID: 108688235
Email: kkia2@myseneca.ca
Workshop 2 - Lab
Date : 9/23/2023
 */

#include "Employee.h"
using namespace sdds;
int main() {
   if(load()) {
      display();
   }
   deallocateMemory();
   return 0;
}