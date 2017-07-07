/*
Programming project 5. Unit conversions 5 (driver program for input, calculation and output)
*/

// #define NDEBUG
#include <iostream>
#include <cassert>
#include <string>
#include <cstdlib>
using namespace std;

void input_kg_to_lb(float& kilos, float& grams);
//Precondition: kilos >= 0; 1000 > grams >= 0
//Postcondition: kilos and grams received the values specified by the user

void convert_kg_to_lb(float kilos, float grams, float& pounds, float& ounces);
//Precondition: pounds >= 0; ounces >= 0; kilos >= 0; 1000 > grams >= 0
//Postcondition: pounds and ounces receive the calculated conversions with ounces < 16.

void output_kg_to_lb(float kilos, float grams, float pounds, float ounces);
//Precondition: pounds >= 0, 16 > ounces >= 0, kilos >= 0, 1000 > grams >= 0
//Prints the conversion result on screen.

const float KG_TO_LB = 2.2046;
const float OZ_TO_G = 28.3495;
const int	LB_TO_OZ = 16;
const int KG_TO_CM = 1000;

int main()
{
	float pounds, ounces, kilos, grams;
	char ans;

	do
	{
		input_kg_to_lb(kilos, grams);
		assert((kilos >= 0) && (1000 > grams) && (grams >= 0));
		convert_kg_to_lb(kilos, grams, pounds, ounces);
		output_kg_to_lb(kilos, grams, pounds, ounces);

		cout << "Would you like to convert another weight? (y/n)\t";
		cin >> ans;
	} while (('y' == ans) || ('Y' == ans));

	return 0;
}

void input_kg_to_lb(float& kilos, float& grams)
{
	do
	{
		cout << "Please enter the weight in kilograms and grams (positive numbers only, grams < 1000):\n";
		cin >> kilos >> grams;
	} while ((kilos < 0) || (1000 <= grams) || (grams < 0));
}

void convert_kg_to_lb(float kilos, float grams, float& pounds, float& ounces)
{
	ounces = (kilos * KG_TO_CM + grams) / OZ_TO_G;
	pounds = static_cast<int>(ounces) / LB_TO_OZ;
	ounces -= pounds *	LB_TO_OZ;
}

void output_kg_to_lb(float kilos, float grams, float pounds, float ounces)
{
	cout << endl << kilos << "kg " << grams << "g converts to:\n"
		<< pounds << "lb " << ounces << "oz\n";
}