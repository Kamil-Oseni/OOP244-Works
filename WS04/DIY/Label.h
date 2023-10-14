//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//Oluwaseun Kamil Oseni
//ID: 168216216
//Email: ooseni2@myseneca.ca
//Date 10/7/2023

#ifndef LABEL_H  
#define LABEL_H
#include <iostream>
#include <cstring>
namespace sdds
{
    class Label
    {
        char* content;
        char frame[9];
    public:
        Label();
        Label(const char* frameArg);
        Label(const char* frameArg, const char* contentArg);
        ~Label();
        std::istream& readLabel();
        std::ostream& printLabel() const;
        Label& text(const char* contentArg);
    };
}

#endif
