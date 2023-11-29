// Name: Oluwaseun Kamil Oseni                Date: 11/09/2023            ID: 168216216			email:ooseni2@myseneca.ca
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_CONTAINER_H
#define SDDS_CONTAINER_H
#include <iostream>

#define SIZE 50


	namespace sdds {


		class Container {
		protected:
			//Attributes
			char m_content[SIZE + 1];
			int m_capacity;
			int m_contentVolume;


		public:
			//Constructors			
			Container(const char* content, int capacity, int contentVolume = 0);


			//Operations
			int operator+=(int value);
			int operator-=(int value);
			operator bool() const;


			//Methods
			void clear(int capacity, const char* content);
			std::ostream& print(std::ostream& COUT)const;
			std::istream& read(std::istream& CIN);

		protected:
			void setEmpty();
			int capacity() const;
			int volume() const;

		};

		std::ostream& operator<<(std::ostream& COUT, const Container& obj); //Kamil don't forget to return COUT and CIN haha
		std::istream& operator>>(std::istream& CIN, Container& obj);


	}



#endif // !SDDS_CONTAINER_H

