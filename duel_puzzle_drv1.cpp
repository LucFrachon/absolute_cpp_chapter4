/*
Programming project 12: Duel puzzle
Driver for shoot
*/

// #define NDEBUG
#include <iostream>
#include <cassert>
#include <cstdlib>
#include <ctime>
using namespace std;

bool shoot(double hit_prob);
//Precondition: target in {1, 2, 3}, 0 <= hit_prob <= 1
//Returns true if the target is still alive (not hit), false otherwise.

const double A_HIT = 1. / 3., B_HIT = 1. / 2., C_HIT = 1.;

srand(static_cast<unsigned int>(time(0))); //Seed the pseudo-random number generator
										   // with a different seed at each execution


int main()
{
	//Assume hit probailities ranked A < B < C
	bool a_alive = true, b_alive = true, c_alive = true;
	char ans;
	bool result;

	do
	{
		if (a_alive)
		{	
			if (c_alive)
			{
				cout << "A shoots C\n";
				c_alive = shoot(A_HIT);
			} 
			else if (b_alive)
			{
				cout << "A shoots B\n";
				b_alive = shoot(A_HIT);
			}
			else
				cout << "A is the last man standing!\n";
		}
		if (b_alive)
		{
			if (c_alive)
			{
				cout << "B shoots C\n";
				c_alive = shoot(B_HIT);
			}
			else if (a_alive)
			{
				cout << "B shoots A\n";
				a_alive = shoot(B_HIT);
			}
			else
				cout << "B is the last man standing!\n";
		}
		if (c_alive)
		{
			if (b_alive)
			{
				cout << "C shoots B\n";
				b_alive = shoot(C_HIT);
			}
			else if (a_alive)
			{
				cout << "C shoots A\n";
				a_alive = shoot(C_HIT);
			}
			else
				cout << "C is the last man standing!\n";
		}

		cout << "A alive: " << a_alive << endl
			<< "B alive: " << b_alive << endl
			<< "C alive: " << c_alive << endl;

		cout << "Run another round?";
		cin >> ans;

	} while (('y' == ans) || ('Y' == ans));

	return 0;
}

bool shoot(double hit_prob)
{
	double shot_prob = (RAND_MAX - rand()) / static_cast<double>(RAND_MAX);
	bool result = (shot_prob > hit_prob);
	cout << "Shot score:\t" << shot_prob << endl 
		<< "Hit probability:\t" << hit_prob << endl 
		<< "Result:\t" << result << endl;
	return result;
}