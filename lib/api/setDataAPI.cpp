#include "setDataAPI.h"

void leftRotate(PTRMH &tree)
{ // chuc nang: xoay cay sang trai
    if (tree == NULL)
        return;

    PTRMH x = tree->pRight;
    tree->pRight = x->pLeft;
    x->pLeft = tree;
    tree = x;
}
void rightRotate(PTRMH &tree)
{ // chuc nang: xoay cay sang phai

    if (tree == NULL)
        return;

    PTRMH x = tree->pLeft;
    tree->pLeft = x->pRight;
    x->pRight = tree;
    tree = x;
}

int getTreeHeight(PTRMH tree)
{ // chuc nang: tinh chieu cao cua node
    if (tree != NULL)
    {
        int left = getTreeHeight(tree->pLeft) + 1;
        int right = getTreeHeight(tree->pRight) + 1;

        return left > right ? left : right;
    }
}

void addCourseToList(PTRMH &Tree_monhoc, Course monhoc)
{
    // strcmp(monhoc.MAMH, Tree_monhoc->monhoc.MAMH) < 0

    if (Tree_monhoc == NULL)
    {
        PTRMH p = new CourseNode;

        p->course = monhoc;
        p->pLeft = NULL;
        p->pRight = NULL;

        Tree_monhoc = p;
    }
    else
    {
        if (strcmp(monhoc.courceCode, Tree_monhoc->course.courceCode) < 0)
        {
            addCourseToList(Tree_monhoc->pLeft, monhoc);
        }
        else if (strcmp(monhoc.courceCode, Tree_monhoc->course.courceCode) > 0)
        {
            addCourseToList(Tree_monhoc->pRight, monhoc);
        }
    }

    int Balance_Value = getTreeHeight(Tree_monhoc->pLeft) - getTreeHeight(Tree_monhoc->pRight);

    // Xoay cay de can bang cay

    // TH1: left left
    if (Balance_Value > 1 && strcmp(monhoc.courceCode, Tree_monhoc->course.courceCode) < 0)
    {
        rightRotate(Tree_monhoc);
        return;
    }
    // TH2: right right
    else if (Balance_Value < -1 && strcmp(monhoc.courceCode, Tree_monhoc->course.courceCode) > 0)
    {
        leftRotate(Tree_monhoc);
        return;
    }
    // TH3: left right
    else if (Balance_Value > 1 && strcmp(monhoc.courceCode, Tree_monhoc->course.courceCode) > 0)
    {
        leftRotate(Tree_monhoc->pLeft);
        rightRotate(Tree_monhoc);
        return;
    }
    // TH4: right left
    else if (Balance_Value < -1 && strcmp(monhoc.courceCode, Tree_monhoc->course.courceCode) < 0)
    {
        rightRotate(Tree_monhoc->pRight);
        leftRotate(Tree_monhoc);
        return;
    }
}

void addStudentToList(PTRSV &FirstSV, Student sv)
{
    PTRSV p = new StudentNode;
    PTRSV q = NULL;
    p->student = sv;

    if (FirstSV == NULL)
    {
        FirstSV = p;
        FirstSV->next = NULL;
    }
    else if (FirstSV->next == NULL)
    { // co mot phan tu
        if (strcmp(p->student.studentID, FirstSV->student.studentID) < 0)
        {
            p->next = FirstSV;
            FirstSV = p;
        }
        else if (strcmp(p->student.studentID, FirstSV->student.studentID) > 0)
        {
            FirstSV->next = p;
            p->next = NULL;
        }
        return; // ket thuc thuat toan
    }
    else
    { // truong hop danh sach da co it nhat 2 phan tu

        if (strcmp(p->student.studentID, FirstSV->student.studentID) < 0)
        {
            p->next = FirstSV;
            FirstSV = p;
            return;
        }

        q = FirstSV;

        while (q->next != NULL)
        {
            if (strcmp(p->student.studentID, q->student.studentID) > 0 && strcmp(p->student.studentID, q->next->student.studentID) < 0)
            {
                p->next = q->next;
                q->next = p;
                return; // ket thuc thuat toan
            }
            q = q->next;
        }

        // TH q da di chuyen ve cuoi danh sach
        q->next = p;
        p->next = NULL;
    }
}

void addNewClassID(PTRLH &FirstLH, char maLopHoc[ClassID_Length])
{
    PTRLH p = new ClassNode;
    PTRLH q = NULL;
    strcpy(p->classID, maLopHoc);

    if (FirstLH == NULL)
    {
        FirstLH = p;
        FirstLH->next = NULL;
    }
    else if (FirstLH->next == NULL)
    { // co mot phan tu
        if (strcmp(p->classID, FirstLH->classID) < 0)
        {
            p->next = FirstLH;
            FirstLH = p;
        }
        else if (strcmp(p->classID, FirstLH->classID) > 0)
        {
            FirstLH->next = p;
            p->next = NULL;
        }
        return; // ket thuc thuat toan
    }
    else
    { // truong hop danh sach da co it nhat 2 phan tu

        if (strcmp(p->classID, FirstLH->classID) < 0)
        {
            p->next = FirstLH;
            FirstLH = p;
            return;
        }

        q = FirstLH;

        while (q->next != NULL)
        {
            if (strcmp(p->classID, q->classID) > 0 && strcmp(p->classID, q->next->classID) < 0)
            {
                p->next = q->next;
                q->next = p;
                return; // ket thuc thuat toan
            }
            q = q->next;
        }

        // TH q da di chuyen ve cuoi danh sach
        q->next = p;
        p->next = NULL;
    }
}

// chuc nang: them thong tin dang ky vao DSLKD danh dang ky lop tin chi co sap xep
void addStudentToRegisList(PTRDK &First_DSSVDK, Registration dangky)
{
    PTRDK p = new RegisNode;
    PTRDK q;
    p->regis = dangky;

    if (First_DSSVDK == NULL)
    {
        First_DSSVDK = p;
        First_DSSVDK->next = NULL;
    }
    else if (First_DSSVDK->next == NULL)
    {

        if (strcmp(p->regis.studentID, First_DSSVDK->regis.studentID) < 0)
        {
            p->next = First_DSSVDK;
            First_DSSVDK = p;
        }
        else if (strcmp(p->regis.studentID, First_DSSVDK->regis.studentID) > 0)
        {
            First_DSSVDK->next = p;
            p->next = NULL;
        }
    }
    else
    { // truong hop danh sach co it nhat 2 phan tu

        if (strcmp(p->regis.studentID, First_DSSVDK->regis.studentID) < 0)
        {
            p->next = First_DSSVDK;
            First_DSSVDK = p;
            return;
        }

        q = First_DSSVDK;

        while (q->next != NULL)
        {
            if (strcmp(p->regis.studentID, q->regis.studentID) > 0 && strcmp(p->regis.studentID, q->next->regis.studentID) < 0)
            {
                p->next = q->next;
                q->next = p;
                return; // ket thuc thuat toan
            }
            q = q->next;
        }
        // TH q da di chuyen ve cuoi danh sach
        p->next = NULL;
        q->next = p;
    }
}

void addCourseByName(PTRMH &Tree_monhoc, Course monhoc)
{
    if (Tree_monhoc == NULL)
    {
        PTRMH p = new CourseNode;

        p->course = monhoc;
        p->pLeft = NULL;
        p->pRight = NULL;

        Tree_monhoc = p;
    }
    else
    {
        if (strcmp(monhoc.courceName, Tree_monhoc->course.courceName) < 0)
            addCourseByName(Tree_monhoc->pLeft, monhoc);

        else if (strcmp(monhoc.courceName, Tree_monhoc->course.courceName) >= 0)
            addCourseByName(Tree_monhoc->pRight, monhoc);
    }
}