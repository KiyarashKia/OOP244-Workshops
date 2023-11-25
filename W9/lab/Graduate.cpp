/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Student : Kiarash Kia
Student ID: 108688235
Email: kkia2@myseneca.ca
Workshop 9 - Lab - Graduate.cpp
Date : 11/25/2023
 */

#define _CRT_SECURE_NO_WARNINGS
#include "Graduate.h"
#include <cstring>
#include <iostream>

namespace sdds {

    Graduate::Graduate() {
        Student();
        thesisTitle = nullptr;
        supervisorName = nullptr;
    
    }

    Graduate::Graduate(const char* name, int age, const char* thesis, const char* supervisor)
        : Student(name, age) {
        if (thesis) {
            thesisTitle = new char[strlen(thesis) + 1];
            strcpy(thesisTitle, thesis);
        }
        else {
            thesisTitle = nullptr;
        }

        if (supervisor) {
            supervisorName = new char[strlen(supervisor) + 1];
            strcpy(supervisorName, supervisor);
        }
        else {
            supervisorName = nullptr;
        }
    }

    Graduate::Graduate(const Graduate& other) : Student(other) {
        if (other.thesisTitle) {
            thesisTitle = new char[strlen(other.thesisTitle) + 1];
            strcpy(thesisTitle, other.thesisTitle);
        }
        else {
            thesisTitle = nullptr;
        }

        if (other.supervisorName) {
            supervisorName = new char[strlen(other.supervisorName) + 1];
            strcpy(supervisorName, other.supervisorName);
        }
        else {
            supervisorName = nullptr;
        }
    }

    Graduate& Graduate::operator=(const Graduate& other) {
        if (this != &other) {
            Student::operator=(other);

            delete[] thesisTitle;
            delete[] supervisorName;

            if (other.thesisTitle) {
                thesisTitle = new char[strlen(other.thesisTitle) + 1];
                strcpy(thesisTitle, other.thesisTitle);
            }
            else {
                thesisTitle = nullptr;
            }

            if (other.supervisorName) {
                supervisorName = new char[strlen(other.supervisorName) + 1];
                strcpy(supervisorName, other.supervisorName);
            }
            else {
                supervisorName = nullptr;
            }
        }
        return *this;
    }

    Graduate::~Graduate() {
        delete[] thesisTitle;
        delete[] supervisorName;
    }

    void Graduate::display() const {
        Student::display();
        std::cout << "Thesis Title: " << thesisTitle << std::endl;
        std::cout << "Supervisor: " << supervisorName << std::endl;
        std::cout << "---------------------------------------------" << std::endl;
    }

}