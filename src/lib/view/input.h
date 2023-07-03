#pragma once
#include <iostream>
#include "drawBoard.h"
#include "../algorithms/algorithms.h"

void input_UI(int x, int y, int selectionSize, std::string *selectionList, std::string *answer, std::string dataType, int maxAnswerLength = 25, bool border = true);

void input_UI(int x, int y, int selectionSize, std::string *selectionList, std::string *answer, std::string dataType, int maxAnswerLength, bool border)
{

    //  x1 = x + maxlength(lua chon co do dai lon nhat) + 2

    /*  <------------------width------------------>
        <------leftSide---->
        x                   x1
                             <--maxAnswerLength-->
        +==========================================+
        | Ma mon hoc       : helo                  |
        | Nien khoa        : helo                  |
        | Hoc ky           : helo                  |
        | Nhom             : helo                  |
        | So sinh vien MIN : helo                  |
        | So sinh vien MAX : helo                  |
        +==========================================+
        Len: ↑     Xuong: ↓     Xac nhan: ENTER     Xoa: BACKSPACE     Thoat: ESC
    */
    int selectionLength = selectionList[0].length();

    int width = selectionLength + maxAnswerLength + 4;

    int pos = 0;
    int keyPressed = -1;
    std::string keyType = "NONE";
    int x1 = x + selectionLength;
    std::string errorType = "NONE";
    std::string description = "Len: \u2191     Xuong: \u2193     Xac nhan: ENTER     Xoa: BACKSPACE     Thoat: ESC";

    if (border == true)
    {
        drawBox(x, y, width, selectionSize + 2);
        gotoxy(x, y + selectionSize + 2);
        std::cout << description;
    }

    for (int i = 0; i < selectionSize; i++)
    {
        gotoxy(x + 2, y + i + 1);
        std::cout << selectionList[i];
        gotoxy(x1 + 2, y + i + 1);
        std::cout << answer[i];
        gotoxy(x1 + 2 + answer[i].length(), y + i + 1);
    }

    while (true)
    {

        // SetColor(23);
        // gotoxy(x_huong_dan, y_huong_dan);

        gotoxy(x1 + 2 + answer[pos].length(), y + 1 + pos);

        keyPressed = getch();
        keyType = getKeyType(keyPressed);

        if (keyType == "UP")
        {
            (pos == 0) ? pos = selectionSize - 1 : pos--;
        }
        else if (keyType == "DOWN")
        {
            (pos == selectionSize - 1) ? pos = 0 : pos++;
        }
        else if (keyType == "XOA_VAN_BAN")
        {
            if (answer[pos].size() > 0)
            {
                gotoxy(x1 + 1 + answer[pos].length(), y + pos + 1);
                std::cout << " ";
                answer[pos].pop_back();
            }
        }

        else if (keyType == "NHAP_VAN_BAN")
        {
            if (answer[pos].length() < maxAnswerLength)
            {
                gotoxy(x1 + 2 + answer[pos].length(), y + pos + 1);
                answer[pos].push_back(char(keyPressed));
                std::cout << char(keyPressed);
            }
        }

        else if (keyType == "ENTER")
        {
            errorType = checkError(answer[pos], dataType);

            if (errorType == "NONE")
            {
                if (pos < selectionSize - 1)
                    pos++;

                else if (pos == selectionSize - 1)
                {

                    // check loi lan cuoi
                    for (int i = 0; i < selectionSize - 1; i++)
                    {
                        errorType = checkError(answer[i], dataType);
                        if (errorType != "NONE") // found error
                        {
                            // in thong bao loi
                            ShowMessage(x, y - 2, "Ma loi: " + errorType, 1000);
                            break;
                        }
                    }

                    if (errorType == "NONE")
                    {
                        clearScreen(x, y, width > description.length() ? width : description.length(), selectionSize + 3);
                        return;
                    }
                }
            }
            else
            {
                // in thong bao loi
                ShowMessage(x, y - 2, "Ma loi: " + errorType, 1000);
                continue;
            }
        }

        else if (keyType == "EXIT")
        {
            // in bieu mau xac nhan
            return;
        }

    } // end while
}
