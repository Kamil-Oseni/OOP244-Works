//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//Oluwaseun Kamil Oseni
//ID: 168216216
//Email: ooseni2@myseneca.ca
//Date 10/7/2023

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Label.h"
namespace sdds {

    Label::Label() : content(nullptr) {
        strcpy(frame, "+-+|+-+|");
    }

    Label::Label(const char* frameArg) {
        if (frameArg == nullptr) {
            content = nullptr;
            strcpy(frame, "+-+|+-+|");
        }
        else {
            content = nullptr;
            
            strcpy(frame, frameArg);
        }
    }


    Label::Label(const char* frameArg, const char* contentArg) {
        if (frameArg)
            strcpy(frame, frameArg);
        else
            strcpy(frame, "+-+|+-+|");

        if (contentArg) {
            content = new char[strlen(contentArg) + 1];
            strcpy(content, contentArg);
        }
        else {
            content = nullptr; // Set content to nullptr if contentArg is not provided
        }
    }

    Label:: ~Label() {
        delete[] content;
    }
    std::istream& Label::readLabel() {
        char tempContent[71];
        std::cout << "> ";
        std::cin.getline(tempContent, 71);
        text(tempContent);
        return std::cin;
    }

    Label& Label::text(const char* contentArg) {
        if (contentArg != nullptr) {
            int len = strlen(contentArg);
            len = (len > 70) ? 70 : len; // Truncate content if it's longer than 70 characters
            // Allocate dynamic memory for content and copy the content
            content = new char[len + 1];
            strncpy(content, contentArg, len);
            content[len] = '\0'; // Ensure null-termination
        }
        return *this; // Return reference to the current object
    }

    std::ostream& Label::printLabel()const {
        if (content) { // Check if the label has content.
            const size_t labelSize = strlen(content) + 3; // Calculate the size needed for the label output.

            //print the frame top line
            std::cout << frame[0] << std::setfill(frame[1]) << std::setw((int)labelSize) << frame[2] << std::endl;
            std::cout << frame[7] << std::setfill(' ') << std::setw((int)labelSize) << frame[3] << std::endl; // Print the second line of theframe.
            std::cout << frame[7] << " " << content << " " << frame[3] << std::endl; // Print the label content with frame decoration.
            std::cout << frame[7] << std::setfill(' ') << std::setw((int)labelSize) << frame[3] << std::endl;  // Print the third line of the frame.
            std::cout << frame[6] << std::setfill(frame[5]) << std::setw((int)labelSize) << frame[4];    // Print the bottom frame line.
        }
        

        return std::cout; // Return a reference to the standard output stream to allow for chaining output operations.
    }

}