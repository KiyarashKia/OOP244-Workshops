/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Student : Kiarash Kia
Student ID: 108688235
Email: kkia2@myseneca.ca
Workshop 4 - DIY - Label.cpp
Date : 10/09/2023
 */

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <istream>
#include <iomanip>
#include <cstring>
#include "Label.h"

using namespace std;
namespace sdds {

	Label::Label() {
		m_frameArg = new char[strlen(DEF_FRAME) + 1];
		strcpy(m_frameArg, DEF_FRAME);

		m_content = nullptr;
	}


	Label::~Label() {
		delete[] m_frameArg;
		delete[] m_content;
	}


	// Got help from Ai-Gpt to build the function for precise result
	void Label::SetFrame(const char* frameArg) {
		if (m_frameArg) {
			delete[] m_frameArg;
			m_frameArg = nullptr;
		}
		const char* FrameCurrent = (frameArg && *frameArg) ? frameArg : DEF_FRAME;
		m_frameArg = new char[strlen(FrameCurrent) + 1];
		strcpy(m_frameArg, FrameCurrent);
	}



	Label::Label(const char* frameArg) {
		m_frameArg = nullptr;
		m_content = nullptr;
		SetFrame(frameArg);
	}


	Label::Label(const char* frameArg, const char* content) {
		SetFrame(frameArg);

		if (content) {
			m_content = new char[strlen(content) + 1];
			strcpy(m_content, content);
		}
		else {
			m_content = nullptr;
		}
	}

	istream& Label::readLabel() {
		char temp[MAX_CHAR + 1];
		cin.getline(temp, MAX_CHAR + 1, '\n');

		delete[] m_content;
		m_content = new char[strlen(temp) + 1];

		strcpy(m_content, temp);
		
		return cin;
	}

	ostream& Label::printLabel() const {
		if (!m_content) return cout;
		cout << right << m_frameArg[0] << setfill(m_frameArg[1]) << setw(strlen(m_content) + 3) << m_frameArg[2] << endl;
		cout << m_frameArg[7] << setfill(' ') << setw(strlen(m_content) + 3) << m_frameArg[3] << endl;
		cout << m_frameArg[7] << " " << m_content << " " << m_frameArg[3] << endl;
		cout << m_frameArg[7] << setfill(' ') << setw(strlen(m_content) + 3) << m_frameArg[3] << endl;
		cout << m_frameArg[6] << setfill(m_frameArg[5]) << setw(strlen(m_content) + 3) << m_frameArg[4];
		return cout;
	}

	Label& Label::text(const char* content) {
		delete[] m_content;

		if (content) {
			m_content = new char[MAX_CHAR + 1];
			strncpy(m_content, content, MAX_CHAR);
			m_content[MAX_CHAR] = '\0';
		}
		else {
			m_content = nullptr;
		}

		return *this;
	}


}

