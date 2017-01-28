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
	saveLastMove(lastMove, &c1, &c);
	do {//game loop
		char possibleMovesPlayer[chessWidth][chessLength];
		clearBoard(possibleMovesPlayer);
		king(&c1, possibleMovesPlayer, &c);
		clearBoard(possibleMovesPlayer);
		if (c1.checkmate) {
			system("cls");
			std::cout << "Gracz 2 wygral partyjke ";
			_getch();
			break;
		}

		do {
			system("cls");
			if (c1.oneMoveBack && c.oneMoveBack) {
				break;
			}
			else if (c.oneMoveBack) {
				if (doYouWantOneStepBack(&c1)) {
					c1.oneMoveBack = true;
				}
				else {
					c.oneMoveBack = false;
				}
				break;
			}
			drawChessBoard(&c1,possibleMovesPlayer,&c);
			movePointer(&c1,possibleMovesPlayer,&c);
		} while (!c1.moveCompleted);

		enemyAntiCheckmate* tmp = new enemyAntiCheckmate();
		c.lastAntiCheckmate = c.enemyFigure;
		delete c.lastAntiCheckmate;
		c.enemyFigure = tmp;
		c.lastAntiCheckmate = tmp;
		clearBoard(possibleMovesPlayer);
		king(&c, possibleMovesPlayer, &c1);
		clearBoard(possibleMovesPlayer);
		if (c.checkmate) {
			system("cls");
			std::cout << "Gracz 1 wygral partyjke ";
			_getch();
			break;
		}

		do {
			system("cls");
			if (c1.oneMoveBack && c.oneMoveBack) {
				break;
			}
			else if (c1.oneMoveBack) {
				if (doYouWantOneStepBack(&c)) {
					c.oneMoveBack = true;
				}
				else {
					c1.oneMoveBack = false;
				}
				break;
			}
			drawChessBoard(&c,possibleMovesPlayer,&c1);
			movePointer(&c,possibleMovesPlayer,&c1);
		} while (!c.moveCompleted);
		tmp = new enemyAntiCheckmate();
		c1.lastAntiCheckmate = c1.enemyFigure;
		delete c1.lastAntiCheckmate;
		c1.enemyFigure = tmp;
		c1.lastAntiCheckmate = tmp;
		if ((c1.oneMoveBack && c.oneMoveBack) && !isItBeginingOfTheGame(lastMove)) {
			oneStepBack(lastMove, &c1, &c);
			c1.oneMoveBack = false;
			c.oneMoveBack = false;
		}
		else if ((c1.oneMoveBack && c.oneMoveBack) && isItBeginingOfTheGame(lastMove)) {
			c1.oneMoveBack = false;
			c.oneMoveBack = false;
		}
		else {
			saveLastMove(lastMove, &c1, &c);
		}
		c1.moveCompleted = false;
		c.moveCompleted = false;
	} while (true);

    return 0;
}

