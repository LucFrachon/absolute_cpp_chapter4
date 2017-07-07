/*
Programming project 4. Unit conversions 6 (driver program for input, calculation both ways and output)
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

void input_kg_to_lb(float& kilos, float& grams);
//Precondition: kilos >= 0; 1000 > grams >= 0
//Postcondition: kilos and grams received the values specified by the user

void convert_kg_to_lb(float kilos, float grams, float& pounds, float& ounces);
//Precondition: pounds >= 0; ounces >= 0; kilos >= 0; 1000 > grams >= 0
//Postcondition: pounds and ounces receive the calculated conversions with ounces < 16.

void output_kg_to_lb(float kilos, float grams, float pounds, float ounces);
//Precondition: pounds >= 0, 16 > ounces >= 0, kilos >= 0, 1000 > grams >= 0
//Prints the conversion result on screen.


void weight_to_metric();
////Wrapper function that executes a conversion from lb/oz to kg/g.
//Postcondition: kilos and grams receive the calculated conversions with grams < 1000. 
//Prints the conversion result on screen.

void weight_to_imperial();
////Wrapper function that executes a conversion from kg/g to lb/oz.
//Postcondition: pounds and ounces receive the calculated conversions with ounces < 16. 
//Prints the conversion result on screen.


const float KG_TO_LB = 2.2046;
const float OZ_TO_G = 28.3495;
const int	LB_TO_OZ = 16;
const int KG_TO_CM = 1000;



int main()
{
	int ans;

	do
	{
		cout << "Enter 1 to convert a weight from imperial to metric\n"
			<< "Enter 2 to convert a weight from metric to imperial\n"
			<< "or enter 3 to exit the program.";
		cin >> ans;

		if (1 == ans)
			weight_to_metric();
		else if (2 == ans)
			weight_to_imperial();

	} while (ans != 3);

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

void weight_to_metric()
{
	char ans;
	float pounds, ounces, kilos, grams;

	do
	{
		input_lb_to_kg(pounds, ounces);
		assert((pounds >= 0) && (16 > ounces) && (ounces>= 0));
		convert_lb_to_kg(pounds, ounces, kilos, grams);
		output_lb_to_kg(pounds, ounces, kilos, grams);

		cout << "Would you like to convert another weight in the same direction? (y/n)\t";
		cin >> ans;
	} while (('y' == ans) || ('Y' == ans));
}

void weight_to_imperial()
{
	char ans;
	float pounds, ounces, kilos, grams;

	do
	{
		input_kg_to_lb(kilos, grams);
		assert((kilos >= 0) && (1000 > grams) && (grams>= 0));
		convert_kg_to_lb(kilos, grams, pounds, ounces);
		output_kg_to_lb(kilos, grams, pounds, ounces);

		cout << "Would you like to convert another weight in the same direction? (y/n)\t";
		cin >> ans;
	} while (('y' == ans) || ('Y' == ans));
}