#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

float addition(float num1, float num2) {
    return(num1 + num2);
}

float subtraction(float num1, float num2) {
    return(num1 - num2);
}

float division(float num1, float num2) {
    return(num1 / num2);
}

float multiplication(float num1, float num2) {
    return(num1 * num2);
}


int main() {

    float num1, num2;
    int option;

    cout << "Enter the first number : ";
    cin >> num1;
    cout << "Enter the first number : ";
    cin >> num2;

    cout << "\nOperations\n" << endl;
    cout << "1- Addition" << endl;
    cout << "2- Subtraction" << endl;
    cout << "3- Division" << endl;
    cout << "4- Multiplication" << endl << endl;

    cout << "Select the operation (1-4) : ";
    cin >> option;



    switch (option)
    {
    case 1: cout << "Addition = " << addition(num1, num2) << endl; break;
    case 2: cout << "Subtraction = " << subtraction(num1, num2) << endl; break;
    case 3: cout << "Division = " << division(num1, num2) << endl; break;
    case 4: cout << "Multiplication = " << multiplication(num1, num2) << endl; break;
    }


    return 0;
}

