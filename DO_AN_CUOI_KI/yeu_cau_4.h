#include "yeu_cau_3.h"

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

