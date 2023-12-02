/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Student : Kiarash Kia
Student ID: 108688235
Email: kkia2@myseneca.ca
Workshop 10 - Lab - selection.h
Date : 12/02/2023
 */

#ifndef SDDS_SELECTION_H
#define SDDS_SELECTION_H

#include <iostream>

namespace sdds {

	template <typename arrayType, typename keyType, typename size_t>
	
	int* select(arrayType array[], keyType key, size_t size) {

		int* indices = new int[size + 1];
			int index = 0;

			for (size_t i = 0; i < size; i++)
			{
				if (array[i] == key)
				{
					indices[index++] = static_cast<int>(i);
				}
				
			}
			indices[index] = -1;
			return indices;
		}




		template <typename arrayType>
		void csvDisplaySelection(const char* title, const arrayType array[], const int* indices) {

			std::cout << title << std::endl;

			if (indices != nullptr && indices[0] != -1) {
				for (int i = 0; indices[i] != -1; ++i) {
					std::cout << array[indices[i]];

					if (indices[i + 1] != -1) {
						std::cout << ", ";
					}
				}
			}

			else std::cout << "Empty Selection";
			std::cout << std::endl;
		}


	}


#endif // SDDS_SELECTION_H

		