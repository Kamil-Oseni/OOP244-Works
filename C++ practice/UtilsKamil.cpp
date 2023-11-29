#include <iostream>
using namespace std;


#ifndef SDDS_UTILSKAMIL_H
#define SDDS_UTILSKAMIL_H

namespace kamil {

    //function to get minimum value in an array
    int getMin(int arr[], int arrSize, int* min) {


        for (int i = 1; i < arrSize; i++) {
            arr[i] < *min ? *min = arr[i] : *min = *min;
        }
        return *min;
    }

    //function to get maximum value in an array
    int getMax(int arr[], int arrSize, int* max) {

        for (int i = 1; i < arrSize; i++) {
            arr[i] > * max ? *max = arr[i] : *max = *max;
        }
        return *max;
    }

    //function to print minimum value in an array
    void printMin(int arr[], int arrSize, int* min) {
        cout << "min is: " << getMin(arr, arrSize, min) << endl;
    }

    //function to print maximum value in an array
    void printMax(int arr[], int arrSize, int* max) {
        cout << "max is: " << getMax(arr, arrSize, max) << endl;
    }



    void incNum(int& number)
    {
        number++;
    }

    int round(double num) {
        num += 0.5;
        return (int)num;
    }


}



#endif // !SDDS_UTILSKAMIL_H

