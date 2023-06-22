#include "my_modify.h"
#include "my_show.h"

void suaThongTinSinhVien(Student &sinhvien)
{

    system("cls");
    std::string content[7] = {""};
    char mssv[Student_ID_Length] = {""};

    ConvertCharToString(sinhvien.studentID, content[0]);
    ConvertCharToString(sinhvien.firstName, content[1]);
    ConvertCharToString(sinhvien.name, content[2]);
    ConvertCharToString(sinhvien.sex, content[3]);
    ConvertCharToString(sinhvien.phoneNum, content[4]);

    if (input_UI(47, 4, 35, "SUA THONG TIN SINH VIEN", 5, thong_tin_sinh_vien_lop_hoc, content, 15, "XAC NHAN XONG") == 1)
    {

        ConvertStringToChar(content[0], mssv);
        // neu sua ma sinh vien, ma mssv moi da ton tai
        // tra ve thongbao
        if (strcmp(sinhvien.studentID, mssv) != 0 && timSinhVien_DSSV(FirstSV, mssv) != NULL)
        {
            system("cls");
            ShowMessage(x_box_thong_bao, y_box_thong_bao, "MA SINH VIEN TRUNG LAP!", 1500);
        }
        else
        {
            ConvertStringToChar(content[0], sinhvien.studentID);
            ConvertStringToChar(content[1], sinhvien.firstName);
            ConvertStringToChar(content[2], sinhvien.name);
            ConvertStringToChar(content[3], sinhvien.sex);
            ConvertStringToChar(content[4], sinhvien.phoneNum);
        }
    }

    return;
}

int suaThongTinLopTinChi(int x_origin, int y_origin, char title[10][100], Credit *loptinchi)
{
    int x_box = x_origin + 5;
    int y_box = y_origin;
    int width_box_selection = 35;

    char maMH[CouseCode_Length] = {""};
    char nienkhoa[SchoolYear_Length] = {""};
    Credit *ptrloptinchi = NULL;

    while (true)
    {
        system("cls");
        drawBox((2 * x_box + width_box_selection - 26) / 2, y_box + 1, 26, 2);
        gotoxy((2 * x_box + width_box_selection - 26) / 2 + 1, y_box + 2);
        std::cout << "SUA THONG TIN LOP TIN CHI";

        std::string content[10] = {""};

        ConvertCharToString(loptinchi->courseCode, content[0]);
        ConvertCharToString(loptinchi->schoolYear, content[1]);
        content[2] = std::to_string(loptinchi->semester);
        content[3] = std::to_string(loptinchi->group);
        content[4] = std::to_string(loptinchi->studentMin);
        content[5] = std::to_string(loptinchi->studentMax);
        content[6] = std::to_string(loptinchi->enable);

        int check = input_UI(x_box, y_box + 4, width_box_selection, {""}, 7, title, content, 2, "XAC NHAN XONG");

        if (check == 1)
        { // da nhap xong thong tin
            ConvertStringToChar(content[0], maMH);
            ConvertStringToChar(content[1], nienkhoa);
            ptrloptinchi = timLopTinChi_theoMAMH_NIENKHOA(dsLTC, maMH, nienkhoa);

            if (ptrloptinchi == NULL || ptrloptinchi == loptinchi)
            {

                ConvertStringToChar(content[0], loptinchi->courseCode);
                ConvertStringToChar(content[1], loptinchi->schoolYear);
                loptinchi->semester = stringTo_Int(content[2]);
                loptinchi->group = stringTo_Int(content[3]);
                loptinchi->studentMin = stringTo_Int(content[4]);
                loptinchi->studentMax = stringTo_Int(content[5]);
                loptinchi->enable = stringTo_Int(content[6]);

                return 1;
            }
            else
            {
                system("cls");
                ShowMessage(x_box_thong_bao, y_box_thong_bao, "LOP TIN CHI TRUNG LAP", 1500);
            }
        }
        else if (check == 0)
            return 0;
    }
}

int suaThongTinMonHoc_User(Course &monhoc, int x_origin, int y_origin)
{

    system("cls");

    std::string monhoc_string[5] = {""};
    char MAMH[CouseName_Length] = {""};

    ConvertCharToString(monhoc.courceCode, monhoc_string[0]);
    ConvertCharToString(monhoc.courceName, monhoc_string[1]);
    monhoc_string[2] = std::to_string(monhoc.STCLT);
    monhoc_string[3] = std::to_string(monhoc.STCTH);

    if (input_UI(x_origin, y_origin, 40, "SUA THONG TIN MON HOC", 4, nhap_thong_tin_mon_hoc, monhoc_string, 12, "XAC NHAN XONG") == 1)
    {

        ConvertStringToChar(monhoc_string[0], MAMH);
        if (strcmp(monhoc.courceCode, MAMH) != 0 && timMonHocTheoMa(treeMH, MAMH) != NULL)
        {
            system("cls");
            ShowMessage(x_box_thong_bao, y_box_thong_bao, "MA MON HOC TRUNG LAP!", 1500);
        }

        else
        {
            ConvertStringToChar(monhoc_string[0], monhoc.courceCode);
            ConvertStringToChar(monhoc_string[1], monhoc.courceName);
            monhoc.STCLT = stringTo_Int(monhoc_string[2]);
            monhoc.STCTH = stringTo_Int(monhoc_string[3]);
            return 1; // bao hieu da nhap thong tin
        }
    }

    else
        return 0;
}
