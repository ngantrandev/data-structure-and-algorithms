#include "struct.h"
#include "basic_function.h"
#include "count_node.h"
// HAM XUAT THONG TIN
void xuatDanhSachSinhVien_File_Txt(PTRSV FirstSv, char File_Name[maxLengthString]);

void xuatDanhSachMonHoc_LNR_File_Txt(PTRMH Tree_monhoc, FILE *fileout);
void xuatDanhSachMonHoc_File_Txt(PTRMH Tree_monhoc, char File_Name[50]);

void xuatDanhSachSVDK_File_Txt(PTRDK First_DSSVDK, FILE *fileout);
void xuatThongTinLopTinChi_File_Txt(Credit *loptinchi, FILE *fileout);
void xuatDanhSachLopTinChi_File_Txt(LIST_LTC dsLTC, char File_Name[maxLengthString]);

void xuatDanhSachSinhVien_File_Csv(PTRSV FirstSv, char File_Name[maxLengthString]);
void xuatDanhSachMonHoc_LNR_File_Csv(PTRMH Tree_monhoc, FILE *fileout);
void xuatDanhSachMonHoc_File_Csv(PTRMH Tree_monhoc, char File_Name[50]);