/*
Programming project 12: Duel puzzle
Complete program
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

char one_duel();
//Simuates a complete duel, ie. rounds occur until there is only one player left
//Return the identity of the winner.

void update_scores(char winner, int& score_a, int& score_b, int& score_c);
//Precondition: score_a, score_b and score_c all == 0. winner in {'A', 'B', 'C'}.
//Postcondition: score_a, score_b and score_c incremented according to winner.


int main()
{
	srand(static_cast<unsigned int>(time(0))); //Seed the pseudo-random number generator
											   // with a different seed at each execution
											   //Assume hit probabilities ranked A < B < C
	int score_a = 0, score_b = 0, score_c = 0;
	int count = 0, num_duels;

	cout << "How many duels would you like to run?\t";
	cin >> num_duels;

	do
	{
		cout << "\nDUEL " << count;
		char winner = one_duel();
		assert(('A' == winner) || ('B' == winner) || ('C' == winner));
		update_scores(winner, score_a, score_b, score_c);
		cout << endl
			<< score_a << " " << score_b << " " << score_c
			<< winner << " won" << endl;
	} while (++count < num_duels);
	
	cout << "\n FINAL SCORES:\n"
		<< "A won " << score_a << " or " << score_a / static_cast<float>(num_duels) * 100 << "% of duels\n"
		<< "B won " << score_b << " or " << score_b / static_cast<float>(num_duels) * 100 << "% of duels\n"
		<< "C won " << score_c << " or " << score_c / static_cast<float>(num_duels) * 100 << "% of duels\n";

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

void one_round(bool& a_alive, bool& b_alive, bool& c_alive)
{
	if (a_alive)
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


char one_duel()
{
	bool a_alive = true, b_alive = true, c_alive = true;
	bool first_round = true;

	do
	{
		one_round(a_alive, b_alive, c_alive, first_round);
		first_round = false;
	}
	while (a_alive + b_alive + c_alive > 1);

	if (a_alive)
		return 'A';
	if (b_alive)
		return 'B';
	if (c_alive)
		return 'C';
}


void update_scores(char winner, int& score_a, int& score_b, int& score_c)
{
	switch (winner)
	{
		case 'A':
			score_a++;
			break;
		case 'B':
			score_b++;
			break;
		case 'C':
			score_c++;
			break;
	}
}
