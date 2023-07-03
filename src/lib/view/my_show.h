#pragma once

#include "input.h"
#include "./menu.h"
#include "../algorithms/algorithms.h"
#include "../data_manager/data_manager.h"


/*
    HAM XUAT THONG TIN
*/
void fillStudentInfoBoard(PTRSV FirstSV, int x, int y);
void fillStudentInfoBoardSortedByName(PTRSV FirstSV, int x, int y); // cau d

void fillRegistedStudentBoard(int x, int y, LIST_LTC dsLTC, PTRSV FirstSV); // cau b
void fillCreditClassBoard(int x, int y, LIST_LTC dsLTC);

void fillCourseInfoBoard(int x, int y, PTRMH Tree_monhoc);
void xuatDanhSachMonHoc_LNR_Console(PTRMH Tree_monhoc, int x, int y, int &stt, int size);
void xuatThongTinMonHoc(int x, int y, int stt, Course monhoc);

void fillCourseInfoBoardSortedByName(int x_origin, int y_origin, PTRMH Tree_monhoc);
void fillCreditClassPointBoard(int x, int y, PTRSV FirstSV, PTRDK firstDK, int size);
void inBangDiemLopTinChi(PTRSV FirstSV, LIST_LTC dsLTC); // cau j
void fillAvgPointBoard(int x, int y, int size, char *classID, PTRSV FirstSV, PTRMH treeMH, LIST_LTC dsLTC, std::map<char *, std::string> anhXaMSSV_dsLTC);
void fillFinalPointBoard(int x, int y, int size, char *maLH, LIST_LTC dsLTC, PTRSV FirstSV, PTRMH treeMH, PTRMH Tree_monhoc, std::map<char *, std::string> anhXaMSSV_dsLTC);


/*
    HAM NHAP THONG TIN
*/
void nhapThongTinLopTinChi_User(int x, int y, Credit *loptinchi);       // cau a
void capNhatLopTinChi_User(int x, int y, LIST_LTC dsLTC, PTRMH treeMH); // cau a
void nhapThongTinSinhVien(int x, int y, Student &sinhvien);             // cau c
void capNhatSinhVienLopHoc(int x, int y, PTRSV firstSV);                // cau c
void nhapThongTinMonHoc_User(int x, int y, Course &monhoc);             // cau e
void capNhatDanhSachMonHoc_User(PTRMH &treeMH, int x, int y);           // cau e
int Nhap_Diem_UI(int x_origin, int y_origin, Credit *loptinchi, PTRSV FirstSV, std::string reprot_notification, char menu_selection[10][100]);
void nhapBangDiem(PTRSV FirstSV, PTRMH Tree_monhoc, LIST_LTC dsLTC); // cau i
void nhapDiem(PTRSV firstSV, PTRDK firstDK, int size);

//=================================
// HAM XUAT THONG TIN
//=================================

void fillStudentInfoBoard(PTRSV FirstSV, int x, int y)
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

    drawStudentInfoBoard(x, y, 10);

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

void fillStudentInfoBoardSortedByName(PTRSV FirstSV, int x, int y)
{ // case 4:  cau d
    char malophoc[ClassID_Length] = "";
    PTRSV ptrSV = NULL; // giu dia chi con tro FirstSV
    PTRSV temp_FirstSV = NULL;
    std::string malop_string[2] = {""};

    while (true)
    {
        system("cls");

        ptrSV = FirstSV;
        temp_FirstSV = NULL; // reset lai danh sach
        input_UI(x, y, 1, nhap_ma_lop_hoc, malop_string, "STRING");

        stringToChar(malop_string[0], malophoc, ClassID_Length);

        while (ptrSV != NULL)
        {
            if (strcmp(ptrSV->student.classID, malophoc) == 0)
                addStudentToList(temp_FirstSV, ptrSV->student);
            ptrSV = ptrSV->next;
        }

        sapXepDanhSachSinhVienTheoTen_Ho_SelectionSort(temp_FirstSV);
        fillStudentInfoBoard(temp_FirstSV, 13, 4);
        deleteLinkedList(temp_FirstSV);
        getch();
    }
}

void fillRegistedStudentBoard(int x, int y, LIST_LTC dsLTC, PTRSV FirstSV)
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
    char nienkhoa[SchoolYear_Length] = "";
    char maMonHoc[CourseCode_Length] = "";
    int hocky = 0;
    int nhom = 0;
    std::string content[4] = {""};

    input_UI(x, y, 4, cau_2, content, "STRING");

    int stt = 0;
    stringToChar(content[0], nienkhoa, SchoolYear_Length);
    hocky = std::stoi(content[1]);
    nhom = std::stoi(content[2]);
    stringToChar(content[3], maMonHoc, CourseCode_Length);

    Credit *loptinchi = timLopTinChi_theoInfo(dsLTC, nienkhoa, hocky, nhom, maMonHoc);

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

    drawStudentInfoBoard(x, y, soSV);

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

    getch();
    clearScreen(x, y - 5, STUDENT_CLASS_INFO_BOARD_WIDTH, y + 8 + stt);
}

void fillCreditClassBoard(int x, int y, LIST_LTC dsLTC)
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
        drawCreditClassInfoBoard(x, y, count_LTC);
    }

    getch();
    clearScreen(x, y, CREDIT_CLASS_INFO_BOARD_WIDTH, count_LTC);
}

void fillCourseInfoBoard(int x, int y, PTRMH Tree_monhoc)
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

    xuatDanhSachMonHoc_LNR_Console(Tree_monhoc, x, y, count, 10);

    drawCourseInfoBoard(x, y, count);
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

void xuatDanhSachMonHoc_LNR_Console(PTRMH Tree_monhoc, int x, int y, int &stt, int size)
{
    if (Tree_monhoc != NULL)
    {
        xuatDanhSachMonHoc_LNR_Console(Tree_monhoc->pLeft, x, y, stt, size);

        stt++;
        if (stt > size)
            return;
        xuatThongTinMonHoc(x, y, stt, Tree_monhoc->course);

        xuatDanhSachMonHoc_LNR_Console(Tree_monhoc->pRight, x, y, stt, size);
    }
}

void fillCourseInfoBoardSortedByName(int x_origin, int y_origin, PTRMH Tree_monhoc)
{
    PTRMH temp_tree = NULL;
    saoChepMonHocTheoTen(Tree_monhoc, temp_tree);
    fillCourseInfoBoard(x_origin, y_origin, temp_tree);
    deleteCourceList(temp_tree);
}

void fillCreditClassPointBoard(int x, int y, PTRSV FirstSV, PTRDK firstDK, int size)
{
    /*
        x         x1             x2                     x3                x4
        +=========+==============+======================+=================+==================+
        |   STT   |     MSSV     |          HO          |       TEN       |       DIEM       |
     y1 +=========+==============+======================+=================+==================+
        |   1     |  N20DCPT001  |  Tran Thi Uyen       |      Hau        |      10.00       |
        |   10    |  N20DCPT090  |  Truong Thanh Thao   |      Uyen       |      0.00        |
        +=========+==============+======================+=================+==================+
    */

    PTRDK ptrDK = firstDK;
    PTRSV ptrSV = NULL;
    int stt = 0;

    system("cls");

    while (ptrDK != NULL)
    {
        ptrSV = timSinhVien_DSSV(FirstSV, ptrDK->regis.studentID);

        stt++;

        if (stt > size)
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

    getch();
    clearScreen(x, y, SCORE_BOARD_WIDTH, y + 3 + stt);
}

void inBangDiemLopTinChi(PTRSV FirstSV, LIST_LTC dsLTC) // cau j
{                                                       // case 10: cau j
    char nienkhoa[SchoolYear_Length] = "";
    char maMH[CourseCode_Length] = "";
    int hocky = 0, nhom = 0;
    Credit *loptinchi = NULL;
    system("cls");
    std::string answer[4] = {""};

    while (true)
    {
        input_UI(10, 10, 4, cau_2, answer, "STRING");
        stringToChar(answer[0], nienkhoa, SchoolYear_Length);
        hocky = std::stoi(answer[1]);
        nhom = std::stoi(answer[2]);
        stringToChar(answer[3], maMH, CourseCode_Length);

        loptinchi = timLopTinChi_theoInfo(dsLTC, nienkhoa, hocky, nhom, maMH);

        if (loptinchi != NULL)
        {
            fillCreditClassPointBoard(10, 10, FirstSV, loptinchi->firstListRegister, 10);
            continue;
        }

        // Khi khong tim thay LTC
        else
        {
            system("cls");
            ShowMessage(15, 15, "KHONG TIM THAY LOP TIN CHI", 1500);
        }
    }
}

void fillAvgPointBoard(int x, int y, int size, char *classID, PTRSV FirstSV, PTRMH treeMH, LIST_LTC dsLTC, std::map<char *, std::string> anhXaMSSV_dsLTC)
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

        if (nodeSV == NULL)
            continue;

        if (strcmp(nodeSV->student.classID, classID) != 0)
            continue;

        stt++;

        if (stt > size)
            break;

        splitDsLTC = customSplit(it.second, ',');

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

    drawAvgScoreBoard(x, y, stt);

    getch();
    clearScreen(x, y, AVG_SCORE_BOARD_WIDTH, y + 3 + stt);
}

void fillFinalPointBoard(int x, int y, int size, char *maLH, LIST_LTC dsLTC, PTRSV FirstSV, PTRMH treeMH, PTRMH Tree_monhoc, std::map<char *, std::string> anhXaMSSV_dsLTC)
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
        stt++;

        if (stt > size)
            break;

        if (strcmp(p->student.classID, maLH) != 0)
            return;

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

void nhapThongTinLopTinChi_User(int x, int y, Credit *loptinchi) // cau a
{
    std::string *answer = new std::string[6];
    answer[0] = charToString(loptinchi->courseCode);
    answer[1] = charToString(loptinchi->schoolYear);
    answer[2] = std::to_string(loptinchi->semester);
    answer[3] = std::to_string(loptinchi->group);
    answer[4] = std::to_string(loptinchi->studentMin);
    answer[5] = std::to_string(loptinchi->studentMax);

    while (true)
    {
        input_UI(x, y, 6, thong_tin_lop_tin_chi, answer, "STRING");

        if (checkError(answer[2], "INTEGER") != "NONE" ||
            checkError(answer[3], "INTEGER") != "NONE" ||
            checkError(answer[4], "INTEGER") != "NONE" ||
            checkError(answer[5], "INTEGER") != "NONE")
        {
            ShowMessage(x, y + 8, "INPUT KHONG PHU HOP", 1000);
            continue;
        }

        stringToChar(answer[0], loptinchi->courseCode, CourseCode_Length);
        stringToChar(answer[1], loptinchi->schoolYear, SchoolYear_Length);
        loptinchi->semester = std::stoi(answer[2]);
        loptinchi->group = std::stoi(answer[3]);
        loptinchi->studentMin = std::stoi(answer[4]);
        loptinchi->studentMax = std::stoi(answer[5]);

        delete[] answer;
        return;
    }
}

void capNhatLopTinChi_User(int x, int y, LIST_LTC dsLTC, PTRMH treeMH) // cau a
{                                                                      // cau a

    int pos = 0, out = 0;
    char maLTC[15] = "";

    while (true)
    {
        out = menu(x, y, cap_nhat_lop_tin_chi, 3, pos);

        if (out == 1)
        {
            if (XacNhan(x, y + 4, "BAN CO MUON THOAT?") == "YES")
            {
                return;
            }
        }

        if (pos == 0)
        {
            while (true)
            {
                Credit *loptinchi = new Credit;
                loptinchi->creditCode = ++dsLTC.currentIndex;

                nhapThongTinLopTinChi_User(x, y, loptinchi);

                if (strlen(loptinchi->courseCode) == 0)
                {
                    ShowMessage(x, y + 4, "MA MON HOC TRONG -> THOAT", 1000);
                    delete loptinchi;
                    break;
                }
                else if (timMonHocTheoMa(treeMH, loptinchi->courseCode) == NULL)
                {
                    ShowMessage(x, y + 4, "MA MON HOC KHONG TON TAI", 1000);
                    delete loptinchi;
                }

                dsLTC.nodes[loptinchi->creditCode] = loptinchi;
            }
        }
        else if (pos == 1)
        {
            Credit *loptinchi = NULL;
            std::string str_maLTC = "";

            while (true)
            {
                str_maLTC = ""; // reset value

                input_UI(x, y, 1, nhap_ma_lop_tin_chi, &str_maLTC, "STRING");

                if (checkError(maLTC, "INTEGER") != "NONE")
                {
                    ShowMessage(x, y + 4, "MA LOP TIN CHI KHONG HOP LE", 1000);
                    continue;
                }
                else
                {
                    loptinchi = dsLTC.nodes[std::stoi(str_maLTC)];
                    if (loptinchi != NULL)
                    {
                        while (true)
                        {
                            nhapThongTinLopTinChi_User(x, y, loptinchi);
                            if (strlen(loptinchi->courseCode) == 0)
                            {
                                ShowMessage(x, y + 4, "KHONG DE TRONG MA MON HOC", 1000);
                                continue;
                            }
                            else if (timMonHocTheoMa(treeMH, loptinchi->courseCode) == NULL)
                            {
                                ShowMessage(x, y + 4, "MA MON HOC KHONG TON TAI", 1000);
                                continue;
                            }

                            break;
                        }
                    }
                }
            }
        }

        else if (pos == 2)
        {
            Credit *loptinchi = NULL;
            std::string str_maLTC = "";

            while (true)
            {
                str_maLTC = ""; // reset value
                input_UI(x, y, 1, nhap_ma_lop_tin_chi, &str_maLTC, "STRING");

                if (checkError(maLTC, "INTEGER") != "NONE")
                {
                    ShowMessage(x, y + 4, "MA LOP TIN CHI KHONG HOP LE", 1000);
                    continue;
                }
                else
                {
                    loptinchi = dsLTC.nodes[std::stoi(str_maLTC)];
                    if (loptinchi != NULL)
                    {
                        if (XacNhan(x, y + 4, "BAN CO CHAC CHAN MUON XOA?") == "YES")
                        {
                            deleteLinkedList(loptinchi->firstListRegister);
                            delete loptinchi;
                            loptinchi = NULL;
                        }
                    }
                }
            }
        }
    }
}

void nhapThongTinSinhVien(int x, int y, Student &sinhvien) // cau c
{
    std::string *answer = new std::string[5];
    answer[0] = charToString(sinhvien.studentID);
    answer[1] = charToString(sinhvien.lastName);
    answer[2] = charToString(sinhvien.firstName);
    answer[3] = charToString(sinhvien.sex);
    answer[4] = charToString(sinhvien.phoneNum);

    while (true)
    {
        input_UI(x, y, 5, thong_tin_sinh_vien_lop_hoc, answer, "ACCEPT_EMPTY");

        stringToChar(answer[0], sinhvien.studentID, Student_ID_Length);
        stringToChar(answer[1], sinhvien.lastName, Last_Name_Length);
        stringToChar(answer[2], sinhvien.firstName, First_Name_Length);
        stringToChar(answer[3], sinhvien.sex, SEX_Length);
        stringToChar(answer[4], sinhvien.phoneNum, PhoneNum_Length);

        delete[] answer;
        return;
    }
}

void capNhatSinhVienLopHoc(int x, int y, PTRSV firstSV) // cau c
{
    int pos = 1;
    int out = 0;
    char c_mssv[Student_ID_Length + 1] = "";

    while (true)
    {
        out = menu(x, y, cap_nhat_sinh_vien, 3, pos);

        if (out == 1)
        {
            if (XacNhan(x, y + 4, "BAN CO MUON THOAT?") == "YES")
            {
                return;
            }
        }

        if (pos == 0)
        {
            while (true)
            {
                // them sinh vien
                Student sv;
                nhapThongTinSinhVien(x, y, sv);

                if (strlen(sv.studentID) == 0)
                {
                    ShowMessage(x, y + 4, "MSSV TRONG -> THOAT", 1000);
                    break;
                }

                if (timSinhVien_DSSV(firstSV, sv.studentID) != NULL)
                {
                    ShowMessage(x, y + 4, "SINH VIEN DA TON TAI", 1000);
                    continue;
                }

                addStudentToList(firstSV, sv);
            }
        }

        else if (pos == 1)
        {
            PTRSV pSV = NULL;
            std::string str_mssv = "";
            while (true)
            {
                // sua thon tin sinh vien
                str_mssv = ""; // reset value

                input_UI(x, y, 1, nhap_mssv, &str_mssv, "STRING");

                if (str_mssv.length() == 0)
                    break;

                stringToChar(str_mssv, c_mssv, Student_ID_Length);
                pSV = timSinhVien_DSSV(firstSV, c_mssv);

                if (pSV == NULL)
                {
                    ShowMessage(x, y + 4, "SINH VIEN KHONG TON TAI", 1000);
                    continue;
                }

                nhapThongTinSinhVien(x, y, pSV->student);
            }
        }

        else if (pos == 2)
        {
            // xoa sinh vien
            PTRSV pSV = NULL;
            std::string str_mssv = "";
            while (true)
            {
                str_mssv = "";

                input_UI(x, y, 1, nhap_mssv, &str_mssv, "STRING");
                if (str_mssv.length() == 0)
                    return;

                stringToChar(str_mssv, c_mssv, Student_ID_Length);
                pSV = timSinhVien_DSSV(firstSV, c_mssv);

                if (pSV == NULL)
                {
                    ShowMessage(x, y + 4, "SINH VIEN KHONG TON TAI", 1000);
                    continue;
                }

                if (XacNhan(x, y + 4, "BAN CO CHAC CHAN MUON XOA?") == "YES")
                {
                    deleteStudentFromStudentList(firstSV, pSV);
                }
            }
        }
    }
}

void nhapThongTinMonHoc_User(int x, int y, Course &monhoc) // cau e
{

    std::string *answer = new std::string[4];
    answer[0] = charToString(monhoc.courceCode);
    answer[1] = charToString(monhoc.courceName);
    answer[2] = std::to_string(monhoc.STCLT);
    answer[3] = std::to_string(monhoc.STCTH);

    while (true)
    {
        input_UI(x, y, 4, nhap_thong_tin_mon_hoc, answer, "ACCEPT_EMPTY");

        if (checkError(answer[2], "INTEGER") != "NONE" || checkError(answer[3], "INTEGER") != "NONE")
        {
            ShowMessage(x, y + 8, "INPUT KHONG PHU HOP", 1000);
            continue;
        }

        stringToChar(answer[0], monhoc.courceCode, CourseCode_Length);
        stringToChar(answer[1], monhoc.courceName, CourseName_Length);
        monhoc.STCLT = std::stoi(answer[2]);
        monhoc.STCTH = std::stoi(answer[3]);

        delete[] answer;
        return;
    }
}

void capNhatDanhSachMonHoc_User(PTRMH &treeMH, int x, int y) // cau e
{

    int out = 0, pos = 0;

    char maMH[CourseCode_Length + 1] = "";

    while (true)
    {
        out = menu(x, y, cap_nhat_mon_hoc, 3, pos);

        if (out == 1)
        {
            if (XacNhan(x, y + 4, "BAN CO MUON THOAT?") == "YES")
            {
                return;
            }
        }

        if (pos == 0)
        {
            while (true)
            {
                Course monhoc;
                nhapThongTinMonHoc_User(x, y, monhoc);
                if (strlen(monhoc.courceCode) == 0)
                {
                    ShowMessage(x, y + 8, "MA MON HOC TRONG -> THOAT", 1000);
                    break;
                }

                if (timMonHocTheoMa(treeMH, monhoc.courceCode) != NULL)
                {
                    ShowMessage(x, y + 8, "MON HOC DA TON TAI", 1000);
                    continue;
                }

                addCourseToList(treeMH, monhoc);
            }
        }

        else if (pos == 1)
        {
            PTRMH pMH = NULL;
            std::string strMaMH = "";
            while (true)
            {
                strMaMH = "";
                input_UI(x, y, 1, nhap_ma_mon_hoc, &strMaMH, "ACCEPT_EMPTY");

                if (strMaMH.length() == 0)
                {
                    ShowMessage(x, y + 8, "MA MON HOC TRONG -> THOAT", 1000);
                    break;
                }

                stringToChar(strMaMH, maMH, CourseCode_Length);
                pMH = timMonHocTheoMa(treeMH, maMH);

                if (pMH == NULL)
                {
                    ShowMessage(x, y + 8, "MA MON HOC KHONG TON TAI", 1000);
                    continue;
                }

                nhapThongTinMonHoc_User(x, y, pMH->course);
            }
        }
        else if (pos == 2)
        {
            PTRMH pMH = NULL;
            std::string strMaMH = "";
            while (true)
            {
                strMaMH = "";
                input_UI(x, y, 1, nhap_ma_mon_hoc, &strMaMH, "ACCEPT_EMPTY");

                if (strMaMH.length() == 0)
                {
                    ShowMessage(x, y + 8, "MA MON HOC TRONG -> THOAT", 1000);
                    break;
                }

                stringToChar(strMaMH, maMH, CourseCode_Length);
                pMH = timMonHocTheoMa(treeMH, maMH);

                if (pMH == NULL)
                {
                    ShowMessage(x, y + 8, "MA MON HOC KHONG TON TAI", 1000);
                    continue;
                }
                else
                {
                    if (XacNhan(x, y + 4, "BAN CO MUON XOA MON HOC?") == "YES")
                    {
                        deleteCource(treeMH, maMH);
                    }
                }
            }
        }
    }
}
