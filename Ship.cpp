#include <iostream>
#include <cstdlib>
#include "Ship.h"


void Ship::BoardPlace(int spaces, char place, char board[10][10]) {		//Asked for GetLegalMoves()
	
	bool nullcheck = false;
	int row = rand() % 10;
	int col = rand() % 10;

	while (board[row][col] != '0') {
		row = rand() % 10;
		col = rand() % 10;
	}

	board[row][col] = place;
	int VorH = rand() % 2;
	for (int move = 0; move < spaces; move++) {
		if (VorH == 0) {
			int nextrow = row + 1;
			if (board[nextrow][col] == '0' && nextrow < 10) {
				board[nextrow][col] = place;
				row = nextrow;
				continue;
			}
			else {
				nullcheck = true;
				break;
			}
		}
		else {
			int nextcol = col + 1;
			if (board[row][nextcol] == '0' && nextcol < 10) {
				board[row][nextcol] = place;
				col = nextcol;
				continue;
			}
			else {
				nullcheck = true;
				break;
			}
		}
	}
	if (nullcheck == true) {
		for (int i = 0; i < 10; i++) {						//Loop for printing whats in board array
			for (int j = 0; j < 10; j++) {
				if (board[i][j] == place) {
					board[i][j] = '0';
				}
			}
		}
		BoardPlace(spaces, place, board);
	}
	return;								//void return
};