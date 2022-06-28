#include <iostream>
#include <deque>
using namespace std;

class cPlayer {
public:
	int x, y;
	cPlayer(int width) { x = width / 2; y = 0; }

};

class cLane {
private:
	deque<bool> cars;
public:
	cLane(int width) {
		for (int i = 0; i < width; i++) 
			cars.push_front(true); //no cars at the beginning		
	}

	void move() {
		if (rand() % 10 == 1)
			cars.push_front(true); // if 1 go ahead next steap
		else
			cars.push_front(false); // if 0 dont make anything
		cars.pop_back(); // remove guy
	}

	bool checkPos(int pos) { return cars[pos]; } //check if 1 on deque;
};

class cGame {
private:
	bool quit;
public:
	void draw() {

	}

	void input() {

	}

	void logic() {

	}

	void run() {
		while (!quit) {
			input();
			draw();
			logic();
		}
	}
};


int main() {

	cLane lane1(10);
	for (int i = 0; i < 20; i++) {
		if (lane1.checkPos(i))
			cout << "1";
		else
			cout << "0";
	}


	getchar();
	return 0;
}
