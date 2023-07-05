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

void ve_cau_truc_bang_diem(int x, int y)
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

void xem_bang_diem_khoa_hoc()
{
	system("cls");
	string tenkhoahoc, tenlop, link;
	goto_XY(34, 10);
	cout << "Nhap ten khoa hoc: ";
	goto_XY(34, 11);
	cout << "Nhap lop: ";
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
		goto_XY(53, 10);
		getline(cin, tenkhoahoc);
		goto_XY(44, 11);
		getline(cin, tenlop);
		string ktra = hoc_ki + "/" + tenkhoahoc + " " + tenlop;
	}
	Xoa_dong(6);
	string file_diem;
	file_diem = hoc_ki + "/" + tenkhoahoc + " " + tenlop + "/Danh sach sinh vien (Diem so).csv";
	ifstream fin;
	fin.open(file_diem);
	if (!fin)
	{
		goto_XY(34, 12);
		cout << "Khoa hoc cua lop hoc nay chua co diem. Vui long quay lai sau.";
		fin.close();
		return;
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

	system("cls");
	int x = 6;
	int y = 4;
	int w = 105;
	int h = 3;
	ve_cau_truc_bang_diem(x, y);
	int stt = 1;
	Diem_so_sv* sv = l.pHead;
	while (sv != nullptr)
	{
		in_1_sv_co_diem(x, y + stt, sv, stt);
		sv = sv->pNext;
		stt++;
	}
	ve_hop(x, y, 103, stt);
}

bool Kiem_tra_ton_tai_sv(List_diem_so_sv l, string mssv, Diem_so_sv*& d)
{
	d = l.pHead;
	while (d != nullptr)
	{
		if (d->mssv == mssv)
			return true;
		d = d->pNext;
	}
	return false;
}

void cap_nhat_ket_qua()
{
	system("cls");
	string tenkhoahoc, tenlop, link;
	goto_XY(34, 10);
	cout << "Nhap ten khoa hoc: ";
	goto_XY(34, 11);
	cout << "Nhap lop: ";
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
		goto_XY(53, 10);
		getline(cin, tenkhoahoc);
		goto_XY(44, 11);
		getline(cin, tenlop);
		string ktra = hoc_ki + "/" + tenkhoahoc + " " + tenlop;
	}
	Xoa_dong(6);
	string file_diem;
	file_diem = hoc_ki + "/" + tenkhoahoc + " " + tenlop + "/Danh sach sinh vien (Diem so).csv";
	ifstream fin;
	fin.open(file_diem);
	if (!fin)
	{
		goto_XY(34, 12);
		cout << "Khoa hoc cua lop hoc nay chua co diem. Vui long quay lai sau.";
		fin.close();
		return;
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

	string mssv_capnhat;
	goto_XY(34, 12);
	cout << "MSSV can thay doi diem: ";
	getline(cin, mssv_capnhat);
	Diem_so_sv* dsv;
	while (Kiem_tra_ton_tai_sv(l, mssv_capnhat, dsv) == false)
	{
		Xoa_dong(13);
		goto_XY(34, 6);
		cout << "Sinh vien nay khong co trong danh sach. Vui long nhap lai.";
		Xoa_dong(12);
		goto_XY(34, 12);
		cout << "MSSV can thay doi diem: ";
		getline(cin, mssv_capnhat);
	}
	system("cls");
	goto_XY(34, 10);
	cout << "Cap nhat lai diem cho sinh vien " << mssv_capnhat;
	goto_XY(34, 11);
	cout << "Diem trung binh mon: ";
	goto_XY(34, 12);
	cout << "Diem cuoi ki: ";
	goto_XY(34, 13);
	cout << "Diem giua ki: ";
	goto_XY(34, 14);
	cout << "Diem thuong xuyen: ";
	goto_XY(56, 11);
	cin >> dsv->dtb_mon;
	goto_XY(48, 12);
	cin >> dsv->diem_cuoi_ki;
	goto_XY(48, 13);
	cin >> dsv->diem_giua_ki;
	goto_XY(53, 14);
	cin >> dsv->diem_qua_trinh;

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
	cout << "Cap nhat diem thanh cong.";
}

