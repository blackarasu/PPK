#pragma once
#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include "Const values.h"

void clearBoard(char chessboard[chessWidth][chessLength]);
void startBlackPawns(char chessBoard[chessWidth][chessLength]);
void startBlackTowers(char chessBoard[chessWidth][chessLength]);
void startBlackQueens(char chessBoard[chessWidth][chessLength]);
void startBlackJumpers(char chessBoard[chessWidth][chessLength]);
void startBlackKings(char chessBoard[chessWidth][chessLength]);
void startBlackBishops(char chessBoard[chessWidth][chessLength]);
void startWhitePawns(char chessBoard[chessWidth][chessLength]);
void startWhiteTowers(char chessBoard[chessWidth][chessLength]);
void startWhiteQueens(char chessBoard[chessWidth][chessLength]);
void startWhiteJumpers(char chessBoard[chessWidth][chessLength]);
void startWhiteKings(char chessBoard[chessWidth][chessLength]);
void startWhiteBishops(char chessBoard[chessWidth][chessLength]);
void putBlackFigures(char chessBoard[chessWidth][chessLength]);
void putWhiteFigures(char chessBoard[chessWidth][chessLength]);
void putFigures(char chessBoard[chessWidth][chessLength]);

void drawMenu();

struct enemyAntiCheckmate {
	int x, y, antiX, antiY;
	enemyAntiCheckmate* next;
	~enemyAntiCheckmate() {
		delete next;
	}
};

struct Cursor {
	enemyAntiCheckmate *enemyFigure,*lastAntiCheckmate;
	char enemyFiguresPositions[chessWidth][chessLength];
	char cursorColor;
	int x, y, chosenX, chosenY, enemyKingX,enemyKingY;
	bool check;
	bool checkmate;
	bool chosen;
	bool moveCompleted;
	bool oneMoveBack;
	Cursor(char color) {
		enemyFigure = new enemyAntiCheckmate();
		lastAntiCheckmate = enemyFigure;
		cursorColor = color;
		check = false;
		chosenX = -1;
		chosenY = -1;
		chosen = false;
		moveCompleted = false;
		oneMoveBack = false;
		checkmate = false;
		enemyKingX = KING_POSITION;
		clearBoard(enemyFiguresPositions);
		if (color == 'b') {
			putWhiteFigures(enemyFiguresPositions);
			enemyKingY = whiteSecondLane;
			x = 0;
			y = 7;		
		}
		if (color == 'w') {
			putBlackFigures(enemyFiguresPositions);
			enemyKingY = blackSecondLane;
			x = 0;
			y = 0;
		}
	}
};
struct LastMoves {
	char white[chessLength][chessWidth];
	int whitePointerX, whitePointerY;
	int blackPointerX, blackPointerY;
	char black[chessLength][chessWidth];
	LastMoves* previous;
	LastMoves* next;

};

bool CheckMate(char possibleKingMoves[chessWidth][chessLength]);
void drawChessBoard( Cursor* pointer, char possibleMoves[chessWidth][chessLength],Cursor* enemyCursor);
void setChosen(Cursor* pointer);
void notChosen(Cursor* pointer);
void movePointer(Cursor* pointer, char possibleMoves[chessWidth][chessLength], Cursor* enemyCursor);
void drawPossibleMoves(Cursor* pointer, char* figure, char possibleMoves[chessWidth][chessLength], Cursor* enemyCursor);
void bishop(Cursor * pointer,  char possibleMoves[chessWidth][chessLength], Cursor* enemyCursor);
void jumper(Cursor * pointer, char possibleMoves[chessWidth][chessLength], Cursor* enemyCursor);
void PossibleMovesOfKing(Cursor * pointer, char possibleMoves[chessWidth][chessLength], Cursor* enemyCursor, char allEnemyPossibleMoves[chessWidth][chessLength]);
void king(Cursor * pointer, char possibleMoves[chessWidth][chessLength], Cursor* enemyCursor);
void findAllEnemyPossibleMoves(Cursor* pointer, int& checkCounter, char allEnemyPossibleMoves[chessWidth][chessLength], Cursor* enemyCursor, char oneEnemyPossibleMoves[chessWidth][chessLength]);
void addToEnemiesPossibleForKing(char oneFigure[chessWidth][chessLength], char allFigures[chessWidth][chessLength]);
bool findMyMoves(Cursor* pointer, char allEnemyPossibleMoves[chessWidth][chessLength], Cursor* enemyCursor);
bool whetherPossibleMoves(char myFigurePossibleMoves[chessWidth][chessLength], char enemyCheckableFigurePossibleMoves[chessWidth][chessLength], Cursor* enemyCursor);
void queen(Cursor * pointer, char possibleMoves[chessWidth][chessLength], Cursor* enemyCursor);
void pawnAttack(Cursor * pointer, char possibleMoves[chessWidth][chessLength], Cursor* enemyCursor);
void pawn(Cursor * pointer, char possibleMoves[chessWidth][chessLength], Cursor* enemyCursor);
void tower(Cursor * pointer, char possibleMoves[chessWidth][chessLength], Cursor* enemyCursor);
bool isThisFigureAntiCheckmate(Cursor* pointer, enemyAntiCheckmate* guider);
void saveLastMove(LastMoves*& currentMove, Cursor* whitePlayer, Cursor* blackPlayer);
void copyTable(char original[chessWidth][chessLength], char copy[chessWidth][chessLength]);
bool isItBeginingOfTheGame(LastMoves* currentMove);
void oneStepBack(LastMoves*& currentMove, Cursor* whitePlayer, Cursor* blackPlayer);
bool doYouWantOneStepBack(Cursor* playerWhoIsAsked);