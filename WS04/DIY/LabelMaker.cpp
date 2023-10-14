//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//Oluwaseun Kamil Oseni
//ID: 168216216
//Email: ooseni2@myseneca.ca
//Date 10/7/2023

#include <iostream>
#include <cstring>
#include "LabelMaker.h"
namespace sdds {

    LabelMaker::LabelMaker(int noOfLabels) : size(noOfLabels) {
        labels = new Label[size];
    }

    void LabelMaker::readLabels() {
        std::cout << "Enter " << size << " labels:" << std::endl;
        for (int i = 0; i < size; ++i) {
            
            std::cout << "Enter label number " << i + 1 << std::endl;
            labels[i].readLabel();
        }
    }

    void LabelMaker::printLabels() {
        for (int i = 0; i < size; ++i) {
            labels[i].printLabel();
            std::cout << std::endl;
        }
    }

    LabelMaker::~LabelMaker() {
        delete[] labels;
    }
}

