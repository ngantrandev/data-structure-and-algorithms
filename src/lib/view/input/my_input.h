#pragma once
#include "struct.h"
#include "basic_function.h"
#include "UI_function.h"
#include "check_error.h"
#include "menu.h"
#include "my_delete.h"
#include "my_search.h"
#include "my_modify.h"
#include "setData.h"
#include "count_node.h"
#include "my_show.h"

const int x_box_thong_bao = 50;
const int y_box_thong_bao = 50;

const int SLEEP_TIME = 1000;

int nhapThongTinMonHoc_User(Course &monhoc, int x_origin, int y_origin);
int nhapThongTinLopTinChi_User(int x_origin, int y_origin, int amountOf_title, char title[10][100], LIST_LTC &dsLTC);
int Nhap_Diem_UI(int x_origin, int y_origin, Credit *loptinchi, PTRSV FirstSV, std::string reprot_notification, char menu_selection[10][100]);
int input_UI(int x_originMenu, int y_originMenu, int width, std::string title, int amount_of_selection, char menu_selection[10][100], std::string content[100], int ma_nhom_du_lieu, std::string reprot_notification);

void nhapBangDiem(PTRSV FirstSV, PTRMH Tree_monhoc, LIST_LTC dsLTC);             // cau i

void capNhatSinhVienLopHoc(PTRSV FirstSV, int x_origin, int y_origin);                                                                                                // cau c
void capNhatDanhSachMonHoc_User(PTRMH &Tree_monhoc, int x_origin, int y_origin);                                                                                      // cau e

