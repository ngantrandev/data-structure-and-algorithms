#pragma once

// Path: lib\basic\struct.h

char fileDsSinhvien[] = "./data/txt_file/danh_sach_sinh_vien.txt";
char fileDsMonhoc[] = "./data/txt_file/danh_sach_mon_hoc.txt";
char fileDsLTC[] = "./data/txt_file/danh_sach_lop_tin_chi.txt";
char fileMapMaLTC_maMH[] = "./data/txt_file/map_maLTC_maMH.txt";
char fileMapMSSV_dsLTC[] = "./data/txt_file/map_MSSV_dsLTC.txt";

const int MAX_BOARD_ELEMENTS = 10; // so luong phan tu toi da tren 1 bang
const int MAXSIZE = 10000;
const int MAXMONHOC = 2000;
const int MAXLTC = 10000; // so lop tin chi toi da
const int Student_ID_Length = 25;
const int First_Name_Length = 25;
const int Last_Name_Length = 25;
const int Ten_Length = 25;
const int SEX_Length = 25;
const int PhoneNum_Length = 25;
const int ClassID_Length = 25;
const int CourseCode_Length = 25;
const int CourseName_Length = 25;
const int SchoolYear_Length = 25;
const int maxLengthString = 128;

const int SCORE_BOARD_WIDTH = 86;
const int AVG_SCORE_BOARD_WIDTH = 80;
const int CREDIT_CLASS_INFO_BOARD_WIDTH = 95;
const int STUDENT_CLASS_INFO_BOARD_WIDTH = 102;
const int COURSE_INFO_BOARD_WIDTH = 71;
const int CREDIT_CLASS_STATUS_BOARD_WIDTH = 99;

const int FAST_TIME = 700;
const int NORMAL_TIME = 1000;
const int SLOW_TIME = 1500;

std::string thong_tin_lop_tin_chi[6] = {
	"Ma mon hoc       : ",
	"Nien khoa        : ",
	"Hoc ky           : ",
	"Nhom             : ",
	"So sinh vien MIN : ",
	"So sinh vien MAX : "};

std::string nhap_ma_lop_tin_chi[1] = {
	"Nhap ma lop tin chi(so nguyen duong): "};

std::string nhap_ma_lop_hoc[2] = {
	"Nhap ma lop hoc(chuoi ky tu): "};

std::string nhap_MALH_NIENKHOA[2] = {
	"Nhap ma lop hoc(chuoi ky tu): ",
	"Nhap nien khoa              : "};

std::string nhap_mssv[2] = {
	"Nhap ma sinh vien(chuoi ky tu): "};

std::string nhap_ma_mon_hoc[2] = {
	"Nhap ma mon hoc(chuoi ky tu): "};

std::string menu_chinh[14] = {
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

std::string show_file[4] = {
	"Xuat danh sach lop tin chi ",
	"Xuat danh sach sinh vien   ",
	"Xuat danh sach mon hoc     "};

std::string cap_nhat_lop_tin_chi[3] = {
	"Mo lop tin chi moi        ",
	"Sua thong tin lop tin chi ",
	"Xoa lop tin chi           "};

std::string cau_g[2] = {
	"Nhap nien khoa: ",
	"Nhap hoc ky   : "};

std::string dang_ky_lop_TC[3] = {
	"Dang ky",
	"Huy dang ky"};

std::string cau_2[5] = {
	"Nhap nien khoa (chuoi ky tu) : ",
	"Nhap hoc ky (so nguyen)      : ",
	"Nhap nhom (so nguyen)        : ",
	"Nhap ma mon hoc (chuoi ky tu): "};

std::string cap_nhat_mon_hoc[4] = {
	"Them mon hoc ",
	"Sua mon hoc  ",
	"Xoa mon hoc  "};

std::string cap_nhat_sinh_vien[4] = {
	"Them sinh vien          ",
	"Sua thong tin sinh vien ",
	"Xoa sinh vien           "};

std::string sua_thong_tin_SV_dang_ky[7] = {
	"Ma mon hoc       : ",
	"Nien khoa        : ",
	"Hoc ky           : ",
	"Nhom             : ",
	"So sinh vien MIN : ",
	"So sinh vien MAX : ",
	"Huy lop (0/1)    : "};

std::string nhap_thong_tin_mon_hoc[5] = {
	"Nhap ma mon hoc   : ",
	"Nhap ten mon hoc  : ",
	"Nhap STCLT        : ",
	"Nhap STCTH        : "};

std::string thong_tin_sinh_vien_lop_hoc[7] = {
	"Ma sinh vien   : ",
	"Ho             : ",
	"Ten            : ",
	"Gioi tinh      : ",
	"So dien thoai  : "};
