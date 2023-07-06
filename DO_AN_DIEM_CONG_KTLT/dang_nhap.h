#include "giao_vu.h"
#pragma once

struct Nguoi_dung_hien_tai
{
	string me; // Có thể là MSSV hoặc email đăng nhập
	string mat_khau;
	string hoten;
	string gioi_tinh;
	string sinh_nhat;
	string cccd;
	Nguoi_dung_hien_tai* pNext;
};

struct List_nguoi_dung_hien_tai
{
	Nguoi_dung_hien_tai* pHead;
	Nguoi_dung_hien_tai* pTail;
};

void Tao_list_nguoi_dung_ht(List_nguoi_dung_hien_tai& l);
void Them_nguoi_dung_vao_duoi_ds(List_nguoi_dung_hien_tai& l, Nguoi_dung_hien_tai* n);
void Doc_nguoi_dung_tu_file(ifstream& fin, List_nguoi_dung_hien_tai& l);
void Dang_nhap_tai_khoan_GV();
void Giao_dien_giao_vu();
void Thao_tac_voi_cac_lop();
void Thao_tac_voi_cac_khoa_hoc();
void Xem_thong_tin_giao_vu();
void quan_li_ket_qua_hoc_tap();
void Giao_vu(Nguoi_dung_hien_tai* nd);
void Xem_profile_GV(Nguoi_dung_hien_tai* nd);
void Doi_mat_khau_GV(Nguoi_dung_hien_tai* nd);
void Dang_nhap_tai_khoan_SV();
void Xem_profile_SV(Nguoi_dung_hien_tai*& nd);
void Menu_chinh();