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
void addToLastMove(char chess[chessWidth][chessLength], char copyChess[chessWidth][chessLength]);
void clearX(char chessBoard[chessWidth][chessLength]);


struct Cursor {
	char enemyFiguresPositions[chessWidth][chessLength];
	char cursorColor;
	int x, y, chosenX, chosenY;
	bool chosen;
	bool moveCompleted;
	bool oneMoveBack;
	Cursor(char color) {
		cursorColor = color;
		chosenX = -1;
		chosenY = -1;
		chosen = false;
		moveCompleted = false;
		oneMoveBack = false;
		clearBoard(enemyFiguresPositions);
		if (color == 'b') {
			putWhiteFigures(enemyFiguresPositions);
			x = 0;
			y = 7;		
		}
		if (color == 'w') {
			putBlackFigures(enemyFiguresPositions);
			x = 0;
			y = 0;
		}
	}
};
struct LastMoves {
	char ChessBoard[chessLength][chessWidth];
	LastMoves* previous;
	LastMoves* next;
};

void drawChessBoard(char chess[chessWidth][chessLength], Cursor* pointer, char possibleMoves[chessWidth][chessLength]);
void setChosen(Cursor* pointer);
void notChosen(Cursor* pointer);
void movePointer(Cursor* pointer, char chessBoard[chessWidth][chessLength], char possibleMoves[chessWidth][chessLength], Cursor* enemyCursor);
void drawPossibleMoves(Cursor* pointer, char* figure, char chessBoard[chessWidth][chessLength], char possibleMoves[chessWidth][chessLength]);
void bishop(Cursor * pointer, char chessBoard[chessWidth][chessLength], char possibleMoves[chessWidth][chessLength]);
void jumper(Cursor * pointer, char chessBoard[chessWidth][chessLength], char possibleMoves[chessWidth][chessLength]);
void king(Cursor * pointer, char chessBoard[chessWidth][chessLength], char possibleMoves[chessWidth][chessLength]);
void queen(Cursor * pointer, char chessBoard[chessWidth][chessLength], char possibleMoves[chessWidth][chessLength]);
void pawn(Cursor * pointer, char chessBoard[chessWidth][chessLength], char possibleMoves[chessWidth][chessLength]);
void tower(Cursor * pointer, char chessBoard[chessWidth][chessLength], char possibleMoves[chessWidth][chessLength]);
