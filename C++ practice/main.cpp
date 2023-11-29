#include<iostream>
#include<string>


template <typename T>
T add(T x, T y) {
	return x + y;
}

template <typename T>
T subtract(T x, T y) {
	return x - y;
}

template <typename T>
T divide(T x, T y) {
	if (y != 0)
	{
		return x / y;
	}
	else
	{
		std::cout << "Cannot Divide by Zero" << std::endl;
		return y;
	}
}

template <typename T>
T remainder(T x, T y) {
	return x % y;
}

template <typename T>
T multiply(T x, T y) {
	return x * y;
}


template <typename T>
void swap(T &a, T &b) {
	T temp = a;
	a = b;
	b = temp;
}

//Using a template to swap elements of an array
template <typename T>
void swap(T arr1[], T arr2[], int size) {
	for (int i = 0; i < size; i++)
	{
		T temp = arr1[i];
		arr1[i] = arr2[i];
		arr2[i] = temp;
	}
}

template<typename T>
void printArray(T arr[], int size) {
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
}

void printName(std::string name1, std::string name2) {
	std::cout  << "Last Name: " << name1 << "\nFirst Name: " << name2 << std::endl;
}
//using template with a class
template<typename T, int N>
class Array {
	T m_array[N];
public:
	int getArrSize() const { return N; }
};

class Car {
	std::string m_brand;
	std::string m_model;
	int m_year;

public:
	Car() : m_brand(nullptr), m_model(nullptr), m_year(0) {};
	Car(std::string brand, std::string model, int year) {
		m_year = year;
		m_brand = brand;
		m_model = model;
	}

	// Getter functions to access private members
	std::string getBrand() const {
		return m_brand;
	}

	std::string getModel() const {
		return m_model;
	}

	int getYear() const {
		return m_year;
	}

	// Setter functions to modify private members
	void setBrand(std::string brand) {
		m_brand = brand;
	}

	void setModel(std::string model) {
		m_model = model;
	}

	void setYear(int year) {
		m_year = year;
	}

	void display() const {
		std::cout << "Brand: " << m_brand << "\nModel: " << m_model << "\nYear: " << m_year << std::endl;
	}

	void display(std::string brand, std::string model) const {
		std::cout << "Brand: " << m_brand << "\nModel: " << m_model << std::endl;
	}
	void display(std::string brand) const {
		std::cout << "Brand: " << m_brand << std::endl;
	}

	Car operator+(const Car& obj) const {
		std::string newBrand = m_brand + obj.m_brand;
		std::string newModel = m_model + obj.m_model;
		int newYear = (m_year > obj.m_year) ? m_year : obj.m_year;

		return Car(newBrand, newModel, newYear);
	}
};

int main() {
	Array<int, 5> array;
	
	std::cout << array.getArrSize() << std::endl;
    return 0;
}
