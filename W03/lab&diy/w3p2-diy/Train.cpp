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
        if (value > MIN_TIME && value < MAX_TIME) {
            int lastTwoDigits = value % 100;
            if (lastTwoDigits <= 59) {
                return true;
            }
        }
        return false;
    }

    // Validate the number of passengers
    bool Train::validNoOfPassengers(int value) const {
        return (value > 0 && value < MAX_NO_OF_PASSENGERS);
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
        delete[] name;
        name = nullptr;
        if (trainName != nullptr && trainName[0] != '\0') {
            int length = strlen(trainName);
            name = new char[length + 1];
            strcpy(name, trainName);
        }
    }
    void Train::set(int noOfPassengers, int departure) {
        // Check if the provided number of passengers and departure time are valid
        if (validNoOfPassengers(noOfPassengers) && validTime(departure)) {
            // If valid, set the number of passengers and departure time
            numPassengers = noOfPassengers;
            departureTime = departure;
        }
        else {
            // If not valid, set the number of passengers and departure time to -1
            // indicating an invalid state for the train object
            numPassengers = -1;
            departureTime = -1;
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

    // 1. Load passengers onto the train
    bool Train::load(int& notBoarded) {
        int passengers;
        std::cout << "Enter number of passengers boarding:" << std::endl;
        std::cout << "> ";
        std::cin >> passengers;
        if ((numPassengers + passengers) > MAX_NO_OF_PASSENGERS) {
            notBoarded = (numPassengers + passengers) - MAX_NO_OF_PASSENGERS;
            numPassengers = MAX_NO_OF_PASSENGERS;
            if (notBoarded > 0) {
                // std::cout << "Train is full, " << notBoarded << " passengers could not be boarded." << std::endl;
            }
            return false;
        }
        else {
            numPassengers += passengers;
            return true;
        }
    }


    // 2. Update departure time
    bool Train::updateDepartureTime()
    {
        int newTime;
        do {
            std::cout << "Enter new departure time:" << std::endl;
            std::cout << "> ";
            std::cin >> newTime;
            if (!validTime(newTime)) {
                std::cout << "Invalid departure time, valid times are between " << MIN_TIME << " and " << MAX_TIME << "!" << std::endl;
            }
        } while (!validTime(newTime));

        departureTime = newTime;
        return true;
    }


    bool Train::transfer(const Train& other)
    {
        int remainingPassengers = 0; // Variable to store the number of passengers that could not be boarded

        // Check if either this train or the other train is in an invalid state
        if (this->isInvalid() || other.isInvalid()) {
            return false; // Transfer cannot be performed if any of the trains is in an invalid state
        }
        else {
            // Calculate the combined length of the names of this train and the other train
            int totalLength = strlen(this->name) + strlen(other.name) + 3;

            // Dynamically allocate memory for the combined name
            char* combinename = new char[totalLength];

            // Combine the names of this train and the other train
            strcpy(combinename, this->name);
            strcat(combinename, ", ");
            strcat(combinename, other.name);

            // Delete the existing name of this train and assign the combined name
            delete[] this->name;
            this->name = combinename;

            // Calculate the total number of passengers after the transfer
            int totalPassengers = this->numPassengers + other.numPassengers;

            // Check if the total number of passengers exceeds the maximum limit
            if (totalPassengers > MAX_NO_OF_PASSENGERS) {
                remainingPassengers = totalPassengers - MAX_NO_OF_PASSENGERS;
                this->numPassengers = MAX_NO_OF_PASSENGERS; // Set the number of passengers to the maximum limit

                // Print a message indicating that some passengers could not be boarded due to full capacity
                std::cout << "Train is full; " << remainingPassengers << " passengers of " << other.name << " could not be boarded!" << std::endl;
                return true; // Transfer is successful, but some passengers could not be boarded
            }
            else {
                this->numPassengers = totalPassengers; // Set the number of passengers to the total after transfer
                return true; // Transfer is successful, all passengers are boarded
            }
        }
    }


}