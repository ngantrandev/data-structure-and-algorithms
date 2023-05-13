#pragma once
#include "struct.h"
#include "basic_function.h"

void xuatThongTinSinhVien(int tabx, int taby, Student sinhvien, int stt);
void xuatDanhSachSinhVien_Console(PTRSV FirstSV, int tabx, int taby);
void xuatThongTinSinhVien_MSSV_Console(PTRSV ptr_SV, int &stt, int tabx, int taby);

void xuatThongTinMonHoc(int tabx, int taby, int stt, Course monhoc);
void xuatDanhSachMonHoc_LNR_Console(PTRMH Tree_monhoc, int x_origin, int y_origin, int &stt);
void xuatDanhSachMonHoc_Console(int x_origin, int y_origin, PTRMH Tree_monhoc);

void xuatThongTinLopTinChi_Console(int x_origin, int y_origin, Credit *loptinchi, int stt);
void xuatDanhSachLopTinChi_Console(int x_origin, int y_origin, LIST_LTC dsLTC);
void xuatDanhSachLopTinChi_Console_Theo_Dieu_Kien(int x_origin, int y_origin, LIST_LTC dsLTC, char nienkhoa[maxLengthString], int nhom);