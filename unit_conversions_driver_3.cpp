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

void input_m_to_ft(float& meters, float& centimeters);
//Precondition: meters >= 0; 100 > centimeters >= 0
//Postcondition: metres and centimeters received the values specified by the user

void convert_m_to_ft(float meters, float centimeters, float& feet, float& inches);
//Precondition: feet >= 0; 12 > inches >= 0; meters >= 0; 100 > centimeters >= 0
//Postcondition: feet and inches receive the calculated conversions with inches < 12.

void output_m_to_ft(float meters, float centimeters, float feet, float inches);
//Precondition: meters >= 0, 12 > centimeters >= 0, feet >= 0, 100 > inches >= 0
//Prints the conversion result on screen.

const float FT_TO_CM = 30.48;
const float	IN_TO_CM = 2.54;
const float M_TO_CM = 100;
const int FT_TO_IN = 12;


int main()
{

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
	cout << endl << feet << "ft " << inches << "in converts to:\n"
		<< meters << "m " << centimeters << "cm\n";
}

void input_m_to_ft(float& meters, float& centimeters)
{
	do
	{
		cout << "Please enter the length in meters and centimeters (positive numbers only, centimeters < 100):\n";
		cin >> meters >> centimeters;
	} while ((meters < 0) || (100 <= centimeters) || (centimeters < 0));
}

void convert_m_to_ft(float meters, float centimeters, float& feet, float& inches)
{
	inches = (meters * M_TO_CM + centimeters) / IN_TO_CM;
	feet = static_cast<int>(inches) / FT_TO_IN;
	inches -= feet * FT_TO_IN;
}

void output_m_to_ft(float meters, float centimeters, float feet, float inches)
{
	cout << endl << meters << "m " << centimeters << "cm converts to:\n"
		<< feet << "ft " << inches << "in\n";
}
