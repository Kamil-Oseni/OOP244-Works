// Name: Oluwaseun Kamil Oseni                Date: 11/17/2023            ID: 168216216			email:ooseni2@myseneca.ca
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_LINE_H
#define SDDS_LINE_H

#include "LblShape.h"

namespace sdds
{
	class Line : public LblShape
	{
	private:
		int m_length;

	public:
		Line();
		Line(const char* Cstring, const int length);
		void getSpecs(std::istream& is);
		void draw(std::ostream& os) const;
	};
}
#endif // !SDDS_LINE_H