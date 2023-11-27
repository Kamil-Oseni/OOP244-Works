// Name: Oluwaseun Kamil Oseni                Date: 11/24/2023            ID: 168216216			email:ooseni2@myseneca.ca
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Graduate.h"

namespace sdds
{
	void Graduate::setEmpty()
	{
		m_thesis = nullptr;
		m_supervisor = nullptr;
	}
	void Graduate::setThesis(const char* title)
	{
		delete[] m_thesis;
		if (title != nullptr) {
			m_thesis = new char[strlen(title) + 1];
			strcpy(m_thesis, title);
		}
		else {
			setEmpty();
		}
	}
	void Graduate::setSupervisor(const char* supervisor)
	{
		delete[] m_supervisor;
		if (supervisor != nullptr) {
			m_supervisor = new char[strlen(supervisor) + 1];
			strcpy(m_supervisor, supervisor);
		}
		else {
			m_supervisor = nullptr; // Only set m_supervisor to nullptr
		}
	}
	Graduate::Graduate() : Student() {
		setEmpty();
	}

	Graduate::Graduate(const char* name, int age, const char* thesis, const char* supervisor) : Student(name, age)
	{
		setEmpty();
		setThesis(thesis);
		setSupervisor(supervisor);

	}
	Graduate::~Graduate()
	{
		delete[]m_thesis;
		delete[]m_supervisor;
	}
	Graduate::Graduate(const Graduate& original) : Student(original) {
		setEmpty();
		*this = original;
	}
	Graduate& Graduate::operator=(const Graduate& original)
	{
		if (this != &original) {
			Student::operator=(original);

			setThesis(original.m_thesis);
			setSupervisor(original.m_supervisor);
		}
		return *this;
	}
	void Graduate::display() const {
		Student::display();
		if (m_thesis != nullptr && m_supervisor != nullptr) {
			std::cout << "Thesis Title: " << m_thesis << std::endl;
			std::cout << "Supervisor: " << m_supervisor << std::endl;
			std::cout << "---------------------------------------------" << std::endl;
		}

	}
}