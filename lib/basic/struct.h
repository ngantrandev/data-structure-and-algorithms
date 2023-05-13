#pragma once
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string>

const int MAXSIZE = 10000;
const int MAXMONHOC = 2000;
const int MAXLTC = 10000; // so lop tin chi toi da
const int Student_ID_Length = 25;
const int First_Name_Length = 25;
const int Ten_Length = 25;
const int SEX_Length = 25;
const int PhoneNum_Length = 25;
const int ClassID_Length = 25;
const int CouseCode_Length = 25;
const int CouseName_Length = 25;
const int SchoolYear_Length = 25;

/// <summary>
/// define course infomation
/// </summary>
struct Course
{
    char courceCode[CouseCode_Length];
    char courceName[CouseName_Length];
    int STCLT; // so tin chi ly thuyet
    int STCTH; // so tin chi thuc hanh
};
struct CourseNode
{
    Course course;             // mon hoc
    struct CourseNode *pLeft;  // node ben trai cua node dang xet
    struct CourseNode *pRight; // node ben phai cua node dang xet
};
typedef CourseNode *PTRMH; // mon hoc

/// <summary>
/// define student infomation
/// </summary>
struct Student
{
    char studentID[Student_ID_Length]; // ma sinh vien
    char firstName[First_Name_Length]; // ho sinh vien
    char name[Ten_Length];             // ten sinh vien
    char sex[SEX_Length];              // gioi tinh
    char phoneNum[PhoneNum_Length];    // so dien thoai
    char classID[ClassID_Length];      // ma lop hoc
};
struct StudentNode
{
    Student student;
    struct StudentNode *next;
};
typedef StudentNode *PTRSV;

/// <summary>
/// define registration infomation
/// </summary>
struct Registration
{
    char studentID[Student_ID_Length] = "Unknow";
    float point = 0;
    bool isRegistered = false;
};

struct RegisNode
{
    Registration regis;
    struct RegisNode *next;
};
typedef RegisNode *PTRDK;

/// <summary>
/// define credit class infomation
/// </summary>
struct Credit
{
    int creditCode = 0;                            // ma lop tin chi
    char courseCode[CouseCode_Length] = "Unknow";  // ma mon hoc
    char schoolYear[SchoolYear_Length] = "Unknow"; // khoa hoc
    int semester = 0, group = 0;                   //
    int studentMin = 0, studentMax = 0;            // so sinh vien lon nhat - nho nhat
    bool enable = false;
    PTRDK firstListRegister = NULL; // con tro danh sach sinh vien dang ky lop tin chi
};
/// <summary>
/// define list of credit
/// </summary>
struct LIST_LTC
{
    Credit *nodes[MAXLTC] = {NULL};
    int currentIndex = 0;
};

/// <summary>
/// define class infomation
/// </summary>
struct ClassNode
{
    char classID[ClassID_Length] = "";
    struct ClassNode *next;
};
typedef ClassNode *PTRLH;

struct Student_Point
{
    PTRDK ptrDK = NULL;
    std::string point = "10";
};

struct StudentListNode
{
    PTRSV ptrSV = NULL;
    float pointSum = 0; // duoc tinh bang tong cua DIEM*(STCLT + STCTH) cac mon trong nien khoa
    int creditSum = 0;
};
typedef StudentListNode *PTRDSSV;