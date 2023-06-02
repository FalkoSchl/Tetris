#include "pch.h"
#include <iostream>
#include <windows.h>
#include "Spiel.h"

int main()
{
	srand(time(NULL));
	Spiel Tetris;
	COORD abcd;									//Cursor verschwindet und anstatt "system ('cls')"
	abcd.X = 0; //koordinaten x
	abcd.Y = 0; //koordinaten y
	CONSOLE_CURSOR_INFO info;
	HANDLE  out;

	info.bVisible = 0;
	info.dwSize = 1;

	out = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorInfo(out, &info);		//
	while (true) {
		Tetris.blockform();
		Tetris.blockbewegen();
		Tetris.display();
		Tetris.reihelöschen();
		Sleep(50);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), abcd);	//anstatt "system('cls')"
	}
}