/*
Programming project 4. Unit conversions 4 (driver program for input, calculation and output)
*/

// #define NDEBUG
#include <iostream>
#include <cassert>
#include <string>
#include <cstdlib>
using namespace std;

void input_lb_to_kg(float& pounds, float& ounces);
//Precondition: pounds >= 0; 16 > ounces >= 0
//Postcondition: pounds and ounces received the values specified by the user

void convert_lb_to_kg(float pounds, float ounces, float& kilos, float& grams);
//Precondition: pounds >= 0; ounces >= 0; kilos >= 0; 1000 > grams >= 0
//Postcondition: kilos and grams receive the calculated conversions with grams < 1000.

void output_lb_to_kg(float pounds, float ounces, float kilos, float grams);
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
		input_lb_to_kg(pounds, ounces);
		assert((pounds >= 0) && (16 > ounces) && (ounces >= 0));
		convert_lb_to_kg(pounds, ounces, kilos, grams);
		output_lb_to_kg(pounds, ounces, kilos, grams);

		cout << "Would you like to convert another weight? (y/n)\t";
		cin >> ans;
	} while (('y' == ans) || ('Y' == ans));

	return 0;
}

void input_lb_to_kg(float& pounds, float& ounces)
{
	do
	{
		cout << "Please enter the weight in pounds and ounces (positive numbers only, ounces < 16):\n";
		cin >> pounds >> ounces;
	} while ((pounds < 0) || (16 <= ounces) || (ounces < 0));
}

void convert_lb_to_kg(float pounds, float ounces, float& kilos, float& grams)
{
	grams = KG_TO_CM * pounds / KG_TO_LB + ounces * OZ_TO_G;
	kilos = static_cast<int>(grams) / KG_TO_CM;
	grams -= kilos * KG_TO_CM;
}

void output_lb_to_kg(float pounds, float ounces, float kilos, float grams)
{
	cout << endl << pounds << "lb " << ounces << "oz converts to:\n"
		<< kilos << "kg " << grams << "g\n";
}