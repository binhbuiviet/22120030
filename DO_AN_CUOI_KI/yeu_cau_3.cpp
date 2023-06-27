#include "yeu_cau_3.h"

void Tao_list_lop(List_lop_hoc& l)
{
	l.pHead = nullptr;
	l.pTail = nullptr;
}

void Tao_node_lop(Lop_hoc* a, string ten)
{
	a = new Lop_hoc;
	a->ten_lop = ten;
	a->pNext = nullptr;
}

void Them_lop_vao_duoi_danh_sach(List_lop_hoc& l, Lop_hoc* a)
{
	if (l.pHead == nullptr)
	{
		l.pHead = a;
		l.pTail = a;
	}
	else
	{
		l.pTail->pNext = a;
		l.pTail = a;
	}
}

void Lay_list_lop(List_lop_hoc& nam1, List_lop_hoc& nam2, List_lop_hoc& nam3, List_lop_hoc& nam4)
{
	ifstream fin;
	fin.open("Lop/Danh sach cac lop.txt");
	string ten_lop;
	string ktra_nam_hoc = "" + nam_hoc_hien_tai[2] + nam_hoc_hien_tai[3];
	int knh = stoi(ktra_nam_hoc);
	while (fin.eof() != true)
	{
		getline(fin, ten_lop, '\n');
		if (ten_lop == "")
			break;
		Lop_hoc* a;
		Tao_node_lop(a, ten_lop);
		string lop = "" + ten_lop[0] + ten_lop[1];
		int l = stoi(lop);
		if (l == knh)
			Them_lop_vao_duoi_danh_sach(nam1, a);
		else if (knh - l == 1)
			Them_lop_vao_duoi_danh_sach(nam2, a);
		else if (knh - l == 2)
			Them_lop_vao_duoi_danh_sach(nam3, a);
		else if (knh - l == 3)
			Them_lop_vao_duoi_danh_sach(nam4, a);
	}
	fin.close();
}

void Xem_cac_lop()
{
	List_lop_hoc nam1;
	Tao_list_lop(nam1);
	List_lop_hoc nam2;
	Tao_list_lop(nam2);
	List_lop_hoc nam3;
	Tao_list_lop(nam3);
	List_lop_hoc nam4;
	Tao_list_lop(nam4);
	Lay_list_lop(nam1, nam2, nam3, nam4);

}