#include "stdafx.h"
#include "chessFunctions.h"

int convertToIndex(char position) {
	if (position <= 'h')
	{
		return position -(int)'a';
	}
	else
	{
		return position -(int)'A';
	}
}

void tower(int positionY, int positionX, char chess[chessWidth][chessLength], char figure)
{
	chess[positionY][positionX] = figure;
	for (int Y = positionY - 1; Y >= 0; Y--)
		chess[Y][positionX] = 'X';
	for (int Y = positionY + 1; Y < chessWidth; Y++)
		chess[Y][positionX] = 'X';
	for (int X = positionX - 1; X >= 0; X--)
		chess[positionY][X] = 'X';
	for (int X = positionX + 1; X < chessLength; X++)
		chess[positionY][X] = 'X';
}

void bishop(int positionY, int positionX, char chess[chessWidth][chessLength], char figure)
{
	chess[positionY][positionX] = figure;
	for (int Y = positionY + 1, X = positionX + 1; Y < chessWidth && X < chessLength; Y++, X++)
		chess[Y][X] = 'X';
	for (int Y = positionY + 1, X = positionX - 1; Y < chessWidth && X >= 0; Y++, X--)
		chess[Y][X] = 'X';
	for (int Y = positionY - 1, X = positionX + 1; Y >= 0 && X < chessLength; Y--, X++)
		chess[Y][X] = 'X';
	for (int Y = positionY - 1, X = positionX - 1; Y >= 0 && X >= 0; Y--, X--)
		chess[Y][X] = 'X';
}

void queen(int positionY, int positionX, char chess[chessWidth][chessLength], char figure)
{
	chess[positionY][positionX] = figure;
	tower(positionY, positionX, chess,figure);
	bishop(positionY, positionX, chess,figure);
}

void jumper(int positionY, int positionX, char chess[chessWidth][chessLength], char figure)
{
	chess[positionY][positionX] = figure;
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

void king(int positionY, int positionX, char chess[chessWidth][chessLength], char figure)
{
	chess[positionY][positionX] = figure;
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

void pawn(int positionY, int positionX, char chess[chessWidth][chessLength], char figure)
{
	if (figure == 'p')
	{
		if (positionY == endOfBoard)
		{
			std::cout << "Nie jest mozliwe by pionek bialy byl na tym polu" << std::endl;
			return;
		}
		else if (positionY == beginingOfBoard)
		{
			std::cout << "Pionek bialy nie moze wykonac wiecej ruchow" << std::endl;
			chess[positionY][positionX] = figure;
			return;
		}
		if (positionY == startPositionWhitePawn)
		{
			chess[positionY + 1][positionX] = 'X';
			chess[positionY + 2][positionX] = 'X';
		}
		else
		{
			chess[positionY + 1][positionX] = 'X';
		}
	}
	else if (figure == 'P')
	{
		if (positionY == beginingOfBoard)
		{
			std::cout << "Nie jest mozliwe by pionek czarny byl na tym polu" << std::endl;
			return;
		}
		else if (positionY == endOfBoard)
		{
			std::cout << "Pionek czarny nie moze wykonac wiecej ruchow" << std::endl;
			chess[positionY][positionX] = figure;
			return;
		}
		if (positionY = startPositionBlackPawn) {
			chess[positionY - 1][positionX] = 'X';
			chess[positionY - 2][positionX] = 'X';
		}
		else {
			chess[positionY - 1][positionX] = 'X';
		}
	}
	chess[positionY][positionX] = figure;
}

bool menuWhite(int positionY, int positionX, char chess[chessWidth][chessLength]) {
	char figure;
	system("cls");
	std::cout << "\tWybierz figure" << std::endl
		<< "<w> Wieza" << std::endl
		<< "<g> Goniec" << std::endl
		<< "<s> Skoczek" << std::endl
		<< "<k> Krol" << std::endl
		<< "<h> lub <q> Hetman/Queen" << std::endl
		<< "<p> Pionek" << std::endl
		<< "Twoj wybor: ";
	figure = _getch();
	std::cout << figure;
	system("cls");
	switch (figure)
	{
	case 'w': case 'W':
		system("title Figury - Biale - Wieza");
		tower(chessLength - toBeginingOfTab - positionY, positionX, chess, 'w');
		break;
	case 'g': case 'G':
		system("title Figury - Biale - Goniec");
		bishop(chessLength - toBeginingOfTab - positionY, positionX, chess, 'g');
		break;
	case 's': case 'S':
		system("title Figury - Biale - Skoczek");
		jumper(chessLength - toBeginingOfTab - positionY, positionX, chess, 's');
		break;
	case 'k': case 'K':
		system("title Figury - Biale - Krol");
		king(chessLength - toBeginingOfTab - positionY, positionX, chess, 'k');
		break;
	case 'h': case 'H': case 'q': case'Q':
		system("title Figury - Biale - Hetman");
		queen(chessLength - toBeginingOfTab - positionY, positionX, chess, 'q');
		break;
	case 'p': case 'P':
		system("title Figury - Biale - Pionek");
		pawn(chessLength - toBeginingOfTab - positionY, positionX, chess, 'p');
		break;
	default:
		std::cout << "Wybrano zla opcje (nieistniejaca)";
		return false;
	}
	return true;
}

bool menuBlack(int positionY, int positionX,char chess[chessWidth][chessLength]){
	char figure = ' ';
	system("cls");
	std::cout << std::endl << "\tWybierz figure"
		<< std::endl << "<w> Wieza"
		<< std::endl << "<g> Goniec"
		<< std::endl << "<s> Skoczek"
		<< std::endl << "<k> Krol"
		<< std::endl << "<h> lub <q> Hetman/Queen"
		<< std::endl << "<p> Pionek"
		<< std::endl << "Twoj wybor: ";
	figure = _getch();
	std::cout << figure;
	system("cls");
	switch (figure)
	{
	case 'w': case 'W':
		system("title Figury - Czarne - Wieza");
		tower(chessLength - toBeginingOfTab - positionY, positionX, chess, 'W');
		break;
	case 'g': case 'G':
		system("title Figury - Czarne - Goniec");
		bishop(chessLength - toBeginingOfTab - positionY, positionX, chess, 'G');
		break;
	case 's': case 'S':
		system("title Figury - Czarne - Skoczek");
		jumper(chessLength - toBeginingOfTab - positionY, positionX, chess, 'S');
		break;
	case 'k': case 'K':
		system("title Figury - Czarne - Krol");
		king(chessLength - toBeginingOfTab - positionY, positionX, chess, 'K');
		break;
	case 'h': case 'H': case 'q': case 'Q':
		system("title Figury - Czarne - Hetman");
		queen(chessLength - toBeginingOfTab - positionY, positionX, chess, 'Q');
		break;
	case 'p': case 'P':
		system("title Figury - Czarne - Pionek");
		pawn(chessLength - toBeginingOfTab - positionY, positionX, chess, 'P');
		break;
	default:
		std::cout << std::endl << "Wybrano zla opcje (nieistniejaca)";
		return false;
	}
	return true;
}

void drawChessBoard(char chess[chessWidth][chessLength]) {
	//UCHWYT DO KONSOLI czyli dostêp do tablicy GUI (chyba) 
	HANDLE h0ut;
	h0ut = GetStdHandle(STD_OUTPUT_HANDLE);
	WORD wOldColorAttrs, whiteBACKGROUND, redFOREGROUND, greenFOREGROUND;
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo; //obiekt za pomoc¹ którego dostaniemy informacje o atrybutach konsoli
										 //poczatkowe ustatwienia konsoli
	GetConsoleScreenBufferInfo(h0ut, &csbiInfo);
	wOldColorAttrs = csbiInfo.wAttributes; //przypisanie poczatkowych atrybutów ekranu do zmiennej 
										   //zmienna typu WORD przechowywujaca jeden z kolorów ekranu (przypisanie atrybutów do zmiennych)
	whiteBACKGROUND = BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY;
	redFOREGROUND = FOREGROUND_RED | FOREGROUND_INTENSITY;
	greenFOREGROUND = FOREGROUND_GREEN | FOREGROUND_INTENSITY;


	std::cout << std::endl << "   A  B  C  D  E  F  G  H" << std::endl;
	for (int i = 0; i < chessWidth; i++)
	{
		std::cout << chessLength - i << " ";
		for (int j = 0; j < chessLength; j++)
		{
			//Przywrócenie postawowych kolorów
			SetConsoleTextAttribute(h0ut, wOldColorAttrs);

			if ((i + j) % 2 == 0) {
				if (chess[i][j] == ' ')
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
}
