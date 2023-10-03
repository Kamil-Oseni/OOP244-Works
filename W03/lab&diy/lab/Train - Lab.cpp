//Name: Oluwaseun Kamil Oseni 
//Email: ooseni2@myseneca.ca
//ID: 168216216
//Date: 9/30/2023

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.



#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Train.h"

namespace sdds {

    // Constructor
    Train::Train() {
        name = nullptr;
        numPassengers = -1;
        departureTime = -1;
    }

    // Destructor
    Train::~Train() {
        finalize();
    }

    // Initialize the train object to an invalid state
    void Train::initialize() {
        if (name) delete[] name;
        name = nullptr;
        numPassengers = -1;
        departureTime = -1;
    }

    // Validate the time value
    bool Train::validTime(int value) const {
        return (value >= MIN_TIME && value <= MAX_TIME && value % 100 < 60);
    }

    // Validate the number of passengers
    bool Train::validNoOfPassengers(int value) const {
        return (value > 0 && value <= MAX_NO_OF_PASSENGERS);
    }


    void Train::clear() {
        if (name) delete[] name;
        name = nullptr;
        numPassengers = -1;
        departureTime = -1;
    }

    // Check if the train object is in an invalid state
    bool Train::isInvalid() const {
        return (name == nullptr || numPassengers == -1 || departureTime == -1);
    }

    // Set the name of the train
    void Train::set(const char* trainName) {
        if (trainName && trainName[0] != '\0') {
            clear();
            name = new char[strlen(trainName) + 1];
            strcpy(name, trainName);
        }
        else {
            clear();
        }
    }

    // Set the number of passengers and departure time
    void Train::set(int noOfPassengers, int departure) {
        if (validNoOfPassengers(noOfPassengers) && validTime(departure)) {
            numPassengers = noOfPassengers;
            departureTime = departure;
        }
        else {
            clear();
        }
    }

    // Set all attributes (name, passengers, departure)
    void Train::set(const char* trainName, int noOfPassengers, int departure) {
        set(trainName);
        set(noOfPassengers, departure);
    }

    void Train::finalize() {
        clear();
    }

    int Train::noOfPassengers() const {
        return numPassengers;
    }

    const char* Train::getName() const {
        return name;
    }

    int Train::getDepartureTime() const {
        return departureTime;
    }

    // Display train information
    void Train::display() const {
        if (isInvalid()) {
            std::cout << "Train in an invalid State!" << std::endl;
        }
        else {
            std::cout << "NAME OF THE TRAIN:    " << name << std::endl;
            std::cout << "NUMBER OF PASSENGERS: " << numPassengers << std::endl;
            std::cout << "DEPARTURE TIME:       " << departureTime << std::endl;
        }
    }
}
