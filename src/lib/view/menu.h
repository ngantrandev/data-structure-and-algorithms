#pragma once
#include <iostream>
#include <conio.h>
#include "./UI_function.h"
#include "../basic/basic_function.h"

// path: lib\basic\menu.h

int menu(int x, int y, int w, std::string *menuName, int size, int &out, int &pos)
{
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
					std::cout << i + 1 << "    " << menuName[i] << std::endl;
			}
		}

		SetColor(23);
		// gotoxy((2 * x + w - 62) / 2 + 4, y + size + 5);
		// std::printf("[SELECT:ENTER]     [EXIT:ESC]     [UP: UP ARROW]     [DOWN: DOWN ARROW]");

		int key_hit = getch();
		status stt = GetKey(key_hit);
		switch (stt)
		{
		case UP:
		LEFT:
		{
			(pos == 0) ? pos = size - 1 : pos--;
			gotoxy(1, 1);
			std::cout << pos;
			break;
		};
		case DOWN:
		RIGHT:
		{
			(pos == size - 1) ? pos = 0 : pos++;
			gotoxy(1, 1);
			std::cout << pos;
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
}