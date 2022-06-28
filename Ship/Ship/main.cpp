#include  <iostream>
#include <ctime>

using namespace std;

const int rows = 10;
const int elements = 10;
int maxShips = 10;

int matrix[rows][elements];

void clear() {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < elements; j++) {
			matrix[i][j] = 0;
		}
	}
}

void show() {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < elements; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

void setShips() {
	
	int s = 0;
	while (s < maxShips) {
		int x = rand() % rows;
		int y = rand() % elements;
		if (matrix[x][y] != 1) {
			s++;
			matrix[x][y] = 1;
		}
	}
}

bool Attack(int x, int y) {
	if (matrix[x][y] == 1) {
		matrix[x][y] = 2;
		return true;
	}
	return false;
}

int numberOfShips() {

	int c = 0;

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < elements; j++) {
			if (matrix[i][j] == 1)
				c++;
		}
	}
	return c;
}

int main() {

	srand(time(NULL));
	clear();
	setShips();
	int pos1, pos2;
	char prompt;
	while (1) {
		cout << "Please input location: "; cin >> pos1 >> pos2;
		if (Attack(pos1, pos2))
			cout << "You got me!" << endl;
		else
			cout << "Sorry no ship at that position" << endl;
		cout << "Number of left ship is: " << numberOfShips() << endl;
		cout << "Do you want to surrender (y/n)? "; cin >> prompt;
		if (prompt == 'y') 
			break;
	}
	cout << "Game Over!" << endl;
	show();
	/*show();
	cout << "***********************" << endl;
	setShips();
	show();
	Attack(1, 1);
	cout << "***********************" << endl;
	show();*/
	
 
	system("pause");
	return 0;
}