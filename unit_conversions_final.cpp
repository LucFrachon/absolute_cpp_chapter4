/*
Programming project 4. Unit conversions, full program (distances and weights, both directions)
*/

// #define NDEBUG
#include <iostream>
#include <cassert>
#include <string>
#include <cstdlib>
using namespace std;


//Functions and constants for distance conversions:

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

void distance_to_metric();
//Wrapper function that executes a conversion from ft/in to m/cm.
//Precondition: feet >= 0; inches >= 0; meters >= 0; 100 > centimeters >= 0
//Postcondition: meters and centimeters receive the calculated conversions with centimeters < 100. 
//Prints the conversion result on screen.

void distance_to_imperial();
//Wrapper function that executes a conversion from m/cm to ft/in.
//Precondition: feet >= 0; inches >= 0; meters >= 0; 100 > centimeters >= 0
//Postcondition: feet and inches receive the calculated conversions with inches < 12. 
//Prints the conversion result on screen.

void convert_distance();
//Wrapper function that executes either distance_to_metric() or distance_to_imperial() depending on 
//user selection.
//Postcondition: meters and centimeters receive the calculated conversions with centimeters < 100
//OR feet and inches receive the calculated conversions with inches < 12.
//Prints the conversion result on screen.

const float FT_TO_CM = 30.48;
const float	IN_TO_CM = 2.54;
const float M_TO_CM = 100;
const int FT_TO_IN = 12;


//Functions and constants for weight conversions:

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

void convert_weight();
//Wrapper function that executes either weight_to_metric() or weight_to_imperial() depending on 
//user selection.
//Postcondition: kilos and grams receive the calculated conversions with grams < 1000
//OR pounds and ounces receive the calculated conversions with ounces < 16.
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
		cout << "\nEnter 1 to convert distances\n"
			<< "Enter 2 to convert weights\n"
			<< "or enter 3 to exit the program.";
		cin >> ans;

		if (1 == ans)
			convert_distance();
		else if (2 == ans)
			convert_weight();

	} while (ans != 3);

	return 0;
}


//Function definitions for distance conversions:

void input_ft_to_m(float& feet, float& inches)
{
	do
	{
		cout << "\nPlease enter the length in feet and inches (positive numbers only, inches < 12):\n";
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
		cout << "\nPlease enter the length in meters and centimeters (positive numbers only, centimeters < 100):\n";
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

void distance_to_metric()
{
	char ans;
	float feet, inches, meters, centimeters;

	do
	{
		input_ft_to_m(feet, inches);
		assert((feet >= 0) && (12 > inches) && (inches >= 0));
		convert_ft_to_m(feet, inches, meters, centimeters);
		output_ft_to_m(feet, inches, meters, centimeters);

		cout << "\nWould you like to convert another distance in the same direction? (y/n)\t";
		cin >> ans;
	} while (('y' == ans) || ('Y' == ans));
}

void distance_to_imperial()
{
	char ans;
	float feet, inches, meters, centimeters;

	do
	{
		input_m_to_ft(meters, centimeters);
		assert((meters >= 0) && (100 > centimeters) && (centimeters >= 0));
		convert_m_to_ft(meters, centimeters, feet, inches);
		output_m_to_ft(meters, centimeters, feet, inches);

		cout << "\nWould you like to convert another distance in the same direction? (y/n)\t";
		cin >> ans;
	} while (('y' == ans) || ('Y' == ans));
}

void convert_distance()
{
	int ans;

	do
	{
		cout << "\nEnter 1 to convert a distance from imperial to metric\n"
			<< "Enter 2 to convert a distance from metric to imperial\n"
			<< "or enter 3 to return to the main menu.";
		cin >> ans;

		if (1 == ans)
			distance_to_metric();
		else if (2 == ans)
			distance_to_imperial();

	} while (ans != 3);
}


//Function definitions for weight conversions:

void input_lb_to_kg(float& pounds, float& ounces)
{
	do
	{
		cout << "\nPlease enter the weight in pounds and ounces (positive numbers only, ounces < 16):\n";
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
		cout << "\nPlease enter the weight in kilograms and grams (positive numbers only, grams < 1000):\n";
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
		assert((pounds >= 0) && (16 > ounces) && (ounces >= 0));
		convert_lb_to_kg(pounds, ounces, kilos, grams);
		output_lb_to_kg(pounds, ounces, kilos, grams);

		cout << "\nWould you like to convert another weight in the same direction? (y/n)\t";
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
		assert((kilos >= 0) && (1000 > grams) && (grams >= 0));
		convert_kg_to_lb(kilos, grams, pounds, ounces);
		output_kg_to_lb(kilos, grams, pounds, ounces);

		cout << "\nWould you like to convert another weight in the same direction? (y/n)\t";
		cin >> ans;
	} while (('y' == ans) || ('Y' == ans));
}

void convert_weight()
{
	int ans;

	do
	{
		cout << "\nEnter 1 to convert a weight from imperial to metric\n"
			<< "Enter 2 to convert a weight from metric to imperial\n"
			<< "or enter 3 to return to the main menu.";
		cin >> ans;

		if (1 == ans)
			weight_to_metric();
		else if (2 == ans)
			weight_to_imperial();

	} while (ans != 3);
}