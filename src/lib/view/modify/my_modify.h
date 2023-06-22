#pragma once


#include "struct.h"
#include "basic_function.h"
#include "my_search.h"

// HAM SUA THONG TIN
void suaThongTinSinhVien(Student &sinhvien);
int suaThongTinLopTinChi(int x_origin, int y_origin, char title[10][100], Credit *loptinchi);
int suaThongTinMonHoc_User(Course &monhoc, int x_origin, int y_origin);
