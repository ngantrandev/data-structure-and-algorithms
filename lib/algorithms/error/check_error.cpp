#include "my_error.h"

int kiem_tra_loi(int ma_nhom_du_lieu, int ma_du_lieu, std::string &du_lieu, PTRMH treeMH, LIST_LTC dsLTC, PTRLH firstLH, PTRSV firstSV)
{
    // tien xu ly du lieu
    if (du_lieu.length() == 0)
        if (ma_nhom_du_lieu != 14 || ma_du_lieu != 1) // TH nhap ma sinh vien khi them sinh vien KHONG XET
            return 8;                                 // chuoi rong

    char char_dulieu[maxLengthString] = {""};
    int int_dulieu = stringTo_Int(du_lieu);
    ConvertStringToChar(du_lieu, char_dulieu);

    if (ma_nhom_du_lieu == 1)
    { // THEM LOP TIN CHI
        if (ma_du_lieu == 1)
        { // ma mon hoc
            if (du_lieu.length() > CouseCode_Length)
                return 9; // vuot gioi han
            else if (timMonHocTheoMa(treeMH, char_dulieu) == NULL)
                return 3; // mon hoc khong ton tai
        }
        else if (ma_du_lieu == 2)
        { // nien khoa
            if (du_lieu.length() > SchoolYear_Length)
                return 9; // vuot qua ky tu
            else if (IsIntNumber(du_lieu) == false)
                return 101;
            else if (1900 >= stringTo_Int(du_lieu) || stringTo_Int(du_lieu) >= 2100)
                return 10; // nam khong hop le
        }
        else if (ma_du_lieu == 3)
        { // hoc ky
            if (IsIntNumber(du_lieu) == false)
                return 101;
            else if (int_dulieu > 10 || int_dulieu <= 0)
                return 14; // hoc ky khong hop le
        }
        else if (ma_du_lieu == 4)
        { // nhom
            if (IsIntNumber(du_lieu) == false)
                return 101;
            else if (int_dulieu > 20 || int_dulieu <= 0)
                return 11; // nhom khong hop le
        }
        else if (ma_du_lieu == 5)
        { // soSV min
            if (du_lieu.length() > 5)
                return 9;
            else if (IsIntNumber(du_lieu) == false)
                return 101;
            else if (int_dulieu <= 0 || int_dulieu >= 500)
                return 15; // sosv min khong hop le
        }
        else if (ma_du_lieu == 6)
        { // sosv max
            if (du_lieu.length() > 5)
                return 9;
            else if (IsIntNumber(du_lieu) == false)
                return 101;
            else if (int_dulieu <= 0 || int_dulieu >= 500)
                return 16; // sosv max khong hop le
        }
    }
    else if (ma_nhom_du_lieu == 2)
    { //  SUA LOP TIN CHI
        // giong nhom 1
        if (ma_du_lieu == 1)
        { // ma mon hoc
            if (du_lieu.length() > CouseCode_Length)
                return 9;
            else if (timMonHocTheoMa(treeMH, char_dulieu) == NULL)
                return 3;
        }
        else if (ma_du_lieu == 2)
        { // nien khoa
            if (du_lieu.length() > SchoolYear_Length)
                return 9; // vuot qua ky tu
            else if (IsIntNumber(du_lieu) == false)
                return 101;
            else if (1900 >= stringTo_Int(du_lieu) || stringTo_Int(du_lieu) >= 2100)
                return 10; // nam khong hop le
        }
        else if (ma_du_lieu == 3)
        { // hoc ky
            if (IsIntNumber(du_lieu) == false)
                return 101;
            else if (int_dulieu > 6 || int_dulieu <= 0)
                return 14; // hoc ky khong hop le
        }
        else if (ma_du_lieu == 4)
        { // nhom
            if (IsIntNumber(du_lieu) == false)
                return 101;
            else if (int_dulieu > 20 || int_dulieu <= 0)
                return 11; // nhom khong hop le
        }
        else if (ma_du_lieu == 5)
        { // soSV min
            if (du_lieu.length() > 5)
                return 9;
            else if (IsIntNumber(du_lieu) == false)
                return 101;
            else if (int_dulieu <= 0 || int_dulieu >= 500)
                return 15; // sosv min khong hop le
        }
        else if (ma_du_lieu == 6)
        { // sosv max
            if (du_lieu.length() > 5)
                return 9;
            else if (IsIntNumber(du_lieu) == false)
                return 101;
            else if (int_dulieu <= 0 || int_dulieu >= 500)
                return 16; // sosv max khong hop le
        }
        else if (ma_du_lieu == 7)
        { // HUY LOP
            if (du_lieu.length() > 1)
                return 9;
            else if (du_lieu != "0" && du_lieu != "1")
                return 101;
        }
    }
    else if (ma_nhom_du_lieu == 3)
    { // NHAP MA LOP TIN CHI
        if (ma_du_lieu == 1)
        { // nhap ma lop tin chi
            if (du_lieu.length() > 8)
                return 9; // qua gioi han
            else if (IsIntNumber(du_lieu) == false)
                return 101; // sai cus phap
            else if (dsLTC.nodes[int_dulieu] == NULL)
                return 2; // lop tin chi khong ton tai
        }
    }

    else if (ma_nhom_du_lieu == 4)
    { // nhap ma lop hoc
        if (ma_du_lieu == 1)
        { // nhap ma lop hoc
            getStandardizedStudentID(du_lieu);
            ConvertStringToChar(du_lieu, char_dulieu);

            if (du_lieu.length() > ClassID_Length)
                return 9;
            else if (timLopHoc(firstLH, char_dulieu) == NULL)
                return 4; // lop hoc khong ton tai
        }
    }

    else if (ma_nhom_du_lieu == 5)
    { // nhap ma sinh vien
        if (ma_du_lieu == 1)
        { // ma sinh vien
            getStandardizedStudentID(du_lieu);
            ConvertStringToChar(du_lieu, char_dulieu);

            if (du_lieu.length() > Student_ID_Length)
                return 9;
            else if (timSinhVien_DSSV(firstSV, char_dulieu) == NULL)
                return 1; // sinh vien khong ton tai
        }
    }

    else if (ma_nhom_du_lieu == 6)
    { // nhap ma mon hoc
        if (ma_du_lieu == 1)
        { // nhap ma mon hoc
            if (du_lieu.length() > CouseCode_Length)
                return 9; // vuot qua gioi han
            else if (timMonHocTheoMa(treeMH, char_dulieu) == NULL)
                return 3; // mon hoc khong ton tai
        }
    }

    else if (ma_nhom_du_lieu == 7)
    { // question 7
        if (ma_du_lieu == 1)
        { // nhap nien khoa
            if (du_lieu.length() > 4)
                return 9; // vuot qua ky tu
            else if (IsIntNumber(du_lieu) == false)
                return 101;
            else if (1900 >= int_dulieu || int_dulieu >= 2100)
                return 10; // nam khong hop le
        }
        else if (ma_du_lieu == 2)
        { // nhap hoc ky
            if (du_lieu.length() > 5)
                return 9;
            else if (IsIntNumber(du_lieu) == false)
                return 101;
            else if (int_dulieu > 10 || int_dulieu <= 0)
                return 14; // hoc ky khong hop le
        }
    }

    else if (ma_nhom_du_lieu == 8)
    { // // cau 2
        if (ma_du_lieu == 1)
        { // nhap nien khoa
            if (du_lieu.length() > 4)
                return 9; // vuot qua ky tu
            else if (IsIntNumber(du_lieu) == false)
                return 101;
            else if (1900 >= int_dulieu || int_dulieu >= 2100)
                return 10; // nam khong hop le
        }
        else if (ma_du_lieu == 2)
        { // nhap hoc ky
            if (du_lieu.length() > 5)
                return 9;
            else if (IsIntNumber(du_lieu) == false)
                return 101;
            else if (int_dulieu > 6 || int_dulieu <= 0)
                return 14; // hoc ky khong hop le
        }
        else if (ma_du_lieu == 3)
        { // nhap nhom
            if (du_lieu.length() > 5)
                return 9;
            else if (IsIntNumber(du_lieu) == false)
                return 101;
            else if (int_dulieu > 20 || int_dulieu <= 0)
                return 11; // hoc ky khong hop le
        }
        else if (ma_du_lieu == 4)
        { // nhap ma mon hoc
            if (du_lieu.length() > CouseCode_Length)
                return 9;
            else if (timMonHocTheoMa(treeMH, char_dulieu) == NULL)
                return 3;
        }
    }

    else if (ma_nhom_du_lieu == 9)
    { // them: nhap thong tin mon hoc
        if (ma_du_lieu == 1)
        { // nhap ma mon hoc
            if (du_lieu.length() > CouseCode_Length)
                return 9;
            else if (timMonHocTheoMa(treeMH, char_dulieu) != NULL)
                return 7;
        }
        else if (ma_du_lieu == 2)
        { // nhap ten mon hoc
            du_lieu = getCapitalized(du_lieu);

            if (du_lieu.length() > 30)
                return 9; // qua gioi han
        }
        else if (ma_du_lieu == 3)
        { // nhap stclt

            if (du_lieu.length() > 5)
                return 9; // qua GH
            else if (IsIntNumber(du_lieu) == false)
                return 101;
            else if (int_dulieu <= 0 || int_dulieu > 10)
                return 12;
        }
        else if (ma_du_lieu == 4)
        { // nhap stcTH
            if (du_lieu.length() > 5)
                return 9; // qua GH
            else if (IsIntNumber(du_lieu) == false)
                return 101;
            else if (int_dulieu <= 0 || int_dulieu > 10)
                return 13;
        }
    }

    else if (ma_nhom_du_lieu == 10)
    { // nhap ma sinh vien de them sinh vien
        if (timSinhVien_DSSV(firstSV, char_dulieu) == NULL)
            return 1;
    }

    else if (ma_nhom_du_lieu == 11)
    { // SUA THONG TIN SVienDK
        if (ma_du_lieu == 1)
        { // ma sinh vien
            getStandardizedStudentID(du_lieu);
            ConvertStringToChar(du_lieu, char_dulieu);

            if (du_lieu.length() > Student_ID_Length)
                return 9;
            else if (timSinhVien_DSSV(firstSV, char_dulieu) == NULL)
                return 1; // sinh vien khong ton tai
        }
        else if (ma_du_lieu == 2)
        { // diem
            if (du_lieu.length() > 10)
                return 9;
            else if (IsFloatNumber(du_lieu) == false)
                return 101;
            else if (stof(du_lieu) < 0)
                return 20; // diem khogn nho hon 0
        }

        else if (ma_du_lieu == 3)
        { // huy dang ky
            if (du_lieu.length() > 1)
                return 9;
            else if (du_lieu != "0" && du_lieu != "1")
                return 101;
        }
    }

    else if (ma_nhom_du_lieu == 12)
    { // sua thong tin mon hoc
        if (ma_du_lieu == 1)
        { // sua ma mon hoc
            if (du_lieu.length() > CouseCode_Length)
                return 9;
            // else if (timMonHocTheoMa(treeMH, char_dulieu) != NULL)
            //     return 7;
        }
        else if (ma_du_lieu == 2)
        { // nhap ten mon hoc
            getCapitalized(du_lieu);

            if (du_lieu.length() > 30)
                return 9; // qua gioi han
        }
        else if (ma_du_lieu == 3)
        { // nhap stclt
            if (du_lieu.length() > 5)
                return 9; // qua GH
            else if (IsIntNumber(du_lieu) == false)
                return 101;
            else if (int_dulieu <= 0 || int_dulieu > 10)
                return 12;
        }
        else if (ma_du_lieu == 4)
        { // nhap stcTH
            if (du_lieu.length() > 5)
                return 9; // qua GH
            else if (IsIntNumber(du_lieu) == false)
                return 101;
            else if (int_dulieu <= 0 || int_dulieu > 10)
                return 13;
        }
    }

    else if (ma_nhom_du_lieu == 14)
    { // them sinh vien vao danh sach sinh vien, chap nhan ma rong
        if (ma_du_lieu == 1)
        { // ma sinh vien
            if (du_lieu.length() == 0)
                return 0;
            getStandardizedStudentID(du_lieu);
            ConvertStringToChar(du_lieu, char_dulieu);

            if (du_lieu.length() > Student_ID_Length)
                return 9;
            else if (timSinhVien_DSSV(firstSV, char_dulieu) != NULL)
                return 5;
        }
        else if (ma_du_lieu == 2)
        { // ho sinh vien
            getStandardizedName(du_lieu);
            if (du_lieu.length() > First_Name_Length)
                return 9;
        }
        else if (ma_du_lieu == 3)
        { // ten sinh vien
            getStandardizedName(du_lieu);
            if (du_lieu.length() > Ten_Length)
                return 9;
        }
        else if (ma_du_lieu == 4)
        { // gioi tinh
            getStandardizedName(du_lieu);
            if (du_lieu.length() > SEX_Length)
                return 9;
        }
        else if (ma_du_lieu == 5)
        { // so dien thoai
            if (du_lieu.length() > PhoneNum_Length)
                return 9;
            else if (IsIntNumber(du_lieu) == false)
                return 101;
        }
    }

    else if (ma_nhom_du_lieu == 15)
    { // sua thong tin sinh vien lop hoc
        if (ma_du_lieu == 1)
        { // ma sinh vien
            getStandardizedStudentID(du_lieu);
            ConvertStringToChar(du_lieu, char_dulieu);

            if (du_lieu.length() > Student_ID_Length)
                return 9;
            // else if(timSinhVien_DSSV(FirstSV, char_dulieu) != NULL)
            //     return 5;
        }
        else if (ma_du_lieu == 2)
        { // ho sinh vien
            getStandardizedName(du_lieu);
            if (du_lieu.length() > First_Name_Length)
                return 9;
        }
        else if (ma_du_lieu == 3)
        { // ten sinh vien
            getStandardizedName(du_lieu);
            if (du_lieu.length() > Ten_Length)
                return 9;
        }
        else if (ma_du_lieu == 4)
        { // gioi tinh
            getStandardizedName(du_lieu);
            if (du_lieu.length() > SEX_Length)
                return 9;
        }
        else if (ma_du_lieu == 5)
        { // so dien thoai
            if (du_lieu.length() > PhoneNum_Length)
                return 9;
            else if (IsIntNumber(du_lieu) == false)
                return 101;
        }
    }

    else if (ma_nhom_du_lieu == 20)
    {
        if (ma_du_lieu == 1)
        { // nhap ma lop hoc
            getStandardizedStudentID(du_lieu);
            ConvertStringToChar(du_lieu, char_dulieu);

            if (du_lieu.length() > ClassID_Length)
                return 9;
            else if (timLopHoc(firstLH, char_dulieu) == NULL)
                return 4; // lop hoc khong ton tai
        }

        else if (ma_du_lieu == 2)
        { // nien khoa
            if (du_lieu.length() > SchoolYear_Length)
                return 9; // vuot qua ky tu
            else if (IsIntNumber(du_lieu) == false)
                return 101;
            else if (1900 >= stringTo_Int(du_lieu) || stringTo_Int(du_lieu) >= 2100)
                return 10; // nam khong hop le
        }
    }

    else if (ma_nhom_du_lieu == 100)
    { // nhap diem trong bang diem
        if (du_lieu.length() > 10)
            return 9;
        else if (IsFloatNumber(du_lieu) == false)
            return 101;
        else if (stof(du_lieu) < 0)
            return 20; // diem khogn nho hon 0
    }

    return 0; // KHONG CO LOI NAO HET
}

