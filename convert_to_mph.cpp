/* Chapter 4, Programming project 13
Conversion to mph from time per mile or from kph
using overloading
*/


#define NDEBUG
#include <iostream>
#include <cstdlib>

using namespace std;

const double MI_TO_KM = 1.609;

int menu_choice();
//Input menu giving a choice between converting from minutes / seconds or from kph.
//Returns: 'M' for min/sec, 'K' for kph, 'E' for exit.

double convert_to_mph(int minutes, int seconds);
//Input: Time over a mile, in minutes and seconds
//Return: Speed in mph
//Precondition: none.

double convert_to_mph(double kph);
//Input: Speed in kph
//Return: Speed in mph
//Precondition: none.


int main()
{
	int minutes, seconds;
	double kph;
	char choice;

	choice = menu_choice();

	while (choice != 'E')
	{
		if (choice == 'M')
		{
			cout << "\nTime in minutes, seconds: " << endl;
			cin >> minutes >> seconds;
			cout << endl;
			cout << convert_to_mph(minutes, seconds) << endl;
		}
		else if(choice == 'K')
		{
			cout << "\nSpeed in kph: " << endl;
			cin >> kph;
			cout << endl;
			cout << convert_to_mph(kph) << endl;
		}
		choice = menu_choice();
	} 

	return 0;
}


int menu_choice()
{
	int choice;

	do
	{
		cout << "\nConvert from minutes and seconds (1), from kph (2) or exit (3)?\n";
		cin >> choice;
	} while ((choice != 1) && (choice != 2) && (choice != 3));

	if (choice == 1)
		return 'M';
	else if (choice == 2)
		return 'K';
	else
		return 'E';
}

double convert_to_mph(int minutes, int seconds) 
{
	double mph;
	mph = 60. / (minutes + seconds / 60.);

	return mph;
}

double convert_to_mph(double kph)
{
	double mph;
	mph = kph / MI_TO_KM;

	return mph;
}

