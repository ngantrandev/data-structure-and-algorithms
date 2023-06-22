#pragma once
#include "struct.h"
#include "basic_function.h"

//=================================
// HAM XOA

void timNodeThayThe(PTRMH &X, PTRMH &Y);
void deleteCource(PTRMH &treeMH, char *maMH);
void deleteStudentFromRegistedList(PTRDK &First_DSSVDK, PTRDK &dangky);
void deleteStudentFromStudentList(PTRSV &first, PTRSV &student);
void deleteCourceList(PTRMH &treeMH);



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
