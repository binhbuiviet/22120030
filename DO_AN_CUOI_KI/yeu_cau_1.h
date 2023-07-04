﻿#include "do_hoa.h"

//Cấu trúc thời gian 

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
	string ho="";
	string ten="";
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

Thoi_gian_hien_tai tght;
string nam_hoc_hien_tai;

void Lay_thoi_gian_hien_tai();
bool Kiem_tra_folder(string& ten_folder);
bool Tao_folder(string& ten_folder);
void Tao_mot_nam_hoc();
void Tao_folder_lop();
void Tao_lop();
void Nhap_1_sinh_vien(sinh_vien*& sv, int x, int y, int stt);
void Tao_danh_sach(List_sinh_vien& l);
void Them_sv_vao_duoi_danh_sach(List_sinh_vien& l, sinh_vien* sv);
void ve_cau_truc_them_sv_vao_lop(int x, int y);
void Doc_sinh_vien_tu_file(ifstream& fin, sinh_vien*& sv);
void Ghi_1_sinh_vien_vao_file(ofstream& fout, sinh_vien* n, int thu_tu);
void Them_sv_vao_file();
void Tao_list_khoa_hoc(List_khoa_hoc& l);
void Xoa_khoa_hoc_khoi_dau_danh_sach(List_khoa_hoc& l);
void xoa_khoa_hoc_bat_ki_khoi_danh_sach(List_khoa_hoc& l, khoa_hoc* a, khoa_hoc* b);
void Them_khoa_hoc_vao_duoi_danh_sach(List_khoa_hoc& l, khoa_hoc* k);
void xoa_sv_dau(List_sinh_vien& l);
void xoa_sv_bat_ki(List_sinh_vien& l, string mssv);
void xoa_tep_tin(const string& folder);
void Xuat_1_sv_cua_lop(sinh_vien* sv, int x, int y, int stt);