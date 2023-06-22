#pragma once
#include "struct.h"

int count_DaDangKy(PTRDK first);
void count_MH(PTRMH Tree_monhoc, int &soLuongMonHoc);
int count_CreditClass(LIST_LTC dsLTC);

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


