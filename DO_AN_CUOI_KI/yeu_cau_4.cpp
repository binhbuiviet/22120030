#include "yeu_cau_4.h"

void doc_sv_co_diem_tu_file(ifstream& fin, Diem_so_sv* d)
{
	string stt;
	getline(fin, stt, ',');
	getline(fin, d->mssv, ',');
	if (d->mssv == "")
		return;
	getline(fin, d->hoten, ',');
	string dtb_mon, diem_cuoi_ki, diem_giua_ki, diem_qua_trinh;
	getline(fin, dtb_mon, ',');
	getline(fin, diem_cuoi_ki, ',');
	getline(fin, diem_giua_ki, ',');
	getline(fin, diem_qua_trinh, '\n');
	d->dtb_mon = stod(dtb_mon);
	d->diem_cuoi_ki = stod(diem_cuoi_ki);
	d->diem_giua_ki = stod(diem_giua_ki);
	d->diem_qua_trinh = stod(diem_qua_trinh);
	d->pNext = nullptr;
}

void in_sv_co_diem_vao_file(ofstream& fout, Diem_so_sv* d, int stt)
{
	fout << stt << ","
		<< d->mssv << ","
		<< d->hoten << ","
		<< d->dtb_mon << ","
		<< d->diem_cuoi_ki << ","
		<< d->diem_giua_ki << ","
		<< d->diem_qua_trinh << "\n";
}

void in_cau_truc_bang_diem(int x, int y)
{
	goto_XY(x + 2, y);
	cout << "STT";
	goto_XY(x + 7, y);
	cout << "|";
	goto_XY(x + 10, y);
	cout << "MSSV";
	goto_XY(x + 20, y);
	cout << "|";
	goto_XY(x + 23, y);
	cout << "Ho ten";
	goto_XY(x + 55, y);
	cout << "|";
	goto_XY(x + 58, y);
	cout << "DTB mon";
	goto_XY(x + 66, y);
	cout << "|";
	goto_XY(x + 69, y);
	cout << "Cuoi ki";
	goto_XY(x + 78, y);
	cout << "|";
	goto_XY(x + 81, y);
	cout << "Giua ki";
	goto_XY(x + 90, y);
	cout << "|";
	goto_XY(x + 93, y);
	cout << "Qua trinh";
}

void in_1_sv_co_diem(int x, int y, Diem_so_sv* d, int stt)
{
	goto_XY(x + 2, y);
	cout << stt;
	goto_XY(x + 7, y);
	cout << "|";
	goto_XY(x + 10, y);
	cout << d->mssv;
	goto_XY(x + 20, y);
	cout << "|";
	goto_XY(x + 23, y);
	cout << d->hoten;
	goto_XY(x + 55, y);
	cout << "|";
	goto_XY(x + 58, y);
	cout << d->dtb_mon;
	goto_XY(x + 66, y);
	cout << "|";
	goto_XY(x + 69, y);
	cout << d->diem_cuoi_ki;
	goto_XY(x + 78, y);
	cout << "|";
	goto_XY(x + 81, y);
	cout << d->diem_giua_ki;
	goto_XY(x + 90, y);
	cout << "|";
	goto_XY(x + 93, y);
	cout << d->diem_qua_trinh;
}

void Them_sv_co_diem_vao_duoi_danh_sach(List_diem_so_sv& l, Diem_so_sv* d)
{
	if (l.pHead == nullptr)
	{
		l.pHead = d;
		l.pTail = d;
	}
	else
	{
		l.pTail->pNext = d;
		l.pTail = d;
	}
}

void Tao_danh_sach_sv_co_diem(List_diem_so_sv& l)
{
	l.pHead = nullptr;
	l.pTail = nullptr;
}

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
	string temp;
	getline(fin, temp, '\n');
	List_diem_so_sv l;
	Tao_danh_sach_sv_co_diem(l);
	while (fin.eof() != true)
	{
		Diem_so_sv* d = new Diem_so_sv;
		doc_sv_co_diem_tu_file(fin, d);
		if (d->mssv == "")
			break;
		Them_sv_co_diem_vao_duoi_danh_sach(l, d);
	}
	fin.close();

	string luu_file;
	luu_file = hoc_ki + "/" + tenkhoahoc + " " + tenlop + "/Danh sach sinh vien (Diem so).csv";
	ofstream fout;
	fout.open(luu_file);
	fout << "STT,MSSV,Ho va ten,DTB mon,Diem cuoi ki,Diem giua ki,Diem qua trinh\n";
	int stt = 1;
	Diem_so_sv* sv = l.pHead;
	while (sv != nullptr)
	{
		in_sv_co_diem_vao_file(fout, sv, stt);
		sv = sv->pNext;
		stt++;
	}
	fout.close();
	goto_XY(34, 15);
	cout << "Nhap diem thanh cong.";
}

