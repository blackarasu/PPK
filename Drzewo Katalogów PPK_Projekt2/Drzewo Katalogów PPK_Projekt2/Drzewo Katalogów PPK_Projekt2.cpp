// Drzewo Katalogów PPK_Projekt2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <windows.h>

int const BUFFORSIZE = 200;

DWORD GetLastSlash(TCHAR Buffor[BUFFORSIZE],DWORD sizeOfBuffor) {
	for (auto i = sizeOfBuffor; i >= 0; i--) {
		if (Buffor[i] == '\\') {
			return i++;
		}
	}
}


int main()
{
	TCHAR Buffor[BUFFORSIZE];
	DWORD directoryNameSize =GetCurrentDirectoryW(BUFFORSIZE, Buffor);
	for (auto i = 0; i < directoryNameSize; i++) {
		std::cout << char(Buffor[i]);
	}
	DWORD positionOfLastSlash = GetLastSlash(Buffor, directoryNameSize);
	TCHAR* RootDirectory = new TCHAR[directoryNameSize - positionOfLastSlash];
	for (auto i = positionOfLastSlash; i < directoryNameSize; i++) {
		RootDirectory[i-positionOfLastSlash] = char(Buffor[i]);
	}
	
	
    return 0;
}

