//Name: Oluwaseun Kamil Oseni 
//Email: ooseni2@myseneca.ca
//ID: 168216216
//Date: 9/25/2023

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include "File.h"

namespace sdds {
    // Declare the file pointer as a global variable
    FILE* fptr;

    // Function to open a file for reading
    bool openFile(const char filename[]) {
        fptr = fopen(filename, "r");
        return fptr != NULL;
    }

    // Function to count the number of records in the file
    int noOfRecords() {
        int noOfRecs = 0;
        char ch;
        while (fscanf(fptr, "%c", &ch) == 1) {
            noOfRecs += (ch == '\n');
        }
        rewind(fptr);
        return noOfRecs;
    }

    // Function to close the file
    void closeFile() {
        if (fptr) fclose(fptr);
    }

    // Function to read a string from the file
    

    // Function to read an integer from the file
    bool read(int& population) {
        if (fscanf(fptr, "%d,", &population) == 1) {
            return true;
        }
        return false;
    }

    
    bool read(char*& name) {
        //Deallocate previous memory if not nullptr
        if (name != nullptr) {
           delete[] name;
           name = nullptr;
       }

        char temp[128];
        if (fscanf(fptr, "%127[^\n]\n", temp) == 1) 
        {
            // Explicitly add a null terminator
            temp[strlen(temp)] = '\0';

            name = new char[strlen(temp) + 1];
            strcpy(name, temp);
            return true;
        }
        return false;
    }
}
