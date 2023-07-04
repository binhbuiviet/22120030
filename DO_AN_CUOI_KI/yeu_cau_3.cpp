#include "yeu_cau_3.h"

void Tao_list_lop(List_lop_hoc& l)
{
	l.pHead = nullptr;
	l.pTail = nullptr;
}

void Tao_node_lop(Lop_hoc*& a, string ten)
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
	fin.open("LOP/Danh sach cac lop.txt");
	string ten_lop;
	string ktra_nam_hoc = nam_hoc_hien_tai.substr(2, 2);
	int knh = stoi(ktra_nam_hoc);
	while (getline(fin, ten_lop, '\n'))
	{
		if (ten_lop == "")
			break;
		Lop_hoc* a;
		Tao_node_lop(a, ten_lop);
		string lop = ten_lop.substr(0, 2); //LƯU Ý CÁI NÀY CÓ THỂ ĐÃ SAI Ở NHỮNG FILE CPP TRƯỚC, CẦN SỬA LẠI
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

void xuat_list_lop(List_lop_hoc l)
{
	Lop_hoc* a = l.pHead;
	int y = 10;
	while (a != nullptr)
	{
		goto_XY(55, y);
		cout << a->ten_lop << "\n";
		a = a->pNext;
		y++;
	}
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
	//MENU cho người dùng nhấn muốn xem năm nào
	char c = '1';
	while (c == '1')
	{
		system("cls");
		int chon;
		cout << "Nhan 1: Cac lop nam nhat.\n"
			<< "Nhan 2: Cac lop nam hai.\n"
			<< "Nhan 3: Cac lop nam ba.\n"
			<< "Nhan 4: Cac lop nam bon.\n"
			<< "Moi ban chon: ";
		cin >> chon;
		while (chon < 1 || chon>4)
		{
			system("cls");
			cout << "Chon lai.\n"
				<< "Nhan 1: Cac lop nam nhat.\n"
				<< "Nhan 2: Cac lop nam hai.\n"
				<< "Nhan 3: Cac lop nam ba.\n"
				<< "Nhan 4: Cac lop nam bon.\n"
				<< "Moi ban chon: ";
			cin >> chon;
		}
		system("cls");
		ve_hop(50, 8, 20, 9);
		switch (chon)
		{
		case 1:
			xuat_list_lop(nam1);
			break;
		case 2:
			xuat_list_lop(nam2);
			break;
		case 3:
			xuat_list_lop(nam3);
			break;
		case 4:
			xuat_list_lop(nam4);
			break;
		}
		goto_XY(50, 20);
		cout << "Ban co muon tiep tuc khong?";
		goto_XY(50, 21);
		cout << "Nhan 1: Tiep tuc.";
		goto_XY(50, 22);
		cout << "Nhan 0: THOAT.";
		goto_XY(50, 23);
		cout << "Moi ban chon: ";
		cin >> c;
		while (c != '1' && c != '0')
		{
			goto_XY(50, 23);
			cout << "Moi ban nhap lai: ";
			cin >> c;
		}
	}
}

void xem_dssv_trong_lop()
{
	List_sinh_vien l;
	string ten_lop;
	Tao_danh_sach(l);
	ifstream fin;
	system("cls");
	goto_XY(34, 10);
	cout << "Nhap lop muon xem danh sach sinh vien: ";
	getline(cin, ten_lop);
	fin.open("LOP/" + ten_lop + ".csv");
	while (!fin)
	{
		system("cls");
		goto_XY(34, 9);
		cout << "Lop ban vua nhap khong ton tai. Vui long nhap lai.";
		goto_XY(34, 10);
		cout << "Nhap lop muon xem danh sach sinh vien: ";
		getline(cin, ten_lop);
		fin.open("LOP/" + ten_lop + ".csv");
	}
	string temp;
	getline(fin, temp, '\n');
	int so_luong = 0;
	while (fin.eof() != true)
	{
		sinh_vien* sv = new sinh_vien;
		Doc_sinh_vien_tu_file(fin, sv);
		if (sv->mssv == "")
			break;
		Them_sv_vao_duoi_danh_sach(l, sv);
		so_luong++;
	}
	fin.close();

	//Xuat danh sach sinh vien ra man hinh
	system("cls");
	ve_cau_truc_them_sv_vao_lop(6, 5);
	int x = 6;
	int y = 4;
	int w = 105;
	int h = 3;
	sinh_vien* a = l.pHead;
	ve_hop(x, y, w, h + so_luong - 1);
	int stt = 1;
	while (a != nullptr)
	{
		Xuat_1_sv_cua_lop(a, x, y + h - 1, stt);
		h++;
		stt++;
		a = a->pNext;
	}
	goto_XY(6, 3 + so_luong + 9);
}

void Lay_list_khoa_hoc(List_khoa_hoc& l, ifstream& fin)
{
	khoa_hoc* k = new khoa_hoc;
	getline(fin, k->ma_mon_hoc, ',');
	if (k->ma_mon_hoc == "")
		return;
	getline(fin, k->ten_khoa_hoc, ',');
	getline(fin, k->ten_lop, ',');
	getline(fin, k->ten_giang_vien, ',');
	string so_tin_chi, sinh_vien_toi_da;
	getline(fin, so_tin_chi, ',');
	k->so_tin_chi = stoi(so_tin_chi);
	getline(fin, sinh_vien_toi_da, ',');
	k->sinh_vien_toi_da = stoi(sinh_vien_toi_da);
	getline(fin, k->buoi_hoc, ',');
	getline(fin, k->khung_gio, '\n');
	k->pNext = nullptr;
	Them_khoa_hoc_vao_duoi_danh_sach(l, k);
}

void bang_ds_khoa_hoc(List_khoa_hoc l)
{
	int x = 0;
	int y = 8;
	goto_XY(x + 2, y);
	cout << "STT";
	goto_XY(x + 6, y);
	cout << "|";
	goto_XY(x + 6, y + 1);
	cout << "|";
	goto_XY(x + 8, y);
	cout << "Ma mon";
	goto_XY(x + 8, y + 1);
	cout << "hoc";
	goto_XY(x + 17, y);
	cout << "|";
	goto_XY(x + 17, y + 1);
	cout << "|";
	goto_XY(x + 19, y);
	cout << "Ten khoa hoc";
	goto_XY(x + 45, y);
	cout << "|";
	goto_XY(x + 45, y + 1);
	cout << "|";
	goto_XY(x + 47, y);
	cout << "Ten lop";
	goto_XY(x + 58, y);
	cout << "|";
	goto_XY(x + 58, y + 1);
	cout << "|";
	goto_XY(x + 60, y);
	cout << "Ten giang vien";
	goto_XY(x + 87, y);
	cout << "|";
	goto_XY(x + 87, y + 1);
	cout << "|";
	goto_XY(x + 89, y);
	cout << "So";
	goto_XY(x + 89, y + 1);
	cout << "TC";
	goto_XY(x + 92, y);
	cout << "|";
	goto_XY(x + 92, y + 1);
	cout << "|";
	goto_XY(x + 94, y);
	cout << "So SV";
	goto_XY(x + 100, y);
	cout << "|";
	goto_XY(x + 100, y + 1);
	cout << "|";
	goto_XY(x + 102, y);
	cout << "Buoi hoc";
	goto_XY(x + 111, y);
	cout << "|";
	goto_XY(x + 111, y + 1);
	cout << "|";
	goto_XY(x + 113, y);
	cout << "Khung";
	goto_XY(x + 113, y + 1);
	cout << "gio";
	goto_XY(x + 19, y + 2);
	khoa_hoc* k = l.pHead;
	int stt = 0;
	y++;
	while (k != nullptr)
	{
		stt++;
		goto_XY(x + 2, y + stt);
		cout << stt;
		goto_XY(x + 6, y + stt);
		cout << "|";
		goto_XY(x + 8, y + stt);
		cout << k->ma_mon_hoc;
		goto_XY(x + 17, y + stt);
		cout << "|";
		goto_XY(x + 19, y + stt);
		cout << k->ten_khoa_hoc;
		goto_XY(x + 45, y + stt);
		cout << "|";
		goto_XY(x + 47, y + stt);
		cout << k->ten_lop;
		goto_XY(x + 58, y + stt);
		cout << "|";
		goto_XY(x + 60, y + stt);
		cout << k->ten_giang_vien;
		goto_XY(x + 87, y + stt);
		cout << "|";
		goto_XY(x + 89, y + stt);
		cout << k->so_tin_chi;
		goto_XY(x + 92, y + stt);
		cout << "|";
		goto_XY(x + 94, y + stt);
		cout << k->sinh_vien_toi_da;
		goto_XY(x + 100, y + stt);
		cout << "|";
		goto_XY(x + 102, y + stt);
		cout << k->buoi_hoc;
		goto_XY(x + 111, y + stt);
		cout << "|";
		goto_XY(x + 113, y + stt);
		cout << k->khung_gio;
	}
	y--;
	ve_hop(x, y, 146, stt + 1);
}

void xem_ds_khoa_hoc()
{
	system("cls");
	goto_XY(34, 5);
	cout << "Chon nam hoc: ";
	goto_XY(34, 6);
	cout << "Hoc ki: (1/2/3) ";
	string nam_hoc;
	int hoc_ki;
	goto_XY(48, 10);
	getline(cin, nam_hoc);
	goto_XY(50, 11);
	cin >> hoc_ki;
	string ten = nam_hoc + "/Hoc ki " + to_string(hoc_ki);
	while (Kiem_tra_folder(ten)==false)
	{
		system("cls");
		goto_XY(34, 9);
		cout << "Nam hoc hoac hoc ki ban vua nhap chua duoc tao. Vui long nhap lai.";
		goto_XY(34, 10);
		cout << "Chon nam hoc: ";
		goto_XY(34, 11);
		cout << "Hoc ki: (1/2/3) ";
		goto_XY(48, 10);
		getline(cin, nam_hoc);
		goto_XY(50, 11);
		cin >> hoc_ki;
		string ten = nam_hoc + "/Hoc ki " + to_string(hoc_ki);
	}
	ifstream fin;
	fin.open(ten + "/Thong tin khoa hoc.txt");
	string temp;
	getline(fin, temp, '\n');
	List_khoa_hoc l;
	Tao_list_khoa_hoc(l);
	while (fin.eof() != true)
	{
		Lay_list_khoa_hoc(l, fin);
	}
	fin.close();
	bang_ds_khoa_hoc(l);
}

void xem_sv_trong_khoa_hoc()
{
	system("cls");
	goto_XY(34, 5);
	cout << "Chon nam hoc: ";
	goto_XY(34, 6);
	cout << "Hoc ki: (1/2/3) ";
	goto_XY(34, 7);
	cout << "Ten khoa hoc: ";
	string nam_hoc, ten_khoa_hoc;
	int hoc_ki;
	goto_XY(48, 10);
	getline(cin, nam_hoc);
	goto_XY(50, 11);
	cin >> hoc_ki;
	goto_XY(48, 12);
	getline(cin, ten_khoa_hoc);
	string ten = nam_hoc + "/Hoc ki " + to_string(hoc_ki) + "/" + ten_khoa_hoc + "/Danh sach Sinh vien.csv";

	ifstream fin;
	fin.open(ten);
	while (!fin)
	{
		system("cls");
		goto_XY(34, 3);
		cout << "Nam hoc, hoac hoc ki, hoac khoa hoc ban vua nhap chua duoc khoi tao. Vui long nhap lai.";
		goto_XY(34, 5);
		cout << "Chon nam hoc: ";
		goto_XY(34, 6);
		cout << "Hoc ki: (1/2/3) ";
		goto_XY(34, 7);
		cout << "Ten khoa hoc: ";
		string nam_hoc, ten_khoa_hoc;
		int hoc_ki;
		goto_XY(48, 10);
		getline(cin, nam_hoc);
		goto_XY(50, 11);
		cin >> hoc_ki;
		goto_XY(48, 12);
		getline(cin, ten_khoa_hoc);
		string ten = nam_hoc + "/Hoc ki " + to_string(hoc_ki) + "/" + ten_khoa_hoc + "/Danh sach Sinh vien.csv";
		fin.open(ten);
	}
	string temp;
	getline(fin, temp, '\n');
	List_sinh_vien l;
	Tao_danh_sach(l);
	while (fin.eof() != true)
	{
		sinh_vien* sv = new sinh_vien;
		Doc_sinh_vien_tu_file(fin, sv);
		if (sv->mssv == "")
			break;
		Them_sv_vao_duoi_danh_sach(l, sv);
	}
	fin.close();

	ve_cau_truc_them_sv_vao_lop(6, 9);
	int x = 6;
	int y = 9;
	int w = 105;
	int h = 3;
	int stt = 0;
	sinh_vien* a = l.pHead;
	while (a != nullptr)
	{
		stt++;
		Xuat_1_sv_cua_lop(a, x, y + h - 1, stt);
		h++;
		a = a->pNext;
	}
	ve_hop(x, y, w, stt + 2);
}

