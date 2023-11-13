/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Student : Kiarash Kia
Student ID: 108688235
Email: kkia2@myseneca.ca
Workshop 1 - DIY
Date : 9/18/2023
 */


#define _CRT_SECURE_NO_WARNINGS	
#include <iostream>
#include <cstring>
#include "Phone.h"
#include "cStrTools.h"

using namespace std;
using namespace sdds;


namespace sdds {

    char partialName[50];
    bool exitOrder = false;
    const char filename[256] = "und";
    const char programtitle[20] = "und";
    phoneRecord records;


	// Runs the phone directory application
	void phoneDir(const char* programtitle, const char* filename) {

        FILE* txtFile = fopen(filename, "r");
        if (txtFile) {


            cout << programtitle << " phone direcotry search" << endl;
            cout << "-------------------------------------------------------" << endl;

            while (!exitOrder) {
                cout << "Enter a partial name to search (no spaces) or enter '!' to exit" << endl << "> ";
                cin >> partialName;

                trim(partialName);
                //strcmp(partialName, "!") == 0
                // Set the exit order by using the flag - Validation
                if (strcmp(partialName, "!") == 0) {
                    exitOrder = true;
                    
                }
                else {
                    
                    bool found = false;

                    char lowercasePartialName[50];
                    for (int i = 0; partialName[i] != '\0'; i++) {
                        lowercasePartialName[i] = tolower(partialName[i]);
                    }
                    lowercasePartialName[strlen(partialName)] = '\0';

                   rewind(txtFile);

                    while (fscanf(txtFile, "%[^\t]\t%s\t%s\t%s\n", records.name, records.areaCode, records.prefix, records.number) != EOF) {

                        char lowercaseName[50];
                        for (int i = 0; records.name[i] != '\0'; i++)
                        {
                            lowercaseName[i] = tolower(records.name[i]);
                        }
                        lowercaseName[strlen(records.name)] = '\0';

                        if (strstr(lowercaseName, lowercasePartialName) != nullptr) 
                        {
                            cout << records.name << ": (" << records.areaCode << ") " << records.prefix << "-" << records.number << endl;
                            found = true;
                        }
                        
                    }

                     
                    if (!found) {
                        // cout << "No records matched" << endl;  ---- Just did not implement to match the expected output of the workshop
                                                                 // but could be a good practice to have it as well to handle if no matched found
                    }

                }
            }

            // Close the file after processing
            fclose(txtFile);
        }
        else {
            cout << programtitle << " phone direcotry search" << endl;
            cout << "-------------------------------------------------------" << endl;
            cout << filename << " file not found!" << endl;
        }


        cout << "Thank you for using " << programtitle << " directory." << "\n";
	}



    // -- This function have had been used. However it was being skipped in Submitter - Thats why it is commented.
 
	/*
    void programTitle(const char* programtitle) {
        cout << programtitle << " phone directory search" << endl;
       cout << "-------------------------------------------------------" << endl;
	}
*/

}
