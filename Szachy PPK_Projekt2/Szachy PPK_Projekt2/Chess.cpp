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


void drawChessBoard(Cursor* pointer, char possibleMoves[chessWidth][chessLength],Cursor* enemyCursor) {
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
					if (pointer->enemyFiguresPositions[i][j] == BLANK_FIELD && enemyCursor->enemyFiguresPositions[i][j] == BLANK_FIELD) {
						std::cout << " " << possibleMoves[i][j] << " ";
						continue;
					}
				}
				else
				{
					SetConsoleTextAttribute(h0ut, redFOREGROUND | cursorBackground);
				}
				if (pointer->enemyFiguresPositions[i][j] != BLANK_FIELD) {
					std::cout << " " << pointer->enemyFiguresPositions[i][j] << " ";
				}
				else {
					std::cout << " " << enemyCursor->enemyFiguresPositions[i][j] << " ";
				}
			}
			else if (i == pointer->chosenY && j == pointer->chosenX) {
				if (possibleMoves[i][j] == 'X')
				{
					SetConsoleTextAttribute(h0ut, greenFOREGROUND | chosenBackground);
					if (pointer->enemyFiguresPositions[i][j] == BLANK_FIELD && enemyCursor->enemyFiguresPositions[i][j] == BLANK_FIELD) {
						std::cout << " " << possibleMoves[i][j] << " ";
						continue;
					}
				}
				else
				{
					SetConsoleTextAttribute(h0ut, redFOREGROUND | chosenBackground);
				}
				if (pointer->enemyFiguresPositions[i][j] != BLANK_FIELD) {
					std::cout << " " << pointer->enemyFiguresPositions[i][j] << " ";
				}
				else {
					std::cout << " " << enemyCursor->enemyFiguresPositions[i][j] << " ";
				}
			}
			else if ((i + j) % evenNumber == 0) {
				if (possibleMoves[i][j] == 'X')
				{
					SetConsoleTextAttribute(h0ut, greenFOREGROUND | whiteBACKGROUND);
					if (pointer->enemyFiguresPositions[i][j] == BLANK_FIELD && enemyCursor->enemyFiguresPositions[i][j] == BLANK_FIELD) {
						std::cout << " " << possibleMoves[i][j] << " ";
						continue;
					}
				}
				else
				{
					SetConsoleTextAttribute(h0ut, redFOREGROUND | whiteBACKGROUND);
				}
				if (pointer->enemyFiguresPositions[i][j] != BLANK_FIELD) {
					std::cout << " " << pointer->enemyFiguresPositions[i][j] << " ";
				}
				else {
					std::cout << " " << enemyCursor->enemyFiguresPositions[i][j] << " ";
				}
			}
			else {
				if (possibleMoves[i][j] == 'X')
				{
					SetConsoleTextAttribute(h0ut, greenFOREGROUND);
					if (pointer->enemyFiguresPositions[i][j] == BLANK_FIELD && enemyCursor->enemyFiguresPositions[i][j] == BLANK_FIELD) {
						std::cout << " " << possibleMoves[i][j] << " ";
						continue;
					}
				}
				else
				{
					SetConsoleTextAttribute(h0ut, redFOREGROUND);
				}
				if (pointer->enemyFiguresPositions[i][j] != BLANK_FIELD) {
					std::cout << " " << pointer->enemyFiguresPositions[i][j] << " ";
				}
				else {
					std::cout << " " << enemyCursor->enemyFiguresPositions[i][j] << " ";
				}
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

void movePointer(Cursor * pointer, char possibleMoves[chessWidth][chessLength],Cursor * enemyCursor)
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
		if (enemyCursor->enemyFiguresPositions[pointer->y][pointer->x] != BLANK_FIELD) {
			clearBoard(possibleMoves);
			char chosenFigure = enemyCursor->enemyFiguresPositions[pointer->y][pointer->x];
			setChosen(pointer);
			drawPossibleMoves(pointer, &chosenFigure, possibleMoves, enemyCursor);
		}
		else if (possibleMoves[pointer->y][pointer->x] == 'X') {
			enemyCursor->enemyFiguresPositions[pointer->y][pointer->x] = enemyCursor->enemyFiguresPositions[pointer->chosenY][pointer->chosenX];
			enemyCursor->enemyFiguresPositions[pointer->chosenY][pointer->chosenX] = BLANK_FIELD;
			pointer->enemyFiguresPositions[pointer->y][pointer->x] = BLANK_FIELD;
			notChosen(pointer);
			clearBoard(possibleMoves);
			pointer->moveCompleted = true;
		}
		break;
	case char(ESCAPE) :
		notChosen(pointer);
		clearBoard(possibleMoves);
		break;
	}	
}

void drawPossibleMoves(Cursor * pointer, char * figure, char possibleMoves[chessWidth][chessLength], Cursor* enemyCursor)
{
	switch (*figure) {
	case'b':
	case'B':
		bishop(pointer, possibleMoves, enemyCursor);
		break;
	case'j':
	case'J':
		jumper(pointer, possibleMoves, enemyCursor);
		break;
	case'k':
	case'K':
		king(pointer, possibleMoves, enemyCursor);
		break;
	case'q':
	case'Q':
		queen(pointer, possibleMoves, enemyCursor);
		break;
	case'p':
	case'P':
		pawn(pointer, possibleMoves, enemyCursor);
		break;
	case't':
	case'T':
		tower(pointer, possibleMoves, enemyCursor);
		break;	
	}
}

void bishop(Cursor * pointer, char possibleMoves[chessWidth][chessLength], Cursor * enemyCursor)
{
	for (int Y = pointer->y - NEXT_POSITION, X = pointer->x + NEXT_POSITION; Y >= CHESSUP && X <= CHESSRIGHT; Y--, X++) {
		if (pointer->enemyFiguresPositions[Y][X] != BLANK_FIELD) {
			possibleMoves[Y][X] = 'X';
			break;
		}
		else if (enemyCursor->enemyFiguresPositions[Y][X] != BLANK_FIELD) {
			break;
		}
		else {
			possibleMoves[Y][X] = 'X';
		}
	}
	for (int Y = pointer->y + NEXT_POSITION, X = pointer->x + NEXT_POSITION; Y <= CHESSDOWN && X <= CHESSRIGHT; Y++, X++) {
		if (pointer->enemyFiguresPositions[Y][X] != BLANK_FIELD) {
			possibleMoves[Y][X] = 'X';
			break;
		}
		else if (enemyCursor->enemyFiguresPositions[Y][X] != BLANK_FIELD) {
			break;
		}
		else {
			possibleMoves[Y][X] = 'X';
		}
	}
	for (int Y = pointer->y + NEXT_POSITION, X = pointer->x - NEXT_POSITION; Y <= CHESSDOWN && X >= CHESSLEFT; Y++, X--) {
		if (pointer->enemyFiguresPositions[Y][X] != BLANK_FIELD) {
			possibleMoves[Y][X] = 'X';
			break;
		}
		else if (enemyCursor->enemyFiguresPositions[Y][X] != BLANK_FIELD) {
			break;
		}
		else {
			possibleMoves[Y][X] = 'X';
		}
	}
	for (int Y = pointer->y - NEXT_POSITION, X = pointer->x - NEXT_POSITION; Y >= CHESSUP && X >= CHESSLEFT; Y--, X--) {
		if (pointer->enemyFiguresPositions[Y][X] != BLANK_FIELD) {
			possibleMoves[Y][X] = 'X';
			break;
		}
		else if (enemyCursor->enemyFiguresPositions[Y][X] != BLANK_FIELD) {
			break;
		}
		else {
			possibleMoves[Y][X] = 'X';
		}
	}
}

void jumper(Cursor * pointer, char possibleMoves[chessWidth][chessLength], Cursor * enemyCursor)
{
	if ((enemyCursor->enemyFiguresPositions[pointer->y + NEXT_POSITION][pointer->x + 2 * NEXT_POSITION] == BLANK_FIELD) && (pointer->y + NEXT_POSITION < chessWidth && pointer->x + 2 * NEXT_POSITION < chessLength))
	{
		possibleMoves[pointer->y + NEXT_POSITION][pointer->x + 2 * NEXT_POSITION] = 'X';
	}
	
	if ((enemyCursor->enemyFiguresPositions[pointer->y + NEXT_POSITION][pointer->x - 2 * NEXT_POSITION] == BLANK_FIELD) && (pointer->y + NEXT_POSITION < chessWidth && pointer->x - 2 * NEXT_POSITION >= CHESSLEFT))
	{
		possibleMoves[pointer->y + NEXT_POSITION][pointer->x - 2 * NEXT_POSITION] = 'X';

	}
	if ((enemyCursor->enemyFiguresPositions[pointer->y + 2 * NEXT_POSITION][pointer->x + NEXT_POSITION] == BLANK_FIELD) && (pointer->y + 2 * NEXT_POSITION < chessWidth && pointer->x + NEXT_POSITION < chessLength))
	{
		possibleMoves[pointer->y + 2 * NEXT_POSITION][pointer->x + NEXT_POSITION] = 'X';
	}

	if ((enemyCursor->enemyFiguresPositions[pointer->y + 2 * NEXT_POSITION][pointer->x - NEXT_POSITION] == BLANK_FIELD) && (pointer->y + 2 * NEXT_POSITION < chessWidth && pointer->x - NEXT_POSITION >= CHESSLEFT))
	{
		possibleMoves[pointer->y + 2 * NEXT_POSITION][pointer->x - NEXT_POSITION] = 'X';
	}

	if ((enemyCursor->enemyFiguresPositions[pointer->y - NEXT_POSITION][pointer->x + 2 * NEXT_POSITION] == BLANK_FIELD) && (pointer->y - NEXT_POSITION >= CHESSUP && pointer->x + 2 * NEXT_POSITION < chessLength))
	{
		possibleMoves[pointer->y - NEXT_POSITION][pointer->x + 2 * NEXT_POSITION] = 'X';
	}

	if ((enemyCursor->enemyFiguresPositions[pointer->y - NEXT_POSITION][pointer->x - 2 * NEXT_POSITION] == BLANK_FIELD) && (pointer->y - NEXT_POSITION >= CHESSUP && pointer->x - 2 * NEXT_POSITION >= CHESSLEFT))
	{
		possibleMoves[pointer->y - NEXT_POSITION][pointer->x - 2 * NEXT_POSITION] = 'X';
	}

	if ((enemyCursor->enemyFiguresPositions[pointer->y - 2 * NEXT_POSITION][pointer->x + NEXT_POSITION] == BLANK_FIELD) && (pointer->y - 2 * NEXT_POSITION >= CHESSUP && pointer->x + NEXT_POSITION < chessLength))
	{
		possibleMoves[pointer->y - 2 * NEXT_POSITION][pointer->x + NEXT_POSITION] = 'X';
	}

	if ((enemyCursor->enemyFiguresPositions[pointer->y - 2 * NEXT_POSITION][pointer->x - NEXT_POSITION] == BLANK_FIELD) && (pointer->y - 2 * NEXT_POSITION >= CHESSUP && pointer->x - NEXT_POSITION >= CHESSLEFT))
	{
		possibleMoves[pointer->y - 2 * NEXT_POSITION][pointer->x - NEXT_POSITION] = 'X';
	}
}

void king(Cursor * pointer, char possibleMoves[chessWidth][chessLength], Cursor * enemyCursor)
{
}

void tower(Cursor * pointer, char possibleMoves[chessWidth][chessLength], Cursor * enemyCursor)
{
	for (int Y = pointer->y + NEXT_POSITION; Y <= CHESSDOWN; Y++) {
		if (pointer->enemyFiguresPositions[Y][pointer->x] != BLANK_FIELD) {
			possibleMoves[Y][pointer->x] = 'X';
			break;
		}
		else if (enemyCursor->enemyFiguresPositions[Y][pointer->x] != BLANK_FIELD) {
			break;
		}
		else {
			possibleMoves[Y][pointer->x] = 'X';
		}
	}
	for (int Y = pointer->y - NEXT_POSITION; Y >= CHESSUP; Y--) {
		if (pointer->enemyFiguresPositions[Y][pointer->x] != BLANK_FIELD) {
			possibleMoves[Y][pointer->x] = 'X';
			break;
		}
		else if (enemyCursor->enemyFiguresPositions[Y][pointer->x] != BLANK_FIELD) {
			break;
		}
		else {
			possibleMoves[Y][pointer->x] = 'X';
		}
	}
	for (int X = pointer->x + NEXT_POSITION; X <= CHESSRIGHT; X++) {
		if (pointer->enemyFiguresPositions[pointer->y][X] != BLANK_FIELD) {
			possibleMoves[pointer->y][X] = 'X';
			break;
		}
		else if (enemyCursor->enemyFiguresPositions[pointer->y][X] != BLANK_FIELD) {
			break;
		}
		else {
			possibleMoves[pointer->y][X] = 'X';
		}
	}
	for (int X = pointer->x - NEXT_POSITION; X >= CHESSLEFT; X--) {
		if (pointer->enemyFiguresPositions[pointer->y][X] != BLANK_FIELD) {
			possibleMoves[pointer->y][X] = 'X';
			break;
		}
		else if (enemyCursor->enemyFiguresPositions[pointer->y][X] != BLANK_FIELD) {
			break;
		}
		else {
			possibleMoves[pointer->y][X] = 'X';
		}
	}
}

void queen(Cursor * pointer, char possibleMoves[chessWidth][chessLength], Cursor * enemyCursor)
{
	bishop(pointer, possibleMoves, enemyCursor);
	tower(pointer, possibleMoves, enemyCursor);
}

void pawn(Cursor * pointer, char possibleMoves[chessWidth][chessLength], Cursor* enemyCursor)
{
	if (pointer->cursorColor=='w') {
		if (pointer->y == whitePawnsPosition) {
			if (enemyCursor->enemyFiguresPositions[pointer->y + NEXT_POSITION][pointer->x] == BLANK_FIELD && pointer->enemyFiguresPositions[pointer->y + NEXT_POSITION][pointer->x] == BLANK_FIELD) {
				if (enemyCursor->enemyFiguresPositions[pointer->y + 2 * NEXT_POSITION][pointer->x] == BLANK_FIELD) {
					possibleMoves[pointer->y + 2 * NEXT_POSITION][pointer->x] = 'X';
				}
			}			
		}
		if (enemyCursor->enemyFiguresPositions[pointer->y + NEXT_POSITION][pointer->x] == BLANK_FIELD && pointer->enemyFiguresPositions[pointer->y + NEXT_POSITION][pointer->x]== BLANK_FIELD)
		{
			possibleMoves[pointer->y + NEXT_POSITION][pointer->x] = 'X';
		}
		if ((pointer->x + NEXT_POSITION < chessLength && pointer->y + NEXT_POSITION < chessWidth) && pointer->enemyFiguresPositions[pointer->y+NEXT_POSITION][pointer->x+NEXT_POSITION] != BLANK_FIELD) {
			possibleMoves[pointer->y + NEXT_POSITION][pointer->x + NEXT_POSITION] = 'X';
		}
		if ((pointer->x - NEXT_POSITION > CHESSLEFT-1 && pointer->y + NEXT_POSITION < chessWidth) && pointer->enemyFiguresPositions[pointer->y + NEXT_POSITION][pointer->x - NEXT_POSITION] != BLANK_FIELD) {
			possibleMoves[pointer->y + NEXT_POSITION][pointer->x - NEXT_POSITION] = 'X';
		}
	}
	else {
		if (pointer->y == blackPawnsPosition) {
			if (enemyCursor->enemyFiguresPositions[pointer->y - NEXT_POSITION][pointer->x] == BLANK_FIELD && pointer->enemyFiguresPositions[pointer->y - NEXT_POSITION][pointer->x] == BLANK_FIELD) {
				if (enemyCursor->enemyFiguresPositions[pointer->y - 2 * NEXT_POSITION][pointer->x] == BLANK_FIELD && pointer->enemyFiguresPositions[pointer->y - 2 * NEXT_POSITION][pointer->x] == BLANK_FIELD) {
					possibleMoves[pointer->y - 2 * NEXT_POSITION][pointer->x] = 'X';
				}
			}
		}
		if (enemyCursor->enemyFiguresPositions[pointer->y - NEXT_POSITION][pointer->x] == BLANK_FIELD  && pointer->enemyFiguresPositions[pointer->y - NEXT_POSITION][pointer->x] == BLANK_FIELD)
		{
			possibleMoves[pointer->y - NEXT_POSITION][pointer->x] = 'X';
		}
		if ((pointer->x + NEXT_POSITION < chessLength && pointer->y - NEXT_POSITION < chessWidth) && pointer->enemyFiguresPositions[pointer->y - NEXT_POSITION][pointer->x + NEXT_POSITION] != BLANK_FIELD) {
			possibleMoves[pointer->y - NEXT_POSITION][pointer->x + NEXT_POSITION] = 'X';
		}
		if ((pointer->x - NEXT_POSITION > CHESSLEFT-1 && pointer->y - NEXT_POSITION < chessWidth) && pointer->enemyFiguresPositions[pointer->y - NEXT_POSITION][pointer->x - NEXT_POSITION] != BLANK_FIELD) {
			possibleMoves[pointer->y - NEXT_POSITION][pointer->x - NEXT_POSITION] = 'X';
		}
	}
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
