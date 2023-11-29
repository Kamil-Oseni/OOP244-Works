// Name: Oluwaseun Kamil Oseni                Date: 11/09/2023            ID: 168216216			email:ooseni2@myseneca.ca
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Pack.h"

namespace sdds {
	Pack::Pack(const char* content, int size, int unitSize, int numOfUnits)
		: Container(content, size* unitSize, numOfUnits* unitSize), m_unitSize(unitSize) {
		if (unitSize <= 0) {
			setEmpty();
		}
	}

	int Pack::operator+=(int num)
	{
		int addedUnits = Container::operator+=(num * m_unitSize) / m_unitSize;
		return addedUnits;
	}

	int Pack::operator-=(int num)
	{
		int removedUnits = Container::operator-=(num * m_unitSize) / m_unitSize;
		return removedUnits;
	}

	int Pack::unit() const
	{
		return m_unitSize;
	}

	int Pack::noOfUnits() const
	{
		return volume() / m_unitSize;
	}

	int Pack::packSize() const
	{
		return capacity() / m_unitSize;
	}

	void Pack::clear(int size, int unitSize, const char* description)
	{
		if (unitSize > 0) {
			Container::clear(size * unitSize, description);
			m_unitSize = unitSize;
		}
		else {
			setEmpty();
		}
	}

	std::ostream& Pack::print(std::ostream& COUT) const
	{
		Container::print(COUT);
		if (*this) {
			COUT << ", " << noOfUnits() << " in a pack of " << packSize();
		}
		return COUT;
	}

	std::istream& Pack::read(std::istream& CIN)
	{
		if (!*this) {
			std::cout << "Broken Container, adding aborted! Press <ENTER> to continue....";
			while (CIN.get() != '\n'); // Clear the input buffer
			return CIN;
		}

		std::cout << "Add to ";
		print(std::cout);
		std::cout << std::endl << "> ";

		if (noOfUnits() < packSize()) {
			int numUnits;
			while (!(CIN >> numUnits) || numUnits < 1 || numUnits >(packSize() - noOfUnits())) {
				if (CIN.fail()) {
					CIN.clear();
					while (CIN.get() != '\n'); // Clear the input buffer
					std::cout << "Invalid Integer, retry: ";
				}
				else {
					std::cout << "Value out of range [1<=val<=" << (packSize() - noOfUnits()) << "]: ";
				}
			}

			int addedUnits = *this += numUnits;
			std::cout << "Added " << addedUnits << std::endl;
		}
		else {
			std::cout << "Pack is full!, press <ENTER> to continue...\n";
			while (CIN.get() != '\n'); // Clear the input buffer
		}

		return CIN;
	}



	std::ostream& operator<<(std::ostream& COUT, const Pack& obj)
	{
		return obj.print(COUT);
	}

	std::istream& operator>>(std::istream& CIN, Pack& obj)
	{
		return obj.read(CIN);
	}

}