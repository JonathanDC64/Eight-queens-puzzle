#include "Board.h"



Board::Board()
{
	clear();
}

Board::Board(const Board & board)
{
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			this->board[j][i] = board.board[j][i];
}


Board::~Board()
{
}

void Board::setPiece(int x, int y)
{
	if (board[y][x] != SET)
	{
		board[y][x] = SET;
		numPieces++;
	}
}

void Board::unsetPiece(int x, int y)
{
	if (board[y][x] != UNSET)
	{
		board[y][x] = UNSET;
		numPieces--;
	}
}

bool Board::movePiece(int fromX, int fromY, int toX, int toY)
{
	if (isSet(fromX, fromY))
	{
		unsetPiece(fromX, fromY);
		setPiece(toX, toY);
		return true;
	}
	return false;
}

bool Board::isSet(int x, int y)
{
	return board[y][x] == SET;
}

short Board::pieceCount()
{
	return numPieces;
}

void Board::clear()
{
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			board[i][j] = 0;
	numPieces = 0;
}

void Board::printBoard()
{
	printf("\n############################\n");
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
			printf(
				"%s[%s]%s", 
				(j == 0 ? "# " : ""),
				(board[i][j] == SET ? "O" : " "),
				(j == 7 ? " #" : "") 
			);

		printf("\n");
	}
	printf("############################\n");
}
