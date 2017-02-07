// TicTacToe.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;

int main()
{
	Game game = Game(3, 3);
	game.drawBoard();
	string turn = "X";
	int pos;

	while (true) {
		cout << "It is " << turn << "'s turn" << endl;
		cout << "Choose a position for your move: ";
		cin >> pos;

		while (!game.validMove(pos, turn)) {
			cout << "Error: Invalid move. Enter a valid position: ";
			cin >> pos;
		}

		cout << endl;
		game.drawBoard();

		if (game.checkVictory(pos)) {
			cout << turn << " has won!" << endl;
			break;
		}

		else if (game.checkDraw()) {
			cout << "Draw!" << endl;
			break;
		}

		turn = (turn == "X") ? "O" : "X";
	}

	return 0;
}