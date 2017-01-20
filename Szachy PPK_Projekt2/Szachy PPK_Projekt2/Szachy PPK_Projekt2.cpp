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

	do {//game loop
		char possibleMovesPlayer1[chessWidth][chessLength];
		clearBoard(possibleMovesPlayer1);
		do {
			system("cls");
			drawChessBoard(&c1,possibleMovesPlayer1,&c);
			movePointer(&c1,possibleMovesPlayer1,&c);
		} while (!c1.moveCompleted);
		

		char possibleMovesPlayer2[chessWidth][chessLength];
		
		clearBoard(possibleMovesPlayer2);
		do {
			system("cls");
			drawChessBoard(&c,possibleMovesPlayer2,&c1);
			movePointer(&c,possibleMovesPlayer2,&c1);
		} while (!c.moveCompleted);

		c1.moveCompleted = false;
		c.moveCompleted = false;
	} while (true);

    return 0;
}

