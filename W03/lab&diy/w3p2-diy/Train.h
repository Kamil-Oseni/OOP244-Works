//Name: Oluwaseun Kamil Oseni 
//Email: ooseni2@myseneca.ca
//ID: 168216216
//Date: 9/30/2023

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_TRAIN_H
#define SDDS_TRAIN_H

namespace sdds {

    const int MIN_TIME = 700;
    const int MAX_TIME = 2300;
    const int MAX_NO_OF_PASSENGERS = 1000;

    class Train {
    private:
        char* name;
        int numPassengers;
        int departureTime;

        bool validTime(int value) const;
        bool validNoOfPassengers(int value) const;
        void clear();

    public:
        Train();
        ~Train();
        void initialize();
        bool isInvalid() const;
        void set(const char* trainName);
        void set(int noOfPassengers, int departure);
        void set(const char* trainName, int noOfPassengers, int departure);
        void finalize();
        int noOfPassengers() const;
        const char* getName() const;
        int getDepartureTime() const;
        void display() const;

        // 1. Load passengers onto the train
        bool load(int& notBoarded);

        // 2. Update departure time
        bool updateDepartureTime();

        // 3. Transfer passengers from one train to another
        bool transfer(const Train& other);
    };
}

#endif // !SDDS_TRAIN_H