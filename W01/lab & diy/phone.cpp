//Name: Oluwaseun Kamil Oseni 
//Email: ooseni2@myseneca.ca
//ID: 168216216
//Date: 9/16/2023

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <cstring>
#include "cStrTools.h"
#include "Phone.h"

using namespace sdds;
using namespace std;


const int MAX_LENGTH = 50;

char Name[MAX_LENGTH];
char area_Code[MAX_LENGTH];
char Prefix[MAX_LENGTH];
char Number[MAX_LENGTH];

//parName variable stores user input
char parName[MAX_LENGTH];

//name from phones.txt is converted to lower case and stored in variable lowerFullName and used for comparing with parName
char lowerFullName[MAX_LENGTH];

//pointer pointing to location that stores the result of the comparison
const char* output;


void phoneDir(const char* programTitle, const char* fileName)
{

    FILE* fptr = fopen(fileName, "r"); //opens file for reading


    if (fptr) {

        cout << programTitle << " phone direcotry search" << endl; cout
            << "-------------------------------------------------------" << endl;
        do
        {
            cout << "Enter a partial name to search (no spaces) or enter '!' to exit" << endl;
            cout << "> ";
            cin >> parName;


            rewind(fptr); //to ensure that we are starting from the first line of the file we use rewind function.

            while (fscanf(fptr, "%[^\t]\t%s\t%s\t%s\n", Name, area_Code, Prefix, Number) == 4) {
                toLowerCaseAndCopy(lowerFullName, Name); //function from cStrTools to convert the case of the name to lower and store it 
                toLowerCaseAndCopy(parName, parName); //function from cStrTools to convert the case of the parName to lower and store it

                output = strStr(lowerFullName, parName); //strStr checks if parName is a substring of lowerFullName

                if (output) {
                    displayRecords(); //if output is true, call display function
                }

            }
        } while (strcmp(parName, "!") != 0);

        cout << "Thank you for using " << programTitle << " directory." << endl;

    }
    else
    {

        cout << programTitle << " phone direcotry search" << endl;
        cout << "-------------------------------------------------------" << endl;
        cout << fileName << " file not found!" << endl;
        cout << "Thank you for using " << programTitle << " directory." << endl;

    }
    fclose(fptr); //close the file to avoid memory leak
}


void displayRecords()
{
    cout << Name << ": " << "(" << area_Code << ") " << Prefix << "-" << Number << endl;
}
