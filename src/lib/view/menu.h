#pragma once
#include <iostream>
#include <conio.h>
#include "UI_function.h"
#include "basic_function.h"

// path: lib\basic\menu.h

int menu(int x, int y, int w, std::string *menuName, int size, int &out, int &pos) {
	std::cout<<"nemd";
	std::printf("menu");
	while (true)
	{

		SetColor(23); // white
		drawBox(x, y, w, size + 1);

		for (int i = 0; i < size; i++)
		{
			gotoxy(x + 1, y + i + 1);

			if (i == pos)
			{
				SetColor(241); // blue
				if (i + 1 < 10)
					std::printf("%d   %c%s \n", i + 1, char(16), menuName[i]);
				else
					std::printf("%d  %c%s \n", i + 1, char(16), menuName[i]);
			}
			else
			{
				SetColor(23); // white
				if (i + 1 < 10)
					std::printf("%d     %s\n", i + 1, menuName[i]);
				else
					std::printf("%d    %s\n", i + 1, menuName[i]);
			}
		}

		SetColor(23);
		gotoxy((2 * x + w - 62) / 2 + 4, y + size + 5);
		std::printf("[SELECT:ENTER]     [EXIT:ESC]     [UP:%c/%c]     [DOWN:%c/%c]", char(30), char(17), char(31), char(16));

		int key_hit = getch();
		status stt = GetKey(key_hit);
		switch (stt)
		{
		case UP:
		LEFT:
		{
			(pos == 0) ? pos = size - 1 : pos--;
			break;
		};
		case DOWN:
		RIGHT:
		{
			(pos == size - 1) ? pos = 0 : pos++;
			break;
		}
		case ENTER:
			return pos + 1;
		case EXIT:
		{
			out = 1;
			return pos = 0;
		}
		}
	} // end while


	return 0;

	// while(true) {
	// 	for(int i = 0;i<size;i++){
	// 	gotoxy(x + 1, y + i + 1);

	// 		if (i == pos)
	// 		{
	// 			SetColor(241); // blue
	// 			if (i + 1 < 10)
	// 				std::printf("%d   %c%s \n", i + 1, char(16), menuName[i]);
	// 			else
	// 				std::printf("%d  %c%s \n", i + 1, char(16), menuName[i]);
	// 		}
	// 		else
	// 		{
	// 			SetColor(23); // white
	// 			if (i + 1 < 10)
	// 				std::printf("%d     %s\n", i + 1, menuName[i]);
	// 			else
	// 				std::printf("%d    %s\n", i + 1, menuName[i]);
	// 		}
	// }
	// }


}

// int Menu(int x, int y, int w, int size, char menuName[10][100], int &out, int &pos)
// {

// 	while (true)
// 	{

// 		SetColor(23); // white
// 		drawBox(x, y, w, size + 1);

// 		for (int i = 0; i < size; i++)
// 		{
// 			gotoxy(x + 1, y + i + 1);

// 			if (i == pos)
// 			{
// 				SetColor(241); // blue
// 				if (i + 1 < 10)
// 					std::printf("%d   %c%s \n", i + 1, char(16), menuName[i]);
// 				else
// 					std::printf("%d  %c%s \n", i + 1, char(16), menuName[i]);
// 			}
// 			else
// 			{
// 				SetColor(23); // white
// 				if (i + 1 < 10)
// 					std::printf("%d     %s\n", i + 1, menuName[i]);
// 				else
// 					std::printf("%d    %s\n", i + 1, menuName[i]);
// 			}
// 		}

// 		SetColor(23);
// 		gotoxy((2 * x + w - 62) / 2 + 4, y + size + 5);
// 		std::printf("[SELECT:ENTER]     [EXIT:ESC]     [UP:%c/%c]     [DOWN:%c/%c]", char(30), char(17), char(31), char(16));

// 		int key_hit = getch();
// 		status stt = GetKey(key_hit);
// 		switch (stt)
// 		{
// 		case UP:
// 		LEFT:
// 		{
// 			(pos == 0) ? pos = size - 1 : pos--;
// 			break;
// 		};
// 		case DOWN:
// 		RIGHT:
// 		{
// 			(pos == size - 1) ? pos = 0 : pos++;
// 			break;
// 		}
// 		case ENTER:
// 			return pos + 1;
// 		case EXIT:
// 		{
// 			out = 1;
// 			return pos = 0;
// 		}
// 		}
// 	} // end while
// }