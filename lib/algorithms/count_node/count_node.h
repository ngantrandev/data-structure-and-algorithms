#pragma once
#include "struct.h"

// HAM DEM HOAC LAY SO LUONG
int Reccount_DSDK(PTRDK First_DSSVDK);
int Reccount_DaDangKy(PTRDK First_DSSVDK);
int Reccount_SV(PTRSV First_SV);
void Reccount_MH(PTRMH Tree_monhoc, int &soLuongMonHoc);
int Reccount_CreditClass(LIST_LTC dsLTC);