#pragma once
#include <iostream>
#include "../basic/basic_function.h"

// check error
std::string checkError(std::string input, std::string dataType);

int getNextCreditClassID(LIST_LTC dsLTC, int currindex, int size);
int countCreditClass(LIST_LTC dsLTC);
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
Credit *timLopTinChi_theoNienKhoaHocKy(LIST_LTC dsLTC, char *nienkhoa, int hocky);
Credit *timLopTinChi_theoInfo(LIST_LTC dsLTC, char *nienkhoa, int hocky, int nhom, char *maMonHoc);
std::vector<int> getCreditList_theoMAMH_NIENKHOA(LIST_LTC dsLTC, int hocky, char *nienkhoa);
// HAM SAP XEP
void sapXepDanhSachSinhVienTheoTen_Ho_SelectionSort(PTRSV &FirstSV);

// MERGE SORT
void mergePTRMH(std::vector<PTRMH> dsMH, int left, int mid, int right);
void mergeSortPTRMH(std::vector<PTRMH> dsMH, int l, int r);

int getNextCreditClassID(LIST_LTC dsLTC, int currindex, int step);
int getNextCourseID(std::vector<PTRMH> dsMonhoc, int currIndex, int step);

/*
=================DEFINITION=================
*/

int getNextCreditClassID(LIST_LTC dsLTC, int currindex, int step)
{
    int count = 0;
    for (int i = currindex + 1; i <= dsLTC.currentIndex; i++)
    {
        if (dsLTC.nodes[i] != NULL)
            count++;
        if (count == step)
            return i;
        if (i == dsLTC.currentIndex && count < step)
            return currindex;
    }
    return -1;
}

int getNextIndexArray(int currIndex, int arraySize, int step)
{
    int count = 0;
    for (int i = currIndex + 1; i < arraySize; i++)
    {
        count++;
        if (count == step)
        {
            return i;
        }
    }
    return currIndex;
}

int getNextCourseID(std::vector<PTRMH> dsMonhoc, int currIndex, int step)
{
    int count = 0;
    for (int i = currIndex + 1; i < dsMonhoc.size(); i++)
    {
        if (dsMonhoc[i] != NULL)
        {
            count++;
        }

        if (count == step)
        {
            return i;
        }
        if (i == dsMonhoc.size() && count < step)
        {
            return currIndex;
        }
    }

    return -1;
}

template <typename T>
T getNextPointer(T First, int size)
{
    T p = First;
    int count = 0;
    while (true)
    {
        if (p->next != NULL)
        {
            count++;
            p = p->next;
        }

        if (count == size)
            return p;

        if (p->next == NULL && count < size)
            return First;
    }
}

template <typename T>
void getListTreeNode(T tree, std::vector<T> &list)
{
    if (tree != NULL)
    {
        list.push_back(tree);
        getListTreeNode(tree->pLeft, list);
        getListTreeNode(tree->pRight, list);
    }
}

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

int countCreditClass(LIST_LTC dsLTC)
{
    int count = 0;
    for (int i = 1; i <= dsLTC.currentIndex; i++)
    {
        if (dsLTC.nodes[i] != NULL)
            count++;
    }
    return count;
}

int count_DaDangKy(PTRDK first)
{ // chuc nang: dem so luong SINH VIEN DANG KY
    int count = 0;
    PTRDK p = first;
    while (p != NULL)
    {
        if (p->regis.disable == false)
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
    for (int i = 1; i <= dsLTC.currentIndex; i++)
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

Credit *timLopTinChi_theoNienKhoaHocKy(LIST_LTC dsLTC, char *nienkhoa, int hocky)
{
    for (int i = 1; i <= dsLTC.currentIndex; i++)
        if (dsLTC.nodes[i] != NULL)
            if (strcmp(dsLTC.nodes[i]->schoolYear, nienkhoa) == 0 && dsLTC.nodes[i]->semester == hocky)
                return dsLTC.nodes[i];

    return NULL;
}

std::vector<int> getCreditList_theoMAMH_NIENKHOA(LIST_LTC dsLTC, int hocky, char *nienkhoa)
{
    std::vector<int> listCreditID;
    for (int i = 1; i <= dsLTC.currentIndex; i++)
        if (dsLTC.nodes[i] != NULL)
            if (dsLTC.nodes[i]->semester == hocky && strcmp(dsLTC.nodes[i]->schoolYear, nienkhoa) == 0)
                listCreditID.push_back(i);

    return listCreditID;
}

Credit *timLopTinChi_theoInfo(LIST_LTC dsLTC, char *nienkhoa, int hocky, int nhom, char *maMonHoc)
{
    for (int i = 1; i <= dsLTC.currentIndex; i++)
        if (dsLTC.nodes[i] != NULL)
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

void mergePTRMH(std::vector<PTRMH> dsMH, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // temp array
    std::vector<PTRMH> L;
    std::vector<PTRMH> R;

    // copy data to temp arrays
    for (int i = 0; i < n1; i++)
    {
        L[i] = dsMH[left + i];
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = dsMH[mid + 1 + j];
    }

    // merge temp arrays to real array
    int i = 0;    // initial index of first subarray
    int j = 0;    // initial index of second subarray
    int k = left; // initial index of merged subarray

    while (i < n1 && j < n2)
    {
        if (strcmp(L[i]->course.courceName, R[j]->course.courceName) < 0)
        {
            dsMH[k] = L[i];
            i++;
        }
        else
        {
            dsMH[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        dsMH[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        dsMH[k] = R[j];
        j++;
        k++;
    }
}

void mergeSortPTRMH(std::vector<PTRMH> dsMH, int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergeSortPTRMH(dsMH, l, m);
        mergeSortPTRMH(dsMH, m + 1, r);

        mergePTRMH(dsMH, l, m, r);
    }
}