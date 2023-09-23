//Name: Oluwaseun Kamil Oseni 
//Email: ooseni2@myseneca.ca
//ID: 168216216
//Date: 9/22/2023

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring> // Include the cstring header for strlen and strcpy

#include "File.h"

namespace sdds {
    FILE* fptr;


    // Opens a file for reading
    bool openFile(const char filename[]) {
        fptr = fopen(filename, "r");
        return fptr != NULL;
    }

    // Counts the number of records in the file
    int noOfRecords() {
        int noOfRecs = 0;
        char ch;
        while (fscanf(fptr, "%c", &ch) == 1) {
            noOfRecs += (ch == '\n');
        }
        rewind(fptr); // Reset the file pointer to the beginning
        return noOfRecs;
    }

    // Closes the open file
    void closeFile() {
        if (fptr) fclose(fptr);
    }

    // Reads a string from the file and dynamically allocates memory for it
    bool read(char*& name) {
        char temp[128];
        if (fscanf(fptr, "%127[^\n]\n", temp) == 1) {
            name = new char[strlen(temp) + 1];
            strcpy(name, temp);
            return true;
        }
        return false;
    }

    // Reads an integer from the file
    bool read(int& empNo) {
        if (fscanf(fptr, "%d,", &empNo) == 1) {
            return true;
        }
        return false;
    }

    // Reads a double from the file
    bool read(double& salary) {
        if (fscanf(fptr, "%lf,", &salary) == 1) {
            return true;
        }
        return false;
    }
}
