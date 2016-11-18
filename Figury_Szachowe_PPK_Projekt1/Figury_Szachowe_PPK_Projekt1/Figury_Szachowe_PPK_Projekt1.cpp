// Figury_chessowe_PPK_Projekt1.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include "chessFunctions.h" //nag³owek ze wszystkimi funkcjami które zosta³e u¿yte w tym projekcie



//BIa³e figury na górze czarne na dole -> bia³e ma³e, czarne du¿e
int main()
{
	system("title Figury");
//ustawianie i czyszczenie szachownicy
	char chess[chessWidth][chessLength];
	for (int i = 0; i<chessWidth; i++)
		for (int j = 0; j<chessLength; j++)
			chess[i][j] = ' ';
	//Pozycja figur
	int positionX=0, positionY=0;
	char positionXChar=' ';
	bool check_cin = false;

	do {

		std::cout << "Podaj pozycje figury na szachownicy <a-h><1-8> ";
		positionXChar=_getch();
		std::cout << positionXChar;
		positionY = _getch();
		std::cout << positionY - (int)'0' << std::endl;
		//sprawdzenie czy nie istnieja zadne bledy w strumieniu wejscia
		if (((positionXChar<'a' || positionXChar>'h') && (positionXChar<'A' || positionXChar>'H'))) {
			system("cls");
			std::cout << "!POZYCJA FIGURY MA BYC POMIEDZY  \'a\' a \'h\' I POMIEDZY \'1\' a \'8\'" << std::endl
			<<"np. G2"<<std::endl;
		}

	} while ((positionXChar<'a' || positionXChar>'h') && (positionXChar<'A' || positionXChar>'H')|| positionY<'1' || positionY>chessWidth + (int)'0');
	positionX = convertToIndex(positionXChar);
	if (positionX == -1) {
		std::cout << "Cos poszlo nietak";
	}
	positionY-=(int)'0'+1;

//Zaczecie menu
	char color, figure;
	std::cout << "\n\t\t\tMENU" << std::endl
		<< "\tWybierz kolor" << std::endl
		<< "<b> Bialy" << std::endl
		<< "<c> Czarny" << std::endl
		<< "Twoj wybor: ";
	color = _getch();
	std::cout << color<<std::endl;
	switch (color)
	{
		//Biale figury (od 10)
	case 'b':
		system("title Figury - Biale");
		std::cout<< "\tWybierz figure" << std::endl
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
			//Wieza (11)
		case 'w':
			system("title Figury - Biale - Wieza");
			chess[chessLength-1-positionY][positionX] = 'w';
			tower(chessLength-1-positionY, positionX, chess);

			break;

			//Goniec (12)
		case 'g':
			system("title Figury - Biale - Goniec");
			chess[chessLength-1-positionY][positionX] = 'g';
			bishop(chessLength-1-positionY, positionX, chess);

			break;

			//Skoczek (13)
		case 's':
			system("title Figury - Biale - Skoczek");
			chess[chessLength-1-positionY][positionX] = 's';
			jumper(chessLength-1-positionY, positionX, chess);

			break;

			//Krol (14)
		case 'k':
			system("title Figury - Biale - Krol");
			chess[chessLength - 1 - positionY][positionX] = 'k';
			king(chessLength - 1 - positionY, positionX, chess);

			break;

			//Hetma/Queen/Krolowa (15)
		case 'h':
		case 'q':
			system("title Figury - Biale - Hetman");
			chess[chessLength - 1 - positionY][positionX] = 'q';
			queen(chessLength - 1 - positionY, positionX, chess);

			break;

			//Pionek (16)
		case 'p':
			system("title Figury - Biale - Pionek");
			if (chessLength - 1 - positionY == 0)
			{
				std::cout << "Nie jest mozliwe by pionek bialy byl na tym polu"<<std::endl;
				break;
			}
			chess[chessLength - 1 - positionY][positionX] = 'p';

			if (chessLength - 1 - positionY == 1)
			{
				chess[chessLength - 1 - positionY + 1][positionX] = 'X';
				chess[chessLength - 1 - positionY + 2][positionX] = 'X';
			}
			else if (chessLength - 1 - positionY == 7)
				std::cout << "Pionek bialy nie moze wykonac wiecej ruchow"<<std::endl;
			else
			{
				chess[chessLength - 1 - positionY + 1][positionX] = 'X';
			}
			break;

		default:
			std::cout << "Wybrano zla opcje (nieistniejaca)";
			check_cin = true;
			break;
		}
		break;

		//Czarne figury (od 20)
	case 'c':
		system("title Figury - Czarne");
		std::cout<< std::endl <<"\tWybierz figure"
			<< std::endl <<"<w> Wieza"
			<< std::endl <<"<g> Goniec"
			<< std::endl <<"<s> Skoczek"
			<< std::endl <<"<k> Krol"
			<< std::endl <<"<h> lub <q> Hetman/Queen"
			<< std::endl <<"<p> Pionek"
			<< std::endl <<"Twoj wybor: ";
		figure = _getch(); //wziêcie 1 znaku z klawiatury 
		std::cout << figure;
		system("cls");
		switch (figure)
		{
			//Wieza (21)
		case 'w':
			system("title Figury - Czarne - Wieza");
			chess[chessLength - 1 - positionY][positionX] = 'W';
			tower(chessLength - 1 - positionY, positionX, chess);
			break;

			//Goniec (22)
		case 'g':
			system("title Figury - Czarne - Goniec");
			chess[chessLength - 1 - positionY][positionX] = 'G';
			bishop(chessLength - 1 - positionY, positionX, chess);
			break;

			//Skoczek (23)
		case 's':
			system("title Figury - Czarne - Skoczek");
			chess[chessLength - 1 - positionY][positionX] = 'S';
			jumper(chessLength - 1 - positionY, positionX, chess);
			break;

			//Krol (24)
		case 'k':
			system("title Figury - Czarne - Krol");
			chess[chessLength - 1 - positionY][positionX] = 'K';
			king(chessLength - 1 - positionY, positionX, chess);
			break;

			//Hetma/Queen/Krolowa (25)
		case 'h':
		case 'q':
			system("title Figury - Czarne - Hetman");
			chess[chessLength - 1 - positionY][positionX] = 'Q';
			queen(chessLength - 1 - positionY, positionX, chess);
			break;

			//Pionek (26)
		case 'p':
			system("title Figury - Czarne - Pionek");
			if (chessLength - 1 - positionY == 7)
			{
				std::cout << "Nie jest mozliwe by pionek czarny byl na tym polu" << std::endl;
				break;
			}
			chess[chessLength - 1 - positionY][positionX] = 'P';

			if (chessLength - 1 - positionY == 6)
			{
				chess[chessLength - 1 - positionY - 1][positionX] = 'X';
				chess[chessLength - 1 - positionY - 2][positionX] = 'X';
			}
			else if (chessLength - 1 - positionY == 0)
				std::cout << "Pionek czarny nie moze wykonac wiecej ruchow" << std::endl;
			else
			{
				chess[chessLength - 1 - positionY - 1][positionX] = 'X';
			}
			break;

		default:
			std::cout << std::endl << "Wybrano zla opcje (nieistniejaca)";
			check_cin = true;
			break;
		}
		break;
	default:
		std::cout << std::endl << "Wybrano zla opcje (nieistniejaca)";
		check_cin = true;
		break;
	}

	if (!check_cin)
	{
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
		for (int i = 0; i<chessWidth; i++)
		{
			std::cout << chessLength - i << " ";
			for (int j = 0; j<chessLength; j++)
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
	_getch();
	return 0;
}


