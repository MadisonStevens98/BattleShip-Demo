
#include <iostream>
#include <string>
#include <time.h>
#include "Ship.h"

using namespace std;
char board[10][10];								//asked for 2D array that is our game board
int n, m, x, y, xcount, misscount;
void print_board();
void hitormiss(int, int);
void recurse();

void recurse() {
	cout << "Please select the x coordinate of where you want to hit (1-10): " << endl;
	cin >> x;
	cout << "Please select the y coordinate of where you want to hit (1-10): " << endl;
	cin >> y;
	y = 10 - y;
	if (x == 0 || y == 0) {
		cout << "You decided to quit, BOO! Try again later!";
		exit(0);
	}
	hitormiss(y, x - 1);
	recurse();
};

void print_board() {									//asked for ShowBoard Function prints out chessboard visual and possible move list
	for (int i = 0; i < 10; i++) {						//Loop for printing whats in board array
		for (int j = 0; j < 10; j++) {
			if (board[i][j] == 'X' || board[i][j] == 'O') {
			cout << board[i][j] << "  ";
			}
			else {
				cout << "0" << "  ";
			}
		}
		cout << endl;
	}
};

//Uncomment this out to test or cheat!

/*void testprint_board() {
	for (int i = 0; i < 10; i++) {						//Loop for printing whats in board array
		for (int j = 0; j < 10; j++) {
			cout << board[i][j] << "  ";
		}
		cout << endl;
	}
};

*/

void hitormiss(int x, int y) {
	if (board[x][y] != '0' && board[x][y] != 'O') {
		board[x][y] = 'X';
		misscount = 0;
		xcount = xcount + 1;
	}
	else {
		board[x][y] = 'O';
		misscount = misscount + 1;
	}
	if (xcount == 17) {
		cout << "You WON!!!";
		system("PAUSE");
		exit(0);
	}
	if (misscount == 15) {
		cout << "You LOSE!!! 15 MISSES IN A ROW!";
		system("PAUSE");
		exit(0);
	}
	print_board();
//	cout << "TEST BOARD\n";
//	testprint_board();
};

int main() {
	for (n = 0; n < 10; n++)
		for (m = 0; m < 10; m++)
		{
			board[n][m] = '0';
		}

	srand(time(NULL));
	Ship frigate;
	frigate.spaces = 1;
	frigate.place = 'F';
	frigate.BoardPlace(frigate.spaces, frigate.place, board);

	Ship sub;
	sub.spaces = 2;
	sub.place = 'S';
	sub.BoardPlace(sub.spaces, sub.place, board);

	Ship destroyer;
	destroyer.spaces = 2;
	destroyer.place = 'D';
	destroyer.BoardPlace(destroyer.spaces, destroyer.place, board);

	Ship battleship;
	battleship.spaces = 3;
	battleship.place = 'B';
	battleship.BoardPlace(battleship.spaces, battleship.place, board);

	Ship aircraft;
	aircraft.spaces = 4;
	aircraft.place = 'A';
	aircraft.BoardPlace(aircraft.spaces, aircraft.place, board);

	cout << "Hi! Welcome to Battleship! Hit any key to start the game. X means you hit O means you missed, \ntype 0 in for x or y to quit! Good Luck!\n";

	xcount = 0;
	misscount = 0;

	print_board();						//calling showboard function
	cout << "TEST BOARD\n";
	//testprint_board();				//UNCOMMENT TO SEE WHERE THE SHIPS ARE, MEANT FOR DEBUGGING
	recurse();
	system("pause");
	return 0;
}