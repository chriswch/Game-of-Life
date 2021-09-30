#ifndef GAME_OF_LIFE_H
#define GAME_OF_LIFE_H



class GameOfLife
{
	public:
		GameOfLife();							//default
		GameOfLife(const int w, const int h);	//initialize size
		void initialize(const int p);			// initialize pattern (1~100)
		void proceed(const int times);			// run "times" times (default 1)
		void display();							//show result
	private:
		int width;				// 16~256
		int height;				// 26~256
		int pattern;			// specify original pattern
		bool cell[256][256];	// map size
};



#endif