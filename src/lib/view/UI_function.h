#pragma once
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <direct.h>
#include <string.h>
#include <windows.h>
#include "./console_function.h"
#include "../basic/basic_function.h"

void ShowProgramName(int x, int y, int w, int h, int sleep_time);
void Show_Loading_Time(int x = 59, int y = 8);
void ShowMessage(int x, int y, std::string message, int duration);
void Show_Error(int error_code);

void drawBox(int x, int y, int w, int h);
void showCourceListBox(int tabx, int taby, int size);
void showStudentList(int tabx, int taby, int size);
void showCreditClassList(int tabx, int taby, int size);
void showCreditClassStatus(int tabx, int taby, int size);
void showPointList(int tabx, int taby, int size);
void drawScoreBoard(int tabx, int taby, int size);
void vebangtongketdiem(int x, int y, int soSV, int so_mon_hoc, std::string maMH[1000]);

void clearScreen(int x_origin, int y_origin, int width, int height);
int XacNhan(int x_origin, int y_origin, std::string title, std::string luachon_1, std::string luachon_2);

// sleep time: mini second
void ShowProgramName(int x, int y, int w, int h, int sleep_time)
{

    std::string program_name = "CHUONG TRINH QUAN LY SINH VIEN";
    std::string teacherName = "GIAO VIEN HUONG DAN: THAY LUU NGUYEN KY THU";
    std::string groupName = "NHOM 10";

    const int colorSize = 15;
    int x_random = 0; // dung de random mang
    int pressed_key = 0;

    int a[colorSize + 1] = {0};
    for (int i = 1; i <= colorSize; i++)
    { // set default value
        if (i == 8)
            a[i] = 5;
        a[i] = i;
    }

    drawBox(x, y, w, h);

    // // show enter button
    gotoxy(x + 15, y + h + 2);
    std::cout << "NHAN ENTER DE BAT DAU";

    ShowCur(0); // tat hien thi con tro

    while (true)
    {

        if (_kbhit())
        {

            gotoxy(0, 0);
            std::cout << "hello world";
            status st = GetKey(getch());
            if (st == ENTER)
            {
                gotoxy(0, 0);
                std::cout << "hello world";
                SetColor(15); // set white color
                ShowCur(1);   // hien thi con tro
                return;
            }
        }

        for (int i = 1; i <= colorSize; i++)
        {
            x_random = i + rand() % (colorSize - i + 1);
            std::swap(a[i], a[x]);
        }

        for (int i = 1; i <= colorSize; i++)
        {
            clearScreen(x + 1, y + 1, w - 2, h - 2);

            gotoxy(x + 1 + (w - 2 - program_name.length()) / 2, y + 1);
            for (int j = 0; j < program_name.length(); j++)
            {
                i += 2;
                if (i < colorSize)
                {
                    SetColor(a[i]);
                    std::cout << program_name[j];
                }
                else
                {
                    i = 1;
                    SetColor(a[i]);
                    std::cout << program_name[j];
                }
            }
            gotoxy(x + 1 + (w - 2 - teacherName.length()) / 2, y + 2);
            for (int j = 0; j < teacherName.length(); j++)
            {
                i += 2;
                if (i < colorSize)
                {
                    SetColor(a[i]);
                    std::cout << teacherName[j];
                }
                else
                {
                    i = 1;
                    SetColor(a[i]);
                    std::cout << teacherName[j];
                }
            }
            gotoxy(x + 1 + (w - 2 - groupName.length()) / 2, y + 3);
            for (int j = 0; j < groupName.length(); j++)
            {

                i += 2;
                if (i < colorSize)
                {
                    SetColor(a[i]);
                    std::cout << groupName[j];
                }
                else
                {
                    i = 1;
                    SetColor(a[i]);
                    std::cout << groupName[j];
                }
            }

            Sleep(sleep_time);
        }
    }
}
void Show_Loading_Time(int x, int y)
{
    system("cls");

    ShowCur(0); // tat con tro

    int x_loading = x;
    int y_loading = y;
    int x_characters = (2 * x_loading + 10 - 20) / 2 + 1;
    int y_characters = y + 1;
    int sleep_time = 1;

    for (int i = 1; i <= 100; i++)
    {
        gotoxy(x_loading, y_loading);
        std::cout << "LOADING " << i << "%";
        if (i % 5 == 0)
        {
            // 176 177 178 219
            gotoxy(x_characters++, y_characters);
            std::cout << char(177);
        }
        Sleep(sleep_time);
    }

    Sleep(sleep_time);

    ShowCur(1); // mowr con tro
}
void ShowMessage(int x, int y, std::string message, int duration)
{
    gotoxy(x, y);
    SetColor(4);
    std::cout << message;
    SetColor(39);
    Sleep(duration);
}
// XAC NHAN TU PHIA NGUOI DUNG
void Show_Error(int error_code)
{
    if (error_code == 1)
        std::cout << "Sinh vien khong ton tai!";
    else if (error_code == 2)
        std::cout << "Lop tin chi khong ton tai!";
    else if (error_code == 3)
        std::cout << "Mon hoc khong ton tai!";
    else if (error_code == 4)
        std::cout << "Lop hoc khong ton tai!";
    else if (error_code == 5)
        std::cout << "Sinh vien da ton tai!";
    else if (error_code == 6)
        std::cout << "Lop tin chi da ton tai!";
    else if (error_code == 7)
        std::cout << "Mon hoc da ton tai!";
    else if (error_code == 8)
        std::cout << "Chuoi rong!";
    else if (error_code == 9)
        std::cout << "Sai: Vuot qua gioi han ky tu!";
    else if (error_code == 10)
        std::cout << "Sai: Nien khoa khong hop le!";
    else if (error_code == 11)
        std::cout << "Sai: Nhom qua lon hoac qua nho!";
    else if (error_code == 12)
        std::cout << "Sai: STCLT khong hop le!";
    else if (error_code == 13)
        std::cout << "Sai: STCTH khong hop le!";
    else if (error_code == 14)
        std::cout << "Sai: Hoc ky qua lon hoac qua nho!";
    else if (error_code == 15)
        std::cout << "Sai: MIN qua lon hoac qua nho!";
    else if (error_code == 16)
        std::cout << "Sai: MAX qua lon hoac qua nho!";
    else if (error_code == 17)
        std::cout << "Sai: Ma lop tin chi khong hop le!";
    else if (error_code == 18)
        std::cout << "Sai: Ma lop hoc khong hop le!";
    else if (error_code == 19)
        std::cout << "Sai: MAX phai >= MIN!";
    else if (error_code == 20)
        std::cout << "Sai: Diem phai >= 0!";
    else if (error_code == 21)
        std::cout << "Sai: Ten mon hoc trung lap!";
    else if (error_code == 101)
        std::cout << "Sai cu phap!";
}

void drawBox(int x, int y, int w, int h)
{
    for (int i = x; i < x + w; i++)
    {
        for (int j = y; j < y + h; j++)
        {
            if (i == x && j == y)
            {
                gotoxy(i, j);
                std::printf("+"); // top left
            }
            else if (i == x && j == y + h - 1)
            {
                gotoxy(i, j);
                std::printf("+"); // bottom left
            }
            else if (i == x + w - 1 && j == y)
            {
                gotoxy(i, j);
                std::printf("+"); // top right
            }
            else if (i == x + w - 1 && j == y + h - 1)
            {
                gotoxy(i, j);
                std::printf("+"); // bot right
            }
            else if (j == y)
            {
                gotoxy(i, j);
                std::printf("="); // bien tren
            }
            else if (j == y + h - 1)
            {
                gotoxy(i, j);
                std::printf("="); // bien duoi
            }
            else if (i == x)
            {
                gotoxy(i, j);
                std::printf("|"); // bien trai
            }
            else if (i == x + w - 1)
            {
                gotoxy(i, j);
                std::printf("|"); // bien phai
            }
            else
                continue;
        }
    }
}
void showCourceListBox(int tabx, int taby, int size)
{
    /*
                  x1             x2                        x3        x4
        +=========+==============+=========================+=========+=========+
        |   STT   |  MA MON HOC  |       TEN MON HOC       |  STCLT  |  STCTH  |
     y1 +=========+==============+=========================+=========+=========+
        |         |              |                         |         |         |
        |         |              |                         |         |         |
        +=========+==============+=========================+=========+=========+
    */
    int tabw = 71;
    int tabh = size + 4;
    int x1 = tabx + 10;
    int x2 = x1 + 15;
    int x3 = x2 + 26;
    int x4 = x3 + 10;
    int y1 = taby + 2;

    // draw border
    drawBox(tabx, taby, tabw, tabh);

    // STT
    gotoxy(tabx + 4, taby + 1);
    std::cout << "STT";
    gotoxy(x1 + 3, taby + 1);
    std::cout << "MA MON HOC";
    gotoxy(x2 + 8, taby + 1);
    std::cout << "TEN MON HOC";
    gotoxy(x3 + 3, taby + 1);
    std::cout << "STCLT";
    gotoxy(x4 + 3, taby + 1);
    std::cout << "STCTH";

    for (int i = 1; i < tabw - 1; i++)
    {
        gotoxy(tabx + i, y1);
        std::cout << "=";
    }

    for (int i = 1; i < tabh; i++)
    {
        gotoxy(x1, taby + i);
        std::cout << "|";
    }

    for (int i = 1; i < tabh; i++)
    {
        gotoxy(x2, taby + i);
        std::cout << "|";
    }

    for (int i = 1; i < tabh; i++)
    {
        gotoxy(x3, taby + i);
        std::cout << "|";
    }

    for (int i = 1; i < tabh; i++)
    {
        gotoxy(x4, taby + i);
        std::cout << "|";
    }

    gotoxy(tabx, y1);
    std::cout << "+";
    gotoxy(tabx + tabw - 1, y1);
    std::cout << "+";
    gotoxy(x1, taby);
    std::cout << "+";
    gotoxy(x1, y1);
    std::cout << "+";
    gotoxy(x1, taby + tabh - 1);
    std::cout << "+";
    gotoxy(x2, taby);
    std::cout << "+";
    gotoxy(x2, y1);
    std::cout << "+";
    gotoxy(x2, taby + tabh - 1);
    std::cout << "+";
    gotoxy(x3, taby);
    std::cout << "+";
    gotoxy(x3, y1);
    std::cout << "+";
    gotoxy(x3, taby + tabh - 1);
    std::cout << "+";
    gotoxy(x4, taby);
    std::cout << "+";
    gotoxy(x4, y1);
    std::cout << "+";
    gotoxy(x4, taby + tabh - 1);
    std::cout << "+";
}
void showStudentList(int tabx, int taby, int size)
{
    /*
                  x1             x2                 x3            x4          x5             x6
        +=========+==============+==================+=============+===========+==============+===============+
        |   STT   |     MSSV     |        HO        |     TEN     | GIOI TINH |    MA LOP    | SO DIEN THOAI |
      y1+=========+==============+==================+=============+===========+==============+===============+
        |         |              |                  |             |           |              |               |
        |         |              |                  |             |           |              |               |
        +=========+==============+==================+=============+===========+==============+===============+
    */

    int tabw = 102;
    int tabh = size + 4;
    int x1 = tabx + 10;
    int x2 = x1 + 15;
    int x3 = x2 + 19;
    int x4 = x3 + 14;
    int x5 = x4 + 12;
    int x6 = x5 + 15;
    int y1 = taby + 2;

    // draw border
    drawBox(tabx, taby, tabw, tabh);

    // STT
    gotoxy(tabx + 4, taby + 1);
    std::cout << "STT";
    // MSSV
    gotoxy(x1 + 6, taby + 1);
    std::cout << "MSSV";
    // HO SINHVIEN
    gotoxy(x2 + 9, taby + 1);
    std::cout << "HO";
    // TEN SINHVIEN
    gotoxy(x3 + 6, taby + 1);
    std::cout << "TEN";
    // GIOI TINH
    gotoxy(x4 + 2, taby + 1);
    std::cout << "GIOI TINH";
    // MA LOP
    gotoxy(x5 + 5, taby + 1);
    std::cout << "MA LOP";
    // SO DIEN THOAI
    gotoxy(x6 + 2, taby + 1);
    std::cout << "SO DIEN THOAI";

    for (int i = 1; i < tabw - 1; i++)
    {
        gotoxy(tabx + i, taby + 2);
        std::cout << "=";
    }

    for (int i = 1; i < tabh; i++)
    {
        gotoxy(x1, taby + i);
        std::cout << "|";
    }

    for (int i = 1; i < tabh; i++)
    {
        gotoxy(x2, taby + i);
        std::cout << "|";
    }

    for (int i = 1; i < tabh; i++)
    {
        gotoxy(x3, taby + i);
        std::cout << "|";
    }

    for (int i = 1; i < tabh; i++)
    {
        gotoxy(x4, taby + i);
        std::cout << "|";
    }

    for (int i = 1; i < tabh; i++)
    {
        gotoxy(x5, taby + i);
        std::cout << "|";
    }

    for (int i = 1; i < tabh; i++)
    {
        gotoxy(x6, taby + i);
        std::cout << "|";
    }

    gotoxy(tabx, taby + 2);
    std::cout << "+";
    gotoxy(tabx + tabw - 1, taby + 2);
    std::cout << "+";

    gotoxy(x1, taby);
    std::cout << "+";
    gotoxy(x1, taby + 2);
    std::cout << "+";
    gotoxy(x1, taby + tabh - 1);
    std::cout << "+";

    gotoxy(x2, taby);
    std::cout << "+";
    gotoxy(x2, taby + 2);
    std::cout << "+";
    gotoxy(x2, taby + tabh - 1);
    std::cout << "+";

    gotoxy(x3, taby);
    std::cout << "+";
    gotoxy(x3, taby + 2);
    std::cout << "+";
    gotoxy(x3, taby + tabh - 1);
    std::cout << "+";

    gotoxy(x4, taby);
    std::cout << "+";
    gotoxy(x4, taby + 2);
    std::cout << "+";
    gotoxy(x4, taby + tabh - 1);
    std::cout << "+";

    gotoxy(x5, taby);
    std::cout << "+";
    gotoxy(x5, taby + 2);
    std::cout << "+";
    gotoxy(x5, taby + tabh - 1);
    std::cout << "+";

    gotoxy(x6, taby);
    std::cout << "+";
    gotoxy(x6, taby + 2);
    std::cout << "+";
    gotoxy(x6, taby + tabh - 1);
    std::cout << "+";
}
void showCreditClassList(int tabx, int taby, int size)
{
    /*        x1       x2           x3            x4       x5       x6        x7        x8
        +=====+========+============+=============+========+========+=========+=========+=============+
        | STT | MA LOP |   MA MON   |  NIEN KHOA  | HOC KY |  NHOM  | SOSVMIN | SOSVMAX |  TINH TRANG |
    y1  +=====+========+============+=============+========+========+=========+=========+=============+
        |     |        |            | 2020 - 2021 |        |        |         |         |  HOAT DONG  |
        |     |        |            |             |        |        |         |         |             |
        +=====+========+============+=============+========+========+=========+=========+=============+
    */
    int tabw = 95;
    int tabh = size + 4;
    int x1 = tabx + 6;
    int x2 = x1 + 9;
    int x3 = x2 + 13;
    int x4 = x3 + 14;
    int x5 = x4 + 9;
    int x6 = x5 + 9;
    int x7 = x6 + 10;
    int x8 = x7 + 10;
    int y1 = taby + 2;

    // draw border
    drawBox(tabx, taby, tabw, tabh);

    gotoxy(tabx + 2, taby + 1);
    std::cout << "STT";
    gotoxy(x1 + 2, taby + 1);
    std::cout << "MA LOP";
    gotoxy(x2 + 4, taby + 1);
    std::cout << "MA MON";
    gotoxy(x3 + 3, taby + 1);
    std::cout << "NIEN KHOA";
    gotoxy(x4 + 2, taby + 1);
    std::cout << "HOC KY";
    gotoxy(x5 + 3, taby + 1);
    std::cout << "NHOM";
    gotoxy(x6 + 2, taby + 1);
    std::cout << "SOSVMIN";
    gotoxy(x7 + 2, taby + 1);
    std::cout << "SOSVMAX";
    gotoxy(x8 + 3, taby + 1);
    std::cout << "TINH TRANG";

    for (int i = 1; i < tabw - 1; i++)
    {
        gotoxy(tabx + i, y1);
        std::cout << "=";
    }

    for (int i = 1; i < tabh; i++)
    {
        gotoxy(x1, taby + i);
        std::cout << "|";
    }

    for (int i = 1; i < tabh; i++)
    {
        gotoxy(x2, taby + i);
        std::cout << "|";
    }

    for (int i = 1; i < tabh; i++)
    {
        gotoxy(x3, taby + i);
        std::cout << "|";
    }

    for (int i = 1; i < tabh; i++)
    {
        gotoxy(x4, taby + i);
        std::cout << "|";
    }

    for (int i = 1; i < tabh; i++)
    {
        gotoxy(x5, taby + i);
        std::cout << "|";
    }

    for (int i = 1; i < tabh; i++)
    {
        gotoxy(x6, taby + i);
        std::cout << "|";
    }

    for (int i = 1; i < tabh; i++)
    {
        gotoxy(x7, taby + i);
        std::cout << "|";
    }

    for (int i = 1; i < tabh; i++)
    {
        gotoxy(x8, taby + i);
        std::cout << "|";
    }

    gotoxy(tabx, y1);
    std::cout << "+";
    gotoxy(tabx + tabw - 1, y1);
    std::cout << "+";

    gotoxy(x1, taby);
    std::cout << "+";
    gotoxy(x1, y1);
    std::cout << "+";
    gotoxy(x1, taby + tabh - 1);
    std::cout << "+";

    gotoxy(tabx + 15, taby);
    std::cout << "+";
    gotoxy(tabx + 15, y1);
    std::cout << "+";
    gotoxy(tabx + 15, taby + tabh - 1);
    std::cout << "+";

    gotoxy(x1, taby);
    std::cout << "+";
    gotoxy(x1, y1);
    std::cout << "+";
    gotoxy(x1, taby + tabh - 1);
    std::cout << "+";

    gotoxy(x2, taby);
    std::cout << "+";
    gotoxy(x2, y1);
    std::cout << "+";
    gotoxy(x2, taby + tabh - 1);
    std::cout << "+";

    gotoxy(x3, taby);
    std::cout << "+";
    gotoxy(x3, y1);
    std::cout << "+";
    gotoxy(x3, taby + tabh - 1);
    std::cout << "+";

    gotoxy(x4, taby);
    std::cout << "+";
    gotoxy(x4, y1);
    std::cout << "+";
    gotoxy(x4, taby + tabh - 1);
    std::cout << "+";

    gotoxy(x5, taby);
    std::cout << "+";
    gotoxy(x5, y1);
    std::cout << "+";
    gotoxy(x5, taby + tabh - 1);
    std::cout << "+";

    gotoxy(x6, taby);
    std::cout << "+";
    gotoxy(x6, y1);
    std::cout << "+";
    gotoxy(x6, taby + tabh - 1);
    std::cout << "+";

    gotoxy(x7, taby);
    std::cout << "+";
    gotoxy(x7, y1);
    std::cout << "+";
    gotoxy(x7, taby + tabh - 1);
    std::cout << "+";

    gotoxy(x8, taby);
    std::cout << "+";
    gotoxy(x8, y1);
    std::cout << "+";
    gotoxy(x8, taby + tabh - 1);
    std::cout << "+";
}
void showCreditClassStatus(int tabx, int taby, int size)
{
    /*
              x1       x2         x3                              x4        x5             x6
        +=====+========+==========+===============================+=========+==============+==============+
        | STT | MA LOP |  MA MON  |           TEN MON             |   NHOM  | SLOT DANG KY | SLOT CON LAI |
     y1 +=====+========+==========+===============================+=========+==============+==============+
        |     |        |          |                               |         |              |              |
        |     |        |          |                               |         |              |              |
        +=====+========+==========+===============================+=========+==============+==============+
    */
    int tabw = 99;
    int tabh = size + 4;
    int x1 = tabx + 6;
    int x2 = x1 + 9;
    int x3 = x2 + 11;
    int x4 = x3 + 32;
    int x5 = x4 + 10;
    int x6 = x5 + 15;

    // draw border
    drawBox(tabx, taby, tabw, tabh);

    // STT
    gotoxy(tabx + 2, taby + 1);
    std::cout << "STT";
    // MA LOP
    gotoxy(x1 + 2, taby + 1);
    std::cout << "MA LOP";
    // MA MON
    gotoxy(x2 + 3, taby + 1);
    std::cout << "MA MON";
    // TEN MON
    gotoxy(x3 + 12, taby + 1);
    std::cout << "TEN MON";
    // NHOM
    gotoxy(x4 + 4, taby + 1);
    std::cout << "NHOM";
    // SLOT DK
    gotoxy(x5 + 2, taby + 1);
    std::cout << "SLOT DANG KY";
    // SLOT CON LAI
    gotoxy(x6 + 2, taby + 1);
    std::cout << "SLOT CON LAI";

    for (int i = 1; i < tabw - 1; i++)
    {
        gotoxy(tabx + i, taby + 2);
        std::cout << "=";
    }

    for (int i = 1; i < tabh; i++)
    {
        gotoxy(x1, taby + i);
        std::cout << "|";
    }

    for (int i = 1; i < tabh; i++)
    {
        gotoxy(x2, taby + i);
        std::cout << "|";
    }

    for (int i = 1; i < tabh; i++)
    {
        gotoxy(x3, taby + i);
        std::cout << "|";
    }

    for (int i = 1; i < tabh; i++)
    {
        gotoxy(x4, taby + i);
        std::cout << "|";
    }

    for (int i = 1; i < tabh; i++)
    {
        gotoxy(x5, taby + i);
        std::cout << "|";
    }

    for (int i = 1; i < tabh; i++)
    {
        gotoxy(x6, taby + i);
        std::cout << "|";
    }

    gotoxy(tabx, taby + 2);
    std::cout << "+";
    gotoxy(tabx + tabw - 1, taby + 2);
    std::cout << "+";

    gotoxy(x1, taby);
    std::cout << "+";
    gotoxy(x1, taby + 2);
    std::cout << "+";
    gotoxy(x1, taby + tabh - 1);
    std::cout << "+";

    gotoxy(x2, taby);
    std::cout << "+";
    gotoxy(x2, taby + 2);
    std::cout << "+";
    gotoxy(x2, taby + tabh - 1);
    std::cout << "+";

    gotoxy(x3, taby);
    std::cout << "+";
    gotoxy(x3, taby + 2);
    std::cout << "+";
    gotoxy(x3, taby + tabh - 1);
    std::cout << "+";

    gotoxy(x4, taby);
    std::cout << "+";
    gotoxy(x4, taby + 2);
    std::cout << "+";
    gotoxy(x4, taby + tabh - 1);
    std::cout << "+";

    gotoxy(x5, taby);
    std::cout << "+";
    gotoxy(x5, taby + 2);
    std::cout << "+";
    gotoxy(x5, taby + tabh - 1);
    std::cout << "+";

    gotoxy(x6, taby);
    std::cout << "+";
    gotoxy(x6, taby + 2);
    std::cout << "+";
    gotoxy(x6, taby + tabh - 1);
    std::cout << "+";
}
void showPointList(int tabx, int taby, int size)
{
    /*
                  x1             x2                     x3                x4
        +=========+==============+======================+=================+============+
        |   STT   |     MSSV     |          HO          |       TEN       |   DIEM TB  |
    y1  +=========+==============+======================+=================+============+
        |         |              |                      |                 |            |
        |         |              |                      |                 |            |
        +=========+==============+======================+=================+============+
    */
    int tabw = 80;
    int tabh = size + 4;
    int x1 = tabx + 10;
    int x2 = x1 + 15;
    int x3 = x2 + 23;
    int x4 = x3 + 18;

    // draw border
    drawBox(tabx, taby, tabw, tabh);

    // STT
    gotoxy(tabx + 4, taby + 1);
    std::cout << "STT";
    // MSSV
    gotoxy(x1 + 6, taby + 1);
    std::cout << "MSSV";
    // HO
    gotoxy(x2 + 11, taby + 1);
    std::cout << "HO";
    // TEN
    gotoxy(x3 + 8, taby + 1);
    std::cout << "TEN";
    // DIEM TB
    gotoxy(x4 + 4, taby + 1);
    std::cout << "DIEM TB";

    for (int i = 1; i < tabw - 1; i++)
    {
        gotoxy(tabx + i, taby + 2);
        std::cout << "=";
    }

    for (int i = 1; i < tabh; i++)
    {
        gotoxy(x1, taby + i);
        std::cout << "|";
    }

    for (int i = 1; i < tabh; i++)
    {
        gotoxy(x2, taby + i);
        std::cout << "|";
    }

    for (int i = 1; i < tabh; i++)
    {
        gotoxy(x3, taby + i);
        std::cout << "|";
    }

    for (int i = 1; i < tabh; i++)
    {
        gotoxy(x4, taby + i);
        std::cout << "|";
    }

    gotoxy(tabx, taby + 2);
    std::cout << "+";
    gotoxy(tabx + tabw - 1, taby + 2);
    std::cout << "+";

    gotoxy(x1, taby);
    std::cout << "+";
    gotoxy(x1, taby + 2);
    std::cout << "+";
    gotoxy(x1, taby + tabh - 1);
    std::cout << "+";

    gotoxy(x2, taby);
    std::cout << "+";
    gotoxy(x2, taby + 2);
    std::cout << "+";
    gotoxy(x2, taby + tabh - 1);
    std::cout << "+";

    gotoxy(x3, taby);
    std::cout << "+";
    gotoxy(x3, taby + 2);
    std::cout << "+";
    gotoxy(x3, taby + tabh - 1);
    std::cout << "+";

    gotoxy(x4, taby);
    std::cout << "+";
    gotoxy(x4, taby + 2);
    std::cout << "+";
    gotoxy(x4, taby + tabh - 1);
    std::cout << "+";
}
void drawScoreBoard(int tabx, int taby, int size)
{

    /*
        x         x1             x2                     x3                x4
        +=========+==============+======================+=================+==================+
        |   STT   |     MSSV     |          HO          |       TEN       |       DIEM       |
     y1 +=========+==============+======================+=================+==================+
        |         |              |                      |                 |                  |
        |         |              |                      |                 |                  |
        +=========+==============+======================+=================+==================+
    */
    int tabw = 86;
    int tabh = size + 4;
    int x1 = tabx + 10;
    int x2 = x1 + 15;
    int x3 = x2 + 23;
    int x4 = x3 + 18;
    int y1 = taby + 2;

    // draw border
    drawBox(tabx, taby, tabw, tabh);

    // STT
    gotoxy(tabx + 4, taby + 1);
    std::cout << "STT";
    // MSSV
    gotoxy(tabx + 16, taby + 1);
    std::cout << "MSSV";
    // HO SINHVIEN
    gotoxy(tabx + 36, taby + 1);
    std::cout << "HO";
    // TEN SINHVIEN
    gotoxy(tabx + 56, taby + 1);
    std::cout << "TEN";
    // DIEM
    gotoxy(tabx + 74, taby + 1);
    std::cout << "DIEM";

    for (int i = 1; i < tabw - 1; i++)
    {
        gotoxy(tabx + i, y1);
        std::cout << "=";
    }

    for (int i = 1; i < tabh; i++)
    {
        gotoxy(x1, taby + i);
        std::cout << "|";
    }

    for (int i = 1; i < tabh; i++)
    {
        gotoxy(x2, taby + i);
        std::cout << "|";
    }

    for (int i = 1; i < tabh; i++)
    {
        gotoxy(x3, taby + i);
        std::cout << "|";
    }

    for (int i = 1; i < tabh; i++)
    {
        gotoxy(x4, taby + i);
        std::cout << "|";
    }

    gotoxy(tabx, y1);
    std::cout << "+";
    gotoxy(tabx + tabw - 1, y1);
    std::cout << "+";

    gotoxy(x1, taby);
    std::cout << "+";
    gotoxy(x1, y1);
    std::cout << "+";
    gotoxy(x1, taby + tabh - 1);
    std::cout << "+";

    gotoxy(x2, taby);
    std::cout << "+";
    gotoxy(x2, y1);
    std::cout << "+";
    gotoxy(x2, taby + tabh - 1);
    std::cout << "+";

    gotoxy(x3, taby);
    std::cout << "+";
    gotoxy(x3, y1);
    std::cout << "+";
    gotoxy(x3, taby + tabh - 1);
    std::cout << "+";

    gotoxy(x4, taby);
    std::cout << "+";
    gotoxy(x4, y1);
    std::cout << "+";
    gotoxy(x4, taby + tabh - 1);
    std::cout << "+";
}
void vebangtongketdiem(int x, int y, int soSV, int so_mon_hoc, std::string maMH[1000])
{
    /*
        <-------------------left_side--------------------->
        x          x1           x2                        x3        <--Step--->
      y +=========+============+==========================+=========+=========+=========+
        |   STT   |    MSSV    |          HO TEN          |   MH    |   MH2   |   MH3   |
        +=========+============+==========================+=========+=========+=========+
        |         |            |                          |         |         |         |
        |         |            |                          |         |         |         |
        +=========+============+==========================+=========+=========+=========+
    */
    int x1 = x + 10;
    int x2 = x1 + 13;
    int x3 = x2 + 27;
    int step = 10;
    // left_size la chieu dai tu dau table den het phan cot HOTEN
    int left_size = x3 - x + 1;
    int w = so_mon_hoc * step + left_size;
    int h = soSV + 4;

    drawBox(x, y, w, h); // ve vien bao quanh

    // STT
    gotoxy(x + 4, y + 1);
    std::cout << "STT";
    // MSSV
    gotoxy(x1 + 5, y + 1);
    std::cout << "MSSV";
    // HO SINHVIEN
    gotoxy(x2 + 11, y + 1);
    std::cout << "HO TEN";

    for (int i = 1; i < w; i++)
    {
        gotoxy(x + i, y + 2);
        std::cout << "=";
    }

    for (int i = 1; i < h; i++)
    {
        gotoxy(x1, y + i);
        std::cout << "|";
    }

    for (int i = 1; i < h; i++)
    {
        gotoxy(x2, y + i);
        std::cout << "|";
    }

    for (int i = 1; i < h; i++)
    {
        gotoxy(x3, y + i);
        std::cout << "|";
    }

    // ve cot ghi diem
    for (int n = 1; n <= so_mon_hoc; n++)
    {
        gotoxy(x3 + n * step - 6, y + 1);
        std::cout << maMH[n - 1];
        for (int i = 1; i < h; i++)
        {
            gotoxy(x3 + n * step, y + i);
            std::cout << "|";
        }
        gotoxy(x3 + n * step, y);
        std::cout << "+";
        gotoxy(x3 + n * step, y + 2);
        std::cout << "+";
        gotoxy(x3 + n * step, y + h - 1);
        std::cout << "+";
    }

    gotoxy(x1, y + 2);
    std::cout << "+";
    gotoxy(x1, y + h - 1);
    std::cout << "+";
    gotoxy(x1, y);
    std::cout << "+";

    gotoxy(x2, y + 2);
    std::cout << "+";
    gotoxy(x2, y + h - 1);
    std::cout << "+";
    gotoxy(x2, y);
    std::cout << "+";

    gotoxy(x3, y);
    std::cout << "+";
    gotoxy(x3, y + 2);
    std::cout << "+";
    gotoxy(x3, y + h - 1);
    std::cout << "+";
}

void clearScreen(int x_origin, int y_origin, int width, int height)
{
    for (int i = 0; i <= height; i++)
    {
        gotoxy(x_origin, y_origin + i);
        for (int j = 1; j <= width + 1; j++)
            std::cout << " ";
    }
}
int XacNhan(int x_origin, int y_origin, std::string title, std::string luachon_1, std::string luachon_2)
{

    ShowCur(0); // an con tro van ban
    // title co chuc nang in ra thong bao toi nguoi dung
    int pos = 1;
    int luachon;

    int length_of_box = 10 + luachon_1.length() + luachon_2.length();

    // tao title thong bao
    int x_title = (2 * x_origin + length_of_box - title.length()) / 2; // toa do cua Title

    SetColor(39);

    gotoxy((2 * x_origin + length_of_box - title.length()) / 2, y_origin);
    SetColor(4);
    std::cout << title;
    SetColor(39);

    gotoxy(x_origin, y_origin + 1);
    std::cout << "              ";
    gotoxy(x_origin, y_origin + 2);
    std::cout << luachon_1 << "          " << luachon_2;

    gotoxy(x_origin, y_origin + 2); // khoi tao gia tri ban dau, hightlight YES
    SetColor(1);
    std::cout << luachon_1;

    // int keyhit;
    while (true)
    {
        luachon = getch();

        if (luachon == 75)
        {
            if (pos == 1)
            {
                gotoxy(x_origin, y_origin + 2);
                SetColor(39);
                std::cout << luachon_1;

                pos = 0;
                gotoxy(x_origin + 10 + luachon_1.length(), y_origin + 2);
                SetColor(1);
                std::cout << luachon_2;
            }
            else if (pos == 0)
            {

                gotoxy(x_origin + 10 + luachon_1.length(), y_origin + 2);
                SetColor(39);
                std::cout << luachon_2;

                pos = 1;
                gotoxy(x_origin, y_origin + 2);
                SetColor(1);
                std::cout << luachon_1;
            }
        }
        else if (luachon == 77)
        {
            if (pos == 1)
            {

                gotoxy(x_origin, y_origin + 2);
                SetColor(39);
                std::cout << luachon_1;

                pos = 0;
                gotoxy(x_origin + 10 + luachon_1.length(), y_origin + 2);
                SetColor(1);
                std::cout << luachon_2;
            }

            else if (pos == 0)
            {

                gotoxy(x_origin + 10 + luachon_1.length(), y_origin + 2);
                SetColor(39);
                std::cout << luachon_2;

                pos = 1;
                gotoxy(x_origin, y_origin + 2);
                SetColor(1);
                std::cout << luachon_1;
            }
        }

        else if (pos == 1 && luachon == 13)
        { // CHON YES
            SetColor(39);
            clearScreen(40, y_origin, 50, 5);
            ShowCur(1); // hien con tro van ban
            return 1;
        }

        else if (pos == 0 && luachon == 13)
        { // CHON NO
            SetColor(39);
            clearScreen(40, y_origin, 50, 5);
            ShowCur(1); // hien con tro van ban
            return 0;
        }
    }
}
