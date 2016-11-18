#include "stdafx.h"
#include "chessFunctions.h"

int convertToIndex(char position) {
	switch (position) {
	case 'A':
	case 'a':
		return 0;
	case 'B':
	case 'b':
		return 1;
	case 'C':
	case 'c':
		return 2;
	case 'D':
	case 'd':
		return 3;
	case 'E':
	case 'e':
		return 4;
	case 'F':
	case 'f':
		return 5;
	case 'G':
	case 'g':
		return 6;
	case 'H':
	case 'h':
		return 7;
	default:
		return -1;
	}
	
}

void tower(int positionY, int positionX, char chess[chessWidth][chessLength])
{
	for (int Y = positionY - 1; Y >= 0; Y--)
		chess[Y][positionX] = 'X';
	for (int Y = positionY + 1; Y < chessWidth; Y++)
		chess[Y][positionX] = 'X';
	for (int X = positionX - 1; X >= 0; X--)
		chess[positionY][X] = 'X';
	for (int X = positionX + 1; X < chessLength; X++)
		chess[positionY][X] = 'X';
}

void bishop(int positionY, int positionX, char chess[chessWidth][chessLength])
{
	for (int Y = positionY + 1, X = positionX + 1; Y < chessWidth && X < chessLength; Y++, X++)
		chess[Y][X] = 'X';
	for (int Y = positionY + 1, X = positionX - 1; Y < chessWidth && X >= 0; Y++, X--)
		chess[Y][X] = 'X';
	for (int Y = positionY - 1, X = positionX + 1; Y >= 0 && X < chessLength; Y--, X++)
		chess[Y][X] = 'X';
	for (int Y = positionY - 1, X = positionX - 1; Y >= 0 && X >= 0; Y--, X--)
		chess[Y][X] = 'X';
}

void queen(int positionY, int positionX, char chess[chessWidth][chessLength])
{
	tower(positionY, positionX, chess);
	bishop(positionY, positionX, chess);
}

void jumper(int positionY, int positionX, char chess[chessWidth][chessLength])
{
	if (positionY + 1 < chessWidth && positionX + 2 < chessLength)
		chess[positionY + 1][positionX + 2] = 'X';

	if (positionY + 1 < chessWidth && positionX - 2 >= 0)
		chess[positionY + 1][positionX - 2] = 'X';

	if (positionY + 2 < chessWidth && positionX + 1 < chessLength)
		chess[positionY + 2][positionX + 1] = 'X';

	if (positionY + 2 < chessWidth && positionX - 1 >= 0)
		chess[positionY + 2][positionX - 1] = 'X';

	if (positionY - 1 >= 0 && positionX + 2 < chessLength)
		chess[positionY - 1][positionX + 2] = 'X';

	if (positionY - 1 >= 0 && positionX - 2 >= 0)
		chess[positionY - 1][positionX - 2] = 'X';

	if (positionY - 2 >= 0 && positionX + 1 < chessLength)
		chess[positionY - 2][positionX + 1] = 'X';

	if (positionY - 2 >= 0 && positionX - 1 >= 0)
		chess[positionY - 2][positionX - 1] = 'X';

}

void king(int positionY, int positionX, char chess[chessWidth][chessLength])
{
	if (positionY + 1 < chessWidth)
		chess[positionY + 1][positionX] = 'X';
	if (positionY - 1 >= 0)
		chess[positionY - 1][positionX] = 'X';
	if (positionY + 1 < chessWidth && positionX + 1 < chessLength)
		chess[positionY + 1][positionX + 1] = 'X';
	if (positionY + 1 < chessWidth && positionX - 1 >= 0)
		chess[positionY + 1][positionX - 1] = 'X';
	if (positionY - 1 >= 0 && positionX + 1 < chessLength)
		chess[positionY - 1][positionX + 1] = 'X';
	if (positionY - 1 >= 0 && positionX - 1 >= 0)
		chess[positionY - 1][positionX - 1] = 'X';
	if (positionX + 1 < chessLength)
		chess[positionY][positionX + 1] = 'X';
	if (positionX - 1 >= 0)
		chess[positionY][positionX - 1] = 'X';
}
