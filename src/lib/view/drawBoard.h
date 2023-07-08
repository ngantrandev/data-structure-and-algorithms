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

void drawBox(int x, int y, int w, int h);
void drawCourseInfoBoard(int x, int y, int size);
void drawStudentInfoBoard(int x, int y, int size);
void drawCreditClassInfoBoard(int x, int y, int size);
void drawCreditClassStatusBoard(int x, int y, int size);
void drawAvgScoreBoard(int x, int y, int size);
void drawScoreBoard(int x, int y, int size);
void drawFinalScoreBoard(int x, int y, int so_mon_hoc, std::vector<PTRMH> dsMH);

void clearScreen(int x_origin, int y_origin, int width, int height);
void clearBorder(int x, int y, int w, int h);
// max title length = 30
std::string XacNhan(int x, int y, std::string title);

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
            std::string st = getKeyType(getch());
            if (st == "ENTER")
            {
                gotoxy(0, 0);
                std::cout << "hello world";
                SetColor("WHITE"); // set white color
                ShowCur(1);        // hien thi con tro
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
    SetColor("RED");
    std::cout << message;
    SetColor("WHITE");
    Sleep(duration);

    clearScreen(x, y, message.length(), 1);
}

void drawBox(int x, int y, int w, int h)
{
    /*
        +================================================+
        |                                                |
        |                                                |
        |                                                |
        |                                                |
        +================================================+
    */
    for (int i = x; i < x + w; i++)
    {
        for (int j = y; j < y + h; j++)
        {
            if (isInSaveArea(i, j) == false)
                continue;
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
void drawCourseInfoBoard(int x, int y, int size)
{
    /*
        x         x1             x2                        x3        x4
        +=========+==============+=========================+=========+=========+
        |   STT   |  MA MON HOC  |       TEN MON HOC       |  STCLT  |  STCTH  |
     y1 +=========+==============+=========================+=========+=========+
        |         |              |                         |         |         |
        |         |              |                         |         |         |
        +=========+==============+=========================+=========+=========+
    */
    int tabw = COURSE_INFO_BOARD_WIDTH;
    int tabh = size + 4;
    int x1 = x + 10;
    int x2 = x1 + 15;
    int x3 = x2 + 26;
    int x4 = x3 + 10;
    int y1 = y + 2;

    // draw border
    drawBox(x, y, tabw, tabh);

    // STT
    gotoxy(x + 4, y + 1);
    std::cout << "STT";
    gotoxy(x1 + 3, y + 1);
    std::cout << "MA MON HOC";
    gotoxy(x2 + 8, y + 1);
    std::cout << "TEN MON HOC";
    gotoxy(x3 + 3, y + 1);
    std::cout << "STCLT";
    gotoxy(x4 + 3, y + 1);
    std::cout << "STCTH";

    for (int i = 1; i < tabw - 1; i++)
    {
        gotoxy(x + i, y1);
        std::cout << "=";
    }

    for (int i = 1; i < tabh; i++)
    {
        gotoxy(x1, y + i);
        std::cout << "|";
    }

    for (int i = 1; i < tabh; i++)
    {
        gotoxy(x2, y + i);
        std::cout << "|";
    }

    for (int i = 1; i < tabh; i++)
    {
        gotoxy(x3, y + i);
        std::cout << "|";
    }

    for (int i = 1; i < tabh; i++)
    {
        gotoxy(x4, y + i);
        std::cout << "|";
    }

    gotoxy(x, y1);
    std::cout << "+";
    gotoxy(x + tabw - 1, y1);
    std::cout << "+";
    gotoxy(x1, y);
    std::cout << "+";
    gotoxy(x1, y1);
    std::cout << "+";
    gotoxy(x1, y + tabh - 1);
    std::cout << "+";
    gotoxy(x2, y);
    std::cout << "+";
    gotoxy(x2, y1);
    std::cout << "+";
    gotoxy(x2, y + tabh - 1);
    std::cout << "+";
    gotoxy(x3, y);
    std::cout << "+";
    gotoxy(x3, y1);
    std::cout << "+";
    gotoxy(x3, y + tabh - 1);
    std::cout << "+";
    gotoxy(x4, y);
    std::cout << "+";
    gotoxy(x4, y1);
    std::cout << "+";
    gotoxy(x4, y + tabh - 1);
    std::cout << "+";
}
void drawStudentInfoBoard(int x, int y, int size)
{
    /*
        x         x1             x2                 x3            x4          x5             x6
        +=========+==============+==================+=============+===========+==============+===============+
        |   STT   |     MSSV     |        HO        |     TEN     | GIOI TINH |    MA LOP    | SO DIEN THOAI |
      y1+=========+==============+==================+=============+===========+==============+===============+
        |         |              |                  |             |           |              |               |
        |         |              |                  |             |           |              |               |
        +=========+==============+==================+=============+===========+==============+===============+
    */

    int tabw = STUDENT_CLASS_INFO_BOARD_WIDTH;
    int tabh = size + 4;
    int x1 = x + 10;
    int x2 = x1 + 15;
    int x3 = x2 + 19;
    int x4 = x3 + 14;
    int x5 = x4 + 12;
    int x6 = x5 + 15;
    int y1 = y + 2;

    // draw border
    drawBox(x, y, tabw, tabh);

    // STT
    gotoxy(x + 4, y + 1);
    std::cout << "STT";
    // MSSV
    gotoxy(x1 + 6, y + 1);
    std::cout << "MSSV";
    // HO SINHVIEN
    gotoxy(x2 + 9, y + 1);
    std::cout << "HO";
    // TEN SINHVIEN
    gotoxy(x3 + 6, y + 1);
    std::cout << "TEN";
    // GIOI TINH
    gotoxy(x4 + 2, y + 1);
    std::cout << "GIOI TINH";
    // MA LOP
    gotoxy(x5 + 5, y + 1);
    std::cout << "MA LOP";
    // SO DIEN THOAI
    gotoxy(x6 + 2, y + 1);
    std::cout << "SO DIEN THOAI";

    for (int i = 1; i < tabw - 1; i++)
    {
        gotoxy(x + i, y + 2);
        std::cout << "=";
    }

    for (int i = 1; i < tabh; i++)
    {
        gotoxy(x1, y + i);
        std::cout << "|";
    }

    for (int i = 1; i < tabh; i++)
    {
        gotoxy(x2, y + i);
        std::cout << "|";
    }

    for (int i = 1; i < tabh; i++)
    {
        gotoxy(x3, y + i);
        std::cout << "|";
    }

    for (int i = 1; i < tabh; i++)
    {
        gotoxy(x4, y + i);
        std::cout << "|";
    }

    for (int i = 1; i < tabh; i++)
    {
        gotoxy(x5, y + i);
        std::cout << "|";
    }

    for (int i = 1; i < tabh; i++)
    {
        gotoxy(x6, y + i);
        std::cout << "|";
    }

    gotoxy(x, y + 2);
    std::cout << "+";
    gotoxy(x + tabw - 1, y + 2);
    std::cout << "+";

    gotoxy(x1, y);
    std::cout << "+";
    gotoxy(x1, y + 2);
    std::cout << "+";
    gotoxy(x1, y + tabh - 1);
    std::cout << "+";

    gotoxy(x2, y);
    std::cout << "+";
    gotoxy(x2, y + 2);
    std::cout << "+";
    gotoxy(x2, y + tabh - 1);
    std::cout << "+";

    gotoxy(x3, y);
    std::cout << "+";
    gotoxy(x3, y + 2);
    std::cout << "+";
    gotoxy(x3, y + tabh - 1);
    std::cout << "+";

    gotoxy(x4, y);
    std::cout << "+";
    gotoxy(x4, y + 2);
    std::cout << "+";
    gotoxy(x4, y + tabh - 1);
    std::cout << "+";

    gotoxy(x5, y);
    std::cout << "+";
    gotoxy(x5, y + 2);
    std::cout << "+";
    gotoxy(x5, y + tabh - 1);
    std::cout << "+";

    gotoxy(x6, y);
    std::cout << "+";
    gotoxy(x6, y + 2);
    std::cout << "+";
    gotoxy(x6, y + tabh - 1);
    std::cout << "+";
}

void drawCreditClassInfoBoard(int x, int y, int size)
{
    /*  x     x1       x2           x3            x4       x5       x6        x7        x8                x9
        +=====+========+============+=============+========+========+=========+=========+=================+=============+
        | STT | MA LOP |   MA MON   |  NIEN KHOA  | HOC KY |  NHOM  | SOSVMIN | SOSVMAX | SLOT DA DANG KY |  TINH TRANG |
    y1  +=====+========+============+=============+========+========+=========+=========+=================+=============+
        |     |        |            | 2020 - 2021 |        |        |         |         |                 |  HOAT DONG  |
        |     |        |            |             |        |        |         |         |                 |             |
        +=====+========+============+=============+========+========+=========+=========+=================+=============+
    */
    int tabw = CREDIT_CLASS_INFO_BOARD_WIDTH;
    int tabh = size + 4;
    int x1 = x + 6;
    int x2 = x1 + 9;
    int x3 = x2 + 13;
    int x4 = x3 + 14;
    int x5 = x4 + 9;
    int x6 = x5 + 9;
    int x7 = x6 + 10;
    int x8 = x7 + 10;
    int x9 = x8 + 18;
    int y1 = y + 2;

    // draw border
    drawBox(x, y, tabw, tabh);

    gotoxy(x + 2, y + 1);
    std::cout << "STT";
    gotoxy(x1 + 2, y + 1);
    std::cout << "MA LOP";
    gotoxy(x2 + 4, y + 1);
    std::cout << "MA MON";
    gotoxy(x3 + 3, y + 1);
    std::cout << "NIEN KHOA";
    gotoxy(x4 + 2, y + 1);
    std::cout << "HOC KY";
    gotoxy(x5 + 3, y + 1);
    std::cout << "NHOM";
    gotoxy(x6 + 2, y + 1);
    std::cout << "SOSVMIN";
    gotoxy(x7 + 2, y + 1);
    std::cout << "SOSVMAX";
    gotoxy(x8 + 2, y + 1);
    std::cout << "SLOT DA DANG KY";
    gotoxy(x9 + 3, y + 1);
    std::cout << "TINH TRANG";


    for (int i = 1; i < tabw - 1; i++)
    {
        gotoxy(x + i, y1);
        std::cout << "=";
    }

    for (int i = 1; i < tabh; i++)
    {
        gotoxy(x1, y + i);
        std::cout << "|";
    }

    for (int i = 1; i < tabh; i++)
    {
        gotoxy(x2, y + i);
        std::cout << "|";
    }

    for (int i = 1; i < tabh; i++)
    {
        gotoxy(x3, y + i);
        std::cout << "|";
    }

    for (int i = 1; i < tabh; i++)
    {
        gotoxy(x4, y + i);
        std::cout << "|";
    }

    for (int i = 1; i < tabh; i++)
    {
        gotoxy(x5, y + i);
        std::cout << "|";
    }

    for (int i = 1; i < tabh; i++)
    {
        gotoxy(x6, y + i);
        std::cout << "|";
    }

    for (int i = 1; i < tabh; i++)
    {
        gotoxy(x7, y + i);
        std::cout << "|";
    }

    for (int i = 1; i < tabh; i++)
    {
        gotoxy(x8, y + i);
        std::cout << "|";
    }
    for(int i = 1; i < tabh; i++)
    {
        gotoxy(x9, y + i);
        std::cout << "|";
    }

    gotoxy(x, y1);
    std::cout << "+";
    gotoxy(x + tabw - 1, y1);
    std::cout << "+";

    gotoxy(x1, y);
    std::cout << "+";
    gotoxy(x1, y1);
    std::cout << "+";
    gotoxy(x1, y + tabh - 1);
    std::cout << "+";

    gotoxy(x + 15, y);
    std::cout << "+";
    gotoxy(x + 15, y1);
    std::cout << "+";
    gotoxy(x + 15, y + tabh - 1);
    std::cout << "+";

    gotoxy(x1, y);
    std::cout << "+";
    gotoxy(x1, y1);
    std::cout << "+";
    gotoxy(x1, y + tabh - 1);
    std::cout << "+";

    gotoxy(x2, y);
    std::cout << "+";
    gotoxy(x2, y1);
    std::cout << "+";
    gotoxy(x2, y + tabh - 1);
    std::cout << "+";

    gotoxy(x3, y);
    std::cout << "+";
    gotoxy(x3, y1);
    std::cout << "+";
    gotoxy(x3, y + tabh - 1);
    std::cout << "+";

    gotoxy(x4, y);
    std::cout << "+";
    gotoxy(x4, y1);
    std::cout << "+";
    gotoxy(x4, y + tabh - 1);
    std::cout << "+";

    gotoxy(x5, y);
    std::cout << "+";
    gotoxy(x5, y1);
    std::cout << "+";
    gotoxy(x5, y + tabh - 1);
    std::cout << "+";

    gotoxy(x6, y);
    std::cout << "+";
    gotoxy(x6, y1);
    std::cout << "+";
    gotoxy(x6, y + tabh - 1);
    std::cout << "+";

    gotoxy(x7, y);
    std::cout << "+";
    gotoxy(x7, y1);
    std::cout << "+";
    gotoxy(x7, y + tabh - 1);
    std::cout << "+";

    gotoxy(x8, y);
    std::cout << "+";
    gotoxy(x8, y1);
    std::cout << "+";
    gotoxy(x8, y + tabh - 1);
    std::cout << "+";

    gotoxy(x9, y);
    std::cout << "+";
    gotoxy(x9, y1);
    std::cout << "+";
    gotoxy(x9, y + tabh - 1);
    std::cout << "+";
}
void drawCreditClassStatusBoard(int x, int y, int size)
{
    /*
        x     x1       x2         x3                              x4        x5             x6
        +=====+========+==========+===============================+=========+==============+==============+
        | STT | MA LOP |  MA MON  |           TEN MON             |   NHOM  | SLOT DANG KY | SLOT CON LAI |
     y1 +=====+========+==========+===============================+=========+==============+==============+
        |     |        |          |                               |         |              |              |
        |     |        |          |                               |         |              |              |
        +=====+========+==========+===============================+=========+==============+==============+
    */
    int tabw = CREDIT_CLASS_STATUS_BOARD_WIDTH;
    int tabh = size + 4;
    int x1 = x + 6;
    int x2 = x1 + 9;
    int x3 = x2 + 11;
    int x4 = x3 + 32;
    int x5 = x4 + 10;
    int x6 = x5 + 15;

    // draw border
    drawBox(x, y, tabw, tabh);

    // STT
    gotoxy(x + 2, y + 1);
    std::cout << "STT";
    // MA LOP
    gotoxy(x1 + 2, y + 1);
    std::cout << "MA LOP";
    // MA MON
    gotoxy(x2 + 3, y + 1);
    std::cout << "MA MON";
    // TEN MON
    gotoxy(x3 + 12, y + 1);
    std::cout << "TEN MON";
    // NHOM
    gotoxy(x4 + 4, y + 1);
    std::cout << "NHOM";
    // SLOT DK
    gotoxy(x5 + 2, y + 1);
    std::cout << "SLOT DANG KY";
    // SLOT CON LAI
    gotoxy(x6 + 2, y + 1);
    std::cout << "SLOT CON LAI";

    for (int i = 1; i < tabw - 1; i++)
    {
        gotoxy(x + i, y + 2);
        std::cout << "=";
    }

    for (int i = 1; i < tabh; i++)
    {
        gotoxy(x1, y + i);
        std::cout << "|";
    }

    for (int i = 1; i < tabh; i++)
    {
        gotoxy(x2, y + i);
        std::cout << "|";
    }

    for (int i = 1; i < tabh; i++)
    {
        gotoxy(x3, y + i);
        std::cout << "|";
    }

    for (int i = 1; i < tabh; i++)
    {
        gotoxy(x4, y + i);
        std::cout << "|";
    }

    for (int i = 1; i < tabh; i++)
    {
        gotoxy(x5, y + i);
        std::cout << "|";
    }

    for (int i = 1; i < tabh; i++)
    {
        gotoxy(x6, y + i);
        std::cout << "|";
    }

    gotoxy(x, y + 2);
    std::cout << "+";
    gotoxy(x + tabw - 1, y + 2);
    std::cout << "+";

    gotoxy(x1, y);
    std::cout << "+";
    gotoxy(x1, y + 2);
    std::cout << "+";
    gotoxy(x1, y + tabh - 1);
    std::cout << "+";

    gotoxy(x2, y);
    std::cout << "+";
    gotoxy(x2, y + 2);
    std::cout << "+";
    gotoxy(x2, y + tabh - 1);
    std::cout << "+";

    gotoxy(x3, y);
    std::cout << "+";
    gotoxy(x3, y + 2);
    std::cout << "+";
    gotoxy(x3, y + tabh - 1);
    std::cout << "+";

    gotoxy(x4, y);
    std::cout << "+";
    gotoxy(x4, y + 2);
    std::cout << "+";
    gotoxy(x4, y + tabh - 1);
    std::cout << "+";

    gotoxy(x5, y);
    std::cout << "+";
    gotoxy(x5, y + 2);
    std::cout << "+";
    gotoxy(x5, y + tabh - 1);
    std::cout << "+";

    gotoxy(x6, y);
    std::cout << "+";
    gotoxy(x6, y + 2);
    std::cout << "+";
    gotoxy(x6, y + tabh - 1);
    std::cout << "+";
}
void drawAvgScoreBoard(int x, int y, int size)
{
    /*
        x         x1             x2                     x3                x4
        +=========+==============+======================+=================+============+
        |   STT   |     MSSV     |          HO          |       TEN       |   DIEM TB  |
    y1  +=========+==============+======================+=================+============+
        |         |              |                      |                 |            |
        |         |              |                      |                 |            |
        +=========+==============+======================+=================+============+
    */
    int tabw = AVG_SCORE_BOARD_WIDTH;
    int tabh = size + 4;
    int x1 = x + 10;
    int x2 = x1 + 15;
    int x3 = x2 + 23;
    int x4 = x3 + 18;

    // draw border
    drawBox(x, y, tabw, tabh);

    // STT
    gotoxy(x + 4, y + 1);
    std::cout << "STT";
    // MSSV
    gotoxy(x1 + 6, y + 1);
    std::cout << "MSSV";
    // HO
    gotoxy(x2 + 11, y + 1);
    std::cout << "HO";
    // TEN
    gotoxy(x3 + 8, y + 1);
    std::cout << "TEN";
    // DIEM TB
    gotoxy(x4 + 4, y + 1);
    std::cout << "DIEM TB";

    for (int i = 1; i < tabw - 1; i++)
    {
        gotoxy(x + i, y + 2);
        std::cout << "=";
    }

    for (int i = 1; i < tabh; i++)
    {
        gotoxy(x1, y + i);
        std::cout << "|";
    }

    for (int i = 1; i < tabh; i++)
    {
        gotoxy(x2, y + i);
        std::cout << "|";
    }

    for (int i = 1; i < tabh; i++)
    {
        gotoxy(x3, y + i);
        std::cout << "|";
    }

    for (int i = 1; i < tabh; i++)
    {
        gotoxy(x4, y + i);
        std::cout << "|";
    }

    gotoxy(x, y + 2);
    std::cout << "+";
    gotoxy(x + tabw - 1, y + 2);
    std::cout << "+";

    gotoxy(x1, y);
    std::cout << "+";
    gotoxy(x1, y + 2);
    std::cout << "+";
    gotoxy(x1, y + tabh - 1);
    std::cout << "+";

    gotoxy(x2, y);
    std::cout << "+";
    gotoxy(x2, y + 2);
    std::cout << "+";
    gotoxy(x2, y + tabh - 1);
    std::cout << "+";

    gotoxy(x3, y);
    std::cout << "+";
    gotoxy(x3, y + 2);
    std::cout << "+";
    gotoxy(x3, y + tabh - 1);
    std::cout << "+";

    gotoxy(x4, y);
    std::cout << "+";
    gotoxy(x4, y + 2);
    std::cout << "+";
    gotoxy(x4, y + tabh - 1);
    std::cout << "+";
}
void drawScoreBoard(int x, int y, int size)
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
    int tabw = SCORE_BOARD_WIDTH;
    int tabh = size + 4;
    int x1 = x + 10;
    int x2 = x1 + 15;
    int x3 = x2 + 23;
    int x4 = x3 + 18;
    int y1 = y + 2;

    // draw border
    drawBox(x, y, tabw, tabh);

    // STT
    gotoxy(x + 4, y + 1);
    std::cout << "STT";
    // MSSV
    gotoxy(x + 16, y + 1);
    std::cout << "MSSV";
    // HO SINHVIEN
    gotoxy(x + 36, y + 1);
    std::cout << "HO";
    // TEN SINHVIEN
    gotoxy(x + 56, y + 1);
    std::cout << "TEN";
    // DIEM
    gotoxy(x + 74, y + 1);
    std::cout << "DIEM";

    for (int i = 1; i < tabw - 1; i++)
    {
        gotoxy(x + i, y1);
        std::cout << "=";
    }

    for (int i = 1; i < tabh; i++)
    {
        gotoxy(x1, y + i);
        std::cout << "|";
    }

    for (int i = 1; i < tabh; i++)
    {
        gotoxy(x2, y + i);
        std::cout << "|";
    }

    for (int i = 1; i < tabh; i++)
    {
        gotoxy(x3, y + i);
        std::cout << "|";
    }

    for (int i = 1; i < tabh; i++)
    {
        gotoxy(x4, y + i);
        std::cout << "|";
    }

    gotoxy(x, y1);
    std::cout << "+";
    gotoxy(x + tabw - 1, y1);
    std::cout << "+";

    gotoxy(x1, y);
    std::cout << "+";
    gotoxy(x1, y1);
    std::cout << "+";
    gotoxy(x1, y + tabh - 1);
    std::cout << "+";

    gotoxy(x2, y);
    std::cout << "+";
    gotoxy(x2, y1);
    std::cout << "+";
    gotoxy(x2, y + tabh - 1);
    std::cout << "+";

    gotoxy(x3, y);
    std::cout << "+";
    gotoxy(x3, y1);
    std::cout << "+";
    gotoxy(x3, y + tabh - 1);
    std::cout << "+";

    gotoxy(x4, y);
    std::cout << "+";
    gotoxy(x4, y1);
    std::cout << "+";
    gotoxy(x4, y + tabh - 1);
    std::cout << "+";
}
void drawFinalScoreBoard(int x, int y, int so_mon_hoc, std::vector<PTRMH> dsMH)
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
    int h = MAX_BOARD_ELEMENTS + 4;

    drawBox(x, y, w, h); // ve vien bao quanh

    // STT
    printStringXY(x + 4, y + 1, "STT");
    // MSSV
    printStringXY(x1 + 5, y + 1, "MSSV");
    // HO SINHVIEN
    printStringXY(x2 + 11, y + 1, "HO TEN");

    for (int i = 1; i < w; i++)
    {
        if (isInSaveArea(x + i, y + 2) == false)
            continue;
        gotoxy(x + i, y + 2);
        std::cout << "=";
    }

    for (int i = 1; i < h; i++)
    {
        if (isInSaveArea(x1, y + i) == false)
            continue;
        gotoxy(x1, y + i);
        std::cout << "|";
    }

    for (int i = 1; i < h; i++)
    {
        if (isInSaveArea(x2, y + i) == false)
            continue;
        gotoxy(x2, y + i);
        std::cout << "|";
    }

    for (int i = 1; i < h; i++)
    {
        if (isInSaveArea(x3, y + i) == false)
            continue;
        gotoxy(x3, y + i);
        std::cout << "|";
    }

    // ve cot ghi diem
    for (int n = 1; n <= so_mon_hoc; n++)
    {
        printStringXY(x3 + n * step - 6, y + 1, dsMH[n - 1]->course.courceCode);
        for (int i = 1; i < h; i++)
        {
            if (isInSaveArea(x3 + n * step, y + i) == false)
                continue;
            gotoxy(x3 + n * step, y + i);
            std::cout << "|";
        }
        if (isInSaveArea(x3 + n * step, y) == true)
        {
            gotoxy(x3 + n * step, y);
            std::cout << "+";
        }
        if (isInSaveArea(x3 + n * step, y + 2) == true)
        {
            gotoxy(x3 + n * step, y + 2);
            std::cout << "+";
        }
        if (isInSaveArea(x3 + n * step, y + h - 1) == true)
        {
            gotoxy(x3 + n * step, y + h - 1);
            std::cout << "+";
        }
    }

    if (isInSaveArea(x1, y + 2) == true)
    {
        gotoxy(x1, y + 2);
        std::cout << "+";
    }

    if (isInSaveArea(x1, y + h - 1) == true)
    {
        gotoxy(x1, y + h - 1);
        std::cout << "+";
    }
    if (isInSaveArea(x1, y) == true)
    {
        gotoxy(x1, y);
        std::cout << "+";
    }

    if (isInSaveArea(x2, y + 2) == true)
    {
        gotoxy(x2, y + 2);
        std::cout << "+";
    }
    if (isInSaveArea(x2, y + h - 1) == true)
    {
        gotoxy(x2, y + h - 1);
        std::cout << "+";
    }
    if (isInSaveArea(x2, y) == true)
    {
        gotoxy(x2, y);
        std::cout << "+";
    }

    if (isInSaveArea(x3, y) == true)
    {
        gotoxy(x3, y);
        std::cout << "+";
    }
    if (isInSaveArea(x3, y + 2) == true)
    {
        gotoxy(x3, y + 2);
        std::cout << "+";
    }
    if (isInSaveArea(x3, y + h - 1) == true)
    {
        gotoxy(x3, y + h - 1);
        std::cout << "+";
    }
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

void clearBorder(int x, int y, int w, int h)
{
    for (int i = 0; i < h; i++)
    {
        gotoxy(x, y + i);
        for (int j = 1; j <= w; j++)
        {
            std::cout << " ";
        }
    }
}
// max title length = 30
std::string XacNhan(int x, int y, std::string title)
{
    /*      <-----------Width------------>
                        x_title
                        |
            x           TITLE   x2
            Lua chon 1          Lua chon 2
    */
    ShowCur(false); // an con tro van ban
    std::string luachon1 = "YES";
    std::string luachon2 = "NO";
    std::string keyType = "NONE";

    int w = 30;
    int pos = 2;
    int keyPressed = 0;
    int x2 = (w - luachon2.length()) + x;

    SetColor("RED");
    if (title.length() >= w)
    {
        gotoxy(x, y);
        for (int i = 0; i < 30; i++)
        {
            std::cout << title[i];
        }
    }
    else
    {
        gotoxy((w - title.length()) / 2 + x, y);
        std::cout << title;
    }
    SetColor("WHITE");

    gotoxy(x, y + 2);
    std::cout << luachon1;
    gotoxy(x2, y + 2);
    std::cout << luachon2;

    gotoxy(x2, y + 2); // khoi tao gia tri ban dau, hightlight YES
    SetColor("BLUE");
    std::cout << luachon2;

    // int keyhit;
    while (true)
    {
        keyPressed = getch();
        keyType = getKeyType(keyPressed);

        if (keyType == "LEFT")
        {
            if (pos == 2)
            {
                pos = 1;
                gotoxy(x2, y + 2);
                SetColor("WHITE");
                std::cout << luachon2;

                gotoxy(x, y + 2);
                SetColor("BLUE");
                std::cout << luachon1;
            }
            else if (pos == 1)
            {
                pos = 2;
                gotoxy(x, y + 2);
                SetColor("WHITE");
                std::cout << luachon1;

                gotoxy(x2, y + 2);
                SetColor("BLUE");
                std::cout << luachon2;
            }
        }
        else if (keyType == "RIGHT")
        {
            if (pos == 1)
            {
                pos = 2;
                gotoxy(x, y + 2);
                SetColor("WHITE");
                std::cout << luachon1;

                gotoxy(x2, y + 2);
                SetColor("BLUE");
                std::cout << luachon2;
            }
            else if (pos == 2)
            {
                pos = 1;
                gotoxy(x2, y + 2);
                SetColor("WHITE");
                std::cout << luachon2;

                gotoxy(x, y + 2);
                SetColor("BLUE");
                std::cout << luachon1;
            }
        }

        else if (keyType == "ENTER")
        {
            clearScreen(x, y, w, 2);
            ShowCur(true);
            SetColor("WHITE");
            return (pos == 1) ? luachon1 : luachon2;
        }
    }
}