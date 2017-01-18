// Szachy PPK_Projekt2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Chess.h"


int main()
{
	bool finish = false;
	LastMoves* Move0 = new LastMoves();
	LastMoves* currentMove = Move0;
	Cursor c('b'), c1('w');
	char chessBoard[chessLength][chessWidth];
	clearBoard(chessBoard);
	putFigures(chessBoard);
	addToLastMove(chessBoard, currentMove->ChessBoard);
	LastMoves* lastMove = new LastMoves();
	currentMove = lastMove;
	do {//game loop
		system("cls");
		drawChessBoard(chessBoard, &c1);
		movePointer(&c1,chessBoard);


	} while (!finish);

    return 0;
}

