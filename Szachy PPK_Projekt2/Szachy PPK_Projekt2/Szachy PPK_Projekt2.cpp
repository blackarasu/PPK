// Szachy PPK_Projekt2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Chess.h"


int main()
{
	bool finish = false;
	ThreeLastMoves* Move0 = new ThreeLastMoves();
	ThreeLastMoves* currentMove = Move0;
	Cursor c('b'), c1('w');
	char chessBoard[chessLength][chessWidth];
	clearBoard(chessBoard);
	putFigures(chessBoard);
	addToLastMove(chessBoard, currentMove->ChessBoard);
	ThreeLastMoves* lastMove = new ThreeLastMoves();
	currentMove = lastMove;
	do {//game loop
		system("cls");
		drawChessBoard(chessBoard, &c1);
		movePointer(&c1,chessBoard);


	} while (!finish);

    return 0;
}

