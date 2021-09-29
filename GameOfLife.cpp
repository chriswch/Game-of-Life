/*
	404410046, CCU CSIE II
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>



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



class GameOfLife
{
	public:
		GameOfLife();							//default
		GameOfLife(const int w, const int h);	//initialize size
		void initialize(const int p);	// initialize pattern (1~100)
		void proceed(const int times);	// run "times" times (default 1)
		void display();		//show result
	private:
		int width;	// 16~256
		int height;	// 26~256
		int pattern;	// specify original pattern
		bool cell[256][256];	// map size
};



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



// default size
GameOfLife::GameOfLife()
{
	width=80;
	height=23;
	fill(&cell[0][0], &cell[height][width], false);
}



// customized size
GameOfLife::GameOfLife(const int w, const int h)
{
	width=w;
	height=h;
	fill(&cell[0][0], &cell[height][width], false);
}



// initialize map
void GameOfLife::initialize(const int p)
{
	if (p>3) {
		int times= width* height* p/ 100;
		int rand_h, rand_w;
		srand(time(NULL));

		while(1) {
			rand_h= rand()%height;
			rand_w= rand()%width;

			if (cell[rand_h][rand_w] == false) {
				cell[rand_h][rand_w]=true;
				times--;
			}

			if(times==0)
				return;
		}
	}
	else {
		int mid_h= height/2;
		int mid_w= width/2;

		switch (p) {
			case 1:
				cell[mid_h-1][mid_w-1] = true;
				cell[mid_h-1][mid_w] = true;
				cell[mid_h-1][mid_w+1] = true;
				cell[mid_h][mid_w-1] = true;
				cell[mid_h+1][mid_w] = true;
			break;
			case 2:
				cell[mid_h-1][mid_w-1] = true;
				cell[mid_h-1][mid_w+2] = true;
				cell[mid_h][mid_w-2] = true;
				cell[mid_h+1][mid_w-2] = true;
				cell[mid_h+1][mid_w+2] = true;
				cell[mid_h+2][mid_w-2] = true;
				cell[mid_h+2][mid_w-1] = true;
				cell[mid_h+2][mid_w] = true;
				cell[mid_h+2][mid_w+1] = true;
			break;
			case 3:
				cell[mid_h-6][mid_w-4] = true;
				cell[mid_h-6][mid_w-3] = true;
				cell[mid_h-6][mid_w+3] = true;
				cell[mid_h-6][mid_w+4] = true;
				cell[mid_h-5][mid_w-3] = true;
				cell[mid_h-5][mid_w-2] = true;
				cell[mid_h-5][mid_w+2] = true;
				cell[mid_h-5][mid_w+3] = true;
				cell[mid_h-4][mid_w-6] = true;
				cell[mid_h-4][mid_w-3] = true;
				cell[mid_h-4][mid_w-1] = true;
				cell[mid_h-4][mid_w+1] = true;
				cell[mid_h-4][mid_w+3] = true;
				cell[mid_h-4][mid_w+6] = true;
				cell[mid_h-3][mid_w-6] = true;
				cell[mid_h-3][mid_w-5] = true;
				cell[mid_h-3][mid_w-4] = true;
				cell[mid_h-3][mid_w-2] = true;
				cell[mid_h-3][mid_w-1] = true;
				cell[mid_h-3][mid_w+1] = true;
				cell[mid_h-3][mid_w+2] = true;
				cell[mid_h-3][mid_w+4] = true;
				cell[mid_h-3][mid_w+5] = true;
				cell[mid_h-3][mid_w+6] = true;
				cell[mid_h-2][mid_w-5] = true;
				cell[mid_h-2][mid_w-3] = true;
				cell[mid_h-2][mid_w-1] = true;
				cell[mid_h-2][mid_w+1] = true;
				cell[mid_h-2][mid_w+3] = true;
				cell[mid_h-2][mid_w+5] = true;
				cell[mid_h-1][mid_w-4] = true;
				cell[mid_h-1][mid_w-3] = true;
				cell[mid_h-1][mid_w-2] = true;
				cell[mid_h-1][mid_w+2] = true;
				cell[mid_h-1][mid_w+3] = true;
				cell[mid_h-1][mid_w+4] = true;
				cell[mid_h+6][mid_w-4] = true;
				cell[mid_h+6][mid_w-3] = true;
				cell[mid_h+6][mid_w+3] = true;
				cell[mid_h+6][mid_w+4] = true;
				cell[mid_h+5][mid_w-3] = true;
				cell[mid_h+5][mid_w-2] = true;
				cell[mid_h+5][mid_w+2] = true;
				cell[mid_h+5][mid_w+3] = true;
				cell[mid_h+4][mid_w-6] = true;
				cell[mid_h+4][mid_w-3] = true;
				cell[mid_h+4][mid_w-1] = true;
				cell[mid_h+4][mid_w+1] = true;
				cell[mid_h+4][mid_w+3] = true;
				cell[mid_h+4][mid_w+6] = true;
				cell[mid_h+3][mid_w-6] = true;
				cell[mid_h+3][mid_w-5] = true;
				cell[mid_h+3][mid_w-4] = true;
				cell[mid_h+3][mid_w-2] = true;
				cell[mid_h+3][mid_w-1] = true;
				cell[mid_h+3][mid_w+1] = true;
				cell[mid_h+3][mid_w+2] = true;
				cell[mid_h+3][mid_w+4] = true;
				cell[mid_h+3][mid_w+5] = true;
				cell[mid_h+3][mid_w+6] = true;
				cell[mid_h+2][mid_w-5] = true;
				cell[mid_h+2][mid_w-3] = true;
				cell[mid_h+2][mid_w-1] = true;
				cell[mid_h+2][mid_w+1] = true;
				cell[mid_h+2][mid_w+3] = true;
				cell[mid_h+2][mid_w+5] = true;
				cell[mid_h+1][mid_w-4] = true;
				cell[mid_h+1][mid_w-3] = true;
				cell[mid_h+1][mid_w-2] = true;
				cell[mid_h+1][mid_w+2] = true;
				cell[mid_h+1][mid_w+3] = true;
				cell[mid_h+1][mid_w+4] = true;
			break;
		}
	}
}



// run generation
void GameOfLife::proceed( int times)
{
	int i, j, alive(0), k;
	int tmp[height][width];

	for (k=1; k<=times; k++) {
		for (i=0; i<height; i++) {
			for (j=0; j<width; j++) {
				alive=0;

				// check how many neighbor alive
				if (i-1>=0 && j-1>=0) {
					if(cell[i-1][j-1] ==true)
						alive++;
				}
				if (i-1>=0 && j>=0) {
					if(cell[i-1][j] ==true)
						alive++;
				}
				if (i-1>=0 && j+1>=0) {
					if(cell[i-1][j+1] ==true)
						alive++;
				}
				if (i>=0 && j-1>=0) {
					if(cell[i][j-1] ==true)
						alive++;
				}
				if (i>=0 && j+1>=0) {
					if(cell[i][j+1] ==true)
						alive++;
				}
				if (i+1>=0 && j-1>=0) {
					if(cell[i+1][j-1] ==true)
						alive++;
				}
				if (i+1>=0 && j>=0) {
					if(cell[i+1][j] ==true)
						alive++;
				}
				if (i+1>=0 && j+1>=0) {
					if(cell[i+1][j+1] ==true)
						alive++;
				}

				tmp[i][j]=alive;
			}
		}

		for (i=0; i<height; i++) {
			for(j=0; j<width; j++) {
				if (tmp[i][j] == 3)				//born
					cell[i][j]=true;
				if (tmp[i][j]<2 || tmp[i][j]>3)	//dead
					cell[i][j]=false;
			}
		}

		display();
		cout<< "generation:"<< k<<endl;
		sleep(0.1);
	}
}



// display world
void GameOfLife::display()
{
	int i, j;

	system("CLS");

	// boundary
	for (i=0; i<width+2; i++)
		cout<< "*";
	cout<< "\n";

	for (i=0; i<height; i++)
	{
		cout<< "*"; // boundary

		// alive with '0', dead with ' '
		for (j=0; j<width; j++) {
			if (cell[i][j]==true)
				cout<<"0";
			else
				cout<<" ";
		}

		cout<< "*"; // boundary
		cout<< "\n";
	}

	// boundary
	for (i=0; i<width+2; i++)
		cout<< "*";
	cout<< "\n";
}
