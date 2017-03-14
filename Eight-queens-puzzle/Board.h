#pragma once
#include <iostream>
#define uchar unsigned char
#define SET 1
#define UNSET 0
class Board
{
private:
	short boardSize = 8 * 8;
	uchar board[8][8];
	short numPieces;
public:
	Board();
	Board(const Board& board);
	~Board();
	void setPiece(int x, int y);
	void unsetPiece(int x, int y);
	bool movePiece(int fromX, int fromY, int toX, int toY);
	bool isSet(int x, int y);
	short pieceCount();
	void clear();
	void printBoard();
};

