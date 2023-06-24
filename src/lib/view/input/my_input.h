#pragma once
#include "struct.h"
#include "basic_function.h"
#include "UI_function.h"
#include "check_error.h"
#include "menu.h"
#include "my_delete.h"
#include "my_search.h"
#include "my_modify.h"
#include "setData.h"
#include "count_node.h"
#include "my_show.h"

const int x_box_thong_bao = 50;
const int y_box_thong_bao = 50;

const int SLEEP_TIME = 1000;

int nhapThongTinMonHoc_User(Course &monhoc, int x_origin, int y_origin);
int nhapThongTinLopTinChi_User(int x_origin, int y_origin, int amountOf_title, char title[10][100], LIST_LTC &dsLTC);
int Nhap_Diem_UI(int x_origin, int y_origin, Credit *loptinchi, PTRSV FirstSV, std::string reprot_notification, char menu_selection[10][100]);
int input_UI(int x_originMenu, int y_originMenu, int width, std::string title, int amount_of_selection, char menu_selection[10][100], std::string content[100], int ma_nhom_du_lieu, std::string reprot_notification);

void nhapBangDiem(PTRSV FirstSV, PTRMH Tree_monhoc, LIST_LTC dsLTC);             // cau i

void capNhatSinhVienLopHoc(PTRSV FirstSV, int x_origin, int y_origin);                                                                                                // cau c
void capNhatDanhSachMonHoc_User(PTRMH &Tree_monhoc, int x_origin, int y_origin);




int nhapThongTinMonHoc_User(Course &monhoc, int x_origin, int y_origin)
{
    std::string monhoc_string[5] = {{""}};

    if (input_UI(x_origin, y_origin, 40, "NHAP THONG TIN MON HOC", 4, nhap_thong_tin_mon_hoc, monhoc_string, 9, "XAC NHAN XONG") == 1)
    {
        getStandardizedName(monhoc_string[1]); // chuan hoa ten mon hoc
        ConvertStringToChar(monhoc_string[0], monhoc.courceCode);
        ConvertStringToChar(monhoc_string[1], monhoc.courceName);
        monhoc.STCLT = stringTo_Int(monhoc_string[2]);
        monhoc.STCTH = stringTo_Int(monhoc_string[3]);
        return 1; // bao hieu da nhap thong tin
    }
    else
        return 0; // bao hieu huy bo thao tac
}

int nhapThongTinLopTinChi_User(int x_origin, int y_origin, int amountOf_title, char title[10][100], LIST_LTC &dsLTC)
{

    int width_UI = 35;
    int x_box_UI = (128 - width_UI) / 2;
    int y_box_UI = y_origin + 4;

    char nienkhoa[SchoolYear_Length] = {""};
    char mamonhoc[CouseCode_Length] = {""};
    int hocky = 0, nhom = 0;
    Credit *loptinchi = NULL;

    while (true)
    {
        system("cls");

        drawBox((x_box_UI * 2 + width_UI - 27) / 2, y_origin, 29, 2);
        gotoxy((x_box_UI * 2 + width_UI - 27) / 2 + 2, y_origin + 1);
        std::cout << "NHAP THONG TIN LOP TIN CHI";

        std::string content[8] = {""};
        int check = input_UI(x_box_UI, y_box_UI, 35, {""}, 6, title, content, 1, "XAC NHAN XONG"); // nhap thong tin

        // da nhap xong thong tin
        if (check == 1)
        {

            ConvertStringToChar(content[0], mamonhoc);
            ConvertStringToChar(content[1], nienkhoa);
            hocky = stringTo_Int(content[2]);
            nhom = stringTo_Int(content[3]);

            loptinchi = timLopTinChi_theoMAMH_NIENKHOA(dsLTC, mamonhoc, nienkhoa);

            if (loptinchi == NULL)
            {
                int malopTC = ++dsLTC.currentIndex;

                dsLTC.nodes[malopTC] = new Credit; // xin cap phat bo nho

                // khoi tao gia tri mac dinh
                dsLTC.nodes[malopTC]->creditCode = malopTC;
                dsLTC.nodes[malopTC]->enable = false;
                dsLTC.nodes[malopTC]->firstListRegister = NULL;

                // sao chep thong tin vua nhap
                ConvertStringToChar(content[0], dsLTC.nodes[malopTC]->courseCode); // ma mon hoc
                ConvertStringToChar(content[1], dsLTC.nodes[malopTC]->schoolYear); // nien khoa
                dsLTC.nodes[malopTC]->semester = stringTo_Int(content[2]);         // hoc ky
                dsLTC.nodes[malopTC]->group = stringTo_Int(content[3]);
                dsLTC.nodes[malopTC]->studentMin = stringTo_Int(content[4]);
                dsLTC.nodes[malopTC]->studentMax = stringTo_Int(content[5]);
            }

            else if (loptinchi != NULL)
            {
                system("cls");
                ShowMessage(x_box_thong_bao, y_box_thong_bao, "LOP TIN CHI TRUNG LAP!", 1500);
            }

            return 1;
        }
        else if (check == 0)
            return 0;
    }
}

int Nhap_Diem_UI(int x_origin, int y_origin, Credit *loptinchi, PTRSV FirstSV, std::string report_notification, char menu_selection[10][100])
{
    int pos = 1, out = 0;
    int width = 85;
    int error_code = 0;

    PTRDK FirstDK = loptinchi->firstListRegister;
    PTRDK ptrDK = NULL;
    PTRSV ptrSV = NULL;
    int soSV = Reccount_DSDK(FirstDK);
    int amount_of_selection = soSV;
    int stt = 1;
    Student_Point student_point[1000 + 1]; // cai nay can sua lại

    int w_thong_bao = 50, h_thong_bao = 5;
    int x_thong_bao = (2 * x_origin + width - w_thong_bao) / 2;
    int y_thong_bao = y_origin + amount_of_selection + 8;

    // sao chep thong tin
    ptrDK = FirstDK;
    while (ptrDK != NULL)
    {
        student_point[stt].ptrDK = ptrDK;
        student_point[stt].point = std::to_string(ptrDK->regis.point);
        ptrDK = ptrDK->next;
        stt++;
    }

    while (true)
    {
        ptrDK = FirstDK;
        stt = 0;

        SetColor(23);
        drawScoreBoard(x_origin, y_origin, width, soSV + 3);

        SetColor(23);
        gotoxy((2 * x_origin + width - 57) / 2, y_origin + amount_of_selection + 5);
        std::printf("[SELECT:ENTER]     [EXIT:ESC]     [UP:%c/%c]     [DOWN:%c/%c]", char(30), char(17), char(31), char(16));

        while (ptrDK != NULL)
        {

            ptrSV = timSinhVien_DSSV(FirstSV, ptrDK->regis.studentID);
            stt++;

            // in thong tin
            gotoxy(x_origin + 5, y_origin + stt + 2);
            std::cout << stt;
            gotoxy(x_origin + 13, y_origin + stt + 2);
            std::cout << ptrDK->regis.studentID;
            gotoxy(x_origin + 28, y_origin + stt + 2);
            std::cout << ptrSV->student.firstName;
            gotoxy(x_origin + 55, y_origin + stt + 2);
            std::cout << ptrSV->student.name;
            gotoxy(x_origin + 72, y_origin + stt + 2);
            std::cout << student_point[stt].point;

            ptrDK = ptrDK->next;
        }

        // ve box thong bao
        drawBox(x_thong_bao, y_thong_bao, w_thong_bao, h_thong_bao);

        gotoxy(x_origin + 72 + student_point[pos].point.size(), y_origin + pos + 2);

        int key_hit = getch();
        status stt = GetKey(key_hit);
        switch (stt)
        {
        case UP:
        case LEFT:
        {
            (pos == 1) ? pos = amount_of_selection : pos--;
            break;
        };
        case DOWN:
        case RIGHT:
        {
            (pos == amount_of_selection) ? pos = 1 : pos++;
            break;
        }

        case XOA_VAN_BAN:
        {
            if (student_point[pos].point.size() > 0)
            {
                gotoxy(x_origin + 72 + student_point[pos].point.size() - 1, y_origin + pos + 2);
                std::cout << " ";
                student_point[pos].point.pop_back();
            }
            break;
        }

        case NHAP_VAN_BAN:
        {
            if (IsFloatDigit(char(key_hit)) == true)
            {
                gotoxy(x_origin + 72 + student_point[pos].point.size(), y_origin + pos + 2);
                student_point[pos].point.push_back(char(key_hit));
                std::cout << char(key_hit);
            }

            break;
        }

        case ENTER:
        {

            error_code = kiem_tra_loi(100, pos + 1, student_point[pos].point);

            if (error_code == 0)
            {
                if (pos < amount_of_selection)
                {
                    pos++;
                }
                else if (pos == amount_of_selection)
                {

                    // check loi lan cuoi
                    for (int i = 1; i <= amount_of_selection; i++)
                    {
                        error_code = kiem_tra_loi(100, i, student_point[pos].point);
                        // tim thay loi thi khong can kiem tra nua
                        if (error_code != 0)
                            break;
                    }
                    //   error_code = 0;

                    if (error_code == 0)
                    {
                        //    clearScreen(x_thong_bao, y_thong_bao, w_thong_bao, h_thong_bao);

                        int luachon = XacNhan(((2 * x_origin + width - 17) / 2), y_thong_bao + h_thong_bao + 2, report_notification, "CO", "KHONG");
                        if (luachon == 1)
                        {
                            for (int i = 1; i <= soSV; i++)
                            {
                                ptrDK = student_point[i].ptrDK;

                                if (ptrDK != NULL)
                                    ptrDK->regis.point = stof(student_point[i].point);
                            }
                            return 1;
                        }
                    }

                    else
                    {
                        gotoxy(x_thong_bao + 2, y_thong_bao + 1);
                        Show_Error(error_code);
                        Sleep(SLEEP_TIME);
                        clearScreen(x_thong_bao + 1, y_thong_bao + 1, w_thong_bao - 2, h_thong_bao - 2);
                    }
                }
            }

            else
            {
                gotoxy(x_thong_bao + 2, y_thong_bao + 1);
                Show_Error(error_code);
                Sleep(SLEEP_TIME);
                clearScreen(x_thong_bao + 1, y_thong_bao + 1, w_thong_bao - 2, h_thong_bao - 2);
            }

            break;
        }

        case EXIT:
        {
            clearScreen(x_thong_bao, y_thong_bao, w_thong_bao, h_thong_bao);

            int luachon = XacNhan((2 * x_origin + width - 17) / 2, y_thong_bao, "XAC NHAN THOAT", "CO", "KHONG");
            if (luachon == 1)
                return 0;

            break;
        }
        }
    } // end while
}

int input_UI(int x_originMenu, int y_originMenu, int width, std::string title, int amount_of_selection, char menu_selection[10][100], std::string content[100], int ma_nhom_du_lieu, std::string report_notification)
{
    int error_code = 0;
    int pos = 0;
    int out = 0;
    int x_box = 0, y_box = 0;
    int length_of_title = title.length();

    if (length_of_title == 0)
    {
        x_box = x_originMenu;
        y_box = y_originMenu;
    }
    else
    {
        x_box = x_originMenu;
        y_box = y_originMenu + 2;
    }

    int w_thong_bao = 50, h_thong_bao = 5;
    int x_thong_bao = (2 * x_box + width - w_thong_bao) / 2;
    int y_thong_bao = y_box + amount_of_selection + 5;

    int x_huong_dan = (2 * x_box + width - 57) / 2;
    int y_huong_dan = y_box + amount_of_selection + 3;

    int x_title = (x_box + x_box + width - length_of_title) / 2;
    gotoxy(x_title, y_originMenu);
    std::cout << title;

    while (true)
    {

        SetColor(23);
        drawBox(x_box, y_box, width, amount_of_selection + 1);

        for (int i = 0; i < amount_of_selection; i++)
        {
            gotoxy(x_box + 1, y_box + i + 1);
            std::printf("%s", menu_selection[i]);

            gotoxy(x_box + strlen(menu_selection[i]) + 1, y_box + i + 1);
            std::cout << content[i];
        }

        SetColor(23);
        gotoxy(x_huong_dan, y_huong_dan);
        std::printf("[SELECT:ENTER]     [EXIT:ESC]     [UP:%c/%c]     [DOWN:%c/%c]", char(30), char(17), char(31), char(16));

        // ve box thong bao
        drawBox(x_thong_bao, y_thong_bao, w_thong_bao, h_thong_bao);

        gotoxy(x_box + strlen(menu_selection[pos]) + 1 + content[pos].size(), y_box + pos + 1);

        int key_hit = getch();
        status stt = GetKey(key_hit);
        switch (stt)
        {
        case UP:
        case LEFT:
        {
            (pos == 0) ? pos = amount_of_selection - 1 : pos--;
            break;
        }
        case DOWN:
        case RIGHT:
        {
            (pos == amount_of_selection - 1) ? pos = 0 : pos++;
            break;
        }
        case XOA_VAN_BAN:
        {
            if (content[pos].size() > 0)
            {
                gotoxy(x_box + strlen(menu_selection[pos]) + 1 + content[pos].size() - 1, y_box + pos + 1);
                std::cout << " ";
                content[pos].pop_back();
            }
            break;
        }

        case NHAP_VAN_BAN:
        {

            gotoxy(x_box + strlen(menu_selection[pos]) + 1 + content[pos].size(), y_box + pos + 1);
            content[pos].push_back(char(key_hit));
            std::cout << char(key_hit);

            break;
        }

        case ENTER:
        {

            error_code = kiem_tra_loi(ma_nhom_du_lieu, pos + 1, content[pos]); // KIEM TRA LOI

            if ((ma_nhom_du_lieu == 1 || ma_nhom_du_lieu == 2) && pos + 1 == 6)
                if (stringTo_Int(content[pos]) < stringTo_Int(content[pos - 1]))
                    error_code = 19;

            if (ma_nhom_du_lieu == 14 && pos + 1 == 1 && content[pos].length() == 0)
            { // TH NHAP MA SINH VIEN RONG
                int luachon = XacNhan(((2 * x_box + width - 17) / 2), y_thong_bao + h_thong_bao + 2, "XAC NHAN KET THUC NHAP", "CO", "KHONG");
                if (luachon == 1)
                    return 0;
                else
                    break;
            }

            if (error_code == 0)
            {

                if (pos < amount_of_selection - 1)
                    pos++;

                else if (pos == amount_of_selection - 1)
                {

                    // check loi lan cuoi
                    for (int i = 0; i < amount_of_selection - 1; i++)
                    {
                        error_code = kiem_tra_loi(ma_nhom_du_lieu, i + 1, content[i]);
                        if (error_code != 0) // tim thay loi thi khong can kiem tra nua
                            break;
                    }

                    if (error_code == 0)
                    {
                        int luachon = XacNhan(((2 * x_box + width - 17) / 2), y_thong_bao + h_thong_bao + 2, report_notification, "CO", "KHONG");
                        if (luachon == 1)
                            return 1;
                    }

                    else
                    {
                        gotoxy(x_thong_bao + 2, y_thong_bao + 1);
                        Show_Error(error_code);
                        Sleep(SLEEP_TIME);
                        clearScreen(x_thong_bao + 1, y_thong_bao + 1, w_thong_bao - 2, h_thong_bao - 2);
                    }
                }
            }
            else
            {
                gotoxy(x_thong_bao + 2, y_thong_bao + 1);
                Show_Error(error_code);
                Sleep(SLEEP_TIME);
                clearScreen(x_thong_bao + 1, y_thong_bao + 1, w_thong_bao - 2, h_thong_bao - 2);
            }

            break;
        }

        case EXIT:
        {
            int luachon = XacNhan((2 * x_box + width - 17) / 2, y_thong_bao + h_thong_bao + 2, "XAC NHAN THOAT", "CO", "KHONG");
            if (luachon == 1)
                return 0;

            break;
        }
        }
    } // end while
}


void nhapBangDiem(PTRSV FirstSV, PTRMH Tree_monhoc, LIST_LTC dsLTC)
{ // case 9: cau i
    char nienkhoa[maxLengthString] = "2020";
    char maMH[maxLengthString] = "MH2";
    int hocky = 3, nhom = 2;
    Credit *loptinchi = NULL;

    while (true)
    {
        system("cls");
        std::string content[5] = {""};

        if (input_UI(44, 4, 40, "NHAP THONG TIN LOP TIN CHI CAN XET", 4, cau_2, content, 8, "XAC NHAN XONG") == 1)
        {
            system("cls");

            ConvertStringToChar(content[0], nienkhoa);
            hocky = stringTo_Int(content[1]);
            nhom = stringTo_Int(content[2]);
            ConvertStringToChar(content[3], maMH);

            loptinchi = timLopTinChi_theoInfo(dsLTC, nienkhoa, hocky, nhom, maMH);

            if (loptinchi != NULL)
            {
                if (loptinchi->enable == false)
                {
                    if (Nhap_Diem_UI(22, 4, loptinchi, FirstSV, "XAC NHAN XONG", nhap_thong_tin_mon_hoc) == 1)
                        continue;
                    else
                        return;
                }
                else
                {
                    system("cls");
                    ShowMessage(x_box_thong_bao, y_box_thong_bao, "LOP TIN CHI DA BI HUY!", 1500);
                }
            }

            // Khi khong tim thay LTC
            else
            {
                system("cls");
                ShowMessage(x_box_thong_bao, y_box_thong_bao, "KHONG TIM THAY LOP TIN CHI YEU CAU", 1500);
            }
        }
        else
            break;
    }

    return;
}


void capNhatSinhVienLopHoc(PTRSV FirstSV, int x_origin, int y_origin)
{ // case 3:  cau c
    int maLop = 1;
    char mssv[Student_ID_Length] = "N20DCPT044";
    char maLopHoc[ClassID_Length] = {""};
    int luachon = 0;
    int out = 0, pos = 0;

    while (true)
    {
        system("cls");
        std::string content[2] = {""};
        pos = 0;

        if (input_UI(41, y_origin, 45, "NHAP MA LOP", 1, nhap_ma_lop_hoc, content, 4, "XAC NHAN XONG") == 1)
        {

            system("cls");

            ConvertStringToChar(content[0], maLopHoc);

            ShowCur(0);
            luachon = Menu(46, 8, 32, 3, cap_nhat_sinh_vien, out, pos);
            ShowCur(1);

            switch (luachon)
            {
            case 1:
            {
                Student sinhvien;

                while (true)
                {
                    system("cls");
                    std::string content[6] = {""};
                    if (input_UI(44, 5, 40, "NHAP THONG TIN SINH VIEN", 5, thong_tin_sinh_vien_lop_hoc, content, 14, "XAC NHAN XONG") == 1)
                    {

                        if (content[0].length() == 0)
                            break; // ket thuc nhap sinh vien

                        ConvertStringToChar(content[0], sinhvien.studentID);
                        ConvertStringToChar(content[1], sinhvien.firstName);
                        ConvertStringToChar(content[2], sinhvien.name);
                        ConvertStringToChar(content[3], sinhvien.sex);
                        ConvertStringToChar(content[4], sinhvien.phoneNum);
                        strcpy(sinhvien.classID, maLopHoc);

                        addStudentToList(FirstSV, sinhvien);
                    }
                    else
                        break;
                }

                break;
            }
            case 2:
            {

                while (true)
                {
                    system("cls");
                    drawBox(48, 2, 34, 2);
                    gotoxy(50, 3);
                    std::cout << "SUA THONG TIN SINH VIEN LOP HOC";

                    std::string content[2] = {""};

                    if (input_UI(47, 6, 35, {""}, 1, nhap_mssv, content, 5, "XAC NHAN XONG") == 1)
                    {
                        ConvertStringToChar(content[0], mssv);

                        PTRSV ptr_sinhvien = timSinhVien_DSSV(FirstSV, mssv); // giu dia chi cua sinh vien can tim
                        if (ptr_sinhvien != NULL)
                            suaThongTinSinhVien(ptr_sinhvien->student);
                    }
                    else
                        break;
                }

                break;
            }
            case 3:
            {
                system("cls");

                drawBox(48, 2, 34, 2);
                gotoxy(50, 3);
                std::cout << "XOA SINH VIEN KHOI LOP HOC";

                std::string content[2] = {""};
                if (input_UI(47, 6, 35, {""}, 1, nhap_mssv, content, 5, "XAC NHAN XONG") == 1)
                {
                    ConvertStringToChar(content[0], mssv);

                    PTRSV ptr_sinhvien = timSinhVien_DSSV(FirstSV, mssv); // giu dia chi cua sinh vien can tim
                    if (ptr_sinhvien != NULL)
                    {
                        xoaSinhVien_DSSV(FirstSV, ptr_sinhvien);
                    }
                }

                break;
            }
            case 0:
            {
                break;
            }
            }
        }

        else
            return;
    }
}

void capNhatDanhSachMonHoc_User(PTRMH &Tree_monhoc, int x_origin, int y_origin)
{ // case 5: cau e

    int out = 0, pos = 0;
    int luachon = 0;

    int x_menu = 99;
    int y_menu = y_origin + 6;
    int w_menu = 20;
    int h_menu = 3;

    while (true)
    {
        system("cls");

        gotoxy((2 * x_origin + 80 - 17) / 2, y_origin + 2);
        std::cout << "CAP NHAT MON HOC";
        xuatDanhSachMonHoc_Console(1, y_origin + 2, Tree_monhoc);

        ShowCur(0);
        luachon = Menu(x_menu, y_menu, w_menu, h_menu, cap_nhat_mon_hoc, out, pos);
        ShowCur(1);

        char maMH[maxLengthString] = {""};

        switch (luachon)
        {
        case 1:
        {
            system("cls");
            gotoxy(57, y_origin + 2);
            std::cout << "THEM MON HOC";

            Course monhoc;
            if (nhapThongTinMonHoc_User(monhoc, 44, y_origin + 4) == 1)
            {
                addCourseToList(Tree_monhoc, monhoc);
                ShowMessage(x_box_thong_bao, y_origin + 18, "DA THEM MON HOC THANH CONG", 1500);
            }
            break;
        }

        case 2:
        {
            while (true)
            {
                system("cls");
                gotoxy(52, y_origin);
                std::cout << "SUA THONG TIN MON HOC";

                std::string mamonhoc_string[1] = {""};

                if (input_UI(48, y_origin + 2, 30, "NHAP MA MON HOC", 1, nhap_ma_mon_hoc, mamonhoc_string, 6, "XAC NHAN XONG") == 1)
                {

                    ConvertStringToChar(mamonhoc_string[0], maMH);

                    PTRMH ptr_monhoc = NULL;
                    ptr_monhoc = timMonHocTheoMa(Tree_monhoc, maMH);

                    if (ptr_monhoc != NULL)
                    {
                        system("cls");
                        suaThongTinMonHoc_User(ptr_monhoc->course, 44, y_origin + 4);
                    }
                    break;
                }

                else
                    break;
            }

            break;
        }

        case 3:
        {

            system("cls");
            gotoxy(57, y_origin);
            std::cout << "XOA MON HOC";

            std::string mamonhoc_string[1] = {""};

            if (input_UI(48, y_origin + 2, 30, "NHAP MA MON HOC", 1, nhap_ma_mon_hoc, mamonhoc_string, 6, "XAC NHAN XONG") == 1)
            {
                ConvertStringToChar(mamonhoc_string[0], maMH);

                if (timMonHocTheoMa(Tree_monhoc, maMH) != NULL)
                {
                    system("cls");
                    xoaMonHoc(Tree_monhoc, maMH);
                    ShowMessage(56, y_origin + 5, "DA XOA MON HOC", 1500);
                }
                break;
            }

            else
                break;
        }

        case 0:
            return;
        }
    }
}
                                                                          // cau e

