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
	Cursor(char color) {
		cursorColor = color;
		chosenX = -1;
		chosenY = -1;
		if (color == 'b') {
			x = 0;
			y = 7;
			
			chosen = false;
		}
		if (color == 'w') {
			x = 0;
			y = 0;
			chosen = false;
		}
	}
};
struct ThreeLastMoves {
	char ChessBoard[chessLength][chessWidth];
	ThreeLastMoves* previous;
	ThreeLastMoves* next;
};

void clearBoard(char chessboard[chessWidth][chessLength]);
void startPawns(char chessBoard[chessLength][chessWidth]);
void startTowers(char chessBoard[chessLength][chessWidth]);
void startQueens(char chessBoard[chessLength][chessWidth]);
void startJumpers(char chessBoard[chessLength][chessWidth]);
void startKings(char chessBoard[chessLength][chessWidth]);
void startBishops(char chessBoard[chessLength][chessWidth]);
void putFigures(char chessBoard[chessLength][chessWidth]);
void drawChessBoard(char chess[chessWidth][chessLength],Cursor* pointer);
void drawMenu();
void addToLastMove(char chess[chessWidth][chessLength], char copyChess[chessWidth][chessLength]);
void clearX(char chessBoard[chessWidth][chessLength]);
void setChosen(Cursor* pointer);
void notChosen(Cursor* pointer);
void movePointer(Cursor* pointer, char chessBoard[chessWidth][chessLength]);