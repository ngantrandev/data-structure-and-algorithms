#include <iostream>
#include <map>

#include "src/lib/view/my_show.h"

std::map<int, char *> anhXaLTC_MH;
std::map<char *, std::string> anhXaMSSV_dsLTC;
PTRSV firstSV;
PTRMH treeMH;
LIST_LTC dsLTC;

void nhapDiem(int x, int y, PTRSV firstSV, PTRDK firstDK, int maxSize)
{
    /*
        x         x1             x2                     x3                x4
        +=========+==============+======================+=================+==================+
        |   STT   |     MSSV     |          HO          |       TEN       |       DIEM       |
     y1 +=========+==============+======================+=================+==================+
        |   1     |  N20DCPT001  |  Tran Thi Uyen       |      Hau        |      ____        |
        |   10    |  N20DCPT090  |  Truong Thanh Thao   |      Uyen       |      ____        |
        +=========+==============+======================+=================+==================+
    */

    PTRDK ptrDK = firstDK;
    PTRSV ptrSV = NULL;
    int stt = 0;
    int x4 = x + 66;
    int y1 = y + 2;

    system("cls");

    while (ptrDK != NULL)
    {
        ptrSV = timSinhVien_DSSV(firstSV, ptrDK->regis.studentID);

        stt++;

        if (stt > maxSize)
            break;

        gotoxy(x + 4, y + 2 + stt);
        std::cout << stt;
        gotoxy(x + 13, y + 2 + stt);
        std::cout << ptrDK->regis.studentID;
        gotoxy(x + 28, y + 2 + stt);
        std::cout << ptrSV->student.lastName;
        gotoxy(x + 55, y + 2 + stt);
        std::cout << ptrSV->student.firstName;
        gotoxy(x + 73, y + 2 + stt);
        std::printf("%0.2f", ptrDK->regis.point);

        ptrDK = ptrDK->next;
    }
    drawScoreBoard(x, y, stt);

    std::string selectionList[stt] = {""};
    std::string answer[stt] = {""};

    input_UI(x4 + 5, y1, stt, selectionList, answer, "INTEGER", 8, false);

    getch();
    clearScreen(x, y, SCORE_BOARD_WIDTH, y + 3 + stt);
}

int main()
{

    /*
        +==================================+
        |1    Cap nhat lop tin chi
        |2  >In danh sach sinh vien lop tin chi
        |3    Cap nhat sinh vien lop hoc
        |4    In danh sach sinh vien lop hoc
        |5    Cap nhat danh sach mon hoc
        |6    In danh sach mon hoc
        |7    Dang ky lop tin chi
        |8    Huy lop tin chi khong du dieu kien
        |9    Nhap diem lop tin chi
        |10   In bang diem lop tin chi
        |11   In bang diem trung binh lop hoc
        |12   In bang diem tong ket cac mon hoc
        |13   Xuat thong tin - Console
        |14   Luu du lieu - File
        +==================================+


    */
    int out = 0;
    int pos = 1;

    char ltcFile[] = "./data/txt_file/danh_sach_lop_tin_chi.txt";
    char svFile[] = "./data/txt_file/danh_sach_sinh_vien.txt";
    dsLTC = loadStudentCreditClassList(ltcFile);
    firstSV = loadStudentList(svFile);

    nhapDiem(10, 10, firstSV, dsLTC.nodes[1]->firstListRegister, 10);

    // dsLTC = loadStudentCreditClassList(ltcFile);

    // xuatDanhSachLopTinChi_Console(10, 2, dsLTC);

    // menu(10, 2, menu_chinh, 14, pos);

    // xuatDanhSachSinhVien_Console(firstSV, 10, 10);

    // std::cout << a << std::endl;
    // std::cout<<strlen(a)<<std::endl;
    getch();
}
