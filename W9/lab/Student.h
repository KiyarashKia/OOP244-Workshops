/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Student : Kiarash Kia
Student ID: 108688235
Email: kkia2@myseneca.ca
Workshop 9 - Lab - Student.h
Date : 11/25/2023
 */

#ifndef SDDS_STUDENT_H
#define SDDS_STUDENT_H


namespace sdds {

	class Student {
		char* stName;
		int stAge;

	public:
		Student();
		Student(const char* name, int age);

		Student(const Student& other);
		Student& operator=(const Student& other);
		virtual ~Student();

		void display() const;

	};

}
#endif // !_STUDENT_H