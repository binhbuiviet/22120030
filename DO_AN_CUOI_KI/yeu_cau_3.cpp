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
	ve_hop_them_sv_vao_lop(6, 5);
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

void Lay_list_khoa_hoc(List_khoa_hoc& l)
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

void xem_ds_khoa_hoc()
{

}