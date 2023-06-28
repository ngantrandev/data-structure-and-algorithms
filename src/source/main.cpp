#include <iostream>
#include "menu.h"
//xuatDanhSachSinhVienDK_LTC
bool LOAD_FILE_ERROR = false; // looix load file
const int SLEEP_TIME = 400;

const int x_box_thong_bao = 50;
const int y_box_thong_bao = 5;

const int width_console_buffer_size = 800;
const int height_console_buffer_size = 500;
const int width_console_size = 128;
const int height_console_size = 30;

LIST_LTC dsLTC;
PTRMH treeMH = NULL;
PTRSV FirstSV = NULL;
PTRLH FirstLH = NULL;
int so_lop_hien_tai_LTC = 0;
int so_mon_hoc_DSMH = 0;
int so_sinh_vien_DSSV = 0;

//====================
//=KHAI BAO PROTOTYPE=
//====================

//==========================
// VIET HAM CHUC NANG CHINH =
//==========================

void moLopTC(LIST_LTC &dsLTC, int x_origin, int y_origin, int &out);                                                                                                  // cau a
int dangKyLopTinChi_bang_MSSV(int x_origin, int y_origin, LIST_LTC &dsLTC, PTRMH Tree_monhoc, char maSV[maxLengthString], char nienkhoa[maxLengthString], int hocky); // ham hoox trowj cau g
void dangKyLopTinChi(LIST_LTC &dsLTC, PTRMH Tree_monhoc, PTRSV FirstSV);

void tuDongHuyLop(LIST_LTC dsLTC); // cau h

void nhapBangDiemLopTinChi(PTRSV FirstSV, PTRMH Tree_monhoc, Credit *loptinchi); // cau i

// cau L
void layDanhSachMaMonHoc(PTRMH Tree_monhoc, std::string maMH[1000], int &index);
void layDanhSachSinhVienCungLop(PTRSV FirstSV, PTRSV dssv[1000], char maLop[ClassID_Length], int &soSV);

//********************************************************
//=========PHAN HAM CHUC NANG CHINH===========================

void moLopTC(LIST_LTC &dsLTC, int x_origin, int y_origin, int &out)
{ // case 1: cau a
    int luachon = 0;
    int pos = 0;
    int width_box_selection = 33;

    while (true)
    {
        system("cls");
        drawBox((2 * x_origin + width_box_selection - 14) / 2, y_origin, 14, 2);
        gotoxy((2 * x_origin + width_box_selection - 14) / 2 + 2, y_origin + 1);
        std::printf("LOP TIN CHI");

        ShowCur(0);
        luachon = Menu(x_origin, y_origin, width_box_selection, 3, cau_a, out, pos);
        ShowCur(1);
        switch (luachon)
        {
        case 1:
        {

            nhapThongTinLopTinChi_User(x_origin, y_origin, 8, them_lop_tin_chi, dsLTC);

            break;
        }

        case 2:
        {
            system("cls");
            int malop = 0;

            drawBox((2 * x_origin + 35 - 25) / 2, y_origin, 28, 2);
            gotoxy((2 * x_origin + 35 - 25) / 2 + 2, y_origin + 1);
            std::printf("SUA THONG TIN LOP TIN CHI");

            std::string ma_lop_string[3] = {""}; // mang string chua ma lop - voi ma_lop_string[0] chua ma lop
            if (input_UI(44, y_origin + 4, 40, {""}, 1, nhap_ma_lop, ma_lop_string, 3, "XAC NHAN XONG") == 1)
            { // UI nhap ma lop tin chi
                malop = stringTo_Int(ma_lop_string[0]);

                if (malop > dsLTC.currentIndex || lopTinChiTonTai(dsLTC.nodes[malop]) == 0)
                    break;

                else
                    suaThongTinLopTinChi(x_origin, y_origin, sua_lop_tin_chi, dsLTC.nodes[malop]);
            }

            break;
        }
        case 3:
        {
            system("cls");
            int malop = 0;
            drawBox((2 * x_origin + 35 - 16) / 2, y_origin, 18, 2);
            gotoxy((2 * x_origin + 35 - 16) / 2 + 2, y_origin + 1);
            std::printf("XOA LOP TIN CHI");

            std::string ma_lop_string[3] = {""};
            if (input_UI(44, y_origin + 4, 40, {""}, 1, nhap_ma_lop, ma_lop_string, 3, "XAC NHAN XONG") == 1)
            { // UI nhap ma lop tin chi

                malop = stringTo_Int(ma_lop_string[0]);

                if (malop > dsLTC.currentIndex || lopTinChiTonTai(dsLTC.nodes[malop]) == false)
                    break;

                else
                {

                    system("cls");
                    drawBox(52, y_origin, 24, 2);
                    gotoxy(54, y_origin + 1);
                    std::cout << "THONG TIN LOP TIN CHI";

                    showCreditClassList(19, 5, 90, 4);
                    xuatThongTinLopTinChi_Console(19, 2, dsLTC.nodes[malop], 1);

                    luachon = XacNhan(55, 15, "XAC NHAN XOA", "CO", "KHONG");
                    if (luachon == 1)
                    {
                        xoaDanhSachDangKy(dsLTC.nodes[malop]->firstListRegister);
                        dsLTC.nodes[malop]->firstListRegister = NULL;
                        delete (dsLTC.nodes[malop]);
                        dsLTC.nodes[malop] = NULL;

                        so_lop_hien_tai_LTC--; // botws ddi 1 LTC

                        ShowMessage((2 * x_origin + 35 - 18) / 2, 12, "DA XOA THANH CONG", 1500);
                        break;
                    }
                }
            }

            break;
        }

        case 0:
        {
            return;
        }
        }
    }
}

int dangKyLopTinChi_bang_MSSV(int x_origin, int y_origin, LIST_LTC &dsLTC, PTRMH Tree_monhoc, char maSV[maxLengthString], char nienkhoa[maxLengthString], int hocky)
{ // case 7: cau g

    system("cls");
    int count_LTC = 0; // dem so lop sinh vien da dang ky;
    PTRMH ptr_monhoc = NULL;
    int luachon = 0;
    int out = 0, pos = 0, slotDK = 0, stt = 0;

    while (true)
    {
        system("cls");
        stt = 0;
        count_LTC = 0;

        // in thong tin cac lop tin chi: ten mon hoc, so nhom, so sv da dang ky...
        for (int i = 1; i <= dsLTC.currentIndex; i++)
        {
            if (lopTinChiTonTai(dsLTC.nodes[i]) && dsLTC.nodes[i]->enable == false)
            {
                if (strcmp(dsLTC.nodes[i]->schoolYear, nienkhoa) == 0 && dsLTC.nodes[i]->semester == hocky)
                {
                    count_LTC++;
                    stt++;
                    ptr_monhoc = timMonHocTheoMa(Tree_monhoc, dsLTC.nodes[i]->courseCode);
                    slotDK = Reccount_DaDangKy(dsLTC.nodes[i]->firstListRegister);

                    gotoxy(x_origin + 3, y_origin + stt + 2);
                    std::cout << stt;
                    gotoxy(x_origin + 10, y_origin + stt + 2);
                    std::cout << dsLTC.nodes[i]->creditCode;
                    gotoxy(x_origin + 20, y_origin + stt + 2);
                    std::cout << dsLTC.nodes[i]->courseCode;
                    gotoxy(x_origin + 33, y_origin + stt + 2);
                    std::cout << ptr_monhoc->course.courceName;
                    gotoxy(x_origin + 62, y_origin + stt + 2);
                    std::cout << dsLTC.nodes[i]->group;
                    gotoxy(x_origin + 74, y_origin + stt + 2);
                    std::cout << slotDK;
                    gotoxy(x_origin + 89, y_origin + stt + 2);
                    std::cout << dsLTC.nodes[i]->studentMax - slotDK;
                }
            }
        }

        if (count_LTC == 0)
        {
            system("cls");
            ShowMessage(x_box_thong_bao, y_box_thong_bao, "KHONG CO LOP TIN CHI NAO THOA MAN", 1500);
            return 0;
        }

        gotoxy(53, y_origin - 2);
        std::printf("THONG TIN LOP TIN CHI");
        showCreditClassStatus(x_origin, y_origin, 98, count_LTC + 3);

        gotoxy(55, y_origin + count_LTC + 5);
        std::printf("DANG KY LOP TIN CHI");

        ShowCur(0);
        luachon = Menu(54, y_origin + count_LTC + 7, 21, 2, dang_ky_lop_TC, out, pos);
        ShowCur(1);

        clearScreen(1, y_origin + count_LTC + 14, 100, 5);

        int maLopTC = 0;
        switch (luachon)
        {

        case 1:
        {
            std::string content[2] = {""};
            if (input_UI(46, y_origin + count_LTC + 12, 40, {""}, 1, nhap_ma_lop, content, 3, "XAC NHAN XONG") == 1)
            {
                maLopTC = stringTo_Int(content[0]);

                if (dsLTC.nodes[maLopTC]->semester != hocky || strcmp(dsLTC.nodes[maLopTC]->schoolYear, nienkhoa) != 0)
                {
                    system("cls");
                    ShowMessage(x_box_thong_bao, y_box_thong_bao, "LOP TIN CHI KHONG THOA MAN DIEU KIEN!", 1000);
                    continue;
                }

                else if (dsLTC.nodes[maLopTC]->enable == true)
                {
                    system("cls");
                    ShowMessage(x_box_thong_bao, y_box_thong_bao, "LOP TIN CHI DA BI HUY!", 1000);
                    continue;
                }

                PTRDK ptrSVDK = timSinhVien_DSSVDK(dsLTC.nodes[maLopTC]->firstListRegister, maSV);

                if (ptrSVDK == NULL)
                {
                    Registration dangky;
                    dangky.point = 0;
                    dangky.isRegistered = false;
                    strcpy(dangky.studentID, maSV);
                    themSinhVienVaoDanhSachDK(dsLTC.nodes[maLopTC]->firstListRegister, dangky);

                    system("cls");
                    ShowMessage(x_box_thong_bao, y_box_thong_bao, "DA DANG KY THANH CONG!", 1000);
                }

                else
                {
                    if (ptrSVDK->regis.isRegistered == false)
                    {
                        system("cls");
                        ShowMessage(x_box_thong_bao, y_box_thong_bao, "SINH VIEN DA DANG KY", 1000);
                    }

                    else if (ptrSVDK->regis.isRegistered == true)
                    {
                        ptrSVDK->regis.isRegistered = false;
                        system("cls");
                        ShowMessage(x_box_thong_bao, y_box_thong_bao, "DA DANG KY THANH CONG!", 1000);
                    }
                }
            }

            break;
        }
        case 2:
        {
            std::string content[2] = {""};
            if (input_UI(46, y_origin + count_LTC + 12, 40, {""}, 1, nhap_ma_lop, content, 3, "XAC NHAN XONG") == 1)
            {
                maLopTC = stringTo_Int(content[0]);

                if (dsLTC.nodes[maLopTC]->semester != hocky || strcmp(dsLTC.nodes[maLopTC]->schoolYear, nienkhoa) != 0)
                {
                    system("cls");
                    ShowMessage(x_box_thong_bao, y_box_thong_bao, "LOP TIN CHI KHONG THOA MAN DIEU KIEN!", 1000);
                    continue;
                }
                else if (dsLTC.nodes[maLopTC]->enable == true)
                {
                    system("cls");
                    ShowMessage(x_box_thong_bao, y_box_thong_bao, "LOP TIN CHI DA BI HUY!", 1000);
                    continue;
                }

                PTRDK ptrSVDK = timSinhVien_DSSVDK(dsLTC.nodes[maLopTC]->firstListRegister, maSV);

                if (ptrSVDK == NULL)
                {
                    system("cls");
                    ShowMessage(x_box_thong_bao, y_box_thong_bao, "SINH VIEN CHUA DANG KY LOP NAY", 1000);
                }

                else
                {
                    if (ptrSVDK->regis.isRegistered == false)
                    {
                        ptrSVDK->regis.isRegistered = true;
                        system("cls");
                        ShowMessage(x_box_thong_bao, y_box_thong_bao, "DA HUY DANG KY THANH CONG!", 1000);
                    }
                    else if (ptrSVDK->regis.isRegistered == true)
                    {
                        system("cls");
                        ShowMessage(x_box_thong_bao, y_box_thong_bao, "SINH VIEN DA HUY DANG KY!", 1000);
                    }
                }
            }

            break;
        }

        case 0:
            return 0;
        }
    }
}

void dangKyLopTinChi(LIST_LTC &dsLTC, PTRMH Tree_monhoc, PTRSV FirstSV)
{
    int stt = 1;
    char maSV[maxLengthString] = "N20DCPT044";
    char nienkhoa[maxLengthString] = {""};
    int hocky = 0;

    while (true)
    {
        system("cls");
        drawBox(53, 1, 22, 2);
        gotoxy(55, 2);
        std::printf("DANG KY LOP TIN CHI");

        std::string mssv_string[2] = {""}; // mang string chua mssv -
        if (input_UI(47, 5, 35, "NHAP MA SINH VIEN", 1, nhap_mssv, mssv_string, 5, "XAC NHAN XONG") == 1)
        { // UI nhap mssv

            clearScreen(35, 5, 80, 30);
            ConvertStringToChar(mssv_string[0], maSV);

            PTRSV ptr_SV = timSinhVien_DSSV(FirstSV, maSV);

            if (ptr_SV != NULL)
            {
                xuatThongTinSinhVien_MSSV_Console(ptr_SV, stt, 14, 5);

                std::string content[3] = {""};

                if (input_UI(54, 13, 22, {""}, 2, question_g, content, 7, "XAC NHAN XONG") == 1)
                {

                    ConvertStringToChar(content[0], nienkhoa);
                    hocky = stringTo_Int(content[1]);

                    dangKyLopTinChi_bang_MSSV(15, 3, dsLTC, Tree_monhoc, maSV, nienkhoa, hocky);
                }
            }
        }

        else
            break;
    }
}

void tuDongHuyLop(LIST_LTC dsLTC)
{ // case 8: cau h
    system("cls");

    drawBox(56, 3, 16, 2);
    gotoxy(57, 4);
    std::cout << "TU DONG HUY LOP";

    int soLuongDK = 0;
    int luachon = XacNhan(56, 8, "XAC NHAN HUY LOP KHONG DU DIEU KIEN", "CO", "KHONG");

    if (luachon == 1)
    {
        for (int i = 1; i <= dsLTC.currentIndex; i++)
        {
            if (lopTinChiTonTai(dsLTC.nodes[i]) == true)
            {
                soLuongDK = Reccount_DSDK(dsLTC.nodes[i]->firstListRegister);

                if (soLuongDK < dsLTC.nodes[i]->studentMin)
                    dsLTC.nodes[i]->enable = true;
            }
        }
        system("cls");
        ShowMessage(61, 8, "DA XONG", 1500);
    }
}

// case 11: cau k

// case 12: cau L

void layDanhSachMaMonHoc(PTRMH Tree_monhoc, std::string maMH[1000], int &index)
{
    if (Tree_monhoc != NULL)
    {
        layDanhSachMaMonHoc(Tree_monhoc->pLeft, maMH, index);
        ConvertCharToString(Tree_monhoc->course.courceCode, maMH[++index]);
        layDanhSachMaMonHoc(Tree_monhoc->pRight, maMH, index);
    }
}

void layDanhSachSinhVienCungLop(PTRSV FirstSV, PTRSV dssv[1000], char maLop[ClassID_Length], int &soSV)
{
    while (FirstSV != NULL)
    { // nap danh sach sinh vien
        if (strcmp(FirstSV->student.classID, maLop) == 0)
            dssv[++soSV] = FirstSV;

        FirstSV = FirstSV->next;
    }
}

// =========HET=====

//=========================================
// HAM KHOI TAO BO NHO VA LUU FILE, XUAT FILE RA CONSOLE

void initMemory(LIST_LTC &dsLTC, PTRMH &treeMH, PTRSV &FirstSV, PTRLH &FirstLH)
{
    char danhsachmonhoc_txt[] = "file_text\\txt_file\\danh_sach_mon_hoc.txt";
    char danhsachLTC_txt[] = "file_text\\txt_file\\danh_sach_lop_tin_chi.txt";
    char danhsachSV_txt[] = "file_text\\txt_file\\danh_sach_sinh_vien.txt";
    char danhsachmaLopHoc_txt[] = "file_text\\txt_file\\danh_sach_ma_lop_hoc.txt";

    for (int i = 1; i <= dsLTC.currentIndex; i++) // dinh dang danh sach lop hoc tin chi
        dsLTC.nodes[i] = NULL;

    loadListCourse_File(treeMH, danhsachmonhoc_txt);
    nhapDanhSachLopTinChi_File(dsLTC, danhsachLTC_txt);
    nhapDanhSachSinhVien_File(FirstSV, danhsachSV_txt);
    nhapDanhSachmaLopHoc_File(FirstLH, danhsachmaLopHoc_txt);
}
void saveFile(LIST_LTC dsLTC, PTRMH treeMH, PTRSV FirstSV)
{
    char danhsachmonhoc_txt[] = "file_text\\txt_file\\danh_sach_mon_hoc.txt";
    char danhsachLTC_txt[] = "file_text\\txt_file\\danh_sach_lop_tin_chi.txt";
    char danhsachSV_txt[] = "file_text\\txt_file\\danh_sach_sinh_vien.txt";
    char danhsachmaLopHoc_txt[] = "file_text\\txt_file\\danh_sach_ma_lop_hoc.txt";

    char danhsachSV_csv[] = "file_text\\csv_file\\danh_sach_sinh_vien.csv";
    char danhsachmonhoc_csv[] = "file_text\\csv_file\\danh_sach_mon_hoc.csv";

    xuatDanhSachMonHoc_File_Txt(treeMH, danhsachmonhoc_txt);
    xuatDanhSachLopTinChi_File_Txt(dsLTC, danhsachLTC_txt);
    xuatDanhSachSinhVien_File_Txt(FirstSV, danhsachSV_txt);

    xuatDanhSachSinhVien_File_Csv(FirstSV, danhsachSV_csv);
    xuatDanhSachMonHoc_File_Csv(treeMH, danhsachmonhoc_csv);
}
void showFile(int x_origin, int y_origin, LIST_LTC dsLTC, PTRMH treeMH, PTRSV FirstSV)
{
    int out = 0, pos = 0;
    int luachon = 0;

    int width = 35;
    int selection = 3;

    while (true)
    {
        system("cls");

        ShowCur(0);
        luachon = Menu(x_origin, y_origin, width, selection, show_file, out, pos);
        ShowCur(1);

        system("cls");

        if (luachon == 1)
        {
            int x = 18, y = 4;
            xuatDanhSachLopTinChi_Console(x, y, dsLTC);
            system("pause");
        }
        else if (luachon == 2)
        {
            int x = 13;
            xuatDanhSachSinhVien_Console(FirstSV, x, y_origin);
            system("pause");
        }
        else if (luachon == 3)
        {
            int x = 24;
            xuatDanhSachMonHoc_Console(x, y_origin, treeMH);
            system("pause");
        }
        else if (luachon == 0)
            return;
    }
}

//===================================================
//===================================================
// MENU LAM VIEC CHINH
void Menu_Chinh(LIST_LTC &dsLTC, PTRSV &FirstSV, PTRMH &Tree_monhoc, int x_origin, int y_origin, int &out, int &pos)
{
    char nienkhoa[maxLengthString];
    int hocky = 0, nhom = 0;
    int luachon = 7;

    while (true)
    {
        system("cls");
        ShowCur(0);
        luachon = Menu(45, 4, 45, 14, menu_chinh, out, pos);
        ShowCur(1);
        switch (luachon)
        {
        case 1:
        { // cau a
            system("cls");
            moLopTC(dsLTC, 47, 5, out);
            break;
        }
        case 2:
        { // cau b
            while (true)
            {
                system("cls");
                char nienkhoa[maxLengthString];
                char maMonHoc[maxLengthString];
                int hocky = 0, nhom = 0;

                std::string content[6] = {""};
                if (input_UI(44, 4, 40, "NHAP THONG TIN LOP TIN CHI CAN XET", 4, cau_2, content, 8, "XAC NHAN XONG") == 1)
                {
                    ConvertStringToChar(content[0], nienkhoa);
                    hocky = stringTo_Int(content[1]);
                    nhom = stringTo_Int(content[2]);
                    ConvertStringToChar(content[3], maMonHoc);

                    if (xuatDanhSachSinhVienDK_LTC(13, y_origin, dsLTC, FirstSV, nienkhoa, hocky, nhom, maMonHoc) == 0)
                    {
                        system("cls");
                        ShowMessage(x_box_thong_bao, y_box_thong_bao, "KHONG TIM THAY LOP TIN CHI YEU CAU", 1000);
                    }
                }

                else
                    break;
            }
            break;
        }
        case 3:
        { // cau c
            // CAN XET THEM
            system("cls");
            capNhatSinhVienLopHoc(FirstSV, 10, 4);
            break;
        }

        case 4:
        { // cau d
            system("cls");
            xuatDanhSachSinhVienLopHoc_Console_TheoTen(dsLTC, FirstSV, 45, 3);
            break;
        }

        case 5:
        { // cau e
            system("cls");
            capNhatDanhSachMonHoc_User(Tree_monhoc, 40, 0);
            break;
        }

        case 6:
        { // cau f
            system("cls");
            drawBox(46, 2, 36, 2);
            gotoxy(47, 3);
            std::cout << "XUAT DANH SACH MON HOC - THEO TEN";
            xuatDanhSachMonHocTheoTen(24, 6, Tree_monhoc);
            system("pause");
            break;
        }

        case 7:
        { // cau g
            system("cls");
            dangKyLopTinChi(dsLTC, Tree_monhoc, FirstSV);
            break;
        }

        case 8:
        { // cau h
            system("cls");
            tuDongHuyLop(dsLTC);
            break;
        }

        case 9:
        { // cau i

            system("cls");
            nhapBangDiem(FirstSV, Tree_monhoc, dsLTC);
            break;
        }

        case 10:
        { // cau j
            system("cls");
            inBangDiem(FirstSV, Tree_monhoc, dsLTC);
            break;
        }

        case 11:
        { // cau k
            system("cls");
            inBangDiemTBKhoaHoc(0, 4, FirstSV, Tree_monhoc, dsLTC);
            break;
        }

        case 12:
        { // cau L
            char maLopHoc[ClassID_Length] = {""};

            while (true)
            {
                system("cls");

                std::string content[2] = {""};
                if (input_UI(39, 4, 50, "NHAP MA LOP HOC CAN XET", 1, nhap_ma_lop_hoc, content, 4, "XAC NHAN XONG") == 1)
                {
                    system("cls");
                    ConvertStringToChar(content[0], maLopHoc);

                    gotoxy(50, 2);
                    std::cout << "BANG DIEM TONG KET CAC MON";
                    gotoxy(52, 4);
                    std::cout << "Ma lop hoc: " << maLopHoc;

                    inBangDiemTongKet(5, 8, dsLTC, FirstSV, Tree_monhoc, maLopHoc);
                }
                else
                    break;
            }
            break;
        }
        case 13:
        {
            system("cls");
            showFile(48, 4, dsLTC, Tree_monhoc, FirstSV);
            break;
        }

        case 14:
        {
            system("cls");
            int luachon = XacNhan(55, 5, "LUU FILE", "CO", "KHONG");
            if (luachon == 1)
                saveFile(dsLTC, Tree_monhoc, FirstSV);
            break;
        }

        default:
        {
            system("cls");
            int luachon = XacNhan(55, 5, "THOAT", "CO", "KHONG");
            if (luachon == 1)
            {
                system("cls");
                luachon = XacNhan(55, 5, "LUU FILE TRUOC KHI THOAT", "CO", "KHONG");
                if (luachon == 1)
                    saveFile(dsLTC, Tree_monhoc, FirstSV);

                return;
            }
            else
                break;
        }
        }
    }
}

int main()
{
    SetScreenBufferSize(width_console_buffer_size, height_console_buffer_size);
    SetWindowSize(width_console_size, height_console_size);
    DisableResizeWindow();
    DisableCtrButton(0, 0, 1);

    SetConsoleTitleA("CHUONG TRINH QUAN LY SINH VIEN"); // set console title with ASCII

    // PHAN TU LAM
    int pos = 0; // luu giu vi tri cua menuchinh
    int out = 0; // trang thai thoat

    initMemory(dsLTC, treeMH, FirstSV, FirstLH);

    ShowProgramName(50, 10, 256);
    Show_Loading_Time(59, 5);

    // neu load file khong co loi
    if (LOAD_FILE_ERROR == true)
        ShowMessage(x_box_thong_bao, y_box_thong_bao, "KHONG CO DU LIEU DAU VAO", 1500);

    Menu_Chinh(dsLTC, FirstSV, treeMH, 35, 1, out, pos);

    return 0;
}
