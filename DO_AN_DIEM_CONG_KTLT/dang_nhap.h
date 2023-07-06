#pragma once
#include "giao_vu.h"

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