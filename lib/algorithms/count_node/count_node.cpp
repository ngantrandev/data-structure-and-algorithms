#include "count_node.h"

//=================================
// HAM DEM HOAC LAY SO LUONG
//=================================

int Reccount_DSDK(PTRDK First_DSSVDK)
{ // chuc nang: dem so luong SINH VIEN DANG KY
    int count = 0;
    PTRDK p = First_DSSVDK;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}

int Reccount_DaDangKy(PTRDK First_DSSVDK)
{ // chuc nang: dem so luong SINH VIEN DANG KY
    int count = 0;
    PTRDK p = First_DSSVDK;
    while (p != NULL)
    {
        if (p->regis.isRegistered == false)
            count++;
        p = p->next;
    }
    return count;
}
int Reccount_SV(PTRSV First_SV)
{ // chuc nang: dem so luong SINH VIEN trong danh sach sinh vien
    int count = 0;
    PTRSV p;
    for (p = First_SV; p != NULL; p = p->next)
        count++;
    return count;
}
void Reccount_MH(PTRMH Tree_monhoc, int &soLuongMonHoc)
{
    if (Tree_monhoc != NULL)
    {
        soLuongMonHoc++;
        Reccount_MH(Tree_monhoc->pLeft, soLuongMonHoc);
        Reccount_MH(Tree_monhoc->pRight, soLuongMonHoc);
    }
}

int Reccount_CreditClass(LIST_LTC dsLTC)
{
    int count = 0;
    for (int i = 0; i < dsLTC.currentIndex; i++)
    {
        if (dsLTC.nodes[i] != NULL)
            count++;
    }
    return count;
}