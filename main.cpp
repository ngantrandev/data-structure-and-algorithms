#include <iostream>
#include <map>
// #include "./src/lib/view/menu.h"
#include "src/lib/struct.h"
#include "src/lib/view/menu.h"
#include "./src/lib/view/UI_function.h"
#include "src/lib/data_manager/data_manager.h"

PTRSV firstSV;

int main()
{
    char tenfile[] = "./data/txt_file/danh_sach_sinh_vien.txt";
    SetWindowSize(1000, 1000);
    SetScreenBufferSize(1000, 1000);
    // ShowScrollBar();/
    HienThanhCuon(TRUE);
    firstSV = loadStudentList(tenfile);

    while (firstSV !=NULL) {
        std::cout<<firstSV->student.studentID<<std::endl;
        firstSV = firstSV->next;
    }

    //     void showCourceListBox(int tabx, int taby, int tabh);
    // void showStudentList(int tabx, int taby, int tabh);
    // void showCreditClassList(int tabx, int taby, int tabh);
    // void showCreditClassStatus(int tabx, int taby, int tabh);
    // void showPointList(int tabx, int taby, int tabh);
    // void drawBox(int x, int y, int w, int h);
    // void drawScoreBoard(int tabx, int taby, int tabh);
    // void vebangtongketdiem(int x, int y, int soSV, int so_mon_hoc, std::string maMH[1000]);

    // showCourceListBox(10, 10, 1);
    // showStudentList(10, 10, 1);
    // showCreditClassList(10, 10, 1);
    // showCreditClassStatus(10, 10, 1);
    // showPointList(10, 10, 1);
    // drawScoreBoard(10, 10, 1);
    // vebangtongketdiem(10, 10, 1, 5, maMH);

    getch();
}
