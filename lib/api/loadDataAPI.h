#pragma once
#include "struct.h"
#include "basic_function.h"
// HAM NHAP DU LIEU
Course loadCourseInfo(FILE *filein);
PTRMH loadCourseList(char File_Name[maxLengthString]);
Student loadStudentInfo(FILE *filein);
PTRSV loadStudentList(char File_Name[maxLengthString]);
PTRLH loadClassList(char File_Name[maxLengthString]);
PTRDK loadRegisStudentList(FILE *filein);
Credit *loadCreditClassInfo(FILE *filein);
LIST_LTC loadStudentCreditClassList(char File_Name[maxLengthString]);
