#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include "vehicle.h"



namespace sdds {
	//default constructor
	Vehicle::Vehicle() : m_year(0), m_mileage(0.0), m_brand(nullptr) {
		m_brand = new char[1]; // Allocate memory for an empty string
		m_brand[0] = '\0'; // Null-terminate the string

	}
	Vehicle::Vehicle(const char* brand, int year, double mileage) : m_year(year), m_mileage(mileage)
	{
		m_brand = new char[strlen(brand) + 1];
		strcpy(m_brand, brand);
		
	}
	

	Vehicle::Vehicle(const Vehicle& old) : m_year(old.m_year), m_mileage(old.m_mileage)
	{
		if (old.m_brand) {
			m_brand = new char[strlen(old.m_brand) + 1];
			strcpy(m_brand, old.m_brand);
		}
	}

	Vehicle& Vehicle::operator=(const Vehicle& old)
	{
		if (this != &old)
		{
			m_year = old.m_year;
			m_mileage = old.m_mileage;
			


			delete[] m_brand;
			m_brand = nullptr;

			if (old.m_brand) {
				m_brand = new char[strlen(old.m_brand) + 1];
				strcpy(m_brand, old.m_brand);
			}
			
		}
		return *this;
	}

	Vehicle::~Vehicle()
	{
		delete[]m_brand;
	}


	int Vehicle::getYear() const
	{
		return m_year;
	}
	double Vehicle::getMileage() const
	{
		return m_mileage;
	}
	
	const char* Vehicle::getBrand() const
	{
		return m_brand;
	}

	void Vehicle::display() const
	{
		std::cout << "Brand: " << m_brand << "\nYear: " << m_year << "\nMileage: " << m_mileage << std::endl;
	}
	
	std::ostream& operator<<(std::ostream& os, const Vehicle& vehicle)
	{
		vehicle.display();
		return os;
	}

}

