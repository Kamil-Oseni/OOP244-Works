// Name: Oluwaseun Kamil Oseni                Date: 11/24/2023            ID: 168216216			email:ooseni2@myseneca.ca
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_GRADUATE_H
#define SDDS_GRADUATE_H
#include "Student.h"

namespace sdds {

	class Graduate : public Student
	{
	private:
		char* m_supervisor;
		char* m_thesis;
		
		void setEmpty();
		void setThesis(const char* title);
		void setSupervisor(const char* supervisor);

	public:
		Graduate();
		Graduate(const char* name, int age, const char* thesis, const char* supervisor);

		virtual ~Graduate();

		Graduate(const Graduate& original);
		Graduate& operator=(const Graduate& original);

		void display()const;
	

	};

	
}


#endif // !SDDS_GRADUATE_H
