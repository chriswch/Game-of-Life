/*
	404410046, CCU CSIE II
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

#include "GameOfLife.h"



using namespace std;



void specificate(int& w, int& h);   // for pattern 4~100
/*
	Precondition:
	w must be integer
	h must be integer
	Postcondition:
	w will be the input represented width
	h will be the input represented height
*/



int main()
{
	int width, height, times;
	int choice;

	while(1) {
		cout<< "Choose pattern "<< endl;
		cout<< "(1) Glider (100 times)"<< endl;
		cout<< "(2) Lightweight spaceship (100 times)"<< endl;
		cout<< "(3) Pulsar (100 times)"<< endl;
		cout<< "(4) Others (input a number of 4~100 represent the percentage)"<< endl;
		cout<< "(0) Exit"<< endl;
		cout<< "input the number between '(' and ')':"<< endl;
		cin>> choice;

		if (choice>=1 && choice<=3) {			//pattern 1~3
			// set map size
			specificate(width, height);

			GameOfLife world(width, height);
			world.initialize(choice);
			world.display();
			world.proceed(100);
		}
		else if (choice>=4 && choice<=100) {	//pattern 4~100
			GameOfLife world;
			world.initialize(choice);
			world.display();
			world.proceed(100);

			do {
				cout<< "input the number of generation you desire (at least 1):";
				cin>> times;
			} while (times<1);

			world.initialize(choice);
			world.display();
			world.proceed(times);
		}
		else if (choice==0) {
			exit(0);
		}
		else {
			cout<< "Input error."<< endl;
			continue;
		}
	}

	exit(0);
}



void specificate(int& w, int& h)
{
	char tmp;

	while(1) {	// map size
		cout<< "Set own size? (y/n):";  cin>> tmp;

		// default size
		if (tmp!='Y' && tmp!='y') {
			w=80;
			h=23;
			break;
		}

		// customized size
		cout<< "input width:";		cin>> w;
		cout<< "input height:";		cin>> h;
		if (w>=16 && w<=256 && h>=16 && h<=256)
			break;
		else {
			cout<< "input error."<< endl;
			continue;
		}
	}
}