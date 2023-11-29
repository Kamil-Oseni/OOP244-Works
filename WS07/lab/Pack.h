// Name: Oluwaseun Kamil Oseni                Date: 11/09/2023            ID: 168216216			email:ooseni2@myseneca.ca
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_PACK_H
#define SDDS_PACK_H

#include <iostream>
#include "Container.h"


namespace sdds {
	class Pack: public Container {
		int m_unitSize;

	public:
		//constructor
		
		Pack(const char* content, int size, int unitSize = 330, int numOfUnits = 0);

		//operations
		int operator+=(int num);
		int operator-=(int num);

		//queries
		int unit() const;
		int noOfUnits() const;
		int packSize() const;

		//methods
		void clear(int size, int unitSize, const char* description);

		std::ostream& print(std::ostream& COUT)const;
		std::istream& read(std::istream& CIN);

	};

	std::ostream& operator<<(std::ostream& COUT, const Pack& obj); //Kamil don't forget to return COUT and CIN haha
	std::istream& operator>>(std::istream& CIN, Pack& obj);

}



#endif // !SDDS_PACK_H

