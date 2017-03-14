#pragma once
#include <algorithm>
#include "Board.h"
#include "Location.h"
class EightQueens
{
private:
	Board board;
	Board threatBoard;
	Location startPoint;

	int initialRow;
	bool safe(int queenNumber, int col);
	void solve(int k);
public:
	EightQueens();
	~EightQueens();

	void solve();
	void resetPieces();
};

