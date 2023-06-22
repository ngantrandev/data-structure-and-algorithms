#include "my_paint.h"

//=================================
// HAM XUAT THONG TIN
//=================================



void xuatDanhSachSinhVienLopHoc_Console_TheoTen(LIST_LTC dsLTC, PTRSV FirstSV, int x_origin, int y_origin)
{ // case 4:  cau d

    int x_box = x_origin;
    int y_box = y_origin;

    char maLopHoc[ClassID_Length] = {""};
    PTRSV ptrSV = FirstSV; // giu dia chi con tro FirstSV
    PTRSV temp_FirstSV = NULL;

    while (true)
    {
        system("cls");
        std::string malop_string[2] = {""};
        ptrSV = FirstSV;
        temp_FirstSV = NULL; // reset lai danh sach

        if (input_UI(41, y_box, 45, "NHAP MA LOP", 1, nhap_ma_lop_hoc, malop_string, 4, "XAC NHAN XONG") == 1)
        {

            ConvertStringToChar(malop_string[0], maLopHoc);

            while (ptrSV != NULL)
            {
                if (strcmp(ptrSV->student.classID, maLopHoc) == 0)
                    themSinhVienVaoDanhSachSV(temp_FirstSV, ptrSV->student);
                ptrSV = ptrSV->next;
            }

            sapXepDanhSachSinhVienTheoTen_Ho_SelectionSort(temp_FirstSV);
            xuatDanhSachSinhVien_Console(temp_FirstSV, 13, 4);
            xoaDanhSachSinhVien(temp_FirstSV);
            system("pause");
        }
        else
            break;
    }
}

int xuatDanhSachSinhVienDK_LTC(int x_box, int y_box, LIST_LTC dsLTC, PTRSV FirstSV, char *nienkhoa, int hocky, int nhom, char *maMonHoc)
{ // case 2: cau b
    // tham so: nien khoa, hoc ky, nhom, ma mon hoc
    system("cls");
    int stt = 0;
    int tabx = x_box;
    int taby = y_box + 4;
    int tabw = 92; // day la chieu rong cua table show DSSV

    Credit *loptinchi = timLopTinChi_theoInfo(dsLTC, nienkhoa, hocky, nhom, maMonHoc);

    if (loptinchi != NULL)
    {

        PTRDK ptrDK = loptinchi->firstListRegister; // bien p tro toi danh sach lop tin chi;
        PTRSV ptr_SV = NULL;
        int soSV = Reccount_DSDK(ptrDK);

        gotoxy((2 * tabx + tabw - 28) / 2, y_box);
        std::cout << "DANH SACH SINH VIEN DANG KY";
        gotoxy((2 * tabx + tabw - 54) / 2, y_box + 1);
        std::printf("Nien khoa %s _ Hoc ky: %d _ Nhom: %d _ Ma mon hoc: %s", nienkhoa, hocky, nhom, maMonHoc);

        gotoxy((2 * tabx + tabw - 33) / 2, y_box + 2);
        std::printf("Co %d sinh vien trong danh sach\n", soSV);
        showStudentList(tabx, taby, soSV + 3);

        while (ptrDK != NULL)
        {

            ptr_SV = timSinhVien_DSSV(FirstSV, ptrDK->regis.studentID);
            if (ptr_SV != NULL)
            {
                stt++;
                gotoxy(tabx + 4, taby + stt + 2);
                std::cout << stt;
                gotoxy(tabx + 11, taby + stt + 2);
                std::cout << ptr_SV->student.studentID;
                gotoxy(tabx + 26, taby + stt + 2);
                std::cout << ptr_SV->student.firstName;
                gotoxy(tabx + 50, taby + stt + 2);
                std::cout << ptr_SV->student.name;
                gotoxy(tabx + 64, taby + stt + 2);
                std::cout << ptr_SV->student.sex;
                gotoxy(tabx + 73, taby + stt + 2);
                std::cout << ptr_SV->student.classID;
                gotoxy(tabx + 89, taby + stt + 2);
                std::cout << ptr_SV->student.phoneNum;
            }
            ptrDK = ptrDK->next;
        }

        gotoxy(tabx, wherey() + 2);
        system("pause");
        return 1;
    }

    else
        return 0;
}


void xuatDanhSachLopTinChi_Console_Theo_Dieu_Kien(int x_origin, int y_origin, LIST_LTC dsLTC, char nienkhoa[maxLengthString], int nhom)
{
    if (dsLTC.currentIndex == 0)
    {
        ShowMessage(10, 3, "KHONG CO LOP TIN CHI NAO THOA MAN", 1500);
        return;
    }
    int stt = 0;
    int tabw = 91;
    int count_LTC = 0; // dem so lop tin chi thoa man

    for (int i = 1; i <= dsLTC.currentIndex; i++)
    {
        if (lopTinChiTonTai(dsLTC.nodes[i]) && dsLTC.nodes[i]->group == nhom && strcmp(dsLTC.nodes[i]->schoolYear, nienkhoa) == 0)
            count_LTC++;
    }

    if (count_LTC > 0)
    {
        drawBox((2 * x_origin + tabw - 22) / 2, 2, 22, 2);
        gotoxy((2 * x_origin + tabw - 22) / 2 + 1, 3);
        std::cout << "DANH SACH LOP TIN CHI";
        gotoxy((2 * x_origin + tabw - 22) / 2, 5);
        std::printf("  CO %d LOP TRONG DANH SACH", count_LTC);

        showCreditClassList(x_origin, 7, tabw, count_LTC + 3);

        for (int i = 1; i <= dsLTC.currentIndex; i++)
        {
            if (lopTinChiTonTai(dsLTC.nodes[i]) && dsLTC.nodes[i]->group == nhom && strcmp(dsLTC.nodes[i]->schoolYear, nienkhoa) == 0)
            {
                stt++;
                gotoxy(x_origin + 3, y_origin + stt + 5);
                std::cout << stt;
                gotoxy(x_origin + 10, y_origin + stt + 5);
                std::cout << dsLTC.nodes[i]->creditCode;
                gotoxy(x_origin + 19, y_origin + stt + 5);
                std::cout << dsLTC.nodes[i]->courseCode;
                gotoxy(x_origin + 30, y_origin + stt + 5);
                std::cout << dsLTC.nodes[i]->schoolYear;
                gotoxy(x_origin + 42, y_origin + stt + 5);
                std::cout << dsLTC.nodes[i]->semester;
                gotoxy(x_origin + 50, y_origin + stt + 5);
                std::cout << dsLTC.nodes[i]->group;
                gotoxy(x_origin + 60, y_origin + stt + 5);
                std::cout << dsLTC.nodes[i]->studentMin;
                gotoxy(x_origin + 70, y_origin + stt + 5);
                std::cout << dsLTC.nodes[i]->studentMax;
                gotoxy(x_origin + 79, y_origin + stt + 5);
                std::cout << (dsLTC.nodes[i]->enable == false ? "Hoat dong" : "Da huy");
            }
        }
    }
    else
    {
        system("cls");
        ShowMessage(10, 3, "KHONG CO LOP TIN CHI NAO THOA MAN", 1500);
        return;
    }
}


void xuatDanhSachLopTinChi_Console(int x_origin, int y_origin, LIST_LTC dsLTC)
{
    system("cls");

    if (dsLTC.currentIndex == 0)
    {
        ShowMessage(50, 3, "KHONG CO LOP TIN CHI NAO", 1500);
        return;
    }

    int stt = 0;
    int tabw = 91;

    drawBox((2 * x_origin + tabw - 22) / 2, y_origin, 22, 2);
    gotoxy((2 * x_origin + tabw - 22) / 2 + 1, y_origin + 1);
    std::cout << "DANH SACH LOP TIN CHI";

    if (so_lop_hien_tai_LTC > 0)
    {
        gotoxy((2 * x_origin + tabw - 28) / 2, y_origin + 4);
        std::printf("  CO %d LOP TRONG DANH SACH", so_lop_hien_tai_LTC);

        showCreditClassList(x_origin, y_origin + 6, tabw, so_lop_hien_tai_LTC + 3);

        for (int i = 1; i <= dsLTC.currentIndex; i++)
        {
            if (lopTinChiTonTai(dsLTC.nodes[i]))
            {
                stt++;
                xuatThongTinLopTinChi_Console(x_origin, y_origin + 3, dsLTC.nodes[i], stt);
            }
        }
    }
    else
    {
        gotoxy((2 * x_origin + tabw - 28) / 2, y_origin + 3);
        std::printf("DANH SACH TRONG");
    }

    // gotoxy(x_origin,  y_origin + stt + 12);
    gotoxy(x_origin, wherey() + 2);
}


void xuatThongTinLopTinChi_Console(int x_origin, int y_origin, Credit *loptinchi, int stt)
{

    gotoxy(x_origin + 3, y_origin + stt + 5);
    std::cout << stt;
    gotoxy(x_origin + 10, y_origin + stt + 5);
    std::cout << loptinchi->creditCode;
    gotoxy(x_origin + 19, y_origin + stt + 5);
    std::cout << loptinchi->courseCode;
    gotoxy(x_origin + 30, y_origin + stt + 5);
    std::cout << loptinchi->schoolYear;
    gotoxy(x_origin + 42, y_origin + stt + 5);
    std::cout << loptinchi->semester;
    gotoxy(x_origin + 50, y_origin + stt + 5);
    std::cout << loptinchi->group;
    gotoxy(x_origin + 60, y_origin + stt + 5);
    std::cout << loptinchi->studentMin;
    gotoxy(x_origin + 70, y_origin + stt + 5);
    std::cout << loptinchi->studentMax;
    gotoxy(x_origin + 79, y_origin + stt + 5);
    std::cout << (loptinchi->enable == false ? "Hoat dong" : "Da huy");
}


void xuatDanhSachMonHoc_Console(int x_origin, int y_origin, PTRMH Tree_monhoc)
{

    if (Tree_monhoc == NULL)
    {
        ShowMessage(x_box_thong_bao, y_box_thong_bao, "DANH SACH MON HOC TRONG!", 1500);
        return;
    }

    int soLuongMonHoc = so_mon_hoc_DSMH; // so luong mon hoc
    int tabw = 80;
    int tabh = soLuongMonHoc + 3;
    int stt = 0;

    gotoxy((2 * x_origin + tabw - 18) / 2, y_origin + 1);
    std::printf("DANH SACH MON HOC");
    gotoxy((2 * x_origin + tabw - 14) / 2, y_origin + 2);
    std::printf("CO %d MON HOC", soLuongMonHoc);

    showCourceList(x_origin, y_origin + 4, tabw, tabh);

    xuatDanhSachMonHoc_LNR_Console(Tree_monhoc, x_origin, y_origin + 2, stt);

    // gotoxy(x_origin, y_origin + tabh + 6);
    gotoxy(x_origin, wherey() + 2);
}


void xuatDanhSachMonHoc_LNR_Console(PTRMH Tree_monhoc, int x_origin, int y_origin, int &stt)
{
    // ║   STT   ║  MA MON HOC  ║          TEN MON HOC          ║   STCLT   ║   STCTH  ║
    if (Tree_monhoc != NULL)
    {
        xuatDanhSachMonHoc_LNR_Console(Tree_monhoc->pLeft, x_origin, y_origin, stt);

        stt++;
        xuatThongTinMonHoc(x_origin, y_origin, stt, Tree_monhoc->course);

        xuatDanhSachMonHoc_LNR_Console(Tree_monhoc->pRight, x_origin, y_origin, stt);
    }
}


void xuatThongTinMonHoc(int tabx, int taby, int stt, Course monhoc)
{
    gotoxy(tabx + 4, taby + stt + 4);
    std::cout << stt;
    gotoxy(tabx + 16, taby + stt + 4);
    std::cout << monhoc.courceCode;
    gotoxy(tabx + 33, taby + stt + 4);
    std::cout << monhoc.courceName;
    gotoxy(tabx + 63, taby + stt + 4);
    std::cout << monhoc.STCLT;
    gotoxy(tabx + 75, taby + stt + 4);
    std::cout << monhoc.STCTH;
}


void xuatDanhSachSinhVien_Console(PTRSV FirstSV, int tabx, int taby)
{
    system("cls");
    if (FirstSV == NULL)
    {
        ShowMessage(x_box_thong_bao, y_box_thong_bao, "DANH SACH SINH VIEN TRONG", 1500);
        return;
    }

    PTRSV p = FirstSV;
    int soSV = Reccount_SV(FirstSV);
    int tabw = 102;
    int tabh = soSV + 3;
    int stt = 0;

    gotoxy((2 * tabx + tabw - 20) / 2, taby);
    std::cout << "DANH SACH SINH VIEN";
    gotoxy((2 * tabx + tabw - 32) / 2, taby + 1);
    std::printf("CO %d SINH VIEN TRONG DANH SACH", soSV);

    showStudentList(tabx, taby + 3, tabh);

    while (p != NULL)
    {
        ++stt;
        xuatThongTinSinhVien(tabx, taby + 1, p->student, stt);
        p = p->next;
    }
    //  gotoxy(tabx, taby + stt + 7);
    gotoxy(tabx, wherey() + 2);
}


// chuc nang: xuat thong tin sinh vien dua vao ma sinh vien
void xuatThongTinSinhVien_MSSV_Console(PTRSV ptr_SV, int &stt, int tabx, int taby)
{
    int tabw = 102;
    int tabh = 4;

    gotoxy((2 * tabx + tabw - 20) / 2, taby);
    std::cout << "THONG TIN SINH VIEN";

    showStudentList(tabx, taby + 2, tabh);

    gotoxy(tabx + 4, taby + stt + 4);
    std::cout << stt;
    gotoxy(tabx + 11, taby + stt + 4);
    std::cout << ptr_SV->student.studentID;
    gotoxy(tabx + 27, taby + stt + 4);
    std::cout << ptr_SV->student.firstName;
    gotoxy(tabx + 50, taby + stt + 4);
    std::cout << ptr_SV->student.name;
    gotoxy(tabx + 64, taby + stt + 4);
    std::cout << ptr_SV->student.sex;
    gotoxy(tabx + 73, taby + stt + 4);
    std::cout << ptr_SV->student.classID;
    gotoxy(tabx + 89, taby + stt + 4);
    std::cout << ptr_SV->student.phoneNum;

    gotoxy(0, taby + stt + 2 + 4);
}


void xuatThongTinSinhVien(int tabx, int taby, Student sinhvien, int stt)
{
    gotoxy(tabx + 4, taby + stt + 4);
    std::cout << stt;
    gotoxy(tabx + 11, taby + stt + 4);
    std::cout << sinhvien.studentID;
    gotoxy(tabx + 26, taby + stt + 4);
    std::cout << sinhvien.firstName;
    gotoxy(tabx + 50, taby + stt + 4);
    std::cout << sinhvien.name;
    gotoxy(tabx + 64, taby + stt + 4);
    std::cout << sinhvien.sex;
    gotoxy(tabx + 73, taby + stt + 4);
    std::cout << sinhvien.classID;
    gotoxy(tabx + 89, taby + stt + 4);
    std::cout << sinhvien.phoneNum;
}

void xuatDanhSachMonHocTheoTen(int x_origin, int y_origin, PTRMH Tree_monhoc)
{
    PTRMH temp_tree = NULL;
    saoChepMonHocTheoTen(Tree_monhoc, temp_tree);
    xuatDanhSachMonHoc_Console(x_origin, y_origin, temp_tree);
    xoaDanhSachMonHoc(temp_tree);
}

void inBangDiemLopTinChi(PTRSV FirstSV, PTRMH Tree_monhoc, Credit *loptinchi)
{ // case 10: cau j

    PTRMH monhoc = timMonHocTheoMa(Tree_monhoc, loptinchi->courseCode);
    PTRDK ptrDK = loptinchi->firstListRegister;
    PTRSV ptrSV = NULL;
    int soSV = Reccount_DSDK(ptrDK);
    int stt = 0;
    int length_of_title = 22 + strlen(monhoc->course.courceName);
    int tabw = 85;
    int x_box = (128 - tabw) / 2;
    int x_origin = 0;
    int y_origin = 4;

    system("cls");
    gotoxy((128 - length_of_title) / 2, y_origin);
    std::cout << "BANG DIEM MON HOC < " << monhoc->course.courceName << " >";
    gotoxy((128 - 48) / 2, y_origin + 1);
    std::printf("Nien khoa: %-10s Hoc ky: %-10d Nhom: %-10d", loptinchi->schoolYear, loptinchi->semester, loptinchi->group);

    drawScoreBoard(x_box, y_origin + 4, tabw, soSV + 3);

    while (ptrDK != NULL)
    {
        ptrSV = timSinhVien_DSSV(FirstSV, ptrDK->regis.studentID);

        stt++;
        gotoxy(x_box + 5, y_origin + stt + 6);
        std::cout << stt;
        gotoxy(x_box + 13, y_origin + stt + 6);
        std::cout << ptrDK->regis.studentID;
        gotoxy(x_box + 28, y_origin + stt + 6);
        std::cout << ptrSV->student.firstName;
        gotoxy(x_box + 55, y_origin + stt + 6);
        std::cout << ptrSV->student.name;
        gotoxy(x_box + 74, y_origin + stt + 6);
        std::printf("%0.2f", ptrDK->regis.point);

        ptrDK = ptrDK->next;
    }
    gotoxy(x_box, wherey() + 2);
    system("pause");
}

void inBangDiem(PTRSV FirstSV, PTRMH Tree_monhoc, LIST_LTC dsLTC)
{ // case 10: cau j
    char nienkhoa[maxLengthString] = "2020";
    char maMH[maxLengthString] = "MH2";
    int hocky = 3, nhom = 2;
    Credit *loptinchi = NULL;

    while (true)
    {
        system("cls");
        std::string content[6] = {""};

        if (input_UI(44, 4, 40, "NHAP THONG TIN LOP TIN CHI CAN XET", 4, cau_2, content, 8, "XAC NHAN XONG") == 1)
        {
            ConvertStringToChar(content[0], nienkhoa);
            hocky = stringTo_Int(content[1]);
            nhom = stringTo_Int(content[2]);
            ConvertStringToChar(content[3], maMH);

            loptinchi = timLopTinChi_theoInfo(dsLTC, nienkhoa, hocky, nhom, maMH);

            if (loptinchi != NULL)
            {
                inBangDiemLopTinChi(FirstSV, Tree_monhoc, loptinchi);
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


void inBangDiemTongKet(int x_origin, int y_origin, LIST_LTC dsLTC, PTRSV FirstSV, PTRMH Tree_monhoc, char maLopHoc[ClassID_Length])
{
    // MAX_SV la:  so sinh vien lon nhat co the co trong 1 lop ( vi du: lop D20CQPT01-n);
    // khac voi ma lop tin chi
    int MAX_SV = Reccount_SV(FirstSV);
    int soSV = 0;
    int soMH = 0;  // so mon hoc
    int step = 10; // do rong cua cot diem

    char temp_maMH[MAXMONHOC] = {""}; // danh sach
    PTRSV dssv[MAX_SV + 1];           // danh sach

    PTRDK ptrDK = NULL;           // dung de tim kiem
    Credit *ptr_loptinchi = NULL; // dung de tim kiem

    std::string maMH[MAXMONHOC];
    int index = 0;

    // PHAN XU LY DU LIEU

    layDanhSachSinhVienCungLop(FirstSV, dssv, maLopHoc, soSV); // nap danh sach sinh vien
    if (soSV == 0)
    {
        system("cls");
        ShowMessage(x_box_thong_bao, y_box_thong_bao, "LOP HOC KHONG CO SINH VIEN", 1500);
        return;
    }

    // reset index = 0;
    index = 0;
    layDanhSachMaMonHoc(Tree_monhoc, maMH, index); // nap danh sach ma mon hoc
    soMH = index;

    // PHAN outPUT

    gotoxy(x_origin, y_origin - 2);
    std::cout << "Chu thich: NONE -> mon hoc chua co lop tin chi";
    gotoxy(x_origin, y_origin - 1);
    std::cout << "           .... -> chua co diem do chua dang ky lop tin chi";
    vebangtongketdiem(x_origin, y_origin, step, soSV, soMH, maMH);

    for (int i = 1; i <= soSV; i++)
    {
        // IN THONG TIN SINH VIEN
        gotoxy(x_origin + 5, y_origin + i + 2);
        std::cout << i;
        gotoxy(x_origin + 13, y_origin + i + 2);
        std::cout << dssv[i]->sv.MASV;
        gotoxy(x_origin + 28, y_origin + i + 2);
        std::cout << dssv[i]->sv.HO;
        gotoxy(x_origin + 55, y_origin + i + 2);
        std::cout << dssv[i]->sv.TEN;

        // IN DIEM

        for (int j = 1; j <= soMH; j++)
        {
            ConvertStringToChar(maMH[j], temp_maMH);
            ptr_loptinchi = timLopTinChi_theoMAMH(dsLTC, temp_maMH);

            if (ptr_loptinchi != NULL)
            {
                ptrDK = timSinhVien_DSSVDK(ptr_loptinchi->firstListRegister, dssv[i]->sv.MASV);

                if (ptrDK != NULL)
                {
                    gotoxy(x_origin + 66 + j * step - 6, y_origin + i + 2);
                    std::printf("%0.2f", ptrDK->regis.point);
                }
                else
                {
                    gotoxy(x_origin + 66 + j * step - 6, y_origin + i + 2);
                    std::printf("....");
                }
            }

            else
            {
                gotoxy(x_origin + 66 + j * step - 6, y_origin + i + 2);
                std::printf("NONE");
            }
        }
    }
    //  gotoxy(0, y_origin + soSV + 5);
    gotoxy(0, wherey() + 2);
    system("pause");
}


void inBangDiemTBKhoaHoc(int x_origin, int y_origin, PTRSV FirstSV, PTRMH Tree_monhoc, LIST_LTC dsLTC)
{
    PTRDK ptrDK = NULL;
    PTRSV ptrSV = NULL;
    PTRMH ptrMH = NULL;
    StudentListNode DSSV[so_sinh_vien_DSSV + 1];

    int stt = 0;
    int crt_index = -1; // chi so mang hien tai
    int index = 0;
    char maLopHoc[ClassID_Length] = {""};
    char nienkhoa[SchoolYear_Length] = "2020";
    int soSV = 0;

    int tabw = 85;
    int x_box = (128 - tabw) / 2;

    while (true)
    {

        crt_index = -1;
        soSV = 0;

        system("cls");
        gotoxy(45, y_origin);
        std::cout << "BANG THONG KE DIEM TRUNG BINH KHOA HOC";

        std::string content[2] = {""};

        if (input_UI(44, y_origin + 2, 45, "NHAP THONG TIN LOP HOC CAN XET", 2, nhap_MALH_NIENKHOA, content, 20, "XAC NHAN XONG") == 1)
        {
            ConvertStringToChar(content[0], maLopHoc);
            ConvertStringToChar(content[1], nienkhoa);

            for (int i = 1; i <= dsLTC.currentIndex; i++)
            {
                if (lopTinChiTonTai(dsLTC.nodes[i]) == true && dsLTC.nodes[i]->enable == false && strcmp(dsLTC.nodes[i]->schoolYear, nienkhoa) == 0)
                {
                    ptrDK = dsLTC.nodes[i]->firstListRegister;
                    ptrMH = timMonHocTheoMa(Tree_monhoc, dsLTC.nodes[i]->courseCode);

                    while (ptrDK != NULL)
                    {
                        ptrSV = timSinhVien_DSSV(FirstSV, ptrDK->regis.studentID);

                        if (strcmp(ptrSV->student.classID, maLopHoc) == 0)
                        {

                            index = timSinhVien_nodeDSSV(DSSV, crt_index, ptrSV);

                            if (index == -1)
                            { // khong tim thay
                                ++crt_index;
                                soSV++;
                                DSSV[crt_index].ptrSV = ptrSV;
                                DSSV[crt_index].tong_diem = ptrDK->regis.point * (ptrMH->course.STCLT + ptrMH->course.STCTH);
                                DSSV[crt_index].creditSum = ptrMH->course.STCLT + ptrMH->course.STCTH;
                            }

                            else
                            {
                                DSSV[index].tong_diem += ptrDK->regis.point * (ptrMH->course.STCLT + ptrMH->course.STCTH);
                                DSSV[index].creditSum += ptrMH->course.STCLT + ptrMH->course.STCTH;
                            }
                        }

                        ptrDK = ptrDK->next;
                    }
                }
            }

            // sap xep lai danh sach
            sapXep_nodeDSSV_SelectionSort(DSSV, crt_index);

            if (soSV == 0)
            {
                system("cls");
                ShowMessage(x_box_thong_bao, y_box_thong_bao, "KHONG CO SINH VIEN THOA MAN", 1500);
                continue;
            }

            system("cls");
            gotoxy(45, y_origin);
            std::cout << "BANG THONG KE DIEM TRUNG BINH KHOA HOC";
            gotoxy(54, y_origin + 1);
            std::cout << "Ma lop: " << maLopHoc;

            veBangInDiemTB(x_box, y_origin + 3, tabw, soSV + 3);

            stt = 0; // reset stt
            for (int i = 0; i <= crt_index; i++)
            {
                stt++;

                gotoxy(x_box + 5, y_origin + stt + 5);
                std::cout << stt;
                gotoxy(x_box + 13, y_origin + stt + 5);
                std::cout << DSSV[i].ptrSV->sv.MASV;
                gotoxy(x_box + 28, y_origin + stt + 5);
                std::cout << DSSV[i].ptrSV->sv.HO;
                gotoxy(x_box + 55, y_origin + stt + 5);
                std::cout << DSSV[i].ptrSV->sv.TEN;
                gotoxy(x_box + 74, y_origin + stt + 5);
                std::printf("%0.2f", DSSV[i].tong_diem / DSSV[i].creditSum);
            }
            gotoxy(x_box, wherey() + 2);
            system("pause");
        }

        else
            break;
    }
}
