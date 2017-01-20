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
		king(&c1, possibleMovesPlayer1, &c);
		clearBoard(possibleMovesPlayer1);
		if (c1.checkmate) {
			system("cls");
			std::cout << "Gracz 2 wygral partyjke ";
			_getch();
			break;
		}

		do {
			system("cls");
			drawChessBoard(&c1,possibleMovesPlayer1,&c);
			movePointer(&c1,possibleMovesPlayer1,&c);
		} while (!c1.moveCompleted);
		

		char possibleMovesPlayer2[chessWidth][chessLength];
		clearBoard(possibleMovesPlayer2);
		king(&c, possibleMovesPlayer2, &c1);
		clearBoard(possibleMovesPlayer2);
		if (c.checkmate) {
			system("cls");
			std::cout << "Gracz 1 wygral partyjke ";
			_getch();
			break;
		}
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

