#include "yeu_cau_4.h"

void Nhap_diem_khoa_hoc()
{
	system("cls");
	string tenkhoahoc, tenlop, link;
	goto_XY(34, 9);
	cout << "Dang tai diem so.";
	goto_XY(34, 10);
	cout << "Nhap ten khoa hoc: ";
	goto_XY(34, 11);
	cout << "Nhap lop: ";
	goto_XY(34, 12);
	cout << "Nhap duong link cua file diem so.";
	goto_XY(53, 10);
	getline(cin, tenkhoahoc);
	goto_XY(44, 11);
	getline(cin, tenlop);
	string ktra = hoc_ki + "/" + tenkhoahoc + " " + tenlop;
	while (Kiem_tra_folder(ktra) == false)
	{
		Xoa_dong(10);
		Xoa_dong(11);
		goto_XY(34, 6);
		cout << "Khoa hoc hoac lop ban nhap khong ton tai. Vui long nhap lai.";
		goto_XY(34, 10);
		cout << "Nhap ten khoa hoc: ";
		goto_XY(34, 11);
		cout << "Nhap lop: ";
		goto_XY(34, 12);
		cout << "Nhap duong link cua file diem so.";
		goto_XY(53, 10);
		getline(cin, tenkhoahoc);
		goto_XY(44, 11);
		getline(cin, tenlop);
		string ktra = hoc_ki + "/" + tenkhoahoc + " " + tenlop;
	}
	goto_XY(34, 13);
	getline(cin, link);
	ifstream fin;
	fin.open(link);
	while (!fin)
	{
		Xoa_dong(6);
		cout << "Duong link ban nhap khong ton tai hoac khong mo duoc. Vui long thu lai.";
		goto_XY(34, 13);
		getline(cin, link);
		fin.open(link);
	}
}