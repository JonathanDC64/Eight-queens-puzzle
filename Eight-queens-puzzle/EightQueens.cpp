#include "EightQueens.h"


void EightQueens::resetPieces()
{
	for (int i = 0; i < 8; i++)
		board.setPiece(0, i);
}

EightQueens::EightQueens() : startPoint(0, 0)
{

}


EightQueens::~EightQueens()
{
}

bool EightQueens::safe(int queenNumber, int col)
{
	for (int i = 0; i < queenNumber; i++)
	{
		bool other = board.isSet(col, i);
		if (board.isSet(col, i) ||
			board.isSet(col - (queenNumber - i), i) ||
			board.isSet(col + (queenNumber - i), i))
			return false;
	}
	return true;
}

void EightQueens::solve()
{
	solve(0);
}

void EightQueens::solve(int k) 
{
	if (k == 8)
	{
		board.printBoard();
	}
	else
	{
		for (int i = 0; i < 8; i++)
		{
			if (safe(k,i))
			{
				board.setPiece(i,k);
				solve(k + 1);
			}
		}

	}
}

//#include "EightQueens.h"
//
//void EightQueens::setPieceThreats(Location & location)
//{
//	board.setPiece(location.x, location.y);
//
//	//horizontal -> [--]
//	for (int i = 0; i < 8; i++)
//		threatBoard.setPiece(i, location.y);
//
//	//vertical -> [ | ]
//	for (int i = 0; i < 8; i++)
//		threatBoard.setPiece(location.x, i);
//
//	////diagonals
//
//	//diagonal -> [ \ ]
//	int startY = std::max(location.y - location.x, 0);
//
//	int startX = std::max(location.x - location.y, 0);
//
//	for (int i = startY; i < 8; i++)
//		for (int j = startX++; j < startX && j < 8; j++)
//			threatBoard.setPiece(j, i);
//
//	//diagonal -> [ / ]
//	startY = std::min(location.x + location.y, 7);
//
//	startX = std::max((location.x - 7) + location.y, 0);
//
//	for (int i = startY; i >= 0; i--)
//		for (int j = startX++; j < startX && j < 8; j++)
//			threatBoard.setPiece(j, i);
//}
//
//void EightQueens::resetPieces()
//{
//	for (int i = 0; i < 8; i++)
//		board.setPiece(0, i);
//}
//
//EightQueens::EightQueens() : startPoint(0, 0)
//{
//	resetPieces();
//	currentRow = 0;
//}
//
//
//EightQueens::~EightQueens()
//{
//}
//
//
//void EightQueens::solve()
//{
//	int count = 1;
//	while (currentRow <= 7)
//	{
//		for (int k = 0; k < 8; k++)
//		{
//			for (int i = 0; i < 8; i++)
//			{
//				if (i == currentRow)
//					continue;
//
//				for (int j = 0; j < 8; j++)
//				{
//					
//				}
//			}
//
//			if(k + 1 < 8)
//				board.movePiece(k, currentRow, k + 1, currentRow);
//		}
//
//		if (board.pieceCount() == 8)
//		{
//			printf("#%d\n", count++);
//			board.printBoard();
//		}
//
//		currentRow++;
//
//		board.clear();
//		resetPieces();
//	}
//}

/*
void EightQueens::solve()
{
	int count = 1;
	while (startPoint.y != 8)
	{
		setPieceThreats(Location(startPoint.x, startPoint.y));
		for (int i = 0; i < 8 && board.pieceCount() < 8; i++)
		{
			for (int j = 0; j < 8 && board.pieceCount() < 8; j++)
			{
				if (!threatBoard.isSet(j, i))
				{
					setPieceThreats(Location(j, i));
				}
			}
		}

		if (board.pieceCount() == 8)
		{
			printf("#%d\n", count++);
			board.printBoard();
		}
		
		
		board.clear();
		threatBoard.clear();


		startPoint.x = (startPoint.x + 1) % 7;
		startPoint.y = (startPoint.x == 0) ? startPoint.y + 1 : startPoint.y;
	}
	
	
}
*/

