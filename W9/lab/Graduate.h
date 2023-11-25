/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Student : Kiarash Kia
Student ID: 108688235
Email: kkia2@myseneca.ca
Workshop 9 - Lab - Graduate.h
Date : 11/25/2023
 */

#ifndef SDDS_GRADUATE_H
#define SDDS_GRADUATE_H

#include "Student.h"

namespace sdds {

    class Graduate : public Student {
        char* thesisTitle;
        char* supervisorName;

    public:
        Graduate();
        Graduate(const char* name, int age, const char* thesis, const char* supervisor);

        Graduate(const Graduate& other);
        Graduate& operator=(const Graduate& other);
        virtual ~Graduate();

        void display() const;
    };

}

#endif // SDDS_GRADUATE_H
