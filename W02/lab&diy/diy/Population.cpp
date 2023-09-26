//Name: Oluwaseun Kamil Oseni 
//Email: ooseni2@myseneca.ca
//ID: 168216216
//Date: 9/25/2023

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm> 
#include "Population.h"
#include "File.h"


namespace sdds {
    // Define global variables
    Population* populationData = nullptr;  // Array to store population data and initialized to null
    int populationCount = 0;  // Number of population records
    extern FILE* fptr;  // Declare fptr as extern because I used it in File.cpp to avoid memory leak

    // Function to check if a string starts with another string
    bool startsWith(const char* cstring, const char* subString) {
        return strncmp(cstring, subString, strlen(subString)) == 0;
    }

    // Function to get a postal code from user input
    bool getPostalCode(char* postal_code_prefix) {
        std::cout << "Population Report" << std::endl;
        std::cout << "-----------------" << std::endl;
        std::cout << "Enter postal code:" << std::endl;
        std::cout << "> ";
        std::cin.getline(postal_code_prefix, 4);

        if (strcmp(postal_code_prefix, "!") == 0) {
            return false;
        }

        return true;
    }

    // Function to load population data from a file
    bool load(const char* filename, const char* partial_postal_code_prefix) {
        if (openFile(filename)) {
            const int maxRecords = noOfRecords();
            populationData = new Population[maxRecords];  // Allocate dynamic memory for population data

            int matchCount = 0;
            char line[100]; // Assume a maximum line length of 100 characters

            while (matchCount < maxRecords && fgets(line, sizeof(line), fptr)) {
                char postalCode[4] = { 0 };
                int population = 0;

                if (sscanf(line, "%3[^,],%d", postalCode, &population) == 2) {
                    if (strcmp(partial_postal_code_prefix, "all") == 0 || startsWith(postalCode, partial_postal_code_prefix)) {
                        populationData[matchCount].postalCode = new char[4];
                        strcpy(populationData[matchCount].postalCode, postalCode);
                        populationData[matchCount].population = population;
                        matchCount++;
                    } 
                }
            }

            populationCount = matchCount;
            closeFile();
            return true;
            
        }
        else {
            std::cerr << "Could not open data file: " << filename << std::endl;
            return false;
        }
    }

        
   // Function to display population data sorted by population and postal code
    void display() {
        std::cout << "Postal Code: population" << std::endl;
        std::cout << "-------------------------" << std::endl;

        // Sort populationData using a custom comparison function
        std::sort(populationData, populationData + populationCount, [](const Population& a, const Population& b) {
            if (a.population != b.population) {
                return a.population < b.population;  // Sort by population in ascending order
            }
            return strcmp(a.postalCode, b.postalCode) < 0;  // Sort by postal code in ascending alphabetical order
            });

        int totalPopulation = 0;
        for (int i = 0; i < populationCount; i++) {
            std::cout << i + 1 << "- " << populationData[i].postalCode << ":  " << populationData[i].population << std::endl;
            totalPopulation += populationData[i].population;
        }
        std::cout << "-------------------------" << std::endl;
        std::cout << "Population of the listed areas: " << totalPopulation << "\n" << std::endl;
    }



    // Function to deallocate memory used for population data
    void deallocateMemory() {
        for (int i = 0; i < populationCount; i++) {
            delete[] populationData[i].postalCode;
        }

        delete[] populationData;  // Deallocate the array of population data
        populationData = nullptr; // Set the pointer to null to avoid accessing freed memory
        populationCount = 0;      // Reset the population count

    }
}
