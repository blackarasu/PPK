#include "stdafx.h"
#include "Chess.h"



void clearBoard(char chessboard[chessWidth][chessLength]) {
	for (int i = 0; i < chessLength; i++) {
		for (int j = 0; j < chessWidth; j++) {
			chessboard[i][j] = BLANK_FIELD;
		}
	}
}

void startBlackPawns(char chessBoard[chessWidth][chessLength])
{
	for (int i = 0; i < chessWidth; i++) {
		chessBoard[blackPawnsPosition][i] = 'P';
	}
}

void startBlackTowers(char chessBoard[chessWidth][chessLength])
{
	chessBoard[blackSecondLane][TOWERS_POSITION1] = 'T';
	chessBoard[blackSecondLane][TOWERS_POSITION2] = 'T';
}

void startBlackQueens(char chessBoard[chessWidth][chessLength])
{
	chessBoard[blackSecondLane][QUEEN_POSITION] = 'Q';
}

void startBlackJumpers(char chessBoard[chessWidth][chessLength])
{
	chessBoard[blackSecondLane][JUMPERS_POSITION1] = 'J';
	chessBoard[blackSecondLane][JUMPERS_POSITION2] = 'J';
}

void startBlackKings(char chessBoard[chessWidth][chessLength])
{
	chessBoard[blackSecondLane][KING_POSITION] = 'K';
}

void startBlackBishops(char chessBoard[chessWidth][chessLength])
{
	chessBoard[blackSecondLane][BISHOPS_POSITION1] = 'B';
	chessBoard[blackSecondLane][BISHOPS_POSITION2] = 'B';
}

void putBlackFigures(char chessBoard[chessWidth][chessLength]) {
	startBlackPawns(chessBoard);
	startBlackTowers(chessBoard);
	startBlackQueens(chessBoard);
	startBlackJumpers(chessBoard);
	startBlackKings(chessBoard);
	startBlackBishops(chessBoard);
}
void putWhiteFigures(char chessBoard[chessWidth][chessLength]) {
	startWhitePawns(chessBoard);
	startWhiteTowers(chessBoard);
	startWhiteQueens(chessBoard);
	startWhiteJumpers(chessBoard);
	startWhiteKings(chessBoard);
	startWhiteBishops(chessBoard);
}

void putFigures(char chessBoard[chessWidth][chessLength])
{
	putBlackFigures(chessBoard);
	putWhiteFigures(chessBoard);
}

//← ↑ → ↓
void drawMenu()
{
	std::cout << std::endl << std::endl << "W/S/A/D -> Move pointer "
		<< std::endl << "K -> Chose Figure/Show its possible moves ->ACCEPT Move"
		<< std::endl << "BCKSPC -> Previous Move"
		<< std::endl << "ESC -> Cancel your chosen figure";
}


void drawChessBoard(char chess[chessWidth][chessLength],Cursor* pointer, char possibleMoves[chessWidth][chessLength]) {
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
				if (possibleMoves[i][j] == 'X')
				{
					SetConsoleTextAttribute(h0ut, greenFOREGROUND | cursorBackground);
					if (chess[i][j] == ' ') {
						std::cout << " " << possibleMoves[i][j] << " ";
						continue;
					}
				}
				else if (chess[i][j] == BLANK_FIELD)
				{
					SetConsoleTextAttribute(h0ut, cursorBackground);
				}
				else
				{
					SetConsoleTextAttribute(h0ut, redFOREGROUND | cursorBackground);
				}
				std::cout << " " << chess[i][j] << " ";
			}
			else if (i == pointer->chosenY && j == pointer->chosenX) {
				if (possibleMoves[i][j] == 'X')
				{
					SetConsoleTextAttribute(h0ut, greenFOREGROUND | chosenBackground);
					if (chess[i][j] == ' ') {
						std::cout << " " << possibleMoves[i][j] << " ";
						continue;
					}
				}
				else if (chess[i][j] == BLANK_FIELD)
				{
					SetConsoleTextAttribute(h0ut, chosenBackground);
				}
				else
				{
					SetConsoleTextAttribute(h0ut, redFOREGROUND | chosenBackground);
				}
				std::cout << " " << chess[i][j] << " ";
			}
			else if ((i + j) % evenNumber == 0) {
				if (possibleMoves[i][j] == 'X')
				{
					SetConsoleTextAttribute(h0ut, greenFOREGROUND | whiteBACKGROUND);
					if (chess[i][j] == ' ') {
						std::cout << " " << possibleMoves[i][j] << " ";
						continue;
					}
				}
				else if (chess[i][j] == BLANK_FIELD)
				{
					SetConsoleTextAttribute(h0ut, whiteBACKGROUND);
				}
				else
				{
					SetConsoleTextAttribute(h0ut, redFOREGROUND | whiteBACKGROUND);
				}
				std::cout << " " << chess[i][j] << " ";
			}
			else {
				if (possibleMoves[i][j] == 'X')
				{
					SetConsoleTextAttribute(h0ut, greenFOREGROUND);
					if (chess[i][j] == ' ') {
						std::cout << " " << possibleMoves[i][j] << " ";
						continue;
					}
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

void movePointer(Cursor * pointer,char chess[chessWidth][chessLength], char possibleMoves[chessWidth][chessLength],Cursor * enemyCursor)
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
						drawPossibleMoves(pointer, &chosenFigure, chess, possibleMoves);
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
						drawPossibleMoves(pointer, &chosenFigure, chess, possibleMoves);
						break;
					}
				}
			}
		}
		break;
	case char(ESCAPE) :
		notChosen(pointer);
		clearX(possibleMoves);
		break;
	}	
}

void drawPossibleMoves(Cursor * pointer, char * figure, char chessBoard[chessWidth][chessLength], char possibleMoves[chessWidth][chessLength])
{
	switch (*figure) {
	case'b':
	case'B':
		bishop(pointer, chessBoard, possibleMoves);
		break;
	case'j':
	case'J':
		jumper(pointer, chessBoard, possibleMoves);
		break;
	case'k':
	case'K':
		king(pointer, chessBoard, possibleMoves);
		break;
	case'q':
	case'Q':
		queen(pointer, chessBoard, possibleMoves);
		break;
	case'p':
	case'P':
		pawn(pointer, chessBoard, possibleMoves);
		break;
	case't':
	case'T':
		tower(pointer, chessBoard, possibleMoves);
		break;	
	}
}

void bishop(Cursor * pointer, char chessBoard[chessWidth][chessLength], char possibleMoves[chessWidth][chessLength])
{

}

void jumper(Cursor * pointer, char chessBoard[chessWidth][chessLength], char possibleMoves[chessWidth][chessLength])
{
}

void king(Cursor * pointer, char chessBoard[chessWidth][chessLength], char possibleMoves[chessWidth][chessLength])
{
}

void queen(Cursor * pointer, char chessBoard[chessWidth][chessLength], char possibleMoves[chessWidth][chessLength])
{
}

void pawn(Cursor * pointer, char chessBoard[chessWidth][chessLength], char possibleMoves[chessWidth][chessLength])
{
	if (pointer->cursorColor=='w') {
		if (pointer->y == whitePawnsPosition) {
			if (chessBoard[pointer->y + 2 * NEXT_POSITION][pointer->x] == BLANK_FIELD) {
				possibleMoves[pointer->y + 2 * NEXT_POSITION][pointer->x] = 'X';
			}
		}
		if (chessBoard[pointer->y + NEXT_POSITION][pointer->x] == BLANK_FIELD)
		{
			possibleMoves[pointer->y + NEXT_POSITION][pointer->x] = 'X';
		}
		if ((pointer->x + NEXT_POSITION < chessLength && pointer->y + NEXT_POSITION < chessWidth) && pointer->enemyFiguresPositions[pointer->y+NEXT_POSITION][pointer->x+NEXT_POSITION] != BLANK_FIELD) {
			possibleMoves[pointer->y + NEXT_POSITION][pointer->x + NEXT_POSITION] = 'X';
		}
		if ((pointer->x - NEXT_POSITION > CHESSLEFT && pointer->y + NEXT_POSITION < chessWidth) && pointer->enemyFiguresPositions[pointer->y + NEXT_POSITION][pointer->x - NEXT_POSITION] != BLANK_FIELD) {
			possibleMoves[pointer->y + NEXT_POSITION][pointer->x - NEXT_POSITION] = 'X';
		}
	}
	else {
		if (pointer->y == blackPawnsPosition) {
			if (chessBoard[pointer->y - 2 * NEXT_POSITION][pointer->x] == BLANK_FIELD) {
				possibleMoves[pointer->y - 2 * NEXT_POSITION][pointer->x] = 'X';
			}
		}
		if (chessBoard[pointer->y - NEXT_POSITION][pointer->x] == BLANK_FIELD)
		{
			possibleMoves[pointer->y - NEXT_POSITION][pointer->x] = 'X';
		}
		if ((pointer->x + NEXT_POSITION < chessLength && pointer->y - NEXT_POSITION < chessWidth) && pointer->enemyFiguresPositions[pointer->y - NEXT_POSITION][pointer->x + NEXT_POSITION] != BLANK_FIELD) {
			possibleMoves[pointer->y - NEXT_POSITION][pointer->x + NEXT_POSITION] = 'X';
		}
		if ((pointer->x - NEXT_POSITION > CHESSLEFT && pointer->y - NEXT_POSITION < chessWidth) && pointer->enemyFiguresPositions[pointer->y - NEXT_POSITION][pointer->x - NEXT_POSITION] != BLANK_FIELD) {
			possibleMoves[pointer->y - NEXT_POSITION][pointer->x - NEXT_POSITION] = 'X';
		}
	}
}

void tower(Cursor * pointer, char chessBoard[chessWidth][chessLength], char possibleMoves[chessWidth][chessLength])
{
}

void startWhitePawns(char chessBoard[chessWidth][chessLength])
{
	for (int i = 0; i < chessWidth; i++) {
		chessBoard[whitePawnsPosition][i] = 'p';
	}
}

void startWhiteTowers(char chessBoard[chessWidth][chessLength])
{
	chessBoard[whiteSecondLane][TOWERS_POSITION1] = 't';
	chessBoard[whiteSecondLane][TOWERS_POSITION2] = 't';
}

void startWhiteQueens(char chessBoard[chessWidth][chessLength])
{
	chessBoard[whiteSecondLane][QUEEN_POSITION] = 'q';
}

void startWhiteJumpers(char chessBoard[chessWidth][chessLength])
{
	chessBoard[whiteSecondLane][JUMPERS_POSITION1] = 'j';
	chessBoard[whiteSecondLane][JUMPERS_POSITION2] = 'j';
}

void startWhiteKings(char chessBoard[chessWidth][chessLength])
{
	chessBoard[whiteSecondLane][KING_POSITION] = 'k';
}

void startWhiteBishops(char chessBoard[chessWidth][chessLength])
{
	chessBoard[whiteSecondLane][BISHOPS_POSITION1] = 'b';
	chessBoard[whiteSecondLane][BISHOPS_POSITION2] = 'b';
}
