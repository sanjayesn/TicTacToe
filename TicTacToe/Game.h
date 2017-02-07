#include "stdafx.h"

class Game {

	public:
		Game(size_t nrows, size_t ncols);
		void drawBoard();
		bool validMove(int pos, std::string turn);
		bool checkVictory(int pos);
		bool checkDraw();

	private:
		bool checkDiag(int pos);
		bool checkRow(int pos);
		bool checkCol(int pos);
		std::string board[3][3];
		size_t nrows, ncols;
};