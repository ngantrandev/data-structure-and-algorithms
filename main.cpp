#include <iostream>
#include <map>
// #include "./src/lib/view/menu.h"
#include "src/lib/struct.h"
#include "src/lib/view/menu.h"
#include "./src/lib/view/UI_function.h"
#include "src/lib/data_manager/data_manager.h"
#include "src/lib/algorithms/my_sort.h"
#include "src/lib/algorithms/my_delete.h"
#include <typeinfo>

std::map<int, char *> anhXaLTC_MH;
std::map<char *, std::string> anhXaMSSV_dsLTC;
PTRSV firstSV;
PTRMH treeMH;
LIST_LTC dsLTC;

PTRDK loadRegisStudentList(FILE *filein, Credit *loptinchi)
{
    PTRDK firstRegisStudent = NULL;
    char temp_line[maxLengthString]; // chuaws chuoi nhap tu file ddeer xu ly
    int soSVDK = 0;
    Registration dangky;

    fgets(temp_line, maxLengthString, filein);
    sscanf(temp_line, "%d", &soSVDK);

    for (int i = 1; i <= soSVDK; i++)
    {
        fgets(dangky.studentID, maxLengthString, filein);

        fgets(temp_line, maxLengthString, filein); // nhap dong chua DIEM
        sscanf(temp_line, "%f", &dangky.point);

        fgets(temp_line, maxLengthString, filein); // nhap dong chua bien TRUE/FALSE ( ma hoa owr dang 0 / 1);
        sscanf(temp_line, "%d", &dangky.isRegistered);

        loaiBoDauXuongDong(dangky.studentID);
        std::cout << "Size: " << anhXaMSSV_dsLTC.size() << std::endl;
        mappingMSSV_dsLTC(dangky.studentID, loptinchi, dsLTC, anhXaMSSV_dsLTC, anhXaLTC_MH);

        addStudentToRegisList(firstRegisStudent, dangky);
    }
    system("pause");

    return firstRegisStudent;
}

Credit *loadCreditClassInfo(FILE *filein)
{
    Credit *creditClass = new Credit;
    char temp_line[maxLengthString];

    fgets(temp_line, maxLengthString, filein);
    sscanf(temp_line, "%d", &creditClass->creditCode);

    fgets(creditClass->courseCode, maxLengthString, filein);
    fgets(creditClass->schoolYear, maxLengthString, filein);
    loaiBoDauXuongDong(creditClass->courseCode);
    loaiBoDauXuongDong(creditClass->schoolYear);

    // mappingMaLTC_MaMH(anhXaLTC_MH, creditClass->creditCode, creditClass->courseCode);

    fgets(temp_line, maxLengthString, filein);
    sscanf(temp_line, "%d %d %d %d", &creditClass->semester, &creditClass->group, &creditClass->studentMin, &creditClass->studentMax);

    fgets(temp_line, maxLengthString, filein);
    sscanf(temp_line, "%d", &creditClass->enable);

    std::cout << creditClass->creditCode << std::endl;
    creditClass->firstListRegister = loadRegisStudentList(filein, creditClass);
    return creditClass;
}
// Chuc nang: nhap danh sach lop tin chi tu file vao chuong trinh
LIST_LTC loadStudentCreditClassList(char *File_Name)
{
    FILE *filein = fopen(File_Name, "r");
    LIST_LTC creditClassList;

    if (filein != NULL)
    {
        char temp_line[maxLengthString];
        int index = 0;
        int size = 0;

        fgets(temp_line, maxLengthString, filein);
        sscanf(temp_line, "%d %d", &size, &creditClassList.currentIndex);

        for (int i = 1; i <= size; i++)
        {
            Credit *loptinchi = NULL; // cap phat bo nho cho node moi
            loptinchi = loadCreditClassInfo(filein);
            index = loptinchi->creditCode; // index store credit code
            creditClassList.nodes[index] = loptinchi;
        }

        return creditClassList;
    }
    else
    {

        std::cout << "Mo file danh sach lop tin chi that bai\n";
        return creditClassList;
    }
}



int main()
{

    char tenfile[] = "./data/txt_file/danh_sach_sinh_vien.txt";
    char tenfile2[] = "./data/txt_file/danh_sach_mon_hoc.txt";
    char tenfile3[] = "./data/txt_file/danh_sach_lop_tin_chi.txt";
    char tenfile4[] = "./data/txt_file/map_maLTC_maMH.txt";
    char tenfile5[] = "./data/txt_file/map_MSSV_dsLTC.txt";
    // SetWindowSize(1000, 1000);
    // SetScreenBufferSize(1000, 1000);
    // // ShowScrollBar();///
    // HienThanhCuon(TRUE);
    // firstSV = loadStudentList(tenfile);
    // treeMH = loadCourseList(tenfile2);
    // dsLTC = loadStudentCreditClassList(tenfile3);

    std::vector<int> vec{10, 20, 30, 40};

    // Print Original Vector
    std::cout << "Original vector :";

    for (int i = 0; i < vec.size(); i++)
        std::cout << " " << vec[i];

    // Element to be searched
    int ser = 30;

    // std::find function call
    auto it = std::find(vec.begin(),
                        vec.end(), ser);
    if (it != vec.end())
    {
        std::cout << "Element " << ser << " found at position : ";
        std::cout << it - vec.begin() << " (counting from zero) \n";
        std::cout << typeid(it).name();
    }
    else
        std::cout << "Element not found.\n\n";

    getch();
}
