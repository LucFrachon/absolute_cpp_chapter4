/*
Programming project 4. Unit conversions 1 (driver program for input, calculation and output)
*/

// #define NDEBUG
#include <iostream>
#include <cassert>
#include <string>
#include <cstdlib>
using namespace std;

void input_ft_to_m(float& feet, float& inches);
//Precondition: feet >= 0; 12 > inches >= 0
//Postcondition: feet and inches received the values specified by the user

void convert_ft_to_m(float feet, float inches, float& meters, float& centimeters);
//Precondition: feet >= 0; inches >= 0; meters >= 0; 100 > centimeters >= 0
//Postcondition: meters and centimeters receive the calculated conversions with centimeters < 100.

void output_ft_to_m(float feet, float inches, float meters, float centimeters);
//Precondition: feet >= 0, 12 > inches >= 0, meters >= 0, 100 > centimeters >= 0
//Prints the conversion result on screen.

const float FT_TO_CM = 30.48;
const float	IN_TO_CM = 2.54;
const int M_TO_CM = 100;

int main()
{
	float feet, inches, meters, centimeters;
	char ans;

	do
	{
		input_ft_to_m(feet, inches);
		assert((feet >= 0) && (12 > inches) && (inches >= 0));
		convert_ft_to_m(feet, inches, meters, centimeters);
		output_ft_to_m(feet, inches, meters, centimeters);

		cout << "Would you like to convert another distance? (y/n)\t";
		cin >> ans;
	} while (('y' == ans) || ('Y' == ans));

	return 0;
}

void input_ft_to_m(float& feet, float& inches)
{
	do
	{
		cout << "Please enter the length in feet and inches (positive numbers only, inches < 12):\n";
		cin >> feet >> inches;
	} while ((feet < 0) || (12 <= inches) || (inches < 0));
}

void convert_ft_to_m(float feet, float inches, float& meters, float& centimeters)
{
	centimeters = feet * FT_TO_CM + inches * IN_TO_CM;
	meters = static_cast<int>(centimeters) / M_TO_CM;
	centimeters -= meters * M_TO_CM;
}

void output_ft_to_m(float feet, float inches, float meters, float centimeters)
{
	cout << endl <<  feet << "ft " << inches << "in converts to:\n"
		<< meters << "m " << centimeters << "cm\n";
}