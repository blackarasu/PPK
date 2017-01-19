#pragma once
#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include "Const values.h"

struct Cursor {
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
		if (color == 'b') {
			x = 0;
			y = 7;		
		}
		if (color == 'w') {
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

void clearBoard(char chessboard[chessWidth][chessLength]);
void startPawns(char chessBoard[chessWidth][chessLength]);
void startTowers(char chessBoard[chessWidth][chessLength]);
void startQueens(char chessBoard[chessWidth][chessLength]);
void startJumpers(char chessBoard[chessWidth][chessLength]);
void startKings(char chessBoard[chessWidth][chessLength]);
void startBishops(char chessBoard[chessWidth][chessLength]);
void putFigures(char chessBoard[chessWidth][chessLength]);
void drawChessBoard(char chess[chessWidth][chessLength], Cursor* pointer, char possibleMoves[chessWidth][chessLength]);
void drawMenu();
void addToLastMove(char chess[chessWidth][chessLength], char copyChess[chessWidth][chessLength]);
void clearX(char chessBoard[chessWidth][chessLength]);
void setChosen(Cursor* pointer);
void notChosen(Cursor* pointer);
void movePointer(Cursor* pointer, char chessBoard[chessWidth][chessLength], char possibleMoves[chessWidth][chessLength]);
void drawPossibleMoves(Cursor* pointer, char* figure, char chessBoard[chessWidth][chessLength], char possibleMoves[chessWidth][chessLength]);
void bishop(Cursor * pointer, char chessBoard[chessWidth][chessLength], char possibleMoves[chessWidth][chessLength]);
void jumper(Cursor * pointer, char chessBoard[chessWidth][chessLength], char possibleMoves[chessWidth][chessLength]);
void king(Cursor * pointer, char chessBoard[chessWidth][chessLength], char possibleMoves[chessWidth][chessLength]);
void queen(Cursor * pointer, char chessBoard[chessWidth][chessLength], char possibleMoves[chessWidth][chessLength]);
void pawn(Cursor * pointer, char chessBoard[chessWidth][chessLength], char possibleMoves[chessWidth][chessLength]);
void tower(Cursor * pointer, char chessBoard[chessWidth][chessLength], char possibleMoves[chessWidth][chessLength]);