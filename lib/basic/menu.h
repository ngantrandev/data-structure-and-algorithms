#pragma once
#include <iostream>
#include "UI_function.h"
#include "basic_function.h"

char them_lop_tin_chi[7][100] = {
	"Ma mon hoc       : ",
	"Nien khoa        : ",
	"Hoc ky           : ",
	"Nhom             : ",
	"So sinh vien MIN : ",
	"So sinh vien MAX : "};

char sua_lop_tin_chi[7][100] = {
	"Ma mon hoc       : ",
	"Nien khoa        : ",
	"Hoc ky           : ",
	"Nhom             : ",
	"So sinh vien MIN : ",
	"So sinh vien MAX : ",
	"Huy lop (0/1)    : "};

char nhap_ma_lop[2][100] = {
	"Nhap ma lop tin chi(so nguyen): "};

char nhap_ma_lop_hoc[2][100] = {
	"Nhap ma lop hoc(chuoi ky tu): "};
char nhap_MALH_NIENKHOA[2][100] = {
	"Nhap ma lop hoc(chuoi ky tu): ",
	"Nhap nien khoa              : "
};

char nhap_mssv[2][100] = {
	"Nhap ma sinh vien: "};

char nhap_ma_mon_hoc[2][100] = {
	"Nhap ma mon hoc: "};

char menu_chinh[14][100] = {
	"Cap nhat lop tin chi                ",
	"In danh sach sinh vien lop tin chi  ",
	"Cap nhat sinh vien lop hoc          ",
	"In danh sach sinh vien lop hoc      ",
	"Cap nhat danh sach mon hoc          ",
	"In danh sach mon hoc                ",
	"Dang ky lop tin chi                 ",
	"Huy lop tin chi khong du dieu kien  ",
	"Nhap diem lop tin chi               ",
	"In bang diem lop tin chi            ",
	"In bang diem trung binh lop hoc     ",
	"In bang diem tong ket cac mon hoc   ",
	"Xuat thong tin - Console            ",
	"Luu du lieu - File                  "};

char show_file[4][100] = {
	"Xuat danh sach lop tin chi",
	"Xuat danh sach sinh vien",
	"Xuat danh sach mon hoc"};

char cau_a[3][100] = {
	"Mo lop tin chi moi",
	"Sua thong tin lop tin chi",
	"Xoa lop tin chi"};

char question_g[3][100] = {
	"Nhap nien khoa: ",
	"Nhap hoc ky   : "};

char dang_ky_lop_TC[3][100] = {
	"Dang ky",
	"Huy dang ky"};

char cau_2[5][100] = {
	"Nhap nien khoa  : ",
	"Nhap hoc ky     : ",
	"Nhap nhom       : ",
	"Nhap ma mon hoc : "};

char cap_nhat_mon_hoc[4][100] = {
	"Them mon hoc",
	"Sua mon hoc",
	"Xoa mon hoc"};

char cap_nhat_sinh_vien[4][100] = {
	"Them sinh vien",
	"Sua thong tin sinh vien",
	"Xoa sinh vien"};

char sua_thong_tin_SV_dang_ky[5][100] = {
	"Ma so sinh vien : ",
	"Diem            : ",
	"Huy dang ky(0/1): "};

char nhap_thong_tin_mon_hoc[5][100] = {
	"Nhap ma mon hoc   : ",
	"Nhap ten mon hoc  : ",
	"Nhap STCLT        : ",
	"Nhap STCTH        : "};

char thong_tin_sinh_vien_lop_hoc[7][100] = {
	"Ma sinh vien   : ",
	"Ho             : ",
	"Ten            : ",
	"Gioi tinh      : ",
	"So dien thoai  : "};

int Menu(int x_originMenu, int y_originMenu, int width, int amount_of_selection, char menu_selection[10][100], int &out, int &pos) {

	while (true) {

		SetColor(23); // white
		drawBox(x_originMenu, y_originMenu, width, amount_of_selection + 1);

		for (int i = 0; i < amount_of_selection; i++) {
			gotoxy(x_originMenu + 1, y_originMenu + i + 1);

			if (i == pos) {
				SetColor(241); // blue
				if (i + 1 < 10)
					std::printf("%d   %c%s \n", i + 1, char(16), menu_selection[i]);
				else
					std::printf("%d  %c%s \n", i + 1, char(16), menu_selection[i]);
			}
			else {
				SetColor(23); // white
				if (i + 1 < 10)
					std::printf("%d     %s\n", i + 1, menu_selection[i]);
				else
					std::printf("%d    %s\n", i + 1, menu_selection[i]);
			}
		}

		SetColor(23);
		gotoxy((2 * x_originMenu + width - 62) / 2 + 4, y_originMenu + amount_of_selection + 5);
		std::printf("[SELECT:ENTER]     [EXIT:ESC]     [UP:%c/%c]     [DOWN:%c/%c]", char(30), char(17), char(31), char(16));

		int key_hit = getch();
		status stt = GetKey(key_hit);
		switch (stt) {
			case UP : LEFT: {
				(pos == 0) ? pos = amount_of_selection - 1 : pos--;
				break;
			};
			case DOWN : RIGHT: {
				(pos == amount_of_selection - 1) ? pos = 0 : pos++;
				break;
			}
			case ENTER:
				return pos + 1;
			case EXIT: {
				out = 1;
				return pos = 0;
			}
		}
	} // end while
}