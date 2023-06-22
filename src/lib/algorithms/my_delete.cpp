#include "my_delete.h"



//=================================
// HAM XOA
//=================================

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