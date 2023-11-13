/***********************************************************************
// OOP244 Workshop #2 lab (part 1)
//
// File  File.h
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//    To be completed by students
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

#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
namespace sdds {
   bool openFile(const char filename[]);
   void closeFile();
   int noOfRecords();

   // TODO: Declare overloaded read function prototypes
 
   // First Overload
   bool read(char*& name, const char filename[]);

   // Second Overload
   bool read(int& empNum, const char filename[]);

   // Third Overload
   bool read(double& empSalary, const char filename[]);


}

#endif // !SDDS_FILE_H_