#include "my_search.h"

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

int timSinhVien_nodeDSSV(StudentListNode DSSV[MAXSIZE], int crt_index, PTRSV ptrSV)
{
    if (crt_index < 0)
        return -1;

    for (int i = 0; i <= crt_index; i++)
    {
        if (DSSV[i].ptrSV == ptrSV)
            return i;
    }

    return -1; // khong tim thay
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
