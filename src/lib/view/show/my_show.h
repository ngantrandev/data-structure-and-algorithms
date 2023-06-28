#pragma once
#include "struct.h"
#include "basic_function.h"
#include "../../algorithms/count_node.h"
#include "../UI_function.h"
#include "../../data_manager/data_manager.h"
#include "../../algorithms/my_sort.h"
#include "../../algorithms/my_delete.h"
#include "../input/my_input.h"

void xuatDanhSachSinhVien_Console(PTRSV FirstSV, int tabx, int taby);
void xuatDanhSachSinhVienLopHoc_Console_TheoTen(PTRSV FirstSV, int x, int y); // cau d
// void xuatThongTinSinhVien_MSSV_Console(PTRSV ptr_SV, int &stt, int tabx, int taby);

void xuatDanhSachSinhVienDK_LTC(int x, int y, LIST_LTC dsLTC, PTRSV FirstSV); // cau b
void xuatDanhSachLopTinChi_Console(int x, int y, LIST_LTC dsLTC);

void xuatDanhSachMonHoc_Console(int x, int y, PTRMH Tree_monhoc);
void xuatDanhSachMonHoc_LNR_Console(PTRMH Tree_monhoc, int x, int y, int &stt);
void xuatThongTinMonHoc(int x, int y, int stt, Course monhoc);

void xuatDanhSachMonHocTheoTen(int x_origin, int y_origin, PTRMH Tree_monhoc);
void inBangDiemMonHocLopTinChi(PTRSV FirstSV, PTRMH Tree_monhoc, Credit *loptinchi); // cau j
void inBangDiemLopTinChi(PTRSV FirstSV, PTRMH Tree_monhoc, LIST_LTC dsLTC);          // cau j
void inBangDiemTBKhoaHoc(int x, int y, char *maLH, PTRSV FirstSV, LIST_LTC dsLTC, std::map<char *, std::string> anhXaMSSV_dsLTC);
void inBangDiemTongKet(int x, int y, char *maLH, LIST_LTC dsLTC, PTRSV FirstSV, PTRMH Tree_monhoc, std::map<char *, std::string> anhXaMSSV_dsLTC);

//=================================
// HAM XUAT THONG TIN
//=================================

void xuatDanhSachSinhVien_Console(PTRSV FirstSV, int x, int y)
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

    system("cls");
    if (FirstSV == NULL)
    {
        // ShowMessage(x_box_thong_bao, y_box_thong_bao, "DANH SACH SINH VIEN TRONG", 1500);
        return;
    }

    PTRSV p = FirstSV;
    int soSV = countLinkedList(FirstSV);
    int tabw = 102;

    int stt = 0;

    showStudentList(x, y, 10);

    while (p != NULL)
    {
        if (stt == 10)
            break;
        ++stt;

        gotoxy(x + 4, y + 2 + stt);
        std::cout << stt;
        gotoxy(x + 13, y + 2 + stt);
        std::cout << p->student.studentID;
        gotoxy(x + 28, y + 2 + stt);
        std::cout << p->student.lastName;
        gotoxy(x + 50, y + 2 + stt);
        std::cout << p->student.firstName;
        gotoxy(x + 63, y + 2 + stt);
        std::cout << p->student.sex;
        gotoxy(x + 72, y + 2 + stt);
        std::cout << p->student.classID;
        gotoxy(x + 89, y + 2 + stt);
        std::cout << p->student.phoneNum;

        p = p->next;
    }
}

void xuatDanhSachSinhVienLopHoc_Console_TheoTen(PTRSV FirstSV, int x, int y)
{ // case 4:  cau d
    char *maLopHoc = NULL;
    PTRSV ptrSV = NULL; // giu dia chi con tro FirstSV
    PTRSV temp_FirstSV = NULL;
    std::string malop_string[2] = {""};

    while (true)
    {
        system("cls");

        ptrSV = FirstSV;
        temp_FirstSV = NULL; // reset lai danh sach

        if (input_UI(x, y, 45, "NHAP MA LOP", 1, nhap_ma_lop_hoc, malop_string, 4, "XAC NHAN XONG") == 1)
        {
            // ConvertStringToChar(malop_string[0], maLopHoc);
            maLopHoc = ConvertStringToChar(malop_string[0]);

            while (ptrSV != NULL)
            {
                if (strcmp(ptrSV->student.classID, maLopHoc) == 0)
                    addStudentToList(temp_FirstSV, ptrSV->student);
                ptrSV = ptrSV->next;
            }

            sapXepDanhSachSinhVienTheoTen_Ho_SelectionSort(temp_FirstSV);
            xuatDanhSachSinhVien_Console(temp_FirstSV, 13, 4);
            deleteLinkedList(temp_FirstSV);
            getch();
        }
    }

    delete[] maLopHoc;
}

void xuatDanhSachSinhVienDK_LTC(int x, int y, LIST_LTC dsLTC, PTRSV FirstSV)
{ // case 2: cau b

    /*
                                            DANH SACH SINH VIEN DANG KY
                                Nien khoa: 2020 _ Hoc ky: 2 _ Nhom: 2 _ Ma mon hoc: MH54
                                            Co 20 sinh vien trong danh sach
        x         x1             x2                 x3            x4          x5             x6
        +=========+==============+==================+=============+===========+==============+===============+
        |   STT   |     MSSV     |        HO        |     TEN     | GIOI TINH |    MA LOP    | SO DIEN THOAI |
    y1  +=========+==============+==================+=============+===========+==============+===============+
        |         |              |                  |             |           |              |               |
        |         |              |                  |             |           |              |               |
        +=========+==============+==================+=============+===========+==============+===============+
    */

    system("cls");
    char *nienkhoa, *maMonHoc;
    int hocky;
    int nhom;
    std::string content[4] = {""};

    if (input_UI(44, 4, 40, "NHAP THONG TIN LOP TIN CHI CAN XET", 4, cau_2, content, 8, "XAC NHAN XONG") == 1)
    {
        system("cls");
        int stt = 0;
        nienkhoa = ConvertStringToChar(content[0]);
        hocky = stringTo_Int(content[1]);
        nhom = stringTo_Int(content[2]);
        maMonHoc = ConvertStringToChar(content[3]);

        Credit *loptinchi = timLopTinChi_theoInfo(dsLTC, nienkhoa, hocky, nhom, maMonHoc);

        delete[] nienkhoa;
        delete[] maMonHoc;

        if (loptinchi == NULL)
        {
            // xuat thong bao
            return;
        }

        PTRDK ptrDK = loptinchi->firstListRegister; // bien p tro toi danh sach dangky;
        PTRSV p = NULL;
        int soSV = countLinkedList(ptrDK);

        gotoxy(x + 37, y - 5);
        std::cout << "DANH SACH SINH VIEN DANG KY";
        gotoxy(x + 25, y - 4);
        std::printf("Nien khoa %s _ Hoc ky: %d _ Nhom: %d _ Ma mon hoc: %s", nienkhoa, hocky, nhom, maMonHoc);
        gotoxy(x + 37, y - 3);
        std::printf("Co %d sinh vien trong danh sach\n", soSV);

        showStudentList(x, y, soSV);

        while (ptrDK != NULL)
        {
            p = timSinhVien_DSSV(FirstSV, ptrDK->regis.studentID);
            if (p != NULL)
            {

                stt++;

                gotoxy(x + 4, y + 2 + stt);
                std::cout << stt;
                gotoxy(x + 13, y + 2 + stt);
                std::cout << p->student.studentID;
                gotoxy(x + 28, y + 2 + stt);
                std::cout << p->student.lastName;
                gotoxy(x + 50, y + 2 + stt);
                std::cout << p->student.firstName;
                gotoxy(x + 63, y + 2 + stt);
                std::cout << p->student.sex;
                gotoxy(x + 72, y + 2 + stt);
                std::cout << p->student.classID;
                gotoxy(x + 89, y + 2 + stt);
                std::cout << p->student.phoneNum;
            }
            ptrDK = ptrDK->next;
        }

        system("pause");
    }
}

void xuatDanhSachLopTinChi_Console(int x, int y, LIST_LTC dsLTC)
{
    /*                                        DANH SACH LOP TIN CHI
                                            CO %d LOP TRONG DANH SACH
        x     x1       x2           x3            x4       x5       x6        x7        x8
        +=====+========+============+=============+========+========+=========+=========+=============+
        | STT | MA LOP |   MA MON   |  NIEN KHOA  | HOC KY |  NHOM  | SOSVMIN | SOSVMAX |  TINH TRANG |
    y1  +=====+========+============+=============+========+========+=========+=========+=============+
        |     |        |            | 2020 - 2021 |        |        |         |         |  HOAT DONG  |
        |     |        |            |             |        |        |         |         |             |
        +=====+========+============+=============+========+========+=========+=========+=============+
    */

    if (dsLTC.currentIndex == 0)
    {
        ShowMessage(10, 3, "KHONG CO LOP TIN CHI NAO THOA MAN", 1500);
        return;
    }

    int count_LTC = 0; // dem so lop tin chi thoa man

    for (int i = 1; i <= dsLTC.currentIndex; i++)
    {
        if (dsLTC.nodes[i] != NULL)
        {
            count_LTC++;

            gotoxy(x + 2, y + 2 + count_LTC);
            std::cout << count_LTC;
            gotoxy(x + 8, y + 2 + count_LTC);
            std::cout << dsLTC.nodes[i]->creditCode;
            gotoxy(x + 18, y + 2 + count_LTC);
            std::cout << dsLTC.nodes[i]->courseCode;
            gotoxy(x + 30, y + 2 + count_LTC);
            std::cout << dsLTC.nodes[i]->schoolYear;
            gotoxy(x + 44, y + 2 + count_LTC);
            std::cout << dsLTC.nodes[i]->semester;
            gotoxy(x + 54, y + 2 + count_LTC);
            std::cout << dsLTC.nodes[i]->group;
            gotoxy(x + 62, y + 2 + count_LTC);
            std::cout << dsLTC.nodes[i]->studentMin;
            gotoxy(x + 72, y + 2 + count_LTC);
            std::cout << dsLTC.nodes[i]->studentMax;
            gotoxy(x + 83, y + 2 + count_LTC);
            std::cout << (dsLTC.nodes[i]->enable == false ? "Hoat dong" : "Da huy");
        }
    }

    if (count_LTC > 0)
    {
        gotoxy(x + 39, y - 4);
        std::cout << "DANH SACH LOP TIN CHI";
        gotoxy(x + 36, y - 3);
        std::printf("  CO %d LOP TRONG DANH SACH", count_LTC);
        showCreditClassList(x, y, count_LTC);
    }
}

void xuatDanhSachMonHoc_Console(int x, int y, PTRMH Tree_monhoc)
{
    /*
                                  DANH SACH MON HOC
                            CO %d MON HOC TRONG DANH SACH

        x         x1             x2                        x3        x4
        +=========+==============+=========================+=========+========+
        |   STT   |  MA MON HOC  |       TEN MON HOC       |  STCLT  |  STCTH |
    y1  +=========+==============+=========================+=========+========+
        |   4     |    MH1       |       Toan Lop 5        |    1    |    2   |
        |   5     |    MH10      |       Toan Cao Cap      |    4    |    4   |
        +=========+==============+=========================+=========+========+
    */

    if (Tree_monhoc == NULL)
    {
        // ShowMessage(x_box_thong_bao, y_box_thong_bao, "DANH SACH MON HOC TRONG!", 1500);
        // thong bao
        return;
    }

    int soLuongMonHoc = 0;                // so luong mon hoc
    count_MH(Tree_monhoc, soLuongMonHoc); // dem so luong mon hoc
    int tabw = 80;
    int count = 0;

    gotoxy(x + 27, y - 4);
    std::cout << "DANH SACH MON HOC";
    gotoxy(x + 21, y - 3);
    std::printf("CO %d MON HOC TRONG DANH SACH", soLuongMonHoc);

    xuatDanhSachMonHoc_LNR_Console(Tree_monhoc, x, y, count);

    showCourceListBox(x, y, count);
}

void xuatThongTinMonHoc(int x, int y, int stt, Course monhoc)
{
    gotoxy(x + 4, y + 2 + stt);
    std::cout << stt;
    gotoxy(x + 15, y + 2 + stt);
    std::cout << monhoc.courceCode;
    gotoxy(x + 33, y + 2 + stt);
    std::cout << monhoc.courceName;
    gotoxy(x + 56, y + 2 + stt);
    std::cout << monhoc.STCLT;
    gotoxy(x + 66, y + 2 + stt);
    std::cout << monhoc.STCTH;
}

void xuatDanhSachMonHoc_LNR_Console(PTRMH Tree_monhoc, int x, int y, int &stt)
{
    if (Tree_monhoc != NULL)
    {
        xuatDanhSachMonHoc_LNR_Console(Tree_monhoc->pLeft, x, y, stt);

        if (stt == 10)
            return;
        stt++;
        xuatThongTinMonHoc(x, y, stt, Tree_monhoc->course);

        xuatDanhSachMonHoc_LNR_Console(Tree_monhoc->pRight, x, y, stt);
    }
}

// // chuc nang: xuat thong tin sinh vien dua vao ma sinh vien
// void xuatThongTinSinhVien_MSSV_Console(PTRSV ptr_SV, int &stt, int tabx, int taby)
// {
//     int tabw = 102;
//     int tabh = 4;

//     gotoxy((2 * tabx + tabw - 20) / 2, taby);
//     std::cout << "THONG TIN SINH VIEN";

//     showStudentList(tabx, taby + 2, tabh);

//     gotoxy(tabx + 4, taby + stt + 4);
//     std::cout << stt;
//     gotoxy(tabx + 11, taby + stt + 4);
//     std::cout << ptr_SV->student.studentID;
//     gotoxy(tabx + 27, taby + stt + 4);
//     std::cout << ptr_SV->student.firstName;
//     gotoxy(tabx + 50, taby + stt + 4);
//     std::cout << ptr_SV->student.name;
//     gotoxy(tabx + 64, taby + stt + 4);
//     std::cout << ptr_SV->student.sex;
//     gotoxy(tabx + 73, taby + stt + 4);
//     std::cout << ptr_SV->student.classID;
//     gotoxy(tabx + 89, taby + stt + 4);
//     std::cout << ptr_SV->student.phoneNum;

//     gotoxy(0, taby + stt + 2 + 4);
// }

void xuatDanhSachMonHocTheoTen(int x_origin, int y_origin, PTRMH Tree_monhoc)
{
    PTRMH temp_tree = NULL;
    saoChepMonHocTheoTen(Tree_monhoc, temp_tree);
    xuatDanhSachMonHoc_Console(x_origin, y_origin, temp_tree);
    xoaDanhSachMonHoc(temp_tree);
}

void inBangDiemMonHocLopTinChi(PTRSV FirstSV, PTRMH Tree_monhoc, Credit *loptinchi) // cau j
{                                                                                   // case 10: cau j
    /*
                                    BANG DIEM MON HOC < Toan Lop 5 >
                           Nien khoa: 2020       Hoc ky: 3          Nhom: 10

        x         x1             x2                     x3                x4
        +=========+==============+======================+=================+==================+
        |   STT   |     MSSV     |          HO          |       TEN       |       DIEM       |
     y1 +=========+==============+======================+=================+==================+
        |   1     |  N20DCPT001  |  Tran Thi Uyen       |      Hau        |      10.00       |
        |   10    |  N20DCPT090  |  Truong Thanh Thao   |      Uyen       |      0.00        |
        +=========+==============+======================+=================+==================+
    */

    int x = 10;
    int y = 10;

    PTRMH monhoc = timMonHocTheoMa(Tree_monhoc, loptinchi->courseCode);
    PTRDK ptrDK = loptinchi->firstListRegister;
    PTRSV ptrSV = NULL;
    int stt = 0;

    system("cls");
    gotoxy(x + 29, y - 4);
    std::cout << "BANG DIEM MON HOC < " << monhoc->course.courceName << " >";
    gotoxy(x + 20, y - 3);
    std::printf("Nien khoa: %-10s Hoc ky: %-10d Nhom: %-10d", loptinchi->schoolYear, loptinchi->semester, loptinchi->group);

    while (ptrDK != NULL)
    {
        ptrSV = timSinhVien_DSSV(FirstSV, ptrDK->regis.studentID);

        if (stt == 10)
            break;
        stt++;
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
}

void inBangDiemLopTinChi(PTRSV FirstSV, PTRMH Tree_monhoc, LIST_LTC dsLTC) // cau j
{                                                                          // case 10: cau j
    char *nienkhoa = NULL, *maMH = NULL;
    int hocky = 3, nhom = 2;
    Credit *loptinchi = NULL;

    while (true)
    {
        system("cls");
        std::string content[6] = {""};

        if (input_UI(44, 4, 40, "NHAP THONG TIN LOP TIN CHI CAN XET", 4, cau_2, content, 8, "XAC NHAN XONG") == 1)
        {
            nienkhoa = ConvertStringToChar(content[0]);
            hocky = stringTo_Int(content[1]);
            nhom = stringTo_Int(content[2]);
            maMH = ConvertStringToChar(content[3]);

            delete[] nienkhoa;
            delete[] maMH;

            loptinchi = timLopTinChi_theoInfo(dsLTC, nienkhoa, hocky, nhom, maMH);

            if (loptinchi != NULL)
            {
                inBangDiemMonHocLopTinChi(loptinchi, FirstSV, Tree_monhoc);
                continue;
            }

            // Khi khong tim thay LTC
            else
            {
                system("cls");
                ShowMessage(x_box_thong_bao, y_box_thong_bao, "KHONG TIM THAY LOP TIN CHI", 1500);
            }
        }
        else
            break;
    }

    return;
}

void inBangDiemTBKhoaHoc(int x, int y, char *maLH, PTRSV FirstSV, LIST_LTC dsLTC, std::map<char *, std::string> anhXaMSSV_dsLTC)
{
    /*
                                BANG THONG KE DIEM TRUNG BINH KHOA HOC
                                        Lop:     <ma lop hoc>
        x         x1             x2                     x3                x4
        +=========+==============+======================+=================+============+
        |   STT   |     MSSV     |          HO          |       TEN       |   DIEM TB  |
    y1  +=========+==============+======================+=================+============+
        |         |              |                      |                 |            |
        |         |              |                      |                 |            |
        +=========+==============+======================+=================+============+
    */
    PTRDK ptrDK = NULL;
    PTRMH ptrMH = NULL;
    char *mssv = NULL;
    PTRSV nodeSV = NULL;
    int stt = 0;
    float totalScore = 0;
    int totalCredit = 0;
    std::vector<int> splitDsLTC;

    for (auto &it : anhXaMSSV_dsLTC)
    {
        mssv = it.first;
        totalScore = 0;
        totalCredit = 0;

        nodeSV = timSinhVien_DSSV(FirstSV, mssv);

        if (strcmp(nodeSV->student.classID, maLH) != 0)
            return;

        splitDsLTC = customSplit(it.second, ',');
        stt++;

        for (int i = 0; i < splitDsLTC.size(); i++)
        {
            ptrDK = timSinhVien_DSSVDK(dsLTC.nodes[splitDsLTC[i]]->firstListRegister, mssv);
            if (ptrDK != NULL)
            {
                ptrMH = timMonHocTheoMa(treeMH, dsLTC.nodes[splitDsLTC[i]]->courseCode);
                totalScore += ptrDK->regis.point * (ptrMH->course.STCLT + ptrMH->course.STCTH);
                totalCredit += ptrMH->course.STCLT + ptrMH->course.STCTH;

                gotoxy(x + 4, y + 2 + stt);
                std::cout << stt;
                gotoxy(x + 12, y + 2 + stt);
                std::cout << mssv;
                gotoxy(x + 28, y + 2 + stt);
                std::cout << nodeSV->student.lastName;
                gotoxy(x + 53, y + 2 + stt);
                std::cout << nodeSV->student.firstName;
                gotoxy(x + 68, y + 2 + stt);
                std::cout << round(totalScore / totalCredit * 100) / 100; // round(totalScore/totalCredit, 2 decimal places)
            }
        }
    }
}

void inBangDiemTongKet(int x, int y, char *maLH, LIST_LTC dsLTC, PTRSV FirstSV, PTRMH Tree_monhoc, std::map<char *, std::string> anhXaMSSV_dsLTC)
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
                                                          index = 0  idx = 1   idx = 2
    */
    int x1 = x + 10;
    int x2 = x1 + 13;
    int x3 = x2 + 27;
    int step = 10;

    int stt = 0;

    int indexMaMH = 0; // vi tri phan tu maMH trong dsMaMH
    PTRDK nodeDK = NULL;
    Credit *loptinchi = NULL;
    PTRSV p = FirstSV;
    std::vector<char *> dsMaMH = getListCourceCode(treeMH);
    std::vector<int> splitDsLTC;

    while (p != NULL)
    {
        if (strcmp(p->student.classID, maLH) != 0)
            return;

        stt++;
        gotoxy(x + 4, y + 2 + stt);
        std::cout << stt;
        gotoxy(x + 12, y + 2 + stt);
        std::cout << p->student.studentID;
        gotoxy(x + 24, y + 2 + stt);
        std::cout << p->student.lastName << " " << p->student.firstName;

        auto it = anhXaMSSV_dsLTC.find(p->student.studentID);
        splitDsLTC = customSplit(it->second, ',');
        for (int i = 0; i <= splitDsLTC.size(); i++)
        {
            loptinchi = dsLTC.nodes[splitDsLTC[i]];
            nodeDK = timSinhVien_DSSVDK(loptinchi->firstListRegister, p->student.studentID);
            indexMaMH = std::find(dsMaMH.begin(), dsMaMH.end(), loptinchi->courseCode) - dsMaMH.begin();

            gotoxy(x3 + step * (indexMaMH + 1) - 8, y + 2 + stt);
            std::cout << round(nodeDK->regis.point * 100) / 100;
        }
    }
}