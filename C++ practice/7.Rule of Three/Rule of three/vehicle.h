#ifndef SDDS_VEHICLE_H
#define SDDS_VEHICLE_H
#include <iostream>
#include <string>

	namespace sdds {
	
		class Vehicle {

		protected:
			char* m_brand{nullptr};
			int m_year{};
			double m_mileage{};
			
		
		
		public:
			Vehicle();
			Vehicle(const char* brand, int year, double mileage = 0.0);

			Vehicle(const Vehicle& old);
			Vehicle& operator=(const Vehicle& old);

			virtual ~Vehicle();

			int getYear()const;
			double getMileage()const;
			
			const char* getBrand()const;
			virtual void display()const;
		
		};

		std::ostream& operator<<(std::ostream& os, const Vehicle& vehicle);
		
	}

#endif // !SDDS_VEHICLE_H

