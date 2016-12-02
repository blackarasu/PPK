#pragma once
#include <iostream>
#include <conio.h>
#include <windows.h>

const int chessLength = 8;
const int chessWidth = 8;
const int endOfBoard = 0;
const int beginingOfBoard = 7;
const int startPositionWhitePawn = 1;
const int startPositionBlackPawn = 6;
const int toBeginingOfTab = 1;
const int evenNumber = 2;


int convertToIndex(char position);

void tower(int positionY, int positionX, char chess[chessWidth][chessLength], char figure);

void bishop(int positionY, int positionX, char chess[chessWidth][chessLength], char figure);

void queen(int positionY, int positionX, char chess[chessWidth][chessLength], char figure);

void jumper(int positionY, int positionX, char chess[chessWidth][chessLength], char figure);

void king(int positionY, int positionX, char chess[chessWidth][chessLength], char figure);

void pawn(int positionY, int positionX, char chess[chessWidth][chessLength], char figure);

bool menuWhite(int positionY, int positionX,char chess[chessWidth][chessLength]);

bool menuBlack(int positionY, int positionX, char chess[chessWidth][chessLength]);

void drawChessBoard(char chess[chessWidth][chessLength]);