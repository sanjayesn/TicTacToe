#include "stdafx.h"
#define ROWS 3;
#define COLS 3;

using namespace std;

Game::Game(size_t nrows, size_t ncols)
	: nrows(nrows), ncols(ncols)
{
	/* Populate the board array with spaces */
	for (size_t i = 0; i < nrows; i++) {
		for (size_t j = 0; j < ncols; j++) {
			board[i][j] = " ";
		}
	}
}

void Game::drawBoard()
{
	for (size_t i = 0; i < nrows; i++) {
		for (size_t j = 0; j < ncols; j++) {
			if (j != ncols - 1) {
				cout << board[i][j] << "|";
			}
			else {
				cout << board[i][j];
				cout << "       " << i * 3 << "|" << i * 3 + 1 << "|" << i * 3 + 2 << endl;
			}
		}

		if (i != nrows - 1) {
			cout << "-----";
			cout << "       -----" << endl;
		}
	}
	cout << endl;
}

bool Game::validMove(int pos, string turn)
{
	/* Move is invalid if position is invalid or already contains a value */
	if (pos < 0 || pos > 8) {
		return false; 
	}

	int row = pos / COLS;
	int col = pos - row * COLS;

	if (board[row][col] != " ") {
		return false; 
	}

	board[row][col] = turn;
	
	return true;
}

bool Game::checkVictory(int pos)
{
	/* Only most recent move must be checked */
	if (pos % 2 == 0) {
		return checkDiag(pos) || checkRow(pos) || checkCol(pos);
	}

	else {
		return checkRow(pos) || checkCol(pos);
	}
	return false;
}

bool Game::checkDraw()
{
	for (size_t i = 0; i < nrows; i++) {
		for (size_t j = 0; j < ncols; j++) {
			if (board[i][j] == " ") {
				return false;
			}
		}
	}

	return true;
}

bool Game::checkDiag(int pos)
{
	bool won = true;

	if (pos == 0 || pos == 4 || pos == 8) {
		if (board[0][0] != board[1][1] || board[0][0] != board[2][2]) {
			won = false;
		}
	}

	if (pos == 2 || pos == 4 || pos == 6) {
		if (board[0][2] != board[1][1] || board[0][2] != board[2][0]) {
			won = false;
		}

		else {
			won = true;
		}
	}

	return won;
}

bool Game::checkRow(int pos)
{
	int row = pos / COLS;
	return board[row][0] == board[row][1] && board[row][0] == board[row][2];
}

bool Game::checkCol(int pos)
{
	int row = pos / COLS;
	int col = pos - row * COLS;
	return board[0][col] == board[1][col] && board[0][col] == board[2][col];
}

/*
 x|o|x    0 1 2   
 -----    3 4 5   
 x|x|o    6 7 8   
 -----
 o|o|x
 
*/