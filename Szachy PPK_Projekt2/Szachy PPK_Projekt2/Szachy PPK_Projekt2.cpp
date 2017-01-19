// Szachy PPK_Projekt2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Chess.h"


int main()
{
	bool finish = false;
	LastMoves* Move0 = new LastMoves();
	LastMoves* lastMove = Move0;
	Cursor c('b'), c1('w');
	char chessBoard[chessWidth][chessLength];
	clearBoard(chessBoard);
	putFigures(chessBoard);
	addToLastMove(chessBoard, lastMove->ChessBoard);
	LastMoves* currentMove = new LastMoves();
	lastMove->next = currentMove;
	currentMove->previous = lastMove;
	currentMove->next = nullptr;
	lastMove=currentMove;
	do {//game loop
		char possibleMovesPlayer1[chessWidth][chessLength];
		clearBoard(possibleMovesPlayer1);

		do {
			system("cls");
			drawChessBoard(chessBoard, &c1,possibleMovesPlayer1);
			movePointer(&c1, chessBoard,possibleMovesPlayer1,&c);
		} while (!c1.moveCompleted);

		char possibleMovesPlayer2[chessWidth][chessLength];
		clearBoard(possibleMovesPlayer2);
		do {
			system("cls");
			drawChessBoard(chessBoard, &c,possibleMovesPlayer2);
			movePointer(&c, chessBoard,possibleMovesPlayer2,&c1);
		} while (!c.moveCompleted);

		addToLastMove(chessBoard, lastMove->ChessBoard);
		LastMoves* currentMove = new LastMoves();
		lastMove->next = lastMove;
		currentMove->previous = lastMove;
		currentMove->next = nullptr;
		lastMove = currentMove;
		
	} while (!finish);

    return 0;
}

