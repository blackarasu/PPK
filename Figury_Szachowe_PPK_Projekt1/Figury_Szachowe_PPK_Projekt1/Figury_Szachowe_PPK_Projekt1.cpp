// Figury_chessowe_PPK_Projekt1.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <cstdlib>
#include "chessFunctions.h" //nag³owek ze wszystkimi funkcjami które zosta³e u¿yte w tym projekcie



//BIa³e figury na górze czarne na dole -> bia³e ma³e, czarne du¿e
int main()
{
	system("title Figury");
	char chess[chessWidth][chessLength];
	for (int i = 0; i < chessWidth; i++)
		for (int j = 0; j < chessLength; j++)
			chess[i][j] = ' ';
	int positionX = 0, positionY = 0;
	char positionXChar = ' ';
	bool check_cin = false, check = false;
	do
	{
		std::cout << "Podaj pozycje figury na szachownicy <a-h><1-8> ";
		positionXChar = _getch();
		std::cout << positionXChar;
		positionY = _getch();
		std::cout << positionY - (int)'0' << std::endl;
		if (((positionXChar<'a' || positionXChar>'h') && (positionXChar<'A' || positionXChar>'H'))) {
			system("cls");
			std::cout << "!POZYCJA FIGURY MA BYC POMIEDZY  \'a\' a \'h\' I POMIEDZY \'1\' a \'8\'" << std::endl
				<< "np. G2" << std::endl;
		}
	} while ((positionXChar<'a' || positionXChar>'h') && (positionXChar<'A' || positionXChar>'H') || positionY<'1' || positionY>chessWidth + (int)'0');
	positionX = convertToIndex(positionXChar);
	if (positionX == -1)
	{
		std::cout << "Cos poszlo nietak";
	}
	positionY -= (int)'0' + 1;
	char color;
	std::cout << "\n\t\t\tMENU" << std::endl
		<< "\tWybierz kolor" << std::endl
		<< "<b> Bialy" << std::endl
		<< "<c> Czarny" << std::endl
		<< "Twoj wybor: ";
	color = _getch();
	std::cout << color << std::endl;
	switch (color)
	{
	case 'b':
		system("title Figury - Biale");
		check = true;
		do {
			check = menuWhite(positionY, positionX, chess);
		} while (!check);
		break;
	case 'c':
		system("title Figury - Czarne");
		check = true;
		do {
			check = menuBlack(positionY, positionX, chess);
		} while (!check);
		break;
	default:
		std::cout << std::endl << "Wybrano zla opcje (nieistniejaca)";
		check_cin = true;
		break;
	}

	if (!check_cin)
	{
		drawChessBoard(chess);
	}
	_getch();
	return 0;
}

