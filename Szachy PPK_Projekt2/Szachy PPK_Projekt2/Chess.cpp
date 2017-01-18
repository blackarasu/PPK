#include "stdafx.h"
#include "Chess.h"



void clearBoard(char chessboard[chessWidth][chessLength]) {
	for (int i = 0; i < chessLength; i++) {
		for (int j = 0; j < chessWidth; j++) {
			chessboard[i][j] = BLANK_FIELD;
		}
	}
}

void startPawns(char chessBoard[chessLength][chessWidth]) {
	for (int i = 0; i < chessWidth; i++) {
		chessBoard[whitePawnsPosition][i] = 'p';
	}
	for (int i = 0; i < chessWidth; i++) {
		chessBoard[blackPawnsPosition][i] = 'P';
	}
}

void startTowers(char chessBoard[chessLength][chessWidth]) {
	chessBoard[whiteSecondLane][TOWERS_POSITION1] = 't';
	chessBoard[whiteSecondLane][TOWERS_POSITION2] = 't';
	chessBoard[blackSecondLane][TOWERS_POSITION1] = 'T';
	chessBoard[blackSecondLane][TOWERS_POSITION2] = 'T';
}

void startQueens(char chessBoard[chessLength][chessWidth]) {
	chessBoard[whiteSecondLane][QUEEN_POSITION] = 'q';
	chessBoard[blackSecondLane][QUEEN_POSITION] = 'Q';
}

void startJumpers(char chessBoard[chessLength][chessWidth]) {
	chessBoard[whiteSecondLane][JUMPERS_POSITION1] = 'j';
	chessBoard[whiteSecondLane][JUMPERS_POSITION2] = 'j';
	chessBoard[blackSecondLane][JUMPERS_POSITION1] = 'J';
	chessBoard[blackSecondLane][JUMPERS_POSITION2] = 'J';
}

void startKings(char chessBoard[chessLength][chessWidth]) {
	chessBoard[whiteSecondLane][KING_POSITION] = 'k';
	chessBoard[blackSecondLane][KING_POSITION] = 'K';
}
void startBishops(char chessBoard[chessLength][chessWidth]) {
	chessBoard[whiteSecondLane][BISHOPS_POSITION1] = 'b';
	chessBoard[whiteSecondLane][BISHOPS_POSITION2] = 'b';
	chessBoard[blackSecondLane][BISHOPS_POSITION1] = 'B';
	chessBoard[blackSecondLane][BISHOPS_POSITION2] = 'B';
}

void putFigures(char chessBoard[chessLength][chessWidth]) {
	startPawns(chessBoard);
	startTowers(chessBoard);
	startQueens(chessBoard);
	startJumpers(chessBoard);
	startKings(chessBoard);
	startBishops(chessBoard);
}

//← ↑ → ↓
void drawMenu()
{
	std::cout << std::endl << std::endl << "W/S/A/D -> Move pointer "
		<< std::endl << "K -> Chose Figure/Show its possible moves ->ACCEPT Move"
		<< std::endl << "BCKSPC -> Previous Move"
		<< std::endl << "ESC -> Cancel your chosen figure";
}


void drawChessBoard(char chess[chessWidth][chessLength],Cursor* pointer) {
	HANDLE h0ut;
	h0ut = GetStdHandle(STD_OUTPUT_HANDLE);
	WORD wOldColorAttrs, whiteBACKGROUND, redFOREGROUND, greenFOREGROUND, cursorBackground,chosenBackground;
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo; 
	GetConsoleScreenBufferInfo(h0ut, &csbiInfo);
	wOldColorAttrs = csbiInfo.wAttributes;
	whiteBACKGROUND = BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY;
	redFOREGROUND = FOREGROUND_RED | FOREGROUND_INTENSITY;
	greenFOREGROUND = FOREGROUND_GREEN | FOREGROUND_INTENSITY;
	chosenBackground = BACKGROUND_GREEN | BACKGROUND_RED;
	std::cout << std::endl << "   A  B  C  D  E  F  G  H" << std::endl;
	switch (pointer->cursorColor) {
	case 'w':
		cursorBackground = BACKGROUND_BLUE | BACKGROUND_INTENSITY;
		break;
	case 'b':
		cursorBackground = BACKGROUND_BLUE;
		break;
	default:
		cursorBackground = 0;
		break;
	}
	for (int i = 0; i < chessWidth; i++)
	{
		std::cout << chessLength - i << " ";
		for (int j = 0; j < chessLength; j++)
		{
			SetConsoleTextAttribute(h0ut, wOldColorAttrs); //Regular colors
			if (i == pointer->y&&j == pointer->x) {
				if (chess[i][j] == BLANK_FIELD)
				{
					SetConsoleTextAttribute(h0ut, cursorBackground);
				}
				else if (chess[i][j] == 'X')
				{
					SetConsoleTextAttribute(h0ut, greenFOREGROUND | cursorBackground);
				}
				else
				{
					SetConsoleTextAttribute(h0ut, redFOREGROUND | cursorBackground);
				}
				std::cout << " " << chess[i][j] << " ";
			}
			else if (i == pointer->chosenY && j == pointer->chosenX) {
				if (chess[i][j] == BLANK_FIELD)
				{
					SetConsoleTextAttribute(h0ut, chosenBackground);
				}
				else if (chess[i][j] == 'X')
				{
					SetConsoleTextAttribute(h0ut, greenFOREGROUND | chosenBackground);
				}
				else
				{
					SetConsoleTextAttribute(h0ut, redFOREGROUND | chosenBackground);
				}
				std::cout << " " << chess[i][j] << " ";
			}
			else if ((i + j) % 2 == 0) {

				if (chess[i][j] == BLANK_FIELD)
				{
					SetConsoleTextAttribute(h0ut, whiteBACKGROUND);
				}
				else if (chess[i][j] == 'X')
				{
					SetConsoleTextAttribute(h0ut, greenFOREGROUND | whiteBACKGROUND);
				}
				else
				{
					SetConsoleTextAttribute(h0ut, redFOREGROUND | whiteBACKGROUND);
				}
				std::cout << " " << chess[i][j] << " ";
			}
			else {
				if (chess[i][j] == 'X')
				{
					SetConsoleTextAttribute(h0ut, greenFOREGROUND);
				}
				else
				{
					SetConsoleTextAttribute(h0ut, redFOREGROUND);
				}
				std::cout << " " << chess[i][j] << " ";
			}
		}
		SetConsoleTextAttribute(h0ut, wOldColorAttrs);
		std::cout << " " << chessLength - i << std::endl;
	}
	std::cout << "   A  B  C  D  E  F  G  H" << std::endl;
	drawMenu();
}

void addToLastMove(char chess[chessWidth][chessLength], char copyChess[chessWidth][chessLength])
{
	for (int i = 0; i < chessWidth; i++) {
		for (int j = 0; j < chessLength; j++) {
			copyChess[i][j] = chess[i][j];
		}
	}
}

void clearX(char chessBoard[chessWidth][chessLength])
{
	for (int i = 0; i < chessWidth; i++) {
		for (int j = 0; j < chessLength; j++) {
			if (chessBoard[i][j] == 'X') {
				chessBoard[i][j] = BLANK_FIELD;
			}
		}
	}
}

void setChosen(Cursor * pointer)
{
	pointer->chosen = true;
	pointer->chosenX = pointer->x;
	pointer->chosenY = pointer->y;
}

void notChosen(Cursor * pointer)
{
	pointer->chosen = false;
	pointer->chosenX = -1;
	pointer->chosenY = -1;
}

void movePointer(Cursor * pointer,char chess[chessWidth][chessLength])
{
	switch (_getch()) {
	case 'w':
		if (pointer->y-1 >= CHESSUP) {
			--pointer->y;
		}
		break;
	case 's':
		if (pointer->y + 1 <= CHESSDOWN) {
			++pointer->y;
		}
		break;
	case 'a':
		if (pointer->x - 1 >= CHESSLEFT) {
			--pointer->x;
		}
		break;
	case 'd':
		if (pointer->x + 1 <= CHESSRIGHT) {
			++pointer->x;
		}
		break;
	case 'k':
		if (pointer->chosen) {

		}
		else {
			if (chess[pointer->y][pointer->x] != BLANK_FIELD) {
				char chosenFigure = chess[pointer->y][pointer->x];
				if (pointer->cursorColor == 'w') {
					switch (chosenFigure) {
					case't':
					case'j':
					case'b':
					case'q':
					case'k':
					case'p':
						setChosen(pointer);
						break;
					}
				}
				else {
					switch (chosenFigure) {
					case'T':
					case'J':
					case'B':
					case'Q':
					case'K':
					case'P':
						setChosen(pointer);
						break;
					}
				}
			}
		}
		break;
	case char(ESCAPE) :
		notChosen(pointer);
		clearX(chess);
		break;
	}	
}

