#pragma once
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include <fstream>
#include "../algorithms/algorithms.h"
#include "../struct.h"
#include "../basic/basic_function.h"

// HAM LOAD DU LIEU TU FILE
Course loadCourseInfo(FILE *filein);
PTRMH loadCourseList(char *filename);
Student loadStudentInfo(FILE *filein);
PTRSV loadStudentList(char *filename);
PTRLH loadClassList(char *filename);
PTRDK loadRegisStudentList(FILE *filein);
Credit *loadCreditClassInfo(FILE *filein);
LIST_LTC loadCreditClassList(char *filename);
std::map<std::string, std::string> loadMapMSSV_dsLTC(char *filename);
std::map<int, char *> loadMapMaLTC_MaMH(char *filename);

// HAM luu THONG TIN vao file
void xuatDanhSachSinhVien_File_Txt(PTRSV FirstSv, char File_Name[maxLengthString]);

void xuatDanhSachMonHoc_LNR_File_Txt(PTRMH Tree_monhoc, FILE *fileout);
void xuatDanhSachMonHoc_File_Txt(PTRMH Tree_monhoc, char File_Name[50]);

void xuatDanhSachSVDK_File_Txt(PTRDK First_DSSVDK, FILE *fileout);
void xuatThongTinLopTinChi_File_Txt(Credit *loptinchi, FILE *fileout);
void xuatDanhSachLopTinChi_File_Txt(LIST_LTC dsLTC, char File_Name[maxLengthString]);

void xuatDanhSachSinhVien_File_Csv(PTRSV FirstSv, char File_Name[maxLengthString]);
void xuatDanhSachMonHoc_LNR_File_Csv(PTRMH Tree_monhoc, FILE *fileout);
void xuatDanhSachMonHoc_File_Csv(PTRMH Tree_monhoc, char File_Name[50]);

void saveMapMaLTC_MaMH(std::map<int, char *> anhXaLTC_MH, char *filename);
void saveMapMSSV_dsLTC(std::map<std::string, std::string> anhXaMSSV_dsLTC, char *filename);

// ham thao tac data bo nho trong chuong trinh
void leftRotate(PTRMH &tree);
void rightRotate(PTRMH &tree);
int getTreeHeight(PTRMH tree);
// void addCourseToList(PTRMH &treeCourse, Course cource);
void addCourseToList(PTRMH &Tree_monhoc, Course monhoc);
void addStudentToList(PTRSV &FirstSV, Student sv);
void addNewClassID(PTRLH &FirstLH, char maLopHoc[ClassID_Length]);
void addStudentToRegisList(PTRDK &First_DSSVDK, Registration dangky);

void addCourseByName(PTRMH &Tree_monhoc, Course monhoc);
void saoChepMonHocTheoTen(PTRMH treeMH, PTRMH &newTree);

// xu ly nghiep vu chuong trinh
void mappingMaLTC_MaMH(std::map<int, char *> &anhXaLTC_MH, int maLTC, char *maMH);
void mappingMSSV_dsLTC(char *mssv, Credit *loptinchi, LIST_LTC listLTC, std::map<std::string, std::string> &anhXaMSSV_dsLTC, std::map<int, char *> dsAnhXaMaLTCMaMH);

void updateStudentHighestScore(LIST_LTC dsLTC, std::map<std::string, std::string> &anhXaMSSV_dsLTC, std::map<int, char *> anhXaMaLTCMaMH);

// load data from file

// nhap thong tin tung mon hoc tu file
Course loadCourseInfo(FILE *filein)
{
    Course monhoc;

    char temp_line[maxLengthString]; // chuaws chuoi nhap tu file ddeer xu ly
    fgets(monhoc.courceCode, maxLengthString, filein);
    fgets(monhoc.courceName, maxLengthString, filein);
    fgets(temp_line, maxLengthString, filein);

    sscanf(temp_line, "%d %d", &monhoc.STCLT, &monhoc.STCTH);

    loaiBoDauXuongDong(monhoc.courceCode);
    loaiBoDauXuongDong(monhoc.courceName);

    return monhoc;
}
// nhap danh sach mon hoc tu file vao chuong trinh
PTRMH loadCourseList(char *File_Name)
{
    FILE *filein = fopen(File_Name, "r");
    if (filein == NULL)
    {
        std::cout << "Mo file danh sach mon hoc that bai\n";
        return NULL;
    }

    PTRMH treeCourse = NULL;

    Course monhoc;
    int soMonHoc = 0;
    char temp_line[maxLengthString]; // chua chuoi nhap tu file ddeer xu ly

    fgets(temp_line, maxLengthString, filein);
    sscanf(temp_line, "%d", &soMonHoc);

    for (int i = 1; i <= soMonHoc; i++)
    {
        monhoc = loadCourseInfo(filein);
        addCourseToList(treeCourse, monhoc);
    }

    return treeCourse;
}

Student loadStudentInfo(FILE *filein)
{
    Student sinhvien;
    fgets(sinhvien.studentID, maxLengthString, filein);
    fgets(sinhvien.lastName, maxLengthString, filein);
    fgets(sinhvien.firstName, maxLengthString, filein);
    fgets(sinhvien.sex, maxLengthString, filein);
    fgets(sinhvien.classID, maxLengthString, filein);
    fgets(sinhvien.phoneNum, maxLengthString, filein);

    loaiBoDauXuongDong(sinhvien.studentID);
    loaiBoDauXuongDong(sinhvien.lastName);
    loaiBoDauXuongDong(sinhvien.firstName);
    loaiBoDauXuongDong(sinhvien.sex);
    loaiBoDauXuongDong(sinhvien.phoneNum);
    loaiBoDauXuongDong(sinhvien.classID);

    return sinhvien;
}

// nhap danh sach sinh vien tu file vao chuong trinh
PTRSV loadStudentList(char *File_Name)
{
    FILE *filein = NULL;
    filein = fopen(File_Name, "r");
    if (filein == NULL)
    {
        std::cout << "Mo file danh sach sinh vien that bai\n";
        return NULL;
    }

    PTRSV firstStudent = NULL;

    Student sinhvien;
    int soSinhVien = 0;
    char temp_line[maxLengthString]; // chuaws chuoi nhap tu file ddeer xu ly

    fgets(temp_line, maxLengthString, filein); // lay thong tin so luong sinh vien
    sscanf(temp_line, "%d", &soSinhVien);

    for (int i = 1; i <= soSinhVien; i++)
    {
        sinhvien = loadStudentInfo(filein);
        addStudentToList(firstStudent, sinhvien);
    }

    return firstStudent;
}

PTRLH loadClassList(char *File_Name)
{
    FILE *filein = NULL;
    filein = fopen(File_Name, "r");
    if (filein == NULL)
    {
        std::cout << "Mo file ma lop hoc that bai\n";
        return NULL;
    }

    PTRLH firstCourseList = NULL;
    int somaLopHoc = 0;
    char temp_line[maxLengthString]; // chuaws chuoi nhap tu file ddeer xu ly

    fgets(temp_line, maxLengthString, filein); // lay thong tin so luong sinh vien
    sscanf(temp_line, "%d", &somaLopHoc);

    for (int i = 1; i <= somaLopHoc; i++)
    {
        fgets(temp_line, maxLengthString, filein);
        loaiBoDauXuongDong(temp_line);

        addNewClassID(firstCourseList, temp_line);
    }

    return firstCourseList;
}

PTRDK loadRegisStudentList(FILE *filein)
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
        sscanf(temp_line, "%d", &dangky.disable);

        loaiBoDauXuongDong(dangky.studentID);

        addStudentToRegisList(firstRegisStudent, dangky);
    }

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

    fgets(temp_line, maxLengthString, filein);
    sscanf(temp_line, "%d %d %d %d", &creditClass->semester, &creditClass->group, &creditClass->studentMin, &creditClass->studentMax);

    fgets(temp_line, maxLengthString, filein);
    sscanf(temp_line, "%d", &creditClass->enable);

    creditClass->firstListRegister = loadRegisStudentList(filein);
    return creditClass;
}
// Chuc nang: nhap danh sach lop tin chi tu file vao chuong trinh
LIST_LTC loadCreditClassList(char *File_Name)
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

std::map<std::string, std::string> loadMapMSSV_dsLTC(char *filename)
{
    FILE *filein = fopen(filename, "r");
    std::map<std::string, std::string> mapMSSV_dsLTC;

    if (filein == NULL)
    {
        std::cout << "Mo danh sach map MSSV dsLTC that bai\n";
        return mapMSSV_dsLTC;
    }

    char temp_line[maxLengthString];
    char mssv[maxLengthString];
    char dsLTC[maxLengthString];
    int size = 0;

    fgets(temp_line, maxLengthString, filein);
    sscanf(temp_line, "%d", &size);

    for (int i = 0; i < size; i++)
    {
        fgets(mssv, maxLengthString, filein);
        fgets(dsLTC, maxLengthString, filein);
        loaiBoDauXuongDong(mssv);
        loaiBoDauXuongDong(dsLTC);

        mapMSSV_dsLTC[charToString(mssv)] = charToString(dsLTC);
    }

    fclose(filein);
    return mapMSSV_dsLTC;
}

std::map<int, char *> loadMapMaLTC_MaMH(char *filename)
{
    FILE *filein = fopen(filename, "r");
    std::map<int, char *> mapMaLTC_MaMH;

    if (filein == NULL)
    {
        std::cout << "Mo danh sach map MaLTC MaMH that bai\n";
        return mapMaLTC_MaMH;
    }

    char temp_line[maxLengthString];
    int maLTC = 0;
    int size = 0;

    fgets(temp_line, maxLengthString, filein);
    sscanf(temp_line, "%d", &size);

    for (int i = 0; i < size; i++)
    {
        fgets(temp_line, maxLengthString, filein);
        sscanf(temp_line, "%d", &maLTC);
        fgets(temp_line, maxLengthString, filein);
        char *value = new char[CourseCode_Length];
        strcpy(value, temp_line);
        loaiBoDauXuongDong(value);
        mapMaLTC_MaMH[maLTC] = value;
    }

    fclose(filein);
    return mapMaLTC_MaMH;
}

// SAVE DATA
void xuatDanhSachSinhVien_File_Txt(PTRSV FirstSv, char File_Name[maxLengthString])
{
    FILE *fileout = NULL;
    fileout = fopen(File_Name, "w");
    if (fileout == NULL)
    {
        std::cout << "Mo file danh sach sinh vien that bai\n";
        return;
    }

    PTRSV p = FirstSv;
    int so_sinh_vien_DSSV = countLinkedList(FirstSv);

    fprintf(fileout, "%d", so_sinh_vien_DSSV);

    while (p != NULL)
    {

        fputs("\n", fileout);
        fputs(p->student.studentID, fileout);
        fputs("\n", fileout);
        fputs(p->student.lastName, fileout);
        fputs("\n", fileout);
        fputs(p->student.firstName, fileout);
        fputs("\n", fileout);
        fputs(p->student.sex, fileout);
        fputs("\n", fileout);
        fputs(p->student.classID, fileout);
        fputs("\n", fileout);
        fputs(p->student.phoneNum, fileout);

        p = p->next;
    }

    fclose(fileout);
}

void xuatDanhSachMonHoc_LNR_File_Txt(PTRMH treeMH, FILE *fileout)
{
    if (treeMH != NULL)
    {
        xuatDanhSachMonHoc_LNR_File_Txt(treeMH->pLeft, fileout);

        fputs("\n", fileout);
        fputs(treeMH->course.courceCode, fileout);
        fputs("\n", fileout);
        fputs(treeMH->course.courceName, fileout);
        fputs("\n", fileout);
        fprintf(fileout, "%d %d", treeMH->course.STCLT, treeMH->course.STCTH);

        xuatDanhSachMonHoc_LNR_File_Txt(treeMH->pRight, fileout);
    }
}

void xuatDanhSachMonHoc_File_Txt(PTRMH treeMH, char File_Name[50])
{
    FILE *fileout = NULL;
    fileout = fopen(File_Name, "w");
    if (fileout == NULL)
    {
        std::cout << "Luu file danh sach mon hoc that bai";
        return;
    }

    int so_mon_hoc_DSMH = 0;
    count_MH(treeMH, so_mon_hoc_DSMH);

    fprintf(fileout, "%d", so_mon_hoc_DSMH); // in so luong vao file

    xuatDanhSachMonHoc_LNR_File_Txt(treeMH, fileout);

    fclose(fileout);
}

void xuatDanhSachSVDK_File_Txt(PTRDK First_DSSVDK, FILE *fileout)
{

    fprintf(fileout, "%d", countLinkedList(First_DSSVDK));

    PTRDK p = First_DSSVDK;
    while (p != NULL)
    {
        fputs("\n", fileout);
        fputs(p->regis.studentID, fileout);
        fputs("\n", fileout);
        fprintf(fileout, "%0.6f", p->regis.point);
        fputs("\n", fileout);
        fprintf(fileout, "%d", p->regis.disable);
        p = p->next;
    }
}

void xuatThongTinLopTinChi_File_Txt(Credit *loptinchi, FILE *fileout)
{
    fprintf(fileout, "%d", loptinchi->creditCode);
    fputs("\n", fileout);
    fputs(loptinchi->courseCode, fileout);
    fputs("\n", fileout);
    fputs(loptinchi->schoolYear, fileout);
    fputs("\n", fileout);
    fprintf(fileout, "%d %d %d %d", loptinchi->semester, loptinchi->group, loptinchi->studentMin, loptinchi->studentMax);
    fputs("\n", fileout);
    fprintf(fileout, "%d", loptinchi->enable);
    fputs("\n", fileout);

    xuatDanhSachSVDK_File_Txt(loptinchi->firstListRegister, fileout);
}

void xuatDanhSachLopTinChi_File_Txt(LIST_LTC dsLTC, char File_Name[maxLengthString])
{
    FILE *fileout = fopen(File_Name, "w");
    if (fileout == NULL)
    {
        std::cout << "Mo file danh sach lop tin chi that bai\n";
        system("pause");
        return;
    }

    int so_lop_hien_tai_LTC = count_CreditClass(dsLTC);

    fprintf(fileout, "%d %d", so_lop_hien_tai_LTC, dsLTC.currentIndex);

    for (int i = 1; i <= dsLTC.currentIndex; i++)
    {
        if (dsLTC.nodes[i] != NULL)
        {
            fputs("\n", fileout);
            xuatThongTinLopTinChi_File_Txt(dsLTC.nodes[i], fileout);
        }
    }

    fclose(fileout);
}

void xuatDanhSachSinhVien_File_Csv(PTRSV FirstSv, char File_Name[maxLengthString])
{
    FILE *fileout = NULL;
    fileout = fopen(File_Name, "w");
    if (fileout == NULL)
    {
        std::cout << "Mo file danh sach sinh vien that bai\n";
        return;
    }

    PTRSV p = FirstSv;

    fprintf(fileout, "%d\n", countLinkedList(FirstSv));
    fputs("Ma sinh vien,Ho,Ten,Gioi tinh,Ma lop,So dien thoai", fileout);

    while (p != NULL)
    {

        fputs("\n", fileout);

        fputs(p->student.studentID, fileout);
        fputs(",", fileout);
        fputs(p->student.lastName, fileout);
        fputs(",", fileout);
        fputs(p->student.firstName, fileout);
        fputs(",", fileout);
        fputs(p->student.sex, fileout);
        fputs(",", fileout);
        fputs(p->student.classID, fileout);
        fputs(",", fileout);

        fputs(p->student.phoneNum, fileout);

        p = p->next;
    }

    fclose(fileout);
}

void xuatDanhSachMonHoc_LNR_File_Csv(PTRMH treeMH, FILE *fileout)
{
    if (treeMH != NULL)
    {
        xuatDanhSachMonHoc_LNR_File_Csv(treeMH->pLeft, fileout);
        fputs("\n", fileout);

        fputs(treeMH->course.courceCode, fileout);
        fputs(",", fileout);
        fputs(treeMH->course.courceName, fileout);
        fputs(",", fileout);
        fprintf(fileout, "%d,%d", treeMH->course.STCLT, treeMH->course.STCTH);

        xuatDanhSachMonHoc_LNR_File_Csv(treeMH->pRight, fileout);
    }
}

void xuatDanhSachMonHoc_File_Csv(PTRMH treeMH, char File_Name[50])
{
    FILE *fileout = NULL;
    fileout = fopen(File_Name, "w");
    if (fileout == NULL)
    {
        std::cout << "Luu file danh sach mon hoc that bai";
        return;
    }

    int soLuongMonHoc = 0;

    count_MH(treeMH, soLuongMonHoc);         // dem so luong mon hoc
    fprintf(fileout, "%d\n", soLuongMonHoc); // in so luong vao file
    fputs("Ma mon hoc,Ten mon hoc,STCLT,STCTH", fileout);
    xuatDanhSachMonHoc_LNR_File_Csv(treeMH, fileout);

    fclose(fileout);
}

void saveMapMaLTC_MaMH(std::map<int, char *> anhXaLTC_MH, char *filename)
{
    FILE *fileout = NULL;
    fileout = fopen(filename, "w");
    if (fileout == NULL)
    {
        std::cout << "Mo file MappingMaLTC_MaMH that bai\n";
        return;
    }

    fprintf(fileout, "%d", anhXaLTC_MH.size());

    for (auto it = anhXaLTC_MH.begin(); it != anhXaLTC_MH.end(); it++)
    {
        fprintf(fileout, "\n%d", it->first);
        fprintf(fileout, "\n%s", it->second);
    }
    fclose(fileout);
}

void saveMapMSSV_dsLTC(std::map<std::string, std::string> anhXaMSSV_dsLTC, char *filename)
{
    FILE *fileout = NULL;
    fileout = fopen(filename, "w");
    if (fileout == NULL)
    {
        std::cout << "Mo file MappingMSSV_dsLTC that bai\n";
        return;
    }
    fprintf(fileout, "%d", anhXaMSSV_dsLTC.size());

    for (auto it = anhXaMSSV_dsLTC.begin(); it != anhXaMSSV_dsLTC.end(); it++)
    {
        fprintf(fileout, "\n%s", it->first.c_str());
        fprintf(fileout, "\n%s", it->second.c_str());
    }
    fclose(fileout);
}

// thao tac data bo nho trong

void leftRotate(PTRMH &tree)
{ // chuc nang: xoay cay sang trai
    if (tree == NULL)
        return;

    PTRMH x = tree->pRight;
    tree->pRight = x->pLeft;
    x->pLeft = tree;
    tree = x;
}
void rightRotate(PTRMH &tree)
{ // chuc nang: xoay cay sang phai

    if (tree == NULL)
        return;

    PTRMH x = tree->pLeft;
    tree->pLeft = x->pRight;
    x->pRight = tree;
    tree = x;
}

int getTreeHeight(PTRMH tree)
{ // chuc nang: tinh chieu cao cua node
    if (tree != NULL)
    {
        int left = getTreeHeight(tree->pLeft) + 1;
        int right = getTreeHeight(tree->pRight) + 1;

        return left > right ? left : right;
    }
}

void addCourseToList(PTRMH &treeMH, Course monhoc)
{
    // strcmp(monhoc.MAMH, treeMH->monhoc.MAMH) < 0

    if (treeMH == NULL)
    {
        PTRMH p = new CourseNode;

        p->course = monhoc;
        p->pLeft = NULL;
        p->pRight = NULL;

        treeMH = p;
    }
    else
    {
        if (strcmp(monhoc.courceCode, treeMH->course.courceCode) < 0)
        {
            addCourseToList(treeMH->pLeft, monhoc);
        }
        else if (strcmp(monhoc.courceCode, treeMH->course.courceCode) > 0)
        {
            addCourseToList(treeMH->pRight, monhoc);
        }
    }

    int Balance_Value = getTreeHeight(treeMH->pLeft) - getTreeHeight(treeMH->pRight);

    // Xoay cay de can bang cay

    // TH1: left left
    if (Balance_Value > 1 && strcmp(monhoc.courceCode, treeMH->course.courceCode) < 0)
    {
        rightRotate(treeMH);
        return;
    }
    // TH2: right right
    else if (Balance_Value < -1 && strcmp(monhoc.courceCode, treeMH->course.courceCode) > 0)
    {
        leftRotate(treeMH);
        return;
    }
    // TH3: left right
    else if (Balance_Value > 1 && strcmp(monhoc.courceCode, treeMH->course.courceCode) > 0)
    {
        leftRotate(treeMH->pLeft);
        rightRotate(treeMH);
        return;
    }
    // TH4: right left
    else if (Balance_Value < -1 && strcmp(monhoc.courceCode, treeMH->course.courceCode) < 0)
    {
        rightRotate(treeMH->pRight);
        leftRotate(treeMH);
        return;
    }
}

void addStudentToList(PTRSV &FirstSV, Student sv)
{
    PTRSV p = new StudentNode;
    PTRSV q = NULL;
    p->student = sv;

    if (FirstSV == NULL)
    {
        FirstSV = p;
        FirstSV->next = NULL;
    }
    else if (FirstSV->next == NULL)
    { // co mot phan tu
        if (strcmp(p->student.studentID, FirstSV->student.studentID) < 0)
        {
            p->next = FirstSV;
            FirstSV = p;
        }
        else if (strcmp(p->student.studentID, FirstSV->student.studentID) > 0)
        {
            FirstSV->next = p;
            p->next = NULL;
        }
        return; // ket thuc thuat toan
    }
    else
    { // truong hop danh sach da co it nhat 2 phan tu

        if (strcmp(p->student.studentID, FirstSV->student.studentID) < 0)
        {
            p->next = FirstSV;
            FirstSV = p;
            return;
        }

        q = FirstSV;

        while (q->next != NULL)
        {
            if (strcmp(p->student.studentID, q->student.studentID) > 0 && strcmp(p->student.studentID, q->next->student.studentID) < 0)
            {
                p->next = q->next;
                q->next = p;
                return; // ket thuc thuat toan
            }
            q = q->next;
        }

        // TH q da di chuyen ve cuoi danh sach
        q->next = p;
        p->next = NULL;
    }
}

void addNewClassID(PTRLH &FirstLH, char maLopHoc[ClassID_Length])
{
    PTRLH p = new ClassNode;
    PTRLH q = NULL;
    strcpy(p->classID, maLopHoc);

    if (FirstLH == NULL)
    {
        FirstLH = p;
        FirstLH->next = NULL;
    }
    else if (FirstLH->next == NULL)
    { // co mot phan tu
        if (strcmp(p->classID, FirstLH->classID) < 0)
        {
            p->next = FirstLH;
            FirstLH = p;
        }
        else if (strcmp(p->classID, FirstLH->classID) > 0)
        {
            FirstLH->next = p;
            p->next = NULL;
        }
        return; // ket thuc thuat toan
    }
    else
    { // truong hop danh sach da co it nhat 2 phan tu

        if (strcmp(p->classID, FirstLH->classID) < 0)
        {
            p->next = FirstLH;
            FirstLH = p;
            return;
        }

        q = FirstLH;

        while (q->next != NULL)
        {
            if (strcmp(p->classID, q->classID) > 0 && strcmp(p->classID, q->next->classID) < 0)
            {
                p->next = q->next;
                q->next = p;
                return; // ket thuc thuat toan
            }
            q = q->next;
        }

        // TH q da di chuyen ve cuoi danh sach
        q->next = p;
        p->next = NULL;
    }
}

// chuc nang: them thong tin dang ky vao DSLKD danh dang ky lop tin chi co sap xep
void addStudentToRegisList(PTRDK &First_DSSVDK, Registration dangky)
{
    PTRDK p = new RegisNode;
    PTRDK q;
    p->regis = dangky;

    if (First_DSSVDK == NULL)
    {
        First_DSSVDK = p;
        First_DSSVDK->next = NULL;
    }
    else if (First_DSSVDK->next == NULL)
    {

        if (strcmp(p->regis.studentID, First_DSSVDK->regis.studentID) < 0)
        {
            p->next = First_DSSVDK;
            First_DSSVDK = p;
        }
        else if (strcmp(p->regis.studentID, First_DSSVDK->regis.studentID) > 0)
        {
            First_DSSVDK->next = p;
            p->next = NULL;
        }
    }
    else
    { // truong hop danh sach co it nhat 2 phan tu

        if (strcmp(p->regis.studentID, First_DSSVDK->regis.studentID) < 0)
        {
            p->next = First_DSSVDK;
            First_DSSVDK = p;
            return;
        }

        q = First_DSSVDK;

        while (q->next != NULL)
        {
            if (strcmp(p->regis.studentID, q->regis.studentID) > 0 && strcmp(p->regis.studentID, q->next->regis.studentID) < 0)
            {
                p->next = q->next;
                q->next = p;
                return; // ket thuc thuat toan
            }
            q = q->next;
        }
        // TH q da di chuyen ve cuoi danh sach
        p->next = NULL;
        q->next = p;
    }
}

void addCourseByName(PTRMH &treeMH, Course monhoc)
{
    if (treeMH == NULL)
    {
        PTRMH p = new CourseNode;

        p->course = monhoc;
        p->pLeft = NULL;
        p->pRight = NULL;

        treeMH = p;
    }
    else
    {
        if (strcmp(monhoc.courceName, treeMH->course.courceName) < 0)
            addCourseByName(treeMH->pLeft, monhoc);

        else
            addCourseByName(treeMH->pRight, monhoc);
    }
}

void saoChepMonHocTheoTen(PTRMH treeMH, PTRMH &newTree)
{
    if (treeMH != NULL)
    {
        addCourseByName(newTree, treeMH->course);
        saoChepMonHocTheoTen(treeMH->pLeft, newTree);
        saoChepMonHocTheoTen(treeMH->pRight, newTree);
    }
}

// xu ly nghiep vu chuong trinh

// dsAnhXaMaLTCMaMH la danh sach lop tin chi ung voi maMH dang xet
void mappingMSSV_dsLTC(char *mssv, Credit *loptinchi, LIST_LTC listLTC, std::map<std::string, std::string> &anhXaMSSV_dsLTC, std::map<int, char *> dsAnhXaMaLTCMaMH)
{
    auto it = anhXaMSSV_dsLTC.find(charToString(mssv));

    if (it == anhXaMSSV_dsLTC.end())
    {
        anhXaMSSV_dsLTC[charToString(mssv)] = std::to_string(loptinchi->creditCode) + ",";
    }
    else
    {
        std::string dsLTC = it->second;

        if (dsLTC.find(std::to_string(loptinchi->creditCode)) != std::string::npos)
            return;

        // kiem tra xem dsLTC cua sinh vien co chua ma lop tin chi cua mon hoc dang xet khong
        // duyet dsAnhXaMaLTCMaMH
        for (auto &x : dsAnhXaMaLTCMaMH)
        {
            // khac lop tim chi nhung cung ma mon hoc
            if (x.first != loptinchi->creditCode && strcmp(x.second, loptinchi->courseCode) == 0)
            {
                size_t index = dsLTC.find(std::to_string(x.first));
                // neu tim thay va maLTC duoc tim thay khac voi maLTC sinh vien dang xet => hoc lai
                if ((index != std::string::npos))
                {
                    // so sanh diem cua 2 lop tin chi
                    PTRDK nodeDK1 = timSinhVien_DSSVDK(listLTC.nodes[x.first]->firstListRegister, mssv);
                    PTRDK nodeDK2 = timSinhVien_DSSVDK(loptinchi->firstListRegister, mssv);

                    if (nodeDK2->regis.point > nodeDK1->regis.point)
                    {
                        it->second.replace(index, std::to_string(loptinchi->creditCode).length(), std::to_string(loptinchi->creditCode));
                        anhXaMSSV_dsLTC[charToString(mssv)] = it->second;
                    }
                }
            }
        }

        // khong tim thay ma lop tin chi cua mon hoc dang xet trong dsLTC cua sinh vien => chua hoc
        it->second += std::to_string(loptinchi->creditCode) + ",";
    }

    // system("pause");
}

void mappingMaLTC_MaMH(std::map<int, char *> &anhXaLTC_MH, int maLTC, char *maMH)
{
    auto it = anhXaLTC_MH.find(maLTC);

    if (it == anhXaLTC_MH.end())
    {
        anhXaLTC_MH[maLTC] = maMH;
    }
}

void updateStudentHighestScore(LIST_LTC dsLTC, std::map<std::string, std::string> &anhXaMSSV_dsLTC, std::map<int, char *> anhXaMaLTCMaMH)
{
    PTRDK p = NULL;

    for (int i = 1; i <= dsLTC.currentIndex; i++)
    {
        if (dsLTC.nodes[i] != NULL)
        {
            p = dsLTC.nodes[i]->firstListRegister;

            while (p != NULL)
            {
                // if (strcmp(p->regis.studentID, "N20DCPT044") == 0)
                mappingMSSV_dsLTC(p->regis.studentID, dsLTC.nodes[i], dsLTC, anhXaMSSV_dsLTC, anhXaMaLTCMaMH);
                // std::cout<<p->regis.studentID<<"  "<<anhXaMSSV_dsLTC[charToString(p->regis.studentID)]<<std::endl;
                p = p->next;
            }
        }
    }
}
