#ifndef SDDS_CAR_H
#define SDDS_CAR_H
#include <iostream>
#include <string>
#include "vehicle.h"

	namespace sdds {

		class Car: public Vehicle {
			int m_numOfDoors{};
			char* m_color{ nullptr };

		public:
			Car();
			Car(const char* brand, int year, double mileage, int door, const char* color);
			virtual ~Car();

			Car(const Car& old);
			Car& operator=(const Car& old);

			void display()const;
			
		};




	}


#endif