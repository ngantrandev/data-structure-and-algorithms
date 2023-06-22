#pragma once
#include "struct.h"
#include "basic/basic_function.h"
#include "algorithms/count_node.h"


// HAM LOAD DU LIEU TU FILE
Course loadCourseInfo(FILE *filein);
PTRMH loadCourseList(char *filename);
Student loadStudentInfo(FILE *filein);
PTRSV loadStudentList(char *filename);
PTRLH loadClassList(char *filename);
PTRDK loadRegisStudentList(FILE *filein);
Credit *loadCreditClassInfo(FILE *filein);
LIST_LTC loadStudentCreditClassList(char *filename);



// HAM luu THONG TIN vao file
void xuatDanhSachSinhVien_File_Txt(PTRSV FirstSv, char File_Name[maxLengthString]);

void xuatDanhSachMonHoc_LNR_File_Txt(PTRMH Tree_monhoc, FILE *fileout);
void xuatDanhSachMonHoc_File_Txt(PTRMH Tree_monhoc, char File_Name[50]);

void xuatDanhSachSVDK_File_Txt(PTRDK First_DSSVDK, FILE *fileout);
void xuatThongTinLopTinChi_File_Txt(Credit *loptinchi, FILE *fileout);
void xuatDanhSachLopTinChi_File_Txt(LIST_LTC dsLTC, char File_Name[maxLengthString]);

void xuatDanhSachSinhVien_File_Csv(PTRSV FirstSv, char File_Name[maxLengthString]);
void xuatDanhSachMonHoc_LNR_File_Csv(PTRMH Tree_monhoc, FILE *fileout);
void xuatDanhSachMonHoc_File_Csv(PTRMH Tree_monhoc, char File_Name[50]);




// ham thao tac data bo nho trong chuong trinh
void leftRotate(PTRMH &tree);
void rightRotate(PTRMH &tree);
int getTreeHeight(PTRMH tree);
// void addCourseToList(PTRMH &treeCourse, Course cource);
void addCourseToList(PTRMH &Tree_monhoc, Course monhoc);
void addStudentToList(PTRSV &FirstSV, Student sv);
void addNewClassID(PTRLH &FirstLH, char maLopHoc[ClassID_Length]);
void addStudentToRegisList(PTRDK &First_DSSVDK, Registration dangky);

void addCourseByName(PTRMH &Tree_monhoc, Course monhoc);