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
    bool read(char*& name) {
        char temp[128];
        if (fscanf(fptr, "%127[^\n]\n", temp) == 1) {
            name = new char[strlen(temp) + 1];
            strcpy(name, temp);
            return true;
        }
        return false;
    }

    // Function to read an integer from the file
    bool read(int& empNo) {
        if (fscanf(fptr, "%d,", &empNo) == 1) {
            return true;
        }
        return false;
    }

    // Function to read a double from the file
    bool read(double& salary) {
        if (fscanf(fptr, "%lf,", &salary) == 1) {
            return true;
        }
        return false;
    }
}
