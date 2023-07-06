#pragma once
#include "do_hoa.h"

struct Thoi_gian_hien_tai
{
	int ngay;
	int thang;
	int nam;
	string wday;
};

struct Lop_hoc
{
	string ten_lop;
	Lop_hoc* pNext;
};

struct List_lop_hoc
{
	Lop_hoc* pHead;
	Lop_hoc* pTail;
};

struct sinh_vien
{
	string mssv = "";
	string ho = "";
	string ten = "";
	string gioi_tinh = "";
	string ngay_sinh = "";
	string cccd = "";
	sinh_vien* pNext;
};

struct List_sinh_vien
{
	sinh_vien* pHead;
	sinh_vien* pTail;
};

struct khoa_hoc
{
	string ma_mon_hoc;
	string ten_khoa_hoc;
	string ten_lop;
	string ten_giang_vien;
	int so_tin_chi;
	int sinh_vien_toi_da;
	string buoi_hoc;
	string khung_gio;
	khoa_hoc* pNext;
};

struct List_khoa_hoc
{
	khoa_hoc* pHead;
	khoa_hoc* pTail;
};

struct Diem_so_sv
{
	string mssv;
	string hoten;
	double dtb_mon;
	double diem_cuoi_ki;
	double diem_giua_ki;
	double diem_qua_trinh;
	Diem_so_sv* pNext;
};

struct List_diem_so_sv
{
	Diem_so_sv* pHead;
	Diem_so_sv* pTail;
};

Thoi_gian_hien_tai tght;
string nam_hoc_hien_tai;
string hoc_ki = ""; //Mục đích của string này là để tạo folder học kì, gán nó trong folder năm học đã tạo trước đó
string thong_tin_cac_khoa_hoc;

void Lay_thoi_gian_hien_tai();
bool Kiem_tra_folder(string& ten_folder);
bool Tao_folder(string& ten_folder);
void Tao_folder_lop();
void Nhap_1_sinh_vien(sinh_vien*& sv, int x, int y, int stt);
void Tao_list_khoa_hoc(List_khoa_hoc& l);
void Them_khoa_hoc_vao_duoi_danh_sach(List_khoa_hoc& l, khoa_hoc* k);
void Xoa_khoa_hoc_khoi_dau_danh_sach(List_khoa_hoc& l);
void xoa_khoa_hoc_bat_ki_khoi_danh_sach(List_khoa_hoc& l, khoa_hoc* a, khoa_hoc* b);
void Tao_danh_sach(List_sinh_vien& l);
void Them_sv_vao_duoi_danh_sach(List_sinh_vien& l, sinh_vien* sv);
void ve_cau_truc_them_sv_vao_lop(int x, int y);
void Doc_sinh_vien_tu_file(ifstream& fin, sinh_vien*& sv);
void Ghi_1_sinh_vien_vao_file(ofstream& fout, sinh_vien* n, int thu_tu);
void xoa_sv_dau(List_sinh_vien& l);
void xoa_sv_bat_ki(List_sinh_vien& l, string mssv);
void xoa_tep_tin(const string& folder);
void xoa_tep_tin(const string& folder);
void Xuat_1_sv_cua_lop(sinh_vien* sv, int x, int y, int stt);

void Nhap_khoa_hoc_vao_file(fstream& f, khoa_hoc* k);
void Lay_list_khoa_hoc(ifstream& fin, List_khoa_hoc& l);
bool Doi_ten_file(const string& ten_cu, const string& ten_moi);
void Doc_khoa_hoc_cua_sv(List_khoa_hoc& l, string mssv);
void Xoa_1_khoa_hoc(List_khoa_hoc& l, string ten_khoa_hoc, string ten_lop);

void Tao_list_lop(List_lop_hoc& l);
void Tao_node_lop(Lop_hoc*& a, string ten);
void Them_lop_vao_duoi_danh_sach(List_lop_hoc& l, Lop_hoc* a);
void Lay_list_lop(List_lop_hoc& nam1, List_lop_hoc& nam2, List_lop_hoc& nam3, List_lop_hoc& nam4);
void xuat_list_lop(List_lop_hoc l);
void bang_ds_khoa_hoc(List_khoa_hoc l);

void doc_sv_co_diem_tu_file(ifstream& fin, Diem_so_sv* d);
void in_sv_co_diem_vao_file(ofstream& fout, Diem_so_sv* d, int stt);
void ve_cau_truc_bang_diem(int x, int y);
void in_1_sv_co_diem(int x, int y, Diem_so_sv* d, int stt);
void Them_sv_co_diem_vao_duoi_danh_sach(List_diem_so_sv& l, Diem_so_sv* d);
void Tao_danh_sach_sv_co_diem(List_diem_so_sv& l);
bool Kiem_tra_ton_tai_sv(List_diem_so_sv l, string mssv, Diem_so_sv*& d);
