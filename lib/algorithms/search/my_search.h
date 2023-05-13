#include "struct.h"

// HAM TIM KIEM
PTRSV timSinhVien_DSSV(PTRSV FirstSV, char MASV[Student_ID_Length]);
int timSinhVien_nodeDSSV(StudentListNode DSSV[MAXSIZE], int size, PTRSV ptrSV);
PTRSV timSinhVien_TheoMaLopHoc(PTRSV FirstSV, char MASV[Student_ID_Length], char maLopHoc[ClassID_Length]);
PTRDK timSinhVien_DSSVDK(PTRDK First_DSSVDK, char MASV[Student_ID_Length]);
PTRMH timMonHocTheoMa(PTRMH tree, char MAMH[CouseCode_Length]);
// PTRMH timMonHocTheoTen(PTRMH tree, char TENMH[CouseCode_Length]);
PTRLH timLopHoc(PTRLH FirstLH, char maLopHoc[ClassID_Length]);
Credit *timLopTinChi_theoMAMH(LIST_LTC dsLTC, char maMH[CouseCode_Length]);
Credit *timLopTinChi_theoInfo(LIST_LTC dsLTC, char *nienkhoa, int hocky, int nhom, char *maMonHoc);
Credit *timLopTinChi_theoMAMH_NIENKHOA(LIST_LTC dsLTC, char maMH[CouseCode_Length], char nienkhoa[SchoolYear_Length]);