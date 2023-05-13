#pragma once
#include "struct.h"
#include "basic_function.h"

void leftRotate(PTRMH &tree);
void rightRotate(PTRMH &tree);
int getTreeHeight(PTRMH tree);
// void addCourseToList(PTRMH &treeCourse, Course cource);
void addCourseToList(PTRMH &Tree_monhoc, Course monhoc);
void addStudentToList(PTRSV &FirstSV, Student sv);
void addNewClassID(PTRLH &FirstLH, char maLopHoc[ClassID_Length]);
void addStudentToRegisList(PTRDK &First_DSSVDK, Registration dangky);

void addCourseByName(PTRMH &Tree_monhoc, Course monhoc);