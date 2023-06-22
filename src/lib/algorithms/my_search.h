#pragma once
#include <string.h>
#include "struct.h"

// HAM TIM KIEM
PTRSV timSinhVien_DSSV(PTRSV FirstSV, char *MASV);
int timSinhVien_nodeDSSV(StudentListNode DSSV[MAXSIZE], int size, PTRSV ptrSV);
PTRSV timSinhVien_TheoMaLopHoc(PTRSV FirstSV, char *MASV, char *maLopHoc);
PTRDK timSinhVien_DSSVDK(PTRDK First_DSSVDK, char *MASV);
PTRMH timMonHocTheoMa(PTRMH tree, char *MAMH);
// PTRMH timMonHocTheoTen(PTRMH tree, char TENMH[CouseCode_Length]);
PTRLH timLopHoc(PTRLH FirstLH, char *maLopHoc);
Credit *timLopTinChi_theoMAMH(LIST_LTC dsLTC, char *maMH);
Credit *timLopTinChi_theoInfo(LIST_LTC dsLTC, char *nienkhoa, int hocky, int nhom, char *maMonHoc);
Credit *timLopTinChi_theoMAMH_NIENKHOA(LIST_LTC dsLTC, char *maMH, char *nienkhoa);