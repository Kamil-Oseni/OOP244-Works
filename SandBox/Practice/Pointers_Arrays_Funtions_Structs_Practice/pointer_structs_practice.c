/*
Goals
 - Create a struct data type with its members; (done)
 - Assign the struct data type to Three objects using arrays; (done)
 - Create a function that uses printf and scanf to assign the elements of the array; (done)
 - Create a function that prints all students information
 - Create a function that takes the elements of the array by address using pointers 
	and prints all student's info;
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define arrSize 3
#define nameSize 20

//Create a struct data type with its members;
struct Person //Declared as a global variable
{
	char name[nameSize];
	int age;
	double height;
};


//Assign the struct data type to five objects using arrays;
struct Person students[arrSize]; //I declared the size as a macro, 
								//and declared students as a global variable. 

//Define a pointer with data type "struct Person" pointing to the address of 
//students.
struct Person* ptrToStudents = &students;

void getStudentInfo() //by value 
{
	//Use printf and scanf to assign the elements of the array;
	for (int i = 0; i < arrSize; i++)
	{
		printf("Enter student %d's information\n", i + 1);
		printf("Enter Name: ");
		scanf("%s", students[i].name);

		printf("Enter Age: ");
		scanf("%d", &students[i].age);
		//need to clear input buffer here, how?
		//fflush(stdin); // Clear input buffer
		printf("Enter Height: ");
		scanf("%lf", &students[i].height);
		printf("\n");
	}
	
}


void printStudentInfo() 
{
	for (int i = 0; i < arrSize; i++)
	{
		printf("Student %d's name is %s, Age is %d, Height is %.2lf\n", i+1, 
			students[i].name, students[i].age, students[i].height);
	}
}

int main()
{
	getStudentInfo();
	printStudentInfo();

	return 0;
}