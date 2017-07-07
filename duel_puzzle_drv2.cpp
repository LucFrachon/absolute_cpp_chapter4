/*
Programming project 12: Duel puzzle
Driver for one_round
*/

// #define NDEBUG
#include <iostream>
#include <cassert>
#include <cstdlib>
#include <ctime>  //for time()
using namespace std;

const double A_HIT = 1. / 3., B_HIT = 1. / 2., C_HIT = 1.;

bool shoot(double hit_prob);
//Precondition: target in {1, 2, 3}, 0 <= hit_prob <= 1
//Returns true if the target is still alive (not hit), false otherwise.

void one_round(bool& a_alive, bool& b_alive, bool& c_alive, bool first_round);
//Simulates a round of duel (ie. each player shoots once, if they are still able to)
//Pre-condition: Hit probabilities are ranked A < B < C.
//Post-condition: a_alivem b_alive and c_alive are updated depending on the outcome of the round.


int main()
{
	srand(static_cast<unsigned int>(time(0))); //Seed the pseudo-random number generator
											   // with a different seed at each execution
	//Assume hit probabilities ranked A < B < C
	bool a_alive = true, b_alive = true, c_alive = true;
	char ans;
	bool first_round = false;

	do
	{
		one_round(a_alive, b_alive, c_alive, first_round);
	} while (a_alive + b_alive + c_alive > 1);

	if (a_alive)
		cout << "A is the last man standing!\n";
	if (b_alive)
		cout << "B is the last man standing!\n";
	if (c_alive)
		cout << "C is the last man standing!\n";

	return 0;
}

bool shoot(double hit_prob)
{
	double shot_prob = (RAND_MAX - rand()) / static_cast<double>(RAND_MAX);
	bool still_alive = (shot_prob > hit_prob);
	cout << "Shot score:\t" << shot_prob << endl
		<< "Hit probability:\t" << hit_prob << endl
		<< "Still alive?\t" << still_alive << endl;
	return still_alive;
}

void one_round(bool& a_alive, bool& b_alive, bool& c_alive, bool first_round)
{
	if (a_alive && !first_round)
	{
		if (c_alive)
		{
			cout << "\nA shoots C\n";
			c_alive = shoot(A_HIT);
		}
		else
		{
			cout << "\nA shoots B\n";
			b_alive = shoot(A_HIT);
		}
	}
	if (b_alive)
	{
		if (c_alive)
		{
			cout << "\nB shoots C\n";
			c_alive = shoot(B_HIT);
		}
		else
		{
			cout << "\nB shoots A\n";
			a_alive = shoot(B_HIT);
		}
	}
	if (c_alive)
	{
		if (b_alive)
		{
			cout << "\nC shoots B\n";
			b_alive = shoot(C_HIT);
		}
		else
		{
			cout << "\nC shoots A\n";
			a_alive = shoot(C_HIT);
		}
	}
		cout << "\nA alive: " << a_alive << endl
		<< "B alive: " << b_alive << endl
		<< "C alive: " << c_alive << endl;
}