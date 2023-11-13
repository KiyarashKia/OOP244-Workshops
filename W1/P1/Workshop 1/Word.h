/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Student : Kiarash Kia
Student ID: 108688235
Email: kkia2@myseneca.ca
 */


#define _CRT_SECURE_NO_WARNINGS

// Compilation Safeguards
#ifndef SDDS_Word_H 
#define SDDS_Word_H

#include <iomanip>

const int MAX_NO_OF_WORDS = 500;
const int MAX_WORD_LEN = 21;
const int SORT_BY_OCCURANCE = 1;
const int SORT_ALPHABETICALLY = 0;


using namespace std;
namespace sdds {
    
    // Function definition in sdds as the namespace is being used in all modules
    struct Word {
        char letters[MAX_WORD_LEN];
        int count;
    };


   
    int searchWords(const Word words[], int num, const char word[]);


    int readWord(char* word, FILE* fptr, int maxLen);


    void addWord(Word words[], int* index, const char newWord[]);


    void title(const char* value, int len);


    void endList();


    void totalWordsStat(int totNoWrds, int totalOverAll, int longestWord);


    void print(const Word* w, int gotoNextLine, int len);


    int findMaxLen(const Word words[], int noOfWords);


    void listWords(const Word words[], int noOfWords, const char* theTitle);


    void swap(Word* p1, Word* p2);


    void sort(Word words[], int cnt, int sortType);


    int totalCount(const Word* words, int num);


    void wordStats(const char* filename);


    void programTitle();

    

}
#endif
