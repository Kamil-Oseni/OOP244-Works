//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//Oluwaseun Kamil Oseni
//ID: 168216216
//Email: ooseni2@myseneca.ca
//Date 10/7/2023

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "CarInventory.h"
namespace sdds {

    // Default constructor
    CarInventory::CarInventory()
    {
        resetInfo();
    }

    // check through to see if any car names are similar
    int find_similar(CarInventory car[], const int num_cars) {
        for (int i = 0; i < num_cars; i++) {
            for (int j = i + 1; j < num_cars; j++) {
                if (car[i].isSimilarTo(car[j])) {
                    return i;
                }
            }
        }
        return -1; // No similar cars found
    }

    // Constructor with default parameters
    CarInventory::CarInventory(const char* type, const char* brand, const char* model, int year, int code, double price) {
        resetInfo();
        setInfo(type, brand, model, year, code, price);
    }

    // Destructor
    CarInventory::~CarInventory() {
        delete[] m_type;
        delete[] m_brand;
        delete[] m_model;
    }

    // Reset by setting to nullptr and zero
    void CarInventory::resetInfo() {
        m_type = nullptr;
        m_brand = nullptr;
        m_model = nullptr;
        m_year = 0;
        m_code = 0;
        m_price = 0.0;
    }

    // Allocate new memory and copy data
    CarInventory& CarInventory::setInfo(const char* type, const char* brand, const char* model, int year, int code, double price) {
        delete[] m_type;
        delete[] m_brand;
        delete[] m_model;

        m_type = new char[strlen(type) + 1];
        strcpy(m_type, type);

        m_brand = new char[strlen(brand) + 1];
        strcpy(m_brand, brand);

        m_model = new char[strlen(model) + 1];
        strcpy(m_model, model);

        m_year = year;
        m_code = code;
        m_price = price;

        return *this;
    }


    // Display info
    void CarInventory::printInfo() const
    {
        std::cout << "| " << std::left << std::setw(11) << m_type;
        std::cout << "| " << std::left << std::setw(17) << m_brand;
        std::cout << "| " << std::left << std::setw(16) << m_model;
        std::cout << " | " << m_year << " |";
        std::cout << std::setw(5) << std::right << m_code << " |";
        std::cout << std::setw(10) << std::fixed << std::setprecision(2) << m_price << " |" << std::endl;
    }

    // Check if details are valid
    bool CarInventory::isValid() const
    {
        return (m_type && m_brand && m_model && m_year >= 1990 && m_code >= 100 && m_code <= 999 && m_price > 0);
    }

    // Check if the type, make, brand and year are equal to the value of another object
    bool CarInventory::isSimilarTo(const CarInventory& car) const {
        if (!m_type || !m_brand || !m_model || !car.m_type || !car.m_brand || !car.m_model) {
            return false;
        }
        return (strcmp(m_type, car.m_type) == 0 &&
            strcmp(m_brand, car.m_brand) == 0 &&
            strcmp(m_model, car.m_model) == 0 &&
            m_year == car.m_year);
    }


} // namespace sdds

