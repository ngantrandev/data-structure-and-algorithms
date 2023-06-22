#include "my_sort.h"

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
            if (strcmp(q->student.name, pmin->student.name) < 0)
                pmin = q;

            else if (strcmp(q->student.name, pmin->student.name) == 0 && strcmp(q->student.firstName, pmin->student.firstName) < 0)
                pmin = q;
        }
        // hoan doi
        std::swap(pmin->student, p->student);
    }
}

void sapXep_nodeDSSV_SelectionSort(StudentListNode DSSV[MAXSIZE], int size)
{
    if (size <= 0)
        return;

    int index_min = 0;

    for (int i = 0; i < size - 1; i++)
    {
        index_min = i;

        for (int j = i + 1; j < size; j++)
            if (strcmp(DSSV[j].ptrSV->student.studentID, DSSV[index_min].ptrSV->student.studentID) < 0)
                index_min = j;

        std::swap(DSSV[index_min], DSSV[i]);
    }
}