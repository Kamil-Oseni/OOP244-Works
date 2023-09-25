//Name: Oluwaseun Kamil Oseni 
//Email: ooseni2@myseneca.ca
//ID: 168216216
//Date: 9/25/2023

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_

namespace sdds {
    // Define a structure to store population data
    struct Population {
        char* postalCode;  
        int population;   
    };

    // Function prototypes
    bool startsWith(const char* cString, const char* subString);
    bool getPostalCode(char* postal_code_prefix);
    bool load(const char* filename, const char* partial_postal_code_prefix);
    void display();
    void deallocateMemory();
}

#endif // !SDDS_POPULATION_H_
