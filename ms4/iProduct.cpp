// Name: Oluwaseun Kamil Oseni                Date: 11/29/2023            ID: 168216216			email:ooseni2@myseneca.ca
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include "iProduct.h"
#include <iostream>



namespace sdds {
	std::ostream& operator <<(std::ostream& os, const iProduct& iproduct) {
		iproduct.display(os);
		return os;
	}

	std::istream& operator >>(std::istream& is, iProduct& iproduct) {
		iproduct.read(is);
		return is;
	}
}