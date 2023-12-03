#define _CRT_SECURE_NO_WARNINGS
#include "car.h"

namespace sdds {
	Car::Car(): Vehicle(), m_numOfDoors(0)
	{
		m_color = new char[1];
		m_color[0] = '\0';
	}

	Car::Car(const char* brand, int year, double mileage, int door, const char* color): Vehicle(brand, year, mileage), m_numOfDoors(door) 
	{
		m_color = new char[strlen(color) + 1];
		strcpy(m_color, color);
	}

	Car::~Car()
	{
		delete[]m_color;
	}

	Car::Car(const Car& old):Vehicle(old), m_numOfDoors(old.m_numOfDoors)
	{
		if (old.m_color) {
			m_color = new char[strlen(old.m_color) + 1];
			strcpy(m_color, old.m_color);
		}
	}

	Car& Car::operator=(const Car& old)
	{
		if (this != & old)
		{
			Vehicle::operator=(old);
			m_numOfDoors = old.m_numOfDoors;
			if (old.m_color) {
				m_color = new char[strlen(old.m_color) + 1];
				strcpy(m_color, old.m_color);
			}
		}
		return *this;
	}

	void Car::display() const
	{
		Vehicle::display();
		std::cout << "Doors: " << m_numOfDoors << "\nColor: " << m_color << std::endl;
	}


}