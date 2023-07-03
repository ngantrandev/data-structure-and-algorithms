#pragma once
#include <iostream>
#include <conio.h>
#include "./drawBoard.h"
#include "../basic/basic_function.h"

// path: lib\basic\menu.h

int menu(int x, int y, std::string *menuName, int size, int &pos)
{
	/*
		+===========================================+
		| 1    Cap nhat lop tin chi                 |
		| 2    In danh sach sinh vien lop tin chi   |
		| 3    Cap nhat sinh vien lop hoc           |
		| 4    In danh sach sinh vien lop hoc       |
		| 5    Cap nhat danh sach mon hoc           |
		+===========================================+
	*/

	int w = menuName[0].length() + 8;

	drawBox(x, y, w, size + 2);
	SetColor("WHITE");
	gotoxy(x, y + 3 + size);
	std::string description = "[SELECT:ENTER]     [EXIT:ESC]     [UP: UP ARROW]     [DOWN: DOWN ARROW]";
	std::printf(description.c_str());

	while (true)
	{
		SetColor(23); // white

		for (int i = 0; i < size; i++)
		{
			gotoxy(x + 2, y + i + 1);

			if (i == pos)
			{
				SetColor(241); // blue
				if (i + 1 < 10)
					std::cout << i + 1 << "  "
							  << ">" << menuName[i] << std::endl;
				else
					std::cout << i + 1 << " "
							  << ">" << menuName[i] << std::endl;
			}
			else
			{
				SetColor(23); // white
				if (i + 1 < 10)
					std::cout << i + 1 << "    " << menuName[i] << std::endl;

				else
					std::cout << i + 1 << "   " << menuName[i] << std::endl;
			}
		}

		int key_hit = getch();
		std::string keyType = getKeyType(key_hit);

		if (keyType == "UP" || keyType == "LEFT")
		{
			(pos == 0) ? pos = size - 1 : pos--;
		}
		else if (keyType == "DOWN" || keyType == "RIGHT")
		{
			(pos == size - 1) ? pos = 0 : pos++;
		}
		else if (keyType == "ENTER")
		{
			clearScreen(x, y, w > description.length() ? w : description.length(), y + 3 + size);
			SetColor("WHITE");
			return 0;
		}
		else if (keyType == "EXIT")
		{
			if (XacNhan(x, y + 5 + size, "BAN CO CHAC MUON THOAT?") == "YES")
			{
				clearScreen(x, y, w > description.length() ? w : description.length(), y + 3 + size);
				SetColor("WHITE");
				return 1;
			}
		}
	}

	return 1;
}