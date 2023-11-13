/***********************************************************************
// OOP244 Workshop #2 lab (part 1)
//
// File  File.cpp
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

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "File.h"

namespace sdds {
   FILE* fptr;
   bool openFile(const char filename[]) {
      fptr = fopen(filename, "r");
      return fptr != NULL;
   }
   int noOfRecords() {
      int noOfRecs = 0;
      char ch;
      while (fscanf(fptr, "%c", &ch) == 1) {
         noOfRecs += (ch == '\n');
      }
      rewind(fptr);
      return noOfRecs;
   }
   void closeFile() {
      if (fptr) fclose(fptr);
   }

   //TODO: read functions go here   

    // First Read Overload
    bool read(char*& name, const char filename[]) {
        char tmpName[128];

        if (fscanf(fptr, "%127[^\n]\n", tmpName) == 1) {

            name = new char[strlen(tmpName) + 1];
            strcpy(name, tmpName);  
            return true;
        }
        if (name != nullptr) {  // Searched for guidance through web to know the importance of having this "if" 
            delete[] name;
            name = nullptr;
        }

        return false;
    }

    // Second Read Overload
     bool read(int& empNum, const char filename[]) {
        
        
        if (fscanf(fptr, "%d,", &empNum) == 1) {
            return true;
        }

        return false;
    }

    // Third Read Overload
     bool read(double& empSalary, const char filename[]) {

         if (fscanf(fptr, "%lf,", &empSalary) == 1) {
             return true;
         }

         return false;
     }
 
}