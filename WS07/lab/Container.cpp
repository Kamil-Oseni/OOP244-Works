// Name: Oluwaseun Kamil Oseni                Date: 11/09/2023            ID: 168216216			email:ooseni2@myseneca.ca
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Container.h"



namespace sdds {
	

	Container::Container(const char* content, int capacity, int contentVolume)
	{
		if (content && capacity > 0) {
			strncpy(m_content, content, SIZE);
			m_content[SIZE] = '\0';
			m_capacity = capacity;
			m_contentVolume = (contentVolume >= 0) ? contentVolume : 0;
		}
		else {
			setEmpty();
		}
	}

	int Container::operator+=(int value)
	{
		int spaceAvailable = m_capacity - m_contentVolume;
		int amountAdded = (value <= spaceAvailable) ? value : spaceAvailable;
		m_contentVolume += amountAdded;
		return amountAdded;
	}

	int Container::operator-=(int value)
	{
		int amountRemoved = (value <= m_contentVolume) ? value : m_contentVolume;
		m_contentVolume -= amountRemoved;
		return amountRemoved;
	}

	Container::operator bool() const
	{
		return (m_content[0] != '\0' && m_contentVolume <= m_capacity);
	}

	void Container::clear(int capacity, const char* content)
	{
		if (content && capacity > 0) {
			strncpy(m_content, content, SIZE);
			m_content[SIZE] = '\0';
			m_capacity = capacity;
			m_contentVolume = 0;
		}
		else {
			setEmpty();
		}
	}

	std::ostream& Container::print(std::ostream& COUT) const
	{
		if (*this) {
			COUT << m_content << ": (" << m_contentVolume << "cc/" << m_capacity << ")";
		}
		else {
			COUT << "****: (**cc/***)";
		}
		return COUT;
	}

	std::istream& Container::read(std::istream& CIN)
	{
		if (!*this) {
			std::cout << "Broken Container, adding aborted! Press <ENTER> to continue....\n";
			while (CIN.get() != '\n'); // Clear the input buffer
			return CIN;
		}

		std::cout << "Add to " << m_content << ": (" << m_contentVolume << "cc/" << m_capacity << ")" << std::endl;
		std::cout <<  "> ";

		int amount;
		while (!(CIN >> amount) || amount < 1 || amount > 999) {
			if (CIN.fail()) {
				CIN.clear();
				while (CIN.get() != '\n'); // Clear the input buffer
				std::cout << "Invalid Integer, retry: ";
			}
			else {
				std::cout << "Value out of range [1<=val<=999]: ";
			}
		}

		int addedAmount = *this += amount;
		std::cout << "Added " << addedAmount << " CCs" << std::endl;

		return CIN;
	}




	void Container::setEmpty()
	{
		m_content[0] = '\0';
		m_capacity = 0;
		m_contentVolume = 0;
	}

	int Container::capacity() const
	{
		return m_capacity;
	}

	int Container::volume() const
	{
		return m_contentVolume;
	}

	std::ostream& operator<<(std::ostream& COUT, const Container& obj)
	{
		obj.print(COUT);
		return COUT;

	}

	std::istream& operator>>(std::istream& CIN, Container& obj)
	{
		return obj.read(CIN);
	}
}