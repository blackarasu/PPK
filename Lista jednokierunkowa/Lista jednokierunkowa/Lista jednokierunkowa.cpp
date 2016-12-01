// Lista jednokierunkowa.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>


struct lista {
	int metadata;
	lista* next;
};

int main()
{
	int data;
	lista* head;
	lista* last;
	head = new lista();
	last = head;
	for (int i = 1;; i++) {
		std::cout << "Type data " << i << " ";
		std::cin >> data;
		lista* newLista = new lista();
		newLista->metadata = data;//wpisanie dany "data" do listy;
		last->next = newLista;//dopisanie struktury na koniec ca³ej listy
		last = newLista;//przepisanie adresu astetniego elementu listy na pomocnicz¹ ostatni¹
	}
    return 0;
}

