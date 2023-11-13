/***********************************************************************
// OOP244 Workshop #2 lab (part 1)
//
// File  Employee.cpp
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
#include "Employee.h"
#include "File.h"
using namespace std;
namespace sdds {

   int noOfEmployees;
   Employee* employees;


   void sort() {
      int i, j;
      Employee temp;
      for (i = noOfEmployees - 1; i > 0; i--) {
         for (j = 0; j < i; j++) {
            if (employees[j].m_empNo > employees[j + 1].m_empNo) {
               temp = employees[j];
               employees[j] = employees[j + 1];
               employees[j + 1] = temp;
            }
         }
      }
   }

   // TODO: Finish the implementation of the 1 arg load function which
   // reads one employee record from the file and loads it into the employee reference
   // argument
   bool load(Employee& emp, const char filename[]) {
     
       // using read function overload to load information of employee
       bool LoadEmpNum = read(emp.m_empNo, filename);
       bool LoadEmpSalary = read(emp.m_salary, filename);
       bool LoadName = read(emp.m_name, filename);
       
     

       // return the combined success result of the three read functions. These read 
      // functions should set the properties of the reference argument of the load function
       bool ok = LoadName && LoadEmpNum && LoadEmpSalary;

      
      return ok;
   }
   // TODO: Finish the implementation of the 0 arg load function 
   bool load() {

       if (!openFile("employees.csv")) {
           cout << "Could not open data file: " << DATAFILE << endl;
           return false;
       }

       noOfEmployees = noOfRecords();

       employees = new Employee[noOfEmployees];

       int i;

       for (i = 0; i < noOfEmployees; i++) {
           if (!load(employees[i], DATAFILE)) {
               cout << "Error: incorrect number of records read; the data is possibly corrupted." << endl;
  
               return false;
           }
       }

       closeFile();

       bool ok = true;

       return ok;
   }

   // TODO: Implementation for the display functions go here


   // First Display Overload
   void display() {

       int i = 0;

       cout << "Employee Salary report, sorted by employee number" << endl;
       cout << "no- Empno, Name, Salary" << endl;
       cout << "------------------------------------------------" << endl;
       sort();

       for (i = 0; i < noOfEmployees; i++)
       {
           cout << i + 1 << "- " << employees[i].m_empNo << ": " << employees[i].m_name << ", $" << (int)employees[i].m_salary << endl;

       }


   }

   // Second Display Overload
   void display(const Employee& emp) {

       cout << emp.m_empNo << "$" << emp.m_salary << emp.m_name << endl;

   }


   // TODO: Implementation for the deallocateMemory function goes here

   void deallocateMemory() {

       
           for (int i = 0; i < noOfEmployees; i++) {
               delete[] employees[i].m_name; 
       }
           delete[] employees;
           employees = nullptr; // As the pointer still may hold the memory address of the released / deleted memory, I set to null to avoid any further unexpected behaviour
   }


}


// Note for me : The nature of data can show if it is dynamic. for m_name : - Names can vary in length - DMA eliminates the risk of buffer Overflow