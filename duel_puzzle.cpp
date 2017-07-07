/*
Programming project 12: Duel puzzle
*/

// #define NDEBUG
#include <iostream>
#include <cassert>
#include <string>
#include <cstdlib>
using namespace std;



bool a_alive = true, b_alive = true, c_alive = true;

int main()
{

	do
	{
		one_round(a_alive, b_alive, c_alive);
	} while (a_alive + b_alive + c_alive > 1)

}
