#pragma once
#include <string>
#include "config.h"

/// <summary>
/// define course infomation
/// </summary>
struct Course
{
    char courceCode[CourseCode_Length] = "";
    char courceName[CourseName_Length] = "";
    int STCLT = 0; // so tin chi ly thuyet
    int STCTH = 0; // so tin chi thuc hanh
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
    char studentID[Student_ID_Length] = ""; // ma sinh vien
    char lastName[First_Name_Length] = "";  // ho sinh vien
    char firstName[Ten_Length] = "";        // ten sinh vien
    char sex[SEX_Length] = "";              // gioi tinh
    char phoneNum[PhoneNum_Length] = "";    // so dien thoai
    char classID[ClassID_Length] = "";      // ma lop hoc
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
    char studentID[Student_ID_Length] = "";
    float point = 0;
    bool disable = false;
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
    int creditCode = 0;                      // ma lop tin chi
    char courseCode[CourseCode_Length] = "";  // ma mon hoc
    char schoolYear[SchoolYear_Length] = ""; // khoa hoc
    int semester = 0, group = 0;             //
    int studentMin = 0, studentMax = 0;      // so sinh vien lon nhat - nho nhat
    bool disable = false;
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
    std::string point = "0";
};
