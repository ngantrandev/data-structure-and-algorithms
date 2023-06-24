#include "UI_function.h"

void ShowProgramName(int x_program_name, int y_program_name, int sleep_time)
{

    std::string program_name = "CHUONG TRINH QUAN LY SINH VIEN";
    std::string lable1 = "GIAO VIEN HUONG DAN: THAY LUU NGUYEN KY THU";
    std::string label2 = "NHOM 10";

    const int color_sum = 15;
    int x = 0; // dung de random mang
    int pressed_key = 0;

    int x_1 = 42, x_2 = 60, x_3 = 48;
    int x_box = 40;
    int y_box = y_program_name - 2;
    int width = 46, height = 6; // set size_box

    int a[color_sum + 1] = {0};
    for (int i = 1; i <= color_sum; i++) // set default value
        a[i] = i;

    drawBox(x_box, y_box, width, height);

    // // show enter button
    gotoxy(52, y_box + height + 2);
    std::cout << "NHAN ENTER DE BAT DAU";

    ShowCur(0); // tat hien thi con tro

    while (true)
    {

        if (kbhit())
        {
            pressed_key = getch();
            if (pressed_key == 13)
            {
                SetColor(15); // set white color
                ShowCur(1);   // hien thi con tro
                return;
            }
        }

        for (int i = 1; i <= color_sum; i++)
        {
            x = i + rand() % (color_sum - i + 1);
            std::swap(a[i], a[x]);
        }

        for (int i = 1; i <= color_sum; i++)
        {
            clearScreen(x_box + 1, y_box + 1, width - 2, height - 2);

            gotoxy(x_program_name, y_program_name - 1);

            for (int j = 0; j < program_name.length(); j++)
            {
                i += 2;
                if (i < color_sum)
                {
                    SetColor(a[i]);
                    std::cout << program_name[j];
                }
                else
                    i = 1;
            }

            gotoxy(x_1, y_program_name + 1);
            for (int j = 0; j < lable1.length(); j++)
            {
                i += 2;
                if (i < color_sum)
                {
                    SetColor(a[i]);
                    std::cout << lable1[j];
                }
                else
                    i = 1;
            }
            gotoxy(x_2, y_program_name + 3);
            for (int j = 0; j < label2.length(); j++)
            {

                i += 2;
                if (i < color_sum)
                {
                    SetColor(a[i]);
                    std::cout << label2[j];
                }
                else
                    i = 1;
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
void ShowMessage(int x_origin, int y_origin, std::string message, int duration)
{
    gotoxy(x_origin, y_origin);
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

void showCourceList(int tabx, int taby, int tabw, int tabh)
{

    // draw border
    drawBox(tabx, taby, tabw, tabh);

    gotoxy(tabx, taby + 2);
    std::cout << char(204);
    for (int i = 1; i < tabw; i++)
    {
        gotoxy(tabx + i, taby + 2);
        std::cout << char(205);
    }
    gotoxy(tabx + tabw, taby + 2);
    std::cout << char(185);

    // STT
    gotoxy(tabx + 4, taby + 1);
    std::cout << "STT";
    gotoxy(tabx + 10, taby);
    std::cout << char(203);
    for (int i = 1; i < tabh + 1; i++)
    {
        gotoxy(tabx + 10, taby + i);
        std::cout << char(186);
    }

    gotoxy(tabx + 10, taby + 2);
    std::cout << char(206);
    gotoxy(tabx + 10, taby + tabh);
    std::cout << char(202);

    // MA MON HOC
    gotoxy(tabx + 13, taby + 1);
    std::cout << "MA MON HOC";
    gotoxy(tabx + 25, taby);
    std::cout << char(203);
    for (int i = 1; i < tabh + 1; i++)
    {
        gotoxy(tabx + 25, taby + i);
        std::cout << char(186);
    }
    gotoxy(tabx + 25, taby + 2);
    std::cout << char(206);
    gotoxy(tabx + 25, taby + tabh);
    std::cout << char(202);

    // HO SINHVIEN
    gotoxy(tabx + 36, taby + 1);
    std::cout << "TEN MON HOC";
    gotoxy(tabx + 57, taby);
    std::cout << char(203);
    for (int i = 1; i < tabh + 1; i++)
    {
        gotoxy(tabx + 57, taby + i);
        std::cout << char(186);
    }
    gotoxy(tabx + 57, taby + 2);
    std::cout << char(206);
    gotoxy(tabx + 57, taby + tabh);
    std::cout << char(202);

    // TEN SINHVIEN
    gotoxy(tabx + 61, taby + 1);
    std::cout << "STCLT";
    gotoxy(tabx + 69, taby);
    std::cout << char(203);
    for (int i = 1; i < tabh + 1; i++)
    {
        gotoxy(tabx + 69, taby + i);
        std::cout << char(186);
    }
    gotoxy(tabx + 69, taby + 2);
    std::cout << char(206);
    gotoxy(tabx + 69, taby + tabh);
    std::cout << char(202);

    // DIEM
    gotoxy(tabx + 73, taby + 1);
    std::cout << "STCTH";
}
void showStudentList(int tabx, int taby, int tabh)
{
    int tabw = 102;
    // draw border
    drawBox(tabx, taby, tabw, tabh);

    gotoxy(tabx, taby + 2);
    std::cout << char(204);
    for (int i = 1; i < tabw; i++)
    {
        gotoxy(tabx + i, taby + 2);
        std::cout << char(205);
    }
    gotoxy(tabx + tabw, taby + 2);
    std::cout << char(185);

    // STT
    gotoxy(tabx + 3, taby + 1);
    std::cout << "STT";
    gotoxy(tabx + 8, taby);
    std::cout << char(203);
    for (int i = 1; i < tabh + 1; i++)
    {
        gotoxy(tabx + 8, taby + i);
        std::cout << char(186);
    }

    gotoxy(tabx + 8, taby + 2);
    std::cout << char(206);
    gotoxy(tabx + 8, taby + tabh);
    std::cout << char(202);

    // MSSV
    gotoxy(tabx + 14, taby + 1);
    std::cout << "MSSV";
    gotoxy(tabx + 23, taby);
    std::cout << char(203);
    for (int i = 1; i < tabh + 1; i++)
    {
        gotoxy(tabx + 23, taby + i);
        std::cout << char(186);
    }
    gotoxy(tabx + 23, taby + 2);
    std::cout << char(206);
    gotoxy(tabx + 23, taby + tabh);
    std::cout << char(202);

    // HO SINHVIEN
    gotoxy(tabx + 32, taby + 1);
    std::cout << "HO";
    gotoxy(tabx + 45, taby);
    std::cout << char(203);
    for (int i = 1; i < tabh + 1; i++)
    {
        gotoxy(tabx + 45, taby + i);
        std::cout << char(186);
    }
    gotoxy(tabx + 45, taby + 2);
    std::cout << char(206);
    gotoxy(tabx + 45, taby + tabh);
    std::cout << char(202);

    // TEN SINHVIEN
    gotoxy(tabx + 51, taby + 1);
    std::cout << "TEN";
    gotoxy(tabx + 59, taby);
    std::cout << char(203);
    for (int i = 1; i < tabh + 1; i++)
    {
        gotoxy(tabx + 59, taby + i);
        std::cout << char(186);
    }
    gotoxy(tabx + 59, taby + 2);
    std::cout << char(206);
    gotoxy(tabx + 59, taby + tabh);
    std::cout << char(202);

    // GIOI TINH
    gotoxy(tabx + 61, taby + 1);
    std::cout << "GIOI TINH";
    gotoxy(tabx + 71, taby);
    std::cout << char(203);
    for (int i = 1; i < tabh + 1; i++)
    {
        gotoxy(tabx + 71, taby + i);
        std::cout << char(186);
    }
    gotoxy(tabx + 71, taby + 2);
    std::cout << char(206);
    gotoxy(tabx + 71, taby + tabh);
    std::cout << char(202);

    // MA LOP
    gotoxy(tabx + 76, taby + 1);
    std::cout << "MA LOP";
    gotoxy(tabx + 86, taby);
    std::cout << char(203);
    for (int i = 1; i < tabh + 1; i++)
    {
        gotoxy(tabx + 86, taby + i);
        std::cout << char(186);
    }
    gotoxy(tabx + 86, taby + 2);
    std::cout << char(206);
    gotoxy(tabx + 86, taby + tabh);
    std::cout << char(202);

    // SO DIEN THOAI
    gotoxy(tabx + 88, taby + 1);
    std::cout << "SO DIEN THOAI";
}
void showCreditClassList(int tabx, int taby, int tabw, int tabh)
{ //  Hoat dong
    //|  STT  |  MA LOP  |   MA MON   | NIENKHOA | HOC KY | NHOM | SOSVMIN | SOSVMAX |  TINH TRANG  |
    //  0  2    6  8       15 18       2627       3537     4345   50
    // draw border
    drawBox(tabx, taby, tabw, tabh);

    gotoxy(tabx, taby + 2);
    std::cout << char(204);
    for (int i = 1; i < tabw; i++)
    {
        gotoxy(tabx + i, taby + 2);
        std::cout << char(205);
    }
    gotoxy(tabx + tabw, taby + 2);
    std::cout << char(185);

    // STT
    gotoxy(tabx + 2, taby + 1);
    std::cout << "STT";
    gotoxy(tabx + 6, taby);
    std::cout << char(203);
    for (int i = 1; i < tabh + 1; i++)
    {
        gotoxy(tabx + 6, taby + i);
        std::cout << char(186);
    }

    gotoxy(tabx + 6, taby + 2);
    std::cout << char(206);
    gotoxy(tabx + 6, taby + tabh);
    std::cout << char(202);

    // MA LOP
    gotoxy(tabx + 8, taby + 1);
    std::cout << "MA LOP";
    gotoxy(tabx + 15, taby);
    std::cout << char(203);
    for (int i = 1; i < tabh + 1; i++)
    {
        gotoxy(tabx + 15, taby + i);
        std::cout << char(186);
    }
    gotoxy(tabx + 15, taby + 2);
    std::cout << char(206);
    gotoxy(tabx + 15, taby + tabh);
    std::cout << char(202);

    // MA MON
    gotoxy(tabx + 18, taby + 1);
    std::cout << "MA MON";
    gotoxy(tabx + 26, taby);
    std::cout << char(203);
    for (int i = 1; i < tabh + 1; i++)
    {
        gotoxy(tabx + 26, taby + i);
        std::cout << char(186);
    }
    gotoxy(tabx + 26, taby + 2);
    std::cout << char(206);
    gotoxy(tabx + 26, taby + tabh);
    std::cout << char(202);

    // NIEN KHOA
    gotoxy(tabx + 28, taby + 1);
    std::cout << "NIEN KHOA";
    gotoxy(tabx + 38, taby);
    std::cout << char(203);
    for (int i = 1; i < tabh + 1; i++)
    {
        gotoxy(tabx + 38, taby + i);
        std::cout << char(186);
    }
    gotoxy(tabx + 38, taby + 2);
    std::cout << char(206);
    gotoxy(tabx + 38, taby + tabh);
    std::cout << char(202);

    // HOC KY
    gotoxy(tabx + 40, taby + 1);
    std::cout << "HOC KY";
    gotoxy(tabx + 47, taby);
    std::cout << char(203);
    for (int i = 1; i < tabh + 1; i++)
    {
        gotoxy(tabx + 47, taby + i);
        std::cout << char(186);
    }
    gotoxy(tabx + 47, taby + 2);
    std::cout << char(206);
    gotoxy(tabx + 47, taby + tabh);
    std::cout << char(202);

    // NHOM
    gotoxy(tabx + 50, taby + 1);
    std::cout << "NHOM";
    gotoxy(tabx + 56, taby);
    std::cout << char(203);
    for (int i = 1; i < tabh + 1; i++)
    {
        gotoxy(tabx + 56, taby + i);
        std::cout << char(186);
    }
    gotoxy(tabx + 56, taby + 2);
    std::cout << char(206);
    gotoxy(tabx + 56, taby + tabh);
    std::cout << char(202);

    // SOSV MIN
    gotoxy(tabx + 58, taby + 1);
    std::cout << "SOSVMIN";
    gotoxy(tabx + 66, taby);
    std::cout << char(203);
    for (int i = 1; i < tabh + 1; i++)
    {
        gotoxy(tabx + 66, taby + i);
        std::cout << char(186);
    }
    gotoxy(tabx + 66, taby + 2);
    std::cout << char(206);
    gotoxy(tabx + 66, taby + tabh);
    std::cout << char(202);

    // SOSV MAX
    gotoxy(tabx + 68, taby + 1);
    std::cout << "SOSVMAX";
    gotoxy(tabx + 76, taby);
    std::cout << char(203);
    for (int i = 1; i < tabh + 1; i++)
    {
        gotoxy(tabx + 76, taby + i);
        std::cout << char(186);
    }
    gotoxy(tabx + 76, taby + 2);
    std::cout << char(206);
    gotoxy(tabx + 76, taby + tabh);
    std::cout << char(202);

    // TINH TRANG
    gotoxy(tabx + 79, taby + 1);
    std::cout << "TINH TRANG";
}
void showCreditClassStatus(int tabx, int taby, int tabw, int tabh)
{
    //"STT", "MA LOP", "MA MON", "TEN MON", "NHOM", "SLOT DANG KY", "SLOT CON LAI
    //|  STT  |  MA LOP  |   MA MON   | NIENKHOA | HOC KY | NHOM | SOSVMIN | SOSVMAX |  TINH TRANG  |
    //  0  2    6  8       15 18       2627       3537     4345   50
    // draw border
    drawBox(tabx, taby, tabw, tabh);

    gotoxy(tabx, taby + 2);
    std::cout << char(204);
    for (int i = 1; i < tabw; i++)
    {
        gotoxy(tabx + i, taby + 2);
        std::cout << char(205);
    }
    gotoxy(tabx + tabw, taby + 2);
    std::cout << char(185);

    // STT
    gotoxy(tabx + 2, taby + 1);
    std::cout << "STT";
    gotoxy(tabx + 6, taby);
    std::cout << char(203);
    for (int i = 1; i < tabh + 1; i++)
    {
        gotoxy(tabx + 6, taby + i);
        std::cout << char(186);
    }

    gotoxy(tabx + 6, taby + 2);
    std::cout << char(206);
    gotoxy(tabx + 6, taby + tabh);
    std::cout << char(202);

    // MA LOP
    gotoxy(tabx + 8, taby + 1);
    std::cout << "MA LOP";
    gotoxy(tabx + 15, taby);
    std::cout << char(203);
    for (int i = 1; i < tabh + 1; i++)
    {
        gotoxy(tabx + 15, taby + i);
        std::cout << char(186);
    }
    gotoxy(tabx + 15, taby + 2);
    std::cout << char(206);
    gotoxy(tabx + 15, taby + tabh);
    std::cout << char(202);

    // MA MON
    gotoxy(tabx + 18, taby + 1);
    std::cout << "MA MON";
    gotoxy(tabx + 26, taby);
    std::cout << char(203);
    for (int i = 1; i < tabh + 1; i++)
    {
        gotoxy(tabx + 26, taby + i);
        std::cout << char(186);
    }
    gotoxy(tabx + 26, taby + 2);
    std::cout << char(206);
    gotoxy(tabx + 26, taby + tabh);
    std::cout << char(202);

    // TEN MON
    gotoxy(tabx + 38, taby + 1);
    std::cout << "TEN MON";
    gotoxy(tabx + 58, taby);
    std::cout << char(203);
    for (int i = 1; i < tabh + 1; i++)
    {
        gotoxy(tabx + 58, taby + i);
        std::cout << char(186);
    }
    gotoxy(tabx + 58, taby + 2);
    std::cout << char(206);
    gotoxy(tabx + 58, taby + tabh);
    std::cout << char(202);

    // NHOM
    gotoxy(tabx + 62, taby + 1);
    std::cout << "NHOM";
    gotoxy(tabx + 68, taby);
    std::cout << char(203);
    for (int i = 1; i < tabh + 1; i++)
    {
        gotoxy(tabx + 68, taby + i);
        std::cout << char(186);
    }
    gotoxy(tabx + 68, taby + 2);
    std::cout << char(206);
    gotoxy(tabx + 68, taby + tabh);
    std::cout << char(202);

    // SLOT DK
    gotoxy(tabx + 70, taby + 1);
    std::cout << "SLOT DANG KY";
    gotoxy(tabx + 83, taby);
    std::cout << char(203);
    for (int i = 1; i < tabh + 1; i++)
    {
        gotoxy(tabx + 83, taby + i);
        std::cout << char(186);
    }
    gotoxy(tabx + 83, taby + 2);
    std::cout << char(206);
    gotoxy(tabx + 83, taby + tabh);
    std::cout << char(202);

    // SLOT CON LAI
    gotoxy(tabx + 85, taby + 1);
    std::cout << "SLOT CON LAI";
}
void showPointList(int tabx, int taby, int tabw, int tabh)
{

    // draw border
    drawBox(tabx, taby, tabw, tabh);

    gotoxy(tabx, taby + 2);
    std::cout << char(204);
    for (int i = 1; i < tabw; i++)
    {
        gotoxy(tabx + i, taby + 2);
        std::cout << char(205);
    }
    gotoxy(tabx + tabw, taby + 2);
    std::cout << char(185);

    // STT
    gotoxy(tabx + 4, taby + 1);
    std::cout << "STT";
    gotoxy(tabx + 10, taby);
    std::cout << char(203);
    for (int i = 1; i < tabh + 1; i++)
    {
        gotoxy(tabx + 10, taby + i);
        std::cout << char(186);
    }

    gotoxy(tabx + 10, taby + 2);
    std::cout << char(206);
    gotoxy(tabx + 10, taby + tabh);
    std::cout << char(202);

    // MSSV
    gotoxy(tabx + 16, taby + 1);
    std::cout << "MSSV";
    gotoxy(tabx + 25, taby);
    std::cout << char(203);
    for (int i = 1; i < tabh + 1; i++)
    {
        gotoxy(tabx + 25, taby + i);
        std::cout << char(186);
    }
    gotoxy(tabx + 25, taby + 2);
    std::cout << char(206);
    gotoxy(tabx + 25, taby + tabh);
    std::cout << char(202);

    // HO SINHVIEN
    gotoxy(tabx + 36, taby + 1);
    std::cout << "HO";
    gotoxy(tabx + 48, taby);
    std::cout << char(203);
    for (int i = 1; i < tabh + 1; i++)
    {
        gotoxy(tabx + 48, taby + i);
        std::cout << char(186);
    }
    gotoxy(tabx + 48, taby + 2);
    std::cout << char(206);
    gotoxy(tabx + 48, taby + tabh);
    std::cout << char(202);

    // TEN SINHVIEN
    gotoxy(tabx + 56, taby + 1);
    std::cout << "TEN";
    gotoxy(tabx + 66, taby);
    std::cout << char(203);
    for (int i = 1; i < tabh + 1; i++)
    {
        gotoxy(tabx + 66, taby + i);
        std::cout << char(186);
    }
    gotoxy(tabx + 66, taby + 2);
    std::cout << char(206);
    gotoxy(tabx + 66, taby + tabh);
    std::cout << char(202);

    // DIEM
    gotoxy(tabx + 72, taby + 1);
    std::cout << "DIEM TB";
}
void drawBox(int x, int y, int w, int h)
{
    for (int i = x; i <= x + w; i++)
    {
        for (int j = y; j <= y + h; j++)
        {
            if (i == x && j == y)
            {
                gotoxy(i, j);
                std::printf("+"); // top left
            }
            else if (i == x && j == y + h)
            {
                gotoxy(i, j);
                std::printf("+"); // bottom left
            }
            else if (i == x + w && j == y)
            {
                gotoxy(i, j);
                std::printf("+"); // top right
            }
            else if (i == x + w && j == y + h)
            {
                gotoxy(x + w, y + h);
                std::printf("+"); // bot right
            }
            else if (j == y)
            {
                gotoxy(i, j);
                std::printf("="); // bien tren
            }
            else if (j == y + h)
            {
                gotoxy(i, j);
                std::printf("="); // bien duoi
            }
            else if (i == x)
            {
                gotoxy(i, j);
                std::printf("||"); // bien trai
            }
            else if (i == x + w)
            {
                gotoxy(i, j);
                std::printf("||"); // bien phai
            }
            else
                continue;
        }
    }
}
void drawScoreBoard(int tabx, int taby, int tabw, int tabh)
{

    // draw border
    drawBox(tabx, taby, tabw, tabh);

    gotoxy(tabx, taby + 2);
    std::cout << char(204);
    for (int i = 1; i < tabw; i++)
    {
        gotoxy(tabx + i, taby + 2);
        std::cout << char(205);
    }
    gotoxy(tabx + tabw, taby + 2);
    std::cout << char(185);

    // STT
    gotoxy(tabx + 4, taby + 1);
    std::cout << "STT";
    gotoxy(tabx + 10, taby);
    std::cout << char(203);
    for (int i = 1; i < tabh + 1; i++)
    {
        gotoxy(tabx + 10, taby + i);
        std::cout << char(186);
    }

    gotoxy(tabx + 10, taby + 2);
    std::cout << char(206);
    gotoxy(tabx + 10, taby + tabh);
    std::cout << char(202);

    // MSSV
    gotoxy(tabx + 16, taby + 1);
    std::cout << "MSSV";
    gotoxy(tabx + 25, taby);
    std::cout << char(203);
    for (int i = 1; i < tabh + 1; i++)
    {
        gotoxy(tabx + 25, taby + i);
        std::cout << char(186);
    }
    gotoxy(tabx + 25, taby + 2);
    std::cout << char(206);
    gotoxy(tabx + 25, taby + tabh);
    std::cout << char(202);

    // HO SINHVIEN
    gotoxy(tabx + 36, taby + 1);
    std::cout << "HO";
    gotoxy(tabx + 48, taby);
    std::cout << char(203);
    for (int i = 1; i < tabh + 1; i++)
    {
        gotoxy(tabx + 48, taby + i);
        std::cout << char(186);
    }
    gotoxy(tabx + 48, taby + 2);
    std::cout << char(206);
    gotoxy(tabx + 48, taby + tabh);
    std::cout << char(202);

    // TEN SINHVIEN
    gotoxy(tabx + 56, taby + 1);
    std::cout << "TEN";
    gotoxy(tabx + 66, taby);
    std::cout << char(203);
    for (int i = 1; i < tabh + 1; i++)
    {
        gotoxy(tabx + 66, taby + i);
        std::cout << char(186);
    }
    gotoxy(tabx + 66, taby + 2);
    std::cout << char(206);
    gotoxy(tabx + 66, taby + tabh);
    std::cout << char(202);

    // DIEM
    gotoxy(tabx + 74, taby + 1);
    std::cout << "DIEM";
}
void vebangtongketdiem(int x, int y, int step, int soSV, int so_mon_hoc, std::string maMH[1000])
{
    // length_info la chieu dai tu dau table den het phan cootj tensinhvien
    int length_info = 66;
    int x_0 = x + length_info; // vi tri bat dau ve cot diem
    int w = so_mon_hoc * step + length_info;
    int h = soSV + 3;
    //	int x_0 = step;

    //	int w = 66;

    drawBox(x, y, w, h); // ve vien bao quanh

    gotoxy(x, y + 2);
    std::cout << char(204);
    for (int i = 1; i < w; i++)
    {
        gotoxy(x + i, y + 2);
        std::cout << char(205);
    }
    gotoxy(x + w, y + 2);
    std::cout << char(185);

    // STT
    gotoxy(x + 4, y + 1);
    std::cout << "STT";
    gotoxy(x + 10, y);
    std::cout << char(203);
    for (int i = 1; i < h + 1; i++)
    {
        gotoxy(x + 10, y + i);
        std::cout << char(186);
    }

    gotoxy(x + 10, y + 2);
    std::cout << char(206);
    gotoxy(x + 10, y + h);
    std::cout << char(202);

    // MSSV
    gotoxy(x + 16, y + 1);
    std::cout << "MSSV";
    gotoxy(x + 25, y);
    std::cout << char(203);
    for (int i = 1; i < h + 1; i++)
    {
        gotoxy(x + 25, y + i);
        std::cout << char(186);
    }
    gotoxy(x + 25, y + 2);
    std::cout << char(206);
    gotoxy(x + 25, y + h);
    std::cout << char(202);

    // HO SINHVIEN
    gotoxy(x + 36, y + 1);
    std::cout << "HO";
    gotoxy(x + 48, y);
    std::cout << char(203);
    for (int i = 1; i < h + 1; i++)
    {
        gotoxy(x + 48, y + i);
        std::cout << char(186);
    }
    gotoxy(x + 48, y + 2);
    std::cout << char(206);
    gotoxy(x + 48, y + h);
    std::cout << char(202);

    // TEN SINHVIEN5

    gotoxy(x + 56, y + 1);
    std::cout << "TEN";
    gotoxy(x + 66, y);
    std::cout << char(203);
    for (int i = 1; i < h + 1; i++)
    {
        gotoxy(x + 66, y + i);
        std::cout << char(186);
    }
    gotoxy(x + 66, y + 2);
    std::cout << char(206);
    gotoxy(x + 66, y + h);
    std::cout << char(202);

    // ve cot ddienf diem
    for (int n = 1; n <= so_mon_hoc; n++)
    {

        gotoxy(x_0 + n * step - 6, y + 1);
        std::cout << maMH[n];
        gotoxy(x_0 + n * step, y);
        std::cout << char(203);
        for (int i = 1; i <= h; i++)
        {
            gotoxy(x_0 + n * step, y + i);
            std::cout << char(186);
        }
        gotoxy(x_0 + n * step, y + 2);
        std::cout << char(206);
        gotoxy(x_0 + n * step, y + h);
        std::cout << char(202);
    }

    gotoxy(x + w, y + 2);
    std::cout << char(185);
    gotoxy(x + w, y);
    std::cout << char(187);
    gotoxy(x + w, y + h);
    std::cout << char(188);

    gotoxy(0, y + h + 5);
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
