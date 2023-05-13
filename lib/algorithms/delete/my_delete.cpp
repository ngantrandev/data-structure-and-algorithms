#include "my_delete.h"

//=================================
// HAM XOA
//=================================

void xoaDanhSachSinhVien(PTRSV &FirstSV)
{
    PTRSV p = NULL;
    while (FirstSV != NULL)
    {
        p = FirstSV;
        FirstSV = FirstSV->next;
        delete p;
    }
    FirstSV = NULL;
}
void xoaDanhSachDangKy(PTRDK &First_DSSVDK)
{
    PTRDK p = NULL;
    while (First_DSSVDK != NULL)
    {
        p = First_DSSVDK;
        First_DSSVDK = First_DSSVDK->next;
        delete p;
    }
    First_DSSVDK = NULL;
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
void xoaMonHoc(PTRMH &Tree_monhoc, char maMH[maxLengthString])
{
    if (Tree_monhoc == NULL)
        return;

    if (strcmp(Tree_monhoc->course.courceCode, maMH) < 0)
        xoaMonHoc(Tree_monhoc->pRight, maMH);
    else if (strcmp(Tree_monhoc->course.courceCode, maMH) > 0)
        xoaMonHoc(Tree_monhoc->pLeft, maMH);

    else
    {
        PTRMH root = Tree_monhoc;

        if (Tree_monhoc->pLeft == NULL)
            Tree_monhoc = Tree_monhoc->pRight;
        else if (Tree_monhoc->pRight == NULL)
            Tree_monhoc = Tree_monhoc->pLeft;
        else
        {
            timNodeThayThe(root, Tree_monhoc->pRight);
        }

        delete root;
    }
}
void xoaSinhVienDK(PTRDK &First_DSSVDK, PTRDK &dangky)
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
void xoaSinhVien_DSSV(PTRSV &FirstSV, PTRSV &ptr_sinhvien)
{
    if (ptr_sinhvien == FirstSV)
    {
        PTRSV p = FirstSV;
        FirstSV = FirstSV->next;
        delete p;
    }

    else
    {
        PTRSV p = FirstSV;
        while (p->next != ptr_sinhvien)
            p = p->next;
        p->next = ptr_sinhvien->next;
        delete ptr_sinhvien;
        ptr_sinhvien = NULL;
    }
}
void xoaDanhSachMonHoc(PTRMH &Tree_monhoc)
{

    if (Tree_monhoc != NULL)
    {
        xoaDanhSachMonHoc(Tree_monhoc->pLeft);
        xoaDanhSachMonHoc(Tree_monhoc->pRight);
        delete Tree_monhoc;
        Tree_monhoc = NULL;
    }
}