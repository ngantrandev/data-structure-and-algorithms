#pragma once
#include <iostream>
#include <stack>
#include "input.h"
#include "./menu.h"
#include "../algorithms/algorithms.h"
#include "../data_manager/data_manager.h"

/*
    HAM XUAT THONG TIN
*/

void fillStudentInfoBoard(PTRSV FirstSV, int x, int y);

void fillRegistedStudentBoard(int x, int y, PTRDK firstDK, PTRSV FirstSV);
void fillCreditClassBoard(int x, int y, LIST_LTC dsLTC);
void fillCourseInfoBoard(int x, int y, std::vector<PTRMH> dsMonHoc);

void inDanhSachMonHocTheoTen(int x_origin, int y_origin, PTRMH Tree_monhoc);
void fillCreditClassPointBoard(int x, int y, PTRSV FirstSV, PTRDK firstDK);
void fillAvgPointBoard(int x, int y, PTRSV FirstSV, PTRMH treeMH, LIST_LTC dsLTC, std::map<std::string, std::string> anhXaMSSV_dsLTC);
void fillFinalPointBoard(int x_origin, int y_origin, LIST_LTC dsLTC, PTRSV FirstSV, PTRMH Tree_monhoc, std::map<std::string, std::string> anhXaMSSV_dsLTC);
void inThongTinLopTinChi(int x, int y, std::vector<int> listCreditID, LIST_LTC dsLTC, PTRMH treeMH, char *mssv);

/*
    HAM NHAP THONG TIN
*/
void nhapThongTinLopTinChi_User(int x, int y, Credit *loptinchi);
void nhapThongTinSinhVien(int x, int y, Student &sinhvien);
void nhapThongTinMonHoc_User(int x, int y, Course &monhoc);
void nhapDiem(int x, int y, PTRSV firstSV, Credit *loptinchi);

void capNhatLopTinChi_User(int x, int y, LIST_LTC &dsLTC, PTRMH treeMH);                                                                                      // cau a
void inDanhSachSinhVienDangKy(int x, int y, PTRSV firstSV, LIST_LTC dsLTC);                                                                                   // cau b
void capNhatSinhVienLopHoc(int x, int y, PTRSV firstSV);                                                                                                      // cau c
void inDanhSachSinhVienTheoTen(int x, int y, PTRSV FirstSV, PTRLH firstLH);                                                                                   // cau d
void capNhatDanhSachMonHoc_User(PTRMH &treeMH, int x, int y);                                                                                                 // cau e
void inDanhSachMonHocTheoTen(int x, int y, PTRMH treeMH);                                                                                                     // cau f
void dangKyLopTinChi(int x, int y, LIST_LTC dsLTC, PTRMH treeMH, PTRSV firstSV);                                                                              // cau g
void huyLopTinChiKhongDuDieuKien(int x, int y, LIST_LTC &dsLTC);                                                                                              // cau h
void nhapDiemLopTinChi(int x, int y, PTRSV firstSV, LIST_LTC dsLTC);                                                                                          // cau i
void inBangDiemLopTinChi(PTRSV FirstSV, LIST_LTC dsLTC);                                                                                                      // cau j
void inBangDiemTrungBinhLopHoc(int x, int y, PTRSV firstSV, PTRLH firstLH, PTRMH treeMH, LIST_LTC dsLTC, std::map<std::string, std::string> anhXaMSSV_dsLTC); // cau k
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
                                                 < Trang   1  /  2 >
    */

    if (FirstSV == NULL)
    {
        ShowMessage(x, y, "DANH SACH SINH VIEN RONG", 1500);
        return;
    }

    int tabw = STUDENT_CLASS_INFO_BOARD_WIDTH;
    PTRSV pfirst = FirstSV;
    PTRSV p = NULL;
    int currentPage = 1;
    int pageSize = ceil((float)countLinkedList(FirstSV) / MAX_BOARD_ELEMENTS);
    int keyPressed = 0;
    std::string keyType = "NONE";
    std::stack<PTRSV> stackSV;

    int stt = 0;
    int count = 0;
    bool reDraw = true;

    gotoxy(x, y - 1);
    std::cout << "[NEXT: RIGHT ARROW]   [PREVIOUS: LEFT ARROW]   [EXIT: ESC]";
    while (true)
    {
        if (reDraw == true)
        {
            clearScreen(x, y, tabw, MAX_BOARD_ELEMENTS + 3);
            drawStudentInfoBoard(x, y, MAX_BOARD_ELEMENTS);
            gotoxy(x + 42, y + MAX_BOARD_ELEMENTS + 4);
            std::printf("< Trang %2d / %d >", currentPage, pageSize);

            p = pfirst;
            count = 0;
            stt = (currentPage == 1) ? 0 : (currentPage - 1) * 10;
            while (p != NULL)
            {
                ++count;
                if (count > MAX_BOARD_ELEMENTS)
                    break;
                ++stt;

                gotoxy(x + 4, y + 2 + count);
                std::cout << ((stt < 10) ? "0" + std::to_string(stt) : std::to_string(stt));
                gotoxy(x + 13, y + 2 + count);
                std::cout << p->student.studentID;
                gotoxy(x + 28, y + 2 + count);
                std::cout << p->student.lastName;
                gotoxy(x + 50, y + 2 + count);
                std::cout << p->student.firstName;
                gotoxy(x + 63, y + 2 + count);
                std::cout << p->student.sex;
                gotoxy(x + 72, y + 2 + count);
                std::cout << p->student.classID;
                gotoxy(x + 89, y + 2 + count);
                std::cout << p->student.phoneNum;

                p = p->next;
            }
            reDraw = false;
        }

        keyPressed = getch();
        keyType = getKeyType(keyPressed);
        if (keyType == "RIGHT")
        {
            if (currentPage < pageSize)
            {
                stackSV.push(pfirst);
                pfirst = getNextPointer(pfirst, MAX_BOARD_ELEMENTS);
                currentPage++;
                reDraw = true;
            }
        }
        else if (keyType == "LEFT")
        {
            if (currentPage > 1)
            {
                pfirst = stackSV.top();
                stackSV.pop();
                currentPage--;
                reDraw = true;
            }
        }
        else if (keyType == "EXIT")
        {
            break;
        }
    }
    clearScreen(x, y - 1, tabw, MAX_BOARD_ELEMENTS + 5);
}

void inDanhSachSinhVienTheoTen(int x, int y, PTRSV FirstSV, PTRLH firstLH) // case 4:  cau d
{
    char malophoc[ClassID_Length] = "";
    PTRSV ptrSV = NULL; // giu dia chi con tro FirstSV
    PTRSV temp_FirstSV = NULL;
    std::string malop_string[2] = {""};
    bool out = false;

    while (true)
    {
        system("cls");

        ptrSV = FirstSV;
        temp_FirstSV = NULL; // reset lai danh sach
        out = input_UI(x, y, 1, nhap_ma_lop_hoc, malop_string, "STRING");

        if (out == true)
        {
            return;
        }

        stringToChar(malop_string[0], malophoc, ClassID_Length);

        if (timLopHoc(firstLH, malophoc) == NULL)
        {
            ShowMessage(x, y - 2, "MA LOP KHONG TON TAI", FAST_TIME);
            continue;
        }

        break;
    }

    while (ptrSV != NULL)
    {
        if (strcmp(ptrSV->student.classID, malophoc) == 0)
            addStudentToList(temp_FirstSV, ptrSV->student);
        ptrSV = ptrSV->next;
    }

    sapXepDanhSachSinhVienTheoTen_Ho_SelectionSort(temp_FirstSV);
    fillStudentInfoBoard(temp_FirstSV, 13, 4);
    deleteLinkedList(temp_FirstSV);
}

void fillRegistedStudentBoard(int x, int y, PTRDK firstDK, PTRSV FirstSV) // case 2: cau b
{
    /*
        x         x1             x2                 x3            x4          x5             x6
        +=========+==============+==================+=============+===========+==============+===============+
        |   STT   |     MSSV     |        HO        |     TEN     | GIOI TINH |    MA LOP    | SO DIEN THOAI |
    y1  +=========+==============+==================+=============+===========+==============+===============+
        |         |              |                  |             |           |              |               |
        |         |              |                  |             |           |              |               |
        +=========+==============+==================+=============+===========+==============+===============+
                                                 < Trang   1  /  2 >
    */

    system("cls");

    if (firstDK == NULL)
    {
        ShowMessage(x, y, "DANH SACH DANG KY RONG", 1500);
        return;
    }

    int tabw = STUDENT_CLASS_INFO_BOARD_WIDTH;
    int currentPage = 1;
    int pageSize = ceil((float)countLinkedList(firstDK) / MAX_BOARD_ELEMENTS);
    int keyPressed = 0;
    std::string keyType = "NONE";
    std::stack<PTRDK> stackDK;

    PTRDK pfirst = firstDK; // bien p tro toi danh sach dangky;
    PTRDK pDK = NULL;
    PTRSV pSV = NULL;
    int stt = 0, count = 0;
    bool reDraw = true;

    gotoxy(x, y - 1);
    std::cout << "[NEXT: RIGHT ARROW]   [PREVIOUS: LEFT ARROW]   [EXIT: ESC]";

    while (true)
    {
        if (reDraw == true)
        {
            clearScreen(x, y, tabw, MAX_BOARD_ELEMENTS + 3);
            drawStudentInfoBoard(x, y, MAX_BOARD_ELEMENTS);
            gotoxy(x + 42, y + MAX_BOARD_ELEMENTS + 4);
            std::printf("< Trang %2d / %d >", currentPage, pageSize);

            pDK = pfirst;
            count = 0;
            stt = (currentPage == 1) ? 0 : (currentPage - 1) * 10;

            while (pDK != NULL)
            {
                pSV = timSinhVien_DSSV(FirstSV, pDK->regis.studentID);
                if (pSV != NULL)
                {
                    count++;
                    if (count > MAX_BOARD_ELEMENTS)
                        break;

                    stt++;
                    gotoxy(x + 4, y + 2 + count);
                    std::cout << ((stt < 10) ? "0" + std::to_string(stt) : std::to_string(stt));
                    gotoxy(x + 13, y + 2 + count);
                    std::cout << pSV->student.studentID;
                    gotoxy(x + 28, y + 2 + count);
                    std::cout << pSV->student.lastName;
                    gotoxy(x + 50, y + 2 + count);
                    std::cout << pSV->student.firstName;
                    gotoxy(x + 63, y + 2 + count);
                    std::cout << pSV->student.sex;
                    gotoxy(x + 72, y + 2 + count);
                    std::cout << pSV->student.classID;
                    gotoxy(x + 89, y + 2 + count);
                    std::cout << pSV->student.phoneNum;
                }
                pDK = pDK->next;
            }

            reDraw = false;
        }

        keyPressed = getch();
        keyType = getKeyType(keyPressed);
        if (keyType == "RIGHT")
        {
            if (currentPage < pageSize)
            {
                stackDK.push(pfirst);
                pfirst = getNextPointer(pfirst, MAX_BOARD_ELEMENTS);
                currentPage++;
                reDraw = true;
            }
        }
        else if (keyType == "LEFT")
        {
            if (currentPage > 1)
            {
                pfirst = stackDK.top();
                stackDK.pop();
                currentPage--;
                reDraw = true;
            }
        }
        else if (keyType == "EXIT")
        {
            break;
        }
    }

    clearScreen(x, y - 1, tabw, MAX_BOARD_ELEMENTS + 5);
}

void fillCreditClassBoard(int x, int y, LIST_LTC dsLTC)
{
    /*                                              DANH SACH LOP TIN CHI
                                                  CO %d LOP TRONG DANH SACH
         x     x1       x2           x3            x4       x5       x6        x7        x8                x9
        +=====+========+============+=============+========+========+=========+=========+=================+=============+
        | STT | MA LOP |   MA MON   |  NIEN KHOA  | HOC KY |  NHOM  | SOSVMIN | SOSVMAX | SLOT DA DANG KY |  TINH TRANG |
    y1  +=====+========+============+=============+========+========+=========+=========+=================+=============+
        |     |        |            | 2020 - 2021 |        |        |         |         |                 |  HOAT DONG  |
        |     |        |            |             |        |        |         |         |                 |             |
        +=====+========+============+=============+========+========+=========+=========+=================+=============+
                                                        < Trang   1  /  2 >
    */
    int size = countCreditClass(dsLTC);

    if (size == 0)
    {
        ShowMessage(10, 3, "DANH SACH LOP TIN CHI RONG", 1500);
        return;
    }
    gotoxy(x + 39, y - 4);
    std::cout << "DANH SACH LOP TIN CHI";
    gotoxy(x + 36, y - 3);
    std::printf("  CO %2d LOP TRONG DANH SACH", size);

    int tabw = CREDIT_CLASS_INFO_BOARD_WIDTH;
    int currentPage = 1;
    int pageSize = ceil((float)size / MAX_BOARD_ELEMENTS);
    int keyPressed = 0;
    std::string keyType = "NONE";

    int firstIndex = 1;
    int curr_index = 0;
    std::stack<int> stackIndex;

    int count = 0; // dem so lop tin chi thoa man
    int stt = 0;
    bool reDraw = true;

    gotoxy(x, y - 1);
    std::cout << "[NEXT: RIGHT ARROW]   [PREVIOUS: LEFT ARROW]   [EXIT: ESC]";
    while (true)
    {
        if (reDraw == true)
        {
            clearScreen(x, y, tabw, MAX_BOARD_ELEMENTS + 3);
            drawCreditClassInfoBoard(x, y, MAX_BOARD_ELEMENTS);
            gotoxy(x + 48, y + MAX_BOARD_ELEMENTS + 4);
            std::printf("< Trang %2d / %d >", currentPage, pageSize);

            count = 0;
            curr_index = firstIndex;
            stt = (currentPage == 1) ? 0 : (currentPage - 1) * 10;
            while (true)
            {
                if (curr_index > dsLTC.currentIndex)
                    break;

                if (dsLTC.nodes[curr_index] != NULL)
                {
                    count++;
                    if (count > MAX_BOARD_ELEMENTS)
                        break;

                    stt++;
                    gotoxy(x + 2, y + 2 + count);
                    std::cout << ((stt < 10) ? "0" + std::to_string(stt) : std::to_string(stt));
                    gotoxy(x + 10, y + 2 + count);
                    std::cout << dsLTC.nodes[curr_index]->creditCode;
                    gotoxy(x + 20, y + 2 + count);
                    std::cout << dsLTC.nodes[curr_index]->courseCode;
                    gotoxy(x + 33, y + 2 + count);
                    std::cout << dsLTC.nodes[curr_index]->schoolYear;
                    gotoxy(x + 46, y + 2 + count);
                    std::cout << dsLTC.nodes[curr_index]->semester;
                    gotoxy(x + 55, y + 2 + count);
                    std::cout << dsLTC.nodes[curr_index]->group;
                    gotoxy(x + 65, y + 2 + count);
                    std::cout << dsLTC.nodes[curr_index]->studentMin;
                    gotoxy(x + 75, y + 2 + count);
                    std::cout << dsLTC.nodes[curr_index]->studentMax;
                    gotoxy(x + 88, y + 2 + count);
                    std::cout << countLinkedList(dsLTC.nodes[curr_index]->firstListRegister);
                    gotoxy(x + 101, y + 2 + count);
                    std::cout << (dsLTC.nodes[curr_index]->disable == false ? "Hoat dong" : "Da huy");
                }

                curr_index++;
            }
            reDraw = false;
        }

        keyPressed = getch();
        keyType = getKeyType(keyPressed);
        if (keyType == "RIGHT")
        {
            if (currentPage < pageSize)
            {
                stackIndex.push(firstIndex);
                firstIndex = getNextCreditClassID(dsLTC, firstIndex, MAX_BOARD_ELEMENTS);
                currentPage++;
                reDraw = true;
            }
        }
        else if (keyType == "LEFT")
        {
            if (currentPage > 1)
            {
                firstIndex = stackIndex.top();
                stackIndex.pop();
                currentPage--;
                reDraw = true;
            }
        }
        else if (keyType == "EXIT")
        {
            break;
        }
    }

    clearScreen(x, y - 4, tabw, MAX_BOARD_ELEMENTS + 9);
}

void fillCourseInfoBoard(int x, int y, std::vector<PTRMH> dsMonHoc)
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
                                  < Trang   1  /  2 >
    */

    if (dsMonHoc.size() == 0)
    {
        ShowMessage(10, 10, "DANH SACH MON HOC RONG", 1500);
        return;
    }

    int soLuongMonHoc = dsMonHoc.size();
    int tabw = COURSE_INFO_BOARD_WIDTH;
    int currentPage = 1;
    int pageSize = ceil((float)soLuongMonHoc / MAX_BOARD_ELEMENTS);
    int keyPressed = 0;
    std::string keyType = "NONE";

    int firstIndex = 0;
    int curr_index = 0;
    std::stack<int> stackIndex;
    int count = 0; // dem so lop tin chi thoa man
    int stt = 0;
    bool reDraw = true;

    gotoxy(x + 27, y - 4);
    std::cout << "DANH SACH MON HOC";
    gotoxy(x + 21, y - 3);
    std::printf("CO %d MON HOC TRONG DANH SACH", soLuongMonHoc);

    gotoxy(x, y - 1);
    std::cout << "[NEXT: RIGHT ARROW]   [PREVIOUS: LEFT ARROW]   [EXIT: ESC]";

    while (true)
    {
        if (reDraw == true)
        {
            clearScreen(x, y, tabw, MAX_BOARD_ELEMENTS + 3);
            drawCourseInfoBoard(x, y, MAX_BOARD_ELEMENTS);
            gotoxy(x + 27, y + MAX_BOARD_ELEMENTS + 4);
            std::printf("< Trang %2d / %d >", currentPage, pageSize);

            count = 0;
            curr_index = firstIndex;
            stt = (currentPage == 1) ? 0 : (currentPage - 1) * 10;

            while (true)
            {
                if (curr_index > soLuongMonHoc - 1)
                    break;

                count++;

                if (count > MAX_BOARD_ELEMENTS)
                    break;

                stt++;
                gotoxy(x + 4, y + 2 + count);
                std::cout << ((stt < 10) ? "0" + std::to_string(stt) : std::to_string(stt));
                gotoxy(x + 15, y + 2 + count);
                std::cout << dsMonHoc[curr_index]->course.courceCode;
                gotoxy(x + 27, y + 2 + count);
                std::cout << dsMonHoc[curr_index]->course.courceName;
                gotoxy(x + 56, y + 2 + count);
                std::cout << dsMonHoc[curr_index]->course.STCLT;
                gotoxy(x + 66, y + 2 + count);
                std::cout << dsMonHoc[curr_index]->course.STCTH;

                curr_index++;
            }
            reDraw = false;
        }

        keyPressed = getch();
        keyType = getKeyType(keyPressed);
        if (keyType == "RIGHT")
        {
            if (currentPage < pageSize)
            {
                stackIndex.push(firstIndex);
                firstIndex = getNextCourseID(dsMonHoc, firstIndex, MAX_BOARD_ELEMENTS);
                currentPage++;
                reDraw = true;
            }
        }
        else if (keyType == "LEFT")
        {
            if (currentPage > 1)
            {
                firstIndex = stackIndex.top();
                stackIndex.pop();
                currentPage--;
                reDraw = true;
            }
        }
        else if (keyType == "EXIT")
        {
            break;
        }
    }
    clearScreen(x, y - 4, tabw, MAX_BOARD_ELEMENTS + 9);
}

void inDanhSachMonHocTheoTen(int x, int y, PTRMH treeMH) // cau f
{
    std::vector<PTRMH> dsMH;
    getListTreeNode(treeMH, dsMH);

    mergeSortPTRMH(dsMH, 0, dsMH.size() - 1);

    fillCourseInfoBoard(x, y, dsMH);
}

void dangKyLopTinChi(int x, int y, LIST_LTC dsLTC, PTRMH treeMH, PTRSV firstSV) // cau g
{
    PTRSV ptrSV = NULL;
    // NHAP NIEN KHOA, HOC KY
    char nienkhoa[SchoolYear_Length] = "";
    int hocky = 0;
    char mssv[Student_ID_Length] = "";
    std::vector<int> creditListID;
    bool out = false;
    while (true)
    {
        std::string answer[1] = {""};
        out = input_UI(x, y, 1, nhap_mssv, answer, "STRING");
        if (out == true)
        {
            return;
        }

        stringToChar(answer[0], mssv, Student_ID_Length);

        ptrSV = timSinhVien_DSSV(firstSV, mssv);

        if (ptrSV == NULL)
        {
            ShowMessage(x, y + 2, "SINH VIEN KHONG TON TAI", FAST_TIME);
            continue;
        }
        break;
    }

    PTRSV temp_firstSV = NULL;
    addStudentToList(temp_firstSV, ptrSV->student);

    fillStudentInfoBoard(temp_firstSV, 10, y);
    deleteLinkedList(temp_firstSV);

    while (true)
    {
        std::string answer[2] = {""};
        input_UI(x, y, 2, cau_g, answer, "STRING");
        if (checkError(answer[1], "INTEGER") != "NONE")
        {
            ShowMessage(x, y + 2, "HOC KY KHONG HOP LE", 1500);
            continue;
        }
        stringToChar(answer[0], nienkhoa, SchoolYear_Length);
        hocky = std::stoi(answer[1]);
        creditListID = getCreditList_theoMAMH_NIENKHOA(dsLTC, hocky, nienkhoa);

        if (creditListID.size() == 0)
        {
            ShowMessage(x, y, "KHONG TIM THAY LOP TIN CHI THOA MAN", 1500);
            continue;
        }
        break;
    }
    ShowCur(0);
    inThongTinLopTinChi(10, y, creditListID, dsLTC, treeMH, mssv);
    ShowCur(1);
}

void huyLopTinChiKhongDuDieuKien(int x, int y, LIST_LTC &dsLTC) // cau h
{
    if (XacNhan(x, y, "XAC NHAN HUY CAC LOP TIN CHI KHONG DU SINH VIEN") == "YES")
    {
        for (int i = 1; i <= dsLTC.currentIndex; i++)
        {
            if (dsLTC.nodes[i] != NULL)
            {
                if (countLinkedList(dsLTC.nodes[i]->firstListRegister) < dsLTC.nodes[i]->studentMin)
                {
                    dsLTC.nodes[i]->disable = true;
                }
            }
        }
    }
}

void fillCreditClassPointBoard(int x, int y, PTRSV FirstSV, PTRDK firstDK)
{
    /*
        x         x1             x2                     x3                x4
        +=========+==============+======================+=================+==================+
        |   STT   |     MSSV     |          HO          |       TEN       |       DIEM       |
     y1 +=========+==============+======================+=================+==================+
        |   1     |  N20DCPT001  |  Tran Thi Uyen       |      Hau        |      10.00       |
        |   10    |  N20DCPT090  |  Truong Thanh Thao   |      Uyen       |      0.00        |
        +=========+==============+======================+=================+==================+
                                          < Trang   1  /  2 >
    */

    int tabw = SCORE_BOARD_WIDTH;
    int currentPage = 1;
    int pageSize = ceil((float)countLinkedList(firstDK) / MAX_BOARD_ELEMENTS);
    int keyPressed = 0;
    std::string keyType = "NONE";
    std::stack<PTRDK> stackDK;

    PTRDK pfirst = firstDK; // bien p tro toi danh sach dangky;
    PTRDK ptrDK = NULL;
    PTRSV ptrSV = NULL;

    int stt = 0, count = 0;
    bool reDraw = true;

    gotoxy(x, y - 1);
    std::cout << "[NEXT: RIGHT ARROW]   [PREVIOUS: LEFT ARROW]   [EXIT: ESC]";

    while (true)
    {
        if (reDraw == true)
        {
            clearScreen(x, y, tabw, MAX_BOARD_ELEMENTS + 3);
            drawScoreBoard(x, y, MAX_BOARD_ELEMENTS);
            gotoxy(x + 34, y + MAX_BOARD_ELEMENTS + 4);
            std::printf("< Trang %2d / %d >", currentPage, pageSize);

            ptrDK = pfirst;
            count = 0;
            stt = (currentPage == 1) ? 0 : (currentPage - 1) * 10;

            while (ptrDK != NULL)
            {
                ptrSV = timSinhVien_DSSV(FirstSV, ptrDK->regis.studentID);

                stt++;
                count++;

                if (count > MAX_BOARD_ELEMENTS)
                    break;

                gotoxy(x + 4, y + 2 + count);
                std::cout << stt;
                gotoxy(x + 13, y + 2 + count);
                std::cout << ptrDK->regis.studentID;
                gotoxy(x + 28, y + 2 + count);
                std::cout << ptrSV->student.lastName;
                gotoxy(x + 55, y + 2 + count);
                std::cout << ptrSV->student.firstName;
                gotoxy(x + 73, y + 2 + count);
                std::printf("%0.2f", ptrDK->regis.point);

                ptrDK = ptrDK->next;
            }
            reDraw = false;
        }

        keyPressed = getch();
        keyType = getKeyType(keyPressed);
        if (keyType == "RIGHT")
        {
            if (currentPage < pageSize)
            {
                stackDK.push(pfirst);
                pfirst = getNextPointer(pfirst, MAX_BOARD_ELEMENTS);
                currentPage++;
                reDraw = true;
            }
        }
        else if (keyType == "LEFT")
        {
            if (currentPage > 1)
            {
                pfirst = stackDK.top();
                stackDK.pop();
                currentPage--;
                reDraw = true;
            }
        }
        else if (keyType == "EXIT")
        {
            break;
        }
    }
    clearScreen(x, y - 1, SCORE_BOARD_WIDTH, MAX_BOARD_ELEMENTS + 5);
}

void nhapDiemLopTinChi(int x, int y, PTRSV firstSV, LIST_LTC dsLTC) // cau i
{
    char nienkhoa[SchoolYear_Length] = "";
    int hocky = 0;
    int nhom = 0;
    char maMH[CourseCode_Length] = "";
    Credit *loptinchi = NULL;
    bool out = false;

    while (true)
    {
        std::string answer[4] = {""};
        out = input_UI(x, y, 4, cau_2, answer, "STRING");
        if (out == true)
            return;

        if (IsIntNumber(answer[1]) == false || IsIntNumber(answer[2]) == false)
        {
            ShowMessage(10, 10, "HOC KY VA NHOM LA SO NGUYEN", 1500);
            continue;
        }

        stringToChar(answer[0], nienkhoa, SchoolYear_Length);
        hocky = std::stoi(answer[1]);
        nhom = std::stoi(answer[2]);
        stringToChar(answer[3], maMH, CourseCode_Length);
        break;
    }

    loptinchi = timLopTinChi_theoInfo(dsLTC, nienkhoa, hocky, nhom, maMH);

    if (loptinchi == NULL)
    {
        ShowMessage(10, 10, "KHONG TIM THAY LOP TIN CHI", 1500);
        return;
    }

    nhapDiem(10, y, firstSV, loptinchi);
}

void inBangDiemLopTinChi(PTRSV FirstSV, LIST_LTC dsLTC) // cau j
{                                                       // case 10: cau j
    char nienkhoa[SchoolYear_Length] = "";
    char maMH[CourseCode_Length] = "";
    int hocky = 0, nhom = 0;
    Credit *loptinchi = NULL;
    system("cls");
    bool out = false;

    while (true)
    {
        std::string answer[4] = {""};
        out = input_UI(20, 10, 4, cau_2, answer, "STRING");
        if (out == true)
            return;

        stringToChar(answer[0], nienkhoa, SchoolYear_Length);
        hocky = std::stoi(answer[1]);
        nhom = std::stoi(answer[2]);
        stringToChar(answer[3], maMH, CourseCode_Length);

        loptinchi = timLopTinChi_theoInfo(dsLTC, nienkhoa, hocky, nhom, maMH);

        if (loptinchi == NULL)
        {
            ShowMessage(10, 10, "KHONG TIM THAY LOP TIN CHI", FAST_TIME);
        }

        fillCreditClassPointBoard(10, 10, FirstSV, loptinchi->firstListRegister);
    }
}

void inBangDiemTrungBinhLopHoc(int x, int y, PTRSV firstSV, PTRLH firstLH, PTRMH treeMH, LIST_LTC dsLTC, std::map<std::string, std::string> anhXaMSSV_dsLTC) // cau k
{
    /*                      BANG DIEM THONG KE DIEM TRUNG BINH KHOA HOC
                                      Lop:     <D20CQPT01-N>

        [NEXT: RIGHT ARROW]   [PREVIOUS: LEFT ARROW]   [EXIT: ESC]
        x         x1             x2                     x3                x4
        +=========+==============+======================+=================+============+
        |   STT   |     MSSV     |          HO          |       TEN       |   DIEM TB  |
    y1  +=========+==============+======================+=================+============+
        |         |              |                      |                 |            |
        |         |              |                      |                 |            |
        +=========+==============+======================+=================+============+
                                        < Trang   1  /  2 >
    */

    bool out = false;

    while (true)
    {
        char malop[ClassID_Length] = "";

        std::string answer[2] = {""};

        out = input_UI(x, y, 1, nhap_ma_lop_hoc, answer, "STRING");

        if (out == true)
            break;

        stringToChar(answer[0], malop, ClassID_Length);

        if (timLopHoc(firstLH, malop) == NULL)
        {
            ShowMessage(x, y, "KHONG TIM THAY LOP HOC", FAST_TIME);
            continue;
        }

        gotoxy(x + 20, y - 4);
        std::cout << "BANG DIEM THONG KE DIEM TRUNG BINH KHOA HOC";
        gotoxy(x + 30, y - 3);
        std::printf("Lop:     <%s>", malop);

        PTRSV temp_firstSV = NULL;
        PTRSV p = firstSV;

        while (p != NULL)
        {
            if (strcmp(p->student.classID, malop) == 0)
            {
                addStudentToList(temp_firstSV, p->student);
            }

            p = p->next;
        }

        fillAvgPointBoard(x, y, temp_firstSV, treeMH, dsLTC, anhXaMSSV_dsLTC);
        deleteLinkedList(temp_firstSV);
        clearScreen(x, y - 4, AVG_SCORE_BOARD_WIDTH, MAX_BOARD_ELEMENTS + 10);

        return;
    }
}

void inDanhSachSinhVienDangKy(int x, int y, PTRSV firstSV, LIST_LTC dsLTC) // cau b
{
    char nienkhoa[SchoolYear_Length] = "";
    int hocky = 0;
    int nhom = 0;
    char maMH[CourseCode_Length] = "";
    std::string answer[4] = {""};
    Credit *loptinchi = NULL;

    bool out = false;

    while (true)
    {
        out = input_UI(x, y, 4, cau_2, answer, "STRING");

        if (out == true)
        {
            return;
        }

        if (IsIntNumber(answer[1]) == false || IsIntNumber(answer[2]) == false)
        {
            ShowMessage(10, 10, "HOC KY VA NHOM LA SO NGUYEN", NORMAL_TIME);
            continue;
            ;
        }
        break;
    }

    stringToChar(answer[0], nienkhoa, SchoolYear_Length);
    hocky = std::stoi(answer[1]);
    nhom = std::stoi(answer[2]);
    stringToChar(answer[3], maMH, CourseCode_Length);

    loptinchi = timLopTinChi_theoInfo(dsLTC, nienkhoa, hocky, nhom, maMH);

    if (loptinchi == NULL)
    {
        ShowMessage(10, 10, "KHONG TIM THAY LOP TIN CHI", 1500);
        return;
    }

    fillRegistedStudentBoard(10, y, loptinchi->firstListRegister, firstSV);
}

void fillAvgPointBoard(int x, int y, PTRSV FirstSV, PTRMH treeMH, LIST_LTC dsLTC, std::map<std::string, std::string> anhXaMSSV_dsLTC)
{
    /*
        x         x1             x2                     x3                x4
        +=========+==============+======================+=================+============+
        |   STT   |     MSSV     |          HO          |       TEN       |   DIEM TB  |
    y1  +=========+==============+======================+=================+============+
        |         |              |                      |                 |            |
        |         |              |                      |                 |            |
        +=========+==============+======================+=================+============+
                                        < Trang   1  /  2 >
    */

    if (FirstSV == NULL)
    {
        ShowMessage(x, y, "DANH SACH SINH VIEN RONG", 1000);
        return;
    }

    int tabw = AVG_SCORE_BOARD_WIDTH;
    int currentPage = 1;
    int pageSize = ceil((float)countLinkedList(FirstSV) / MAX_BOARD_ELEMENTS);

    PTRSV pfirst = FirstSV;
    PTRSV ptrSV = NULL;
    PTRDK ptrDK = NULL;
    PTRMH nodeMH = NULL;
    float totalScore = 0;
    int totalCredit = 0;
    std::vector<int> splitDsLTC;

    int keyPressed = 0;
    std::string keyType = "NONE";
    std::stack<PTRSV> stackSV;

    int stt = 0, count = 0;
    bool reDraw = true;

    gotoxy(x, y - 1);
    std::cout << "[NEXT: RIGHT ARROW]   [PREVIOUS: LEFT ARROW]   [EXIT: ESC]";
    while (true)
    {
        if (reDraw == true)
        {
            clearScreen(x, y, tabw, MAX_BOARD_ELEMENTS + 3);
            drawAvgScoreBoard(x, y, MAX_BOARD_ELEMENTS);
            gotoxy(x + 34, y + MAX_BOARD_ELEMENTS + 4);
            std::printf("< Trang %2d / %d >", currentPage, pageSize);

            ptrSV = pfirst;
            count = 0;
            stt = (currentPage == 1) ? 0 : (currentPage - 1) * 10;

            while (ptrSV != NULL)
            {
                totalScore = 0; // reset value
                totalCredit = 0;

                count++;
                if (count > MAX_BOARD_ELEMENTS)
                    break;

                stt++;

                if (anhXaMSSV_dsLTC.count(ptrSV->student.studentID) != 0)
                    splitDsLTC = customSplit(anhXaMSSV_dsLTC[charToString(ptrSV->student.studentID)], ',');

                for (int i = 0; i < splitDsLTC.size(); i++)
                {
                    ptrDK = timSinhVien_DSSVDK(dsLTC.nodes[splitDsLTC[i]]->firstListRegister, ptrSV->student.studentID);
                    if (ptrDK != NULL)
                    {
                        nodeMH = timMonHocTheoMa(treeMH, dsLTC.nodes[splitDsLTC[i]]->courseCode);
                        totalScore += ptrDK->regis.point * (nodeMH->course.STCLT + nodeMH->course.STCTH);
                        totalCredit += nodeMH->course.STCLT + nodeMH->course.STCTH;
                    }
                }

                gotoxy(x + 4, y + 2 + count);
                std::cout << ((stt < 10) ? "0" + std::to_string(stt) : std::to_string(stt));
                gotoxy(x + 12, y + 2 + count);
                std::cout << ptrSV->student.studentID;
                gotoxy(x + 28, y + 2 + count);
                std::cout << ptrSV->student.lastName;
                gotoxy(x + 55, y + 2 + count);
                std::cout << ptrSV->student.firstName;
                gotoxy(x + 72, y + 2 + count);
                if (totalCredit == 0)
                    std::cout << "0.00";
                else
                    std::cout << round(totalScore / totalCredit * 100) / 100; // round(totalScore/totalCredit, 2 decimal places)

                ptrSV = ptrSV->next;
            }
            reDraw = false;
        }

        keyPressed = getch();
        keyType = getKeyType(keyPressed);
        if (keyType == "RIGHT")
        {
            if (currentPage < pageSize)
            {
                stackSV.push(pfirst);
                pfirst = getNextPointer(pfirst, MAX_BOARD_ELEMENTS);
                currentPage++;
                reDraw = true;
            }
        }
        else if (keyType == "LEFT")
        {
            if (currentPage > 1)
            {
                pfirst = stackSV.top();
                stackSV.pop();
                currentPage--;
                reDraw = true;
            }
        }
        else if (keyType == "EXIT")
        {
            break;
        }
    }

    clearScreen(x, y - 1, tabw, MAX_BOARD_ELEMENTS + 5);
}

void fillFinalPointBoard(int x_origin, int y_origin, LIST_LTC dsLTC, PTRSV FirstSV, PTRMH Tree_monhoc, std::map<std::string, std::string> anhXaMSSV_dsLTC)
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
                                        < Trang   1  /  2 >
    */

    int x = x_origin;
    int y = y_origin;
    int x3 = x + 50;
    int step = 10;

    std::vector<PTRMH> dsMonHoc;
    getListTreeNode(Tree_monhoc, dsMonHoc);
    std::vector<int> splitDsLTC;

    // left_size la chieu dai tu dau table den het phan cot HOTEN
    int so_mon_hoc = dsMonHoc.size();
    int left_size = 51;
    int w = so_mon_hoc * step + left_size;

    int indexMaMH = 0; // vi tri phan tu maMH trong dsMaMH
    Credit *loptinchi = NULL;
    PTRDK nodeDK = NULL;
    PTRSV pfirst = FirstSV;
    PTRSV p = NULL;

    int currentPage = 1;
    int pageSize = ceil((float)countLinkedList(FirstSV) / MAX_BOARD_ELEMENTS);
    int keyPressed = 0;
    std::string keyType = "NONE";
    std::stack<PTRSV> stackSV;
    std::string temp_str = "";

    int stt = 0;
    int count = 0;
    bool reDraw = true;

    while (true)
    {
        if (reDraw == true)
        {
            system("cls");
            x3 = x + 50; // update x3

            gotoxy(10, y - 1);
            std::cout << "[NEXT: RIGHT ARROW]   [PREVIOUS: LEFT ARROW]    [SCROOL: A,D]    [EXIT: ESC]";
            gotoxy(42, y + MAX_BOARD_ELEMENTS + 4);
            std::printf("< Trang %2d / %d >", currentPage, pageSize);
            drawFinalScoreBoard(x, y, so_mon_hoc, dsMonHoc);

            p = pfirst;
            count = 0;
            stt = (currentPage == 1) ? 0 : (currentPage - 1) * 10;
            while (p != NULL)
            {
                count++;

                if (count > MAX_BOARD_ELEMENTS)
                    break;

                stt++;

                printStringXY(x + 4, y + 2 + count, ((stt < 10) ? "0" + std::to_string(stt) : std::to_string(stt)));
                printStringXY(x + 12, y + 2 + count, p->student.studentID, Student_ID_Length);
                printStringXY(x + 28, y + 2 + count, charToString(p->student.lastName) + " " + charToString(p->student.firstName));

                auto it = anhXaMSSV_dsLTC.find(charToString(p->student.studentID));

                if (it == anhXaMSSV_dsLTC.end())
                {
                    p = p->next;
                    continue;
                }

                splitDsLTC = customSplit(it->second, ',');

                for (int i = 0; i < splitDsLTC.size(); i++)
                {
                    loptinchi = dsLTC.nodes[splitDsLTC[i]];

                    nodeDK = timSinhVien_DSSVDK(loptinchi->firstListRegister, p->student.studentID);
                    // indexMaMH = std::find(dsMonHoc.begin(), dsMonHoc.end(), loptinchi->courseCode) - dsMonHoc.begin();
                    indexMaMH = std::find_if(dsMonHoc.begin(), dsMonHoc.end(), [loptinchi](PTRMH node)
                                             { return strcmp(node->course.courceCode, loptinchi->courseCode) == 0; }) -
                                dsMonHoc.begin();

                    printStringXY(x3 + step * (indexMaMH + 1) - 8, y + 2 + count, round(nodeDK->regis.point * 100) / 100);
                    // break;
                }

                p = p->next;
            }
            reDraw = false;
        }

        keyPressed = getch();
        keyType = getKeyType(keyPressed);
        if (keyType == "RIGHT")
        {
            if (currentPage < pageSize)
            {
                stackSV.push(pfirst);
                pfirst = getNextPointer(pfirst, MAX_BOARD_ELEMENTS);
                currentPage++;
                reDraw = true;
            }
        }
        else if (keyType == "LEFT")
        {
            if (currentPage > 1)
            {
                pfirst = stackSV.top();
                stackSV.pop();
                currentPage--;
                reDraw = true;
            }
        }

        else if (keyType == "NHAP_VAN_BAN")
        {
            if (keyPressed == 'a' || keyPressed == 'A')
            {
                reDraw = true;
                x += SCROOL_STEP;
            }
            else if (keyPressed == 'd' || keyPressed == 'D')
            {
                reDraw = true;
                x -= SCROOL_STEP;
            }
        }
        else if (keyType == "EXIT")
        {
            break;
        }
    }

    system("cls");
}

void inThongTinLopTinChi(int x, int y, std::vector<int> listCreditID, LIST_LTC dsLTC, PTRMH treeMH, char *mssv)
{
    /*  [NEXT: RIGHT ARROW]   [PREVIOUS: LEFT ARROW]   [EXIT: ESC]
        x     x1       x2         x3                              x4        x5             x6
        +=====+========+==========+===============================+=========+==============+==============+
        | STT | MA LOP |  MA MON  |           TEN MON             |   NHOM  | SLOT DANG KY | SLOT CON LAI |
    y1 +=====+========+==========+===============================+=========+==============+==============+
        |     |        |          |                               |         |              |              |
        |     |        |          |                               |         |              |              |
        +=====+========+==========+===============================+=========+==============+==============+
                                                < Trang  1 / 2 >
     */

    if (listCreditID.size() == 0)
    {
        ShowMessage(x, y, "DANH SACH LOP TIN CHI RONG", 1500);
        return;
    }

    int w = CREDIT_CLASS_STATUS_BOARD_WIDTH;
    int currPage = 1;
    int pageSize = ceil((float)listCreditID.size() / MAX_BOARD_ELEMENTS);

    Credit *loptinchi = NULL;
    PTRMH ptrMH = NULL;
    int soSV = 0;
    int firstIndex = 0;
    int currIndex = firstIndex;
    std::stack<int> stackIndex;
    Credit *tempCreditList[MAX_BOARD_ELEMENTS]; // luu giu dia chi loptinchi trong trang hien tai

    int keyPressed = 0;
    std::string keyType = "NONE";

    int stt = 0, count = 0;
    int pos = 0;
    bool reDraw = true;

    gotoxy(x, y - 1);
    std::cout << "[NEXT: RIGHT ARROW]   [PREVIOUS: LEFT ARROW]   [EXIT: ESC]";
    while (true)
    {
        if (reDraw == true)
        {
            clearScreen(x - 8, y, w + 8, MAX_BOARD_ELEMENTS + 3);
            drawCreditClassStatusBoard(x, y, MAX_BOARD_ELEMENTS);
            gotoxy(x + 40, y + MAX_BOARD_ELEMENTS + 4);
            std::printf("< Trang %2d / %d >", currPage, pageSize);

            count = 0;
            currIndex = firstIndex;
            stt = (currPage == 1) ? 0 : (currPage - 1) * 10;

            while (true)
            {
                if (currIndex > listCreditID.size() - 1)
                    break;

                count++;

                if (count > MAX_BOARD_ELEMENTS)
                    break;

                stt++;
                loptinchi = dsLTC.nodes[listCreditID[currIndex]];
                ptrMH = timMonHocTheoMa(treeMH, loptinchi->courseCode);
                soSV = countLinkedList(loptinchi->firstListRegister);
                tempCreditList[count - 1] = loptinchi;

                gotoxy(x + 2, y + 2 + count);
                std::cout << ((stt < 10) ? "0" + std::to_string(stt) : std::to_string(stt));
                gotoxy(x + 10, y + 2 + count);
                std::cout << loptinchi->creditCode;
                gotoxy(x + 18, y + 2 + count);
                std::cout << loptinchi->courseCode;
                gotoxy(x + 32, y + 2 + count);
                std::cout << ptrMH->course.courceName;
                gotoxy(x + 62, y + 2 + count);
                std::cout << loptinchi->group;
                gotoxy(x + 72, y + 2 + count);
                std::cout << soSV;
                gotoxy(x + 88, y + 2 + count);
                std::cout << loptinchi->studentMax - soSV;

                currIndex++;
            }

            reDraw = false;
        }

        gotoxy(x - 8, y + 3 + pos);
        SetColor("BLUE");
        std::cout << "Chon =>";
        SetColor("WHITE");

        keyPressed = getch();
        keyType = getKeyType(keyPressed);
        if (keyType == "RIGHT")
        {
            if (currPage < pageSize)
            {
                stackIndex.push(firstIndex);
                firstIndex = getNextIndexArray(firstIndex, listCreditID.size(), MAX_BOARD_ELEMENTS);
                currPage++;
                reDraw = true;
            }
        }
        else if (keyType == "LEFT")
        {
            if (currPage > 1)
            {
                firstIndex = stackIndex.top();
                stackIndex.pop();
                currPage--;
                reDraw = true;
            }
        }
        else if (keyType == "UP")
        {
            clearScreen(x - 8, y + 3 + pos, 7, 1);
            (pos == 0) ? pos = count - 1 : pos--;
        }
        else if (keyType == "DOWN")
        {
            clearScreen(x - 8, y + 3 + pos, 7, 1);
            (pos == count - 1) ? pos = 0 : pos++;
        }
        else if (keyType == "EXIT")
        {
            break;
        }
        else if (keyType == "ENTER")
        {
            if (XacNhan(x, y + MAX_BOARD_ELEMENTS + 6, "XAC NHAN DANG KY LOP NAY?") == "YES")
            {
                if (tempCreditList[pos]->disable == true)
                {
                    ShowMessage(x, y + MAX_BOARD_ELEMENTS + 6, "LOP TIN CHI KHONG CO SAN", FAST_TIME);
                    continue;
                }
                if (timSinhVien_DSSVDK(tempCreditList[pos]->firstListRegister, mssv) != NULL)
                {
                    ShowMessage(x, y + MAX_BOARD_ELEMENTS + 6, "BAN DA DANG KY LOP NAY", FAST_TIME);
                    continue;
                }
                Registration newRegis;
                strcpy(newRegis.studentID, mssv);
                addStudentToRegisList(tempCreditList[pos]->firstListRegister, newRegis);
            }
        }
    }
}

void nhapThongTinLopTinChi_User(int x, int y, Credit *loptinchi)
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
        input_UI(x, y, 6, thong_tin_lop_tin_chi, answer, "ACCEPT_EMPTY");

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

void capNhatLopTinChi_User(int x, int y, LIST_LTC &dsLTC, PTRMH treeMH) // cau a
{                                                                       // cau a

    int pos = 0, out = 0;

    while (true)
    {
        ShowCur(0);
        out = menu(x, y, cap_nhat_lop_tin_chi, 3, pos);
        ShowCur(1);
        if (out == 1)
        {
            break;
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
                    ShowMessage(x, y + 4, "MA MON HOC TRONG -> NGUNG DANG KY MOI", FAST_TIME);
                    delete loptinchi;
                    break;
                }
                if (timMonHocTheoMa(treeMH, loptinchi->courseCode) == NULL)
                {
                    ShowMessage(x, y + 4, "MA MON HOC KHONG TON TAI", FAST_TIME);
                    delete loptinchi;
                    continue;
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

                input_UI(x, y, 1, nhap_ma_lop_tin_chi, &str_maLTC, "ACCEPT_EMPTY");

                if (str_maLTC.length() == 0)
                {
                    ShowMessage(x, y + 4, "MA LOP TIN CHI TRONG -> THOAT", FAST_TIME);
                    break;
                }
                if (checkError(str_maLTC, "INTEGER") != "NONE")
                {
                    ShowMessage(x, y + 4, "MA LOP TIN CHI KHONG HOP LE", FAST_TIME);
                    continue;
                }

                loptinchi = dsLTC.nodes[std::stoi(str_maLTC)];
                if (loptinchi != NULL)
                {
                    while (true)
                    {
                        nhapThongTinLopTinChi_User(x, y, loptinchi);
                        if (strlen(loptinchi->courseCode) == 0)
                        {
                            ShowMessage(x, y + 4, "KHONG DE TRONG MA MON HOC", FAST_TIME);
                            continue;
                        }
                        if (timMonHocTheoMa(treeMH, loptinchi->courseCode) == NULL)
                        {
                            ShowMessage(x, y + 4, "MA MON HOC KHONG TON TAI", FAST_TIME);
                            continue;
                        }

                        break;
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
                input_UI(x, y, 1, nhap_ma_lop_tin_chi, &str_maLTC, "ACCEPT_EMPTY");

                if (str_maLTC.length() == 0)
                {
                    ShowMessage(x, y + 4, "MA LOP TIN CHI TRONG -> THOAT", NORMAL_TIME);
                    break;
                }

                if (checkError(str_maLTC, "INTEGER") != "NONE")
                {
                    ShowMessage(x, y + 4, "MA LOP TIN CHI KHONG HOP LE", FAST_TIME);
                    continue;
                }

                loptinchi = dsLTC.nodes[std::stoi(str_maLTC)];
                dsLTC.nodes[std::stoi(str_maLTC)] = NULL;
                if (loptinchi != NULL)
                {
                    if (XacNhan(x, y + 4, "BAN CO CHAC CHAN MUON XOA?") == "YES")
                    {
                        deleteLinkedList(loptinchi->firstListRegister);
                        delete loptinchi;
                        loptinchi = NULL;
                    }
                }
                else
                {
                    ShowMessage(x, y + 4, "MA LOP TIN CHI KHONG TON TAI", FAST_TIME);
                    continue;
                }
            }
        }
    }
}

void nhapThongTinSinhVien(int x, int y, Student &sinhvien)
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
    int pos = 0;
    int out = 0;
    char c_mssv[Student_ID_Length + 1] = "";

    while (true)
    {
        ShowCur(0);
        out = menu(x, y, cap_nhat_sinh_vien, 3, pos);
        ShowCur(1);

        if (out == 1)
        {
            return;
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
                    ShowMessage(x, y + 4, "MSSV TRONG -> THOAT", FAST_TIME);
                    break;
                }

                if (timSinhVien_DSSV(firstSV, sv.studentID) != NULL)
                {
                    ShowMessage(x, y + 4, "SINH VIEN DA TON TAI", FAST_TIME);
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
                // sua thong tin sinh vien
                str_mssv = ""; // reset value

                input_UI(x, y, 1, nhap_mssv, &str_mssv, "STRING");

                if (str_mssv.length() == 0)
                {
                    ShowMessage(x, y + 4, "MSSV TRONG -> THOAT", FAST_TIME);
                    break;
                }

                stringToChar(str_mssv, c_mssv, Student_ID_Length);
                pSV = timSinhVien_DSSV(firstSV, c_mssv);

                if (pSV == NULL)
                {
                    ShowMessage(x, y + 4, "SINH VIEN KHONG TON TAI", FAST_TIME);
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
                {
                    ShowMessage(x, y + 4, "MSSV TRONG -> THOAT", FAST_TIME);
                    break;
                }

                stringToChar(str_mssv, c_mssv, Student_ID_Length);
                pSV = timSinhVien_DSSV(firstSV, c_mssv);

                if (pSV == NULL)
                {
                    ShowMessage(x, y + 4, "SINH VIEN KHONG TON TAI", FAST_TIME);
                    continue;
                }

                if (XacNhan(x, y + 4, "BAN CO CHAC CHAN MUON XOA?") == "YES")
                {
                    deleteStudentFromStudentList(firstSV, pSV);
                }
            }
        }
    }
    return;
}

void nhapThongTinMonHoc_User(int x, int y, Course &monhoc)
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
            return;
        }

        if (pos == 0)
        {
            while (true)
            {
                Course monhoc;
                nhapThongTinMonHoc_User(x, y, monhoc);
                if (strlen(monhoc.courceCode) == 0)
                {
                    ShowMessage(x, y + 8, "MA MON HOC TRONG -> THOAT", FAST_TIME);
                    break;
                }

                if (timMonHocTheoMa(treeMH, monhoc.courceCode) != NULL)
                {
                    ShowMessage(x, y + 8, "MON HOC DA TON TAI", FAST_TIME);
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
                    ShowMessage(x, y + 8, "MA MON HOC TRONG -> THOAT", FAST_TIME);
                    break;
                }

                stringToChar(strMaMH, maMH, CourseCode_Length);
                pMH = timMonHocTheoMa(treeMH, maMH);

                if (pMH == NULL)
                {
                    ShowMessage(x, y + 8, "MA MON HOC KHONG TON TAI", FAST_TIME);
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
                    ShowMessage(x, y + 8, "MA MON HOC TRONG -> THOAT", FAST_TIME);
                    break;
                }

                stringToChar(strMaMH, maMH, CourseCode_Length);
                pMH = timMonHocTheoMa(treeMH, maMH);

                if (pMH == NULL)
                {
                    ShowMessage(x, y + 8, "MA MON HOC KHONG TON TAI", FAST_TIME);
                    continue;
                }

                if (XacNhan(x, y + 4, "BAN CO MUON XOA MON HOC?") == "YES")
                {
                    deleteCource(treeMH, maMH);
                }
            }
        }
    }
}

void nhapDiem(int x, int y, PTRSV firstSV, Credit *loptinchi)
{ // diem moi duoc nhap vao se tu dong duoc cap nhat ma khong can xac nhan
    /*
        x         x1             x2                     x3                x4
        +=========+==============+======================+=================+==================+
        |   STT   |     MSSV     |          HO          |       TEN       |       DIEM       |
     y1 +=========+==============+======================+=================+==================+
        |   1     |  N20DCPT001  |  Tran Thi Uyen       |      Hau        |      ____        |
        |   10    |  N20DCPT090  |  Truong Thanh Thao   |      Uyen       |      ____        |
        +=========+==============+======================+=================+==================+
                                        < Trang   1  /  2 >
    */
    PTRDK pfirst = loptinchi->firstListRegister;
    PTRDK ptrDK = NULL;
    PTRSV ptrSV = NULL;
    PTRDK listPtrDK[MAX_BOARD_ELEMENTS + 1] = {NULL};
    int stt = 0, count = 0;
    std::string temp_point[MAX_BOARD_ELEMENTS + 1] = {""};

    int currentPage = 1;
    int pageSize = ceil((float)countLinkedList(loptinchi->firstListRegister) / MAX_BOARD_ELEMENTS);

    int keyPressed = 0;
    std::string keyType = "NONE";
    std::stack<PTRDK> stackDK;

    int x4 = x + 66;
    int maxInputLength = 10;
    int pos = 0;
    bool reDraw = true;
    gotoxy(x, y - 1);
    std::cout << "[UP: ARROW UP]    [DOWN: ARROW DOWN]    [NEXT: RIGHT ARROW]   [PREVIOUS: LEFT ARROW]   [EXIT: ESC]";

    while (true)
    {

        if (reDraw == true)
        {
            ptrDK = pfirst;
            count = 0;
            stt = (currentPage == 1) ? 0 : (currentPage - 1) * 10;

            clearScreen(x, y, SCORE_BOARD_WIDTH, MAX_BOARD_ELEMENTS + 3);
            drawScoreBoard(x, y, MAX_BOARD_ELEMENTS);
            gotoxy(x + 32, y + MAX_BOARD_ELEMENTS + 4);
            std::printf("< Trang %2d / %d >", currentPage, pageSize);

            while (ptrDK != NULL)
            {
                count++;

                if (count > MAX_BOARD_ELEMENTS)
                {
                    count--;
                    break;
                }

                ptrSV = timSinhVien_DSSV(firstSV, ptrDK->regis.studentID);

                stt++;
                listPtrDK[count - 1] = ptrDK;
                temp_point[count - 1] = std::to_string(listPtrDK[count - 1]->regis.point);

                gotoxy(x + 4, y + 2 + count);
                std::cout << ((stt < 10) ? "0" + std::to_string(stt) : std::to_string(stt));
                gotoxy(x + 13, y + 2 + count);
                std::cout << ptrSV->student.studentID;
                gotoxy(x + 28, y + 2 + count);
                std::cout << ptrSV->student.lastName;
                gotoxy(x + 55, y + 2 + count);
                std::cout << ptrSV->student.firstName;
                gotoxy(x + 72, y + 2 + count);
                std::cout << temp_point[count - 1];

                ptrDK = ptrDK->next;
            }
            reDraw = false;
        }

        pos = (pos > count - 1) ? count - 1 : pos; // case new page has less than (pos + 1) elements
        gotoxy(x4 + 6 + temp_point[pos].length(), y + 3 + pos);

        keyPressed = getch();
        keyType = getKeyType(keyPressed);

        if (keyType == "UP")
        {
            (pos == 0) ? pos = count - 1 : pos--;
        }
        else if (keyType == "DOWN")
        {
            (pos == count - 1) ? pos = 0 : pos++;
        }
        else if (keyType == "ENTER")
        {
            if (IsFloatNumber(temp_point[pos]) == false)
            {
                ShowMessage(x, y + MAX_BOARD_ELEMENTS + 5, "DIEM KHONG HOP LE", 1000);
                continue;
            }
            (pos == count - 1) ? pos = 0 : pos++;
        }
        else if (keyType == "NHAP_VAN_BAN")
        {
            if (temp_point[pos].length() < maxInputLength)
            {
                gotoxy(x4 + 6 + temp_point[pos].length(), y + pos + 3);
                temp_point[pos].push_back(char(keyPressed));
                std::cout << char(keyPressed);
            }
        }
        else if (keyType == "XOA_VAN_BAN")
        {
            if (temp_point[pos].size() > 0)
            {
                gotoxy(x4 + 5 + temp_point[pos].length(), y + pos + 3);
                std::cout << " ";
                temp_point[pos].pop_back();
            }
        }

        else if (keyType == "RIGHT")
        {
            if (currentPage < pageSize)
            {
                for (int i = 0; i < count; i++)
                {
                    if (temp_point[i].length() == 0)
                    {
                        listPtrDK[i]->regis.point = 0;
                        continue;
                    }
                    if (IsFloatNumber(temp_point[i]) == false)
                    {
                        ShowMessage(x, y + MAX_BOARD_ELEMENTS + 5, "CO DIEM KHONG HOP LE", FAST_TIME);
                        // listPtrDK[i]->regis.point = 0;
                        continue;
                    }

                    listPtrDK[i]->regis.point = std::stof(temp_point[i]);
                }
                stackDK.push(pfirst);
                pfirst = getNextPointer(pfirst, MAX_BOARD_ELEMENTS);
                reDraw = true;

                currentPage++;
            }
        }
        else if (keyType == "LEFT")
        {
            if (currentPage > 1)
            {
                for (int i = 0; i < count; i++)
                {
                    if (temp_point[i].length() == 0)
                    {
                        listPtrDK[i]->regis.point = 0;
                        continue;
                    }
                    if (IsFloatNumber(temp_point[i]) == false)
                    {
                        ShowMessage(x, y + MAX_BOARD_ELEMENTS + 5, "CO DIEM KHONG HOP LE", FAST_TIME);
                        // listPtrDK[i]->regis.point = 0;
                        continue;
                    }
                    listPtrDK[i]->regis.point = std::stof(temp_point[i]);
                }

                reDraw = true;
                pfirst = stackDK.top();
                stackDK.pop();
                currentPage--;
            }
        }

        else if (keyType == "EXIT")
        {
            if (XacNhan(x, y + MAX_BOARD_ELEMENTS + 6, "XAC NHAN THOAT + LUU CHINH SUA") == "NO")
                continue;

            for (int i = 0; i < count; i++)
            {
                if (temp_point[i].length() == 0)
                {
                    listPtrDK[i]->regis.point = 0;
                    continue;
                }
                if (IsFloatNumber(temp_point[i]) == false)
                {
                    ShowMessage(x, y + MAX_BOARD_ELEMENTS + 5, "CO DIEM KHONG HOP LE", FAST_TIME);
                    // listPtrDK[i]->regis.point = 0;
                    continue;
                }

                listPtrDK[i]->regis.point = std::stof(temp_point[i]);
            }
            break;
        }
    }

    clearScreen(x, y - 1, 99, MAX_BOARD_ELEMENTS + 5);
}