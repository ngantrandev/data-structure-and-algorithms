#pragma once
#include <iostream>
#include "../basic/basic_function.h"

// check error
std::string checkError(std::string input, std::string dataType);

// count node
int count_DaDangKy(PTRDK first);
void count_MH(PTRMH Tree_monhoc, int &soLuongMonHoc);
int count_CreditClass(LIST_LTC dsLTC);

// delete node
void timNodeThayThe(PTRMH &X, PTRMH &Y);
void deleteCource(PTRMH &treeMH, char *maMH);
void deleteStudentFromRegistedList(PTRDK &First_DSSVDK, PTRDK &dangky);
void deleteStudentFromStudentList(PTRSV &first, PTRSV &student);
void deleteCourceList(PTRMH &treeMH);

// HAM TIM KIEM
PTRSV timSinhVien_DSSV(PTRSV FirstSV, char *MASV);
PTRSV timSinhVien_TheoMaLopHoc(PTRSV FirstSV, char *MASV, char *maLopHoc);
PTRDK timSinhVien_DSSVDK(PTRDK First_DSSVDK, char *MASV);
PTRMH timMonHocTheoMa(PTRMH tree, char *MAMH);
// PTRMH timMonHocTheoTen(PTRMH tree, char TENMH[CouseCode_Length]);
PTRLH timLopHoc(PTRLH FirstLH, char *maLopHoc);
Credit *timLopTinChi_theoMAMH(LIST_LTC dsLTC, char *maMH);
Credit *timLopTinChi_theoInfo(LIST_LTC dsLTC, char *nienkhoa, int hocky, int nhom, char *maMonHoc);
Credit *timLopTinChi_theoMAMH_NIENKHOA(LIST_LTC dsLTC, char *maMH, char *nienkhoa);

// HAM SAP XEP
void sapXepDanhSachSinhVienTheoTen_Ho_SelectionSort(PTRSV &FirstSV);

// check error
std::string checkError(std::string input, std::string dataType)
{
    /*
        data type: FLOAT, INTERGER
    */
    if (dataType != "ACCEPT_EMPTY" && input.length() == 0)
        return "EMPTY INPUT";

    if (dataType == "FLOAT")
    {
        if (IsFloatNumber(input) == false)
            return "NONE FLOAT";
        else
            return "NONE";
    }
    else if (dataType == "INTEGER")
    {
        if (IsIntNumber(input) == false)
            return "NONE INTERGER";
        else
            return "NONE";
    }

    return "NONE";
}

// count node
template <typename T>
int countLinkedList(T First)
{
    int count = 0;
    T p = First;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}

int count_DaDangKy(PTRDK first)
{ // chuc nang: dem so luong SINH VIEN DANG KY
    int count = 0;
    PTRDK p = first;
    while (p != NULL)
    {
        if (p->regis.isRegistered == false)
            count++;
        p = p->next;
    }
    return count;
}

void count_MH(PTRMH Tree_monhoc, int &soLuongMonHoc)
{
    if (Tree_monhoc != NULL)
    {
        soLuongMonHoc++;
        count_MH(Tree_monhoc->pLeft, soLuongMonHoc);
        count_MH(Tree_monhoc->pRight, soLuongMonHoc);
    }
}

int count_CreditClass(LIST_LTC dsLTC)
{
    int count = 0;
    for (int i = 0; i < dsLTC.currentIndex; i++)
    {
        if (dsLTC.nodes[i] != NULL)
            count++;
    }
    return count;
}

//=================================
// HAM XOA
//=================================
template <typename T>
void deleteLinkedList(T &first)
{
    T p = NULL;
    while (first != NULL)
    {
        p = first;
        first = first->next;
        delete p;
    }
    first = NULL;
}

void timNodeThayThe(PTRMH &X, PTRMH &Y)
{ // dung de xoa node trong cay nhi phan
    if (Y->pLeft != NULL)
    {
        timNodeThayThe(X, Y->pLeft);
    }
    else
    {
        X->course = Y->course;
        X = Y;
        Y = Y->pRight;
    }
}
void deleteCource(PTRMH &treeMH, char *maMH)
{
    if (treeMH == NULL)
        return;

    if (strcmp(treeMH->course.courceCode, maMH) < 0)
        deleteCource(treeMH->pRight, maMH);
    else if (strcmp(treeMH->course.courceCode, maMH) > 0)
        deleteCource(treeMH->pLeft, maMH);

    else
    {
        PTRMH root = treeMH;

        if (treeMH->pLeft == NULL)
            treeMH = treeMH->pRight;
        else if (treeMH->pRight == NULL)
            treeMH = treeMH->pLeft;
        else
        {
            timNodeThayThe(root, treeMH->pRight);
        }

        delete root;
    }
}
void deleteStudentFromRegistedList(PTRDK &First_DSSVDK, PTRDK &dangky)
{
    if (dangky == First_DSSVDK)
    {
        PTRDK p = First_DSSVDK;
        First_DSSVDK = First_DSSVDK->next;
        delete p;
    }

    else
    {
        PTRDK p = First_DSSVDK;
        while (p->next != dangky)
            p = p->next;
        p->next = dangky->next;
        delete dangky;
        dangky = NULL;
    }
}
void deleteStudentFromStudentList(PTRSV &first, PTRSV &student)
{
    if (student == first)
    {
        PTRSV p = first;
        first = first->next;
        delete p;
    }

    else
    {
        PTRSV p = first;
        while (p->next != student)
            p = p->next;
        p->next = student->next;
        delete student;
        student = NULL;
    }
}
void deleteCourceList(PTRMH &treeMH)
{

    if (treeMH != NULL)
    {
        deleteCourceList(treeMH->pLeft);
        deleteCourceList(treeMH->pRight);
        delete treeMH;
        treeMH = NULL;
    }
}

//=================================
// HAM TIM KIEM
//=================================

// chuc nang: tim kiem sinh vien trong DSSV bang mssv, phuong phap duyet tuyen tinh
PTRSV timSinhVien_DSSV(PTRSV FirstSV, char *MASV)
{
    if (FirstSV == NULL)
        return NULL;

    PTRSV p = FirstSV;
    while (p != NULL)
    {
        if (strcmp(p->student.studentID, MASV) == 0)
            return p;
        else
            p = p->next;
    }
    return NULL;
}

PTRSV timSinhVien_TheoMaLopHoc(PTRSV FirstSV, char *MASV, char *maLopHoc)
{
    if (FirstSV == NULL)
        return NULL;

    PTRSV p = FirstSV;
    while (p != NULL)
    {
        if (strcmp(p->student.studentID, MASV) == 0 && strcmp(p->student.classID, maLopHoc) == 0)
            return p;
        else
            p = p->next;
    }
    return NULL;
}

// chuc nang: tim kiem sinh vien trong DSSVDK bang mssv, phuong phap duyet tuyen tinh
PTRDK timSinhVien_DSSVDK(PTRDK First_DSSVDK, char *MASV)
{
    if (First_DSSVDK == NULL)
        return NULL;

    PTRDK p = First_DSSVDK;
    while (p != NULL)
    {
        if (strcmp(p->regis.studentID, MASV) == 0)
            return p;
        else
            p = p->next;
    }
    return NULL;
}

// chuc nang: tra ve dia chi mon hoc
PTRMH timMonHocTheoMa(PTRMH tree, char *MAMH)
{
    if (tree == NULL)
        return NULL;

    PTRMH p = tree;

    while (p != NULL)
    {
        if (strcmp(p->course.courceCode, MAMH) == 0)
            return p;
        else if (strcmp(MAMH, p->course.courceCode) < 0)
            p = p->pLeft;
        else
            p = p->pRight;
    }

    return NULL;
}

PTRLH timLopHoc(PTRLH FirstLH, char *maLopHoc)
{
    if (FirstLH == NULL)
        return NULL;

    PTRLH p = FirstLH;

    while (p != NULL)
    {
        if (strcmp(p->classID, maLopHoc) == 0)
            return p;
        p = p->next;
    }

    return NULL;
}

Credit *timLopTinChi_theoMAMH(LIST_LTC dsLTC, char *maMH)
{
    for (int i = 1; i <= dsLTC.currentIndex; i++)
        if (dsLTC.nodes[i] == NULL && strcmp(dsLTC.nodes[i]->courseCode, maMH) == 0)
            return dsLTC.nodes[i];

    return NULL;
}

Credit *timLopTinChi_theoMAMH_NIENKHOA(LIST_LTC dsLTC, char *maMH, char *nienkhoa)
{
    for (int i = 1; i <= dsLTC.currentIndex; i++)
        if (dsLTC.nodes[i] == NULL)
            if (strcmp(dsLTC.nodes[i]->courseCode, maMH) == 0 && strcmp(dsLTC.nodes[i]->schoolYear, nienkhoa) == 0)
                return dsLTC.nodes[i];

    return NULL;
}

Credit *timLopTinChi_theoInfo(LIST_LTC dsLTC, char *nienkhoa, int hocky, int nhom, char *maMonHoc)
{
    for (int i = 1; i <= dsLTC.currentIndex; i++)
        if (dsLTC.nodes[i] == NULL)
            if (strcmp(dsLTC.nodes[i]->schoolYear, nienkhoa) == 0 && dsLTC.nodes[i]->semester == hocky && dsLTC.nodes[i]->group == nhom && strcmp(dsLTC.nodes[i]->courseCode, maMonHoc) == 0)
                return dsLTC.nodes[i];
    return NULL;
}

//=================================
// HAM SAP XEP
//=================================

void sapXepDanhSachSinhVienTheoTen_Ho_SelectionSort(PTRSV &FirstSV)
{
    PTRSV p = NULL, q = NULL;
    PTRSV pmin = NULL;

    if (FirstSV == NULL)
        return;

    for (p = FirstSV; p->next != NULL; p = p->next)
    {
        pmin = p;

        for (q = p->next; q != NULL; q = q->next)
        {
            if (strcmp(q->student.firstName, pmin->student.firstName) < 0)
                pmin = q;

            else if (strcmp(q->student.firstName, pmin->student.firstName) == 0 && strcmp(q->student.lastName, pmin->student.lastName) < 0)
                pmin = q;
        }
        // hoan doi
        std::swap(pmin->student, p->student);
    }
}
