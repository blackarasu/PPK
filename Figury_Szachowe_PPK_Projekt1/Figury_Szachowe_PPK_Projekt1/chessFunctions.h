#pragma once

const int chessLength = 8;
const int chessWidth = 8;

int convertToIndex(char position);

void tower(int positionY, int positionX, char chess[chessWidth][chessLength]);

void bishop(int positionY, int positionX, char chess[chessWidth][chessLength]);

void queen(int positionY, int positionX, char chess[chessWidth][chessLength]);

void jumper(int positionY, int positionX, char chess[chessWidth][chessLength]);

void king(int positionY, int positionX, char chess[chessWidth][chessLength]);



