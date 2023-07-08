#include <iostream>
#include <map>

// #include "src/lib/view/my_show.h"
#include "src/lib/data_manager/data_manager.h"
#include "src/lib/view/input.h"
#include "src/lib/view/drawBoard.h"
#include "src/lib/algorithms/algorithms.h"
#include "src/lib/view/my_show.h"
#include <stack>

std::map<int, char *> anhXaLTC_MH;
std::map<char *, std::string> anhXaMSSV_dsLTC;
PTRSV firstSV = NULL;
PTRMH treeMH = NULL;
LIST_LTC dsLTC;
PTRLH firstLH = NULL;

int main()
{
    int out = 0;
    int pos = 0;

    char ltcFile[] = "./data/txt_file/danh_sach_lop_tin_chi.txt";
    char svFile[] = "./data/txt_file/danh_sach_sinh_vien.txt";
    char mhFile[] = "./data/txt_file/danh_sach_mon_hoc.txt";
    char lhFile[] = "./data/txt_file/danh_sach_ma_lop_hoc.txt";
    treeMH = loadCourseList(mhFile);
    dsLTC = loadCreditClassList(ltcFile);
    firstSV = loadStudentList(svFile);
    firstLH = loadClassList(lhFile);

    char a[100] = "N20DCPT001";
    char b[100] = "N20DCPT002";
    char c[100] = "N20DCPT003";
    char d[100] = "N20DCPT004";

    // anhXaMSSV_dsLTC[a] = "LTC1,LTC2,LTC3";
    // anhXaMSSV_dsLTC[b] = "LTC1,LTC2,LTC3";
    // anhXaMSSV_dsLTC[c] = "LTC1,LTC2,LTC3";
    // anhXaMSSV_dsLTC[d] = "LTC1,LTC2,LTC3";

    // mappingMSSV_dsLTC(a, dsLTC.nodes[1], dsLTC, anhXaMSSV_dsLTC, anhXaLTC_MH);
    // mappingMSSV_dsLTC(b, dsLTC.nodes[1], dsLTC, anhXaMSSV_dsLTC, anhXaLTC_MH);
    // mappingMSSV_dsLTC(c, dsLTC.nodes[1], dsLTC, anhXaMSSV_dsLTC, anhXaLTC_MH);
    // mappingMSSV_dsLTC(d, dsLTC.nodes[1], dsLTC, anhXaMSSV_dsLTC, anhXaLTC_MH);

    // // getch();
    // PTRDK p = NULL;
    // for (int i = 1; i <= dsLTC.currentIndex; i++)
    // {
    //     if (dsLTC.nodes[i] != NULL)
    //     {
    //         mappingMaLTC_MaMH(anhXaLTC_MH, i, dsLTC.nodes[i]->courseCode);
    //     }
    // }

    anhXaMSSV_dsLTC= loadMapMSSV_dsLTC(fileMapMSSV_dsLTC);
    anhXaLTC_MH = loadMapMaLTC_MaMH(fileMapMaLTC_maMH);

    for (auto it = anhXaMSSV_dsLTC.begin(); it != anhXaMSSV_dsLTC.end(); it++)
    {
        std::cout << it->first << " " << it->second << std::endl;
    }
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "\n";

    for (auto it = anhXaLTC_MH.begin(); it != anhXaLTC_MH.end(); it++)
    {
        std::cout << it->first << " " << it->second << std::endl;
    }

    getch();

    while (true)
    {
        SetColor("WHITE");
        ShowCur(0);
        out = menu(30, 4, menu_chinh, 14, pos);
        // pos = 11;
        ShowCur(1);

        if (out == 1)
        {
            break;
        }

        if (pos == 0) // cau a
        {
            capNhatLopTinChi_User(30, 10, dsLTC, treeMH);
        }

        else if (pos == 1) // cau b
        {
            inDanhSachSinhVienDangKy(30, 10, firstSV, dsLTC);
        }
        else if (pos == 2) // cau c
        {
            capNhatSinhVienLopHoc(30, 10, firstSV);
        }
        else if (pos == 3) // cau d
        {
            inDanhSachSinhVienTheoTen(30, 10, firstSV, firstLH);
        }
        else if (pos == 4) // cau e
        {
            capNhatDanhSachMonHoc_User(treeMH, 30, 10);
        }
        else if (pos == 5) // cau f
        {
            inDanhSachMonHocTheoTen(30, 10, treeMH);
        }
        else if (pos == 6) // cau g
        {
            dangKyLopTinChi(30, 10, dsLTC, treeMH, firstSV);
        }
        else if (pos == 7) // cau h
        {
            huyLopTinChiKhongDuDieuKien(30, 10, dsLTC);
        }
        else if (pos == 8) // cau i
        {
            nhapDiemLopTinChi(30, 10, firstSV, dsLTC);
        }
        else if (pos == 9) // cau j
        {
            inBangDiemLopTinChi(firstSV, dsLTC);
        }
        else if (pos == 10) // cau k
        {
            inBangDiemTrungBinhLopHoc(20, 10, firstSV, firstLH, treeMH, dsLTC, anhXaMSSV_dsLTC);
        }
        else if (pos == 11) // cau l
        {
            // in bang diem tong ket
            ShowCur(0);
            fillFinalPointBoard(10, 10, dsLTC, firstSV, treeMH, anhXaMSSV_dsLTC);
            ShowCur(1);
        }
        else if (pos == 12) // xuat thong tin
        {
            int pos = 0;
            int out = 0;

            while (true)
            {
                out = menu(30, 10, show_file, 3, pos);
                if (out == 1)
                {
                    break;
                }

                if (pos == 0)
                { // xuat danh sach lop tin chi
                    fillCreditClassBoard(15, 10, dsLTC);
                }
                else if (pos == 1)
                { // xuat danh sach sinh vien
                    fillStudentInfoBoard(firstSV, 10, 10);
                }
                else if (pos == 2)
                { // xuat danh sach mon hoc
                    std::vector<PTRMH> dsMonhoc;
                    getListTreeNode(treeMH, dsMonhoc);
                    fillCourseInfoBoard(20, 10, dsMonhoc);
                }
            }
        }
        else if (pos == 13)
        {
            if (XacNhan(30, 10, "XAC NHAN LUU TIEN TRINH") == "YES")
            {
                // xuatDanhSachSinhVien_File_Txt(firstSV, fileDsSinhvien);
                // xuatDanhSachMonHoc_File_Txt(treeMH, fileDsMonhoc);
                // xuatDanhSachLopTinChi_File_Txt(dsLTC, fileDsLTC);
                saveMapMSSV_dsLTC(anhXaMSSV_dsLTC, fileMapMSSV_dsLTC);
                saveMapMaLTC_MaMH(anhXaLTC_MH, fileMapMaLTC_maMH);
            }
        }
    }

    return 0;
}

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