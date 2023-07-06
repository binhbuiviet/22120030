#include "dang_nhap.h"

void Tao_list_nguoi_dung_ht(List_nguoi_dung_hien_tai& l)
{
	l.pHead = nullptr;
	l.pTail = nullptr;
}

void Them_nguoi_dung_vao_duoi_ds(List_nguoi_dung_hien_tai& l, Nguoi_dung_hien_tai* n)
{
	if (l.pHead == nullptr)
	{
		l.pHead = n;
		l.pTail = n;
	}
	else
	{
		l.pTail->pNext = n;
		l.pTail = n;
	}
}

void Doc_nguoi_dung_tu_file(ifstream& fin, List_nguoi_dung_hien_tai& l)
{
	Nguoi_dung_hien_tai* n = new Nguoi_dung_hien_tai;
	getline(fin, n->me, ',');
	if (n->me == "")
		return;
	getline(fin, n->mat_khau, ',');
	getline(fin, n->hoten, ',');
	getline(fin, n->gioi_tinh, ',');
	getline(fin, n->sinh_nhat, ',');
	getline(fin, n->cccd, '\n');
	n->pNext = nullptr;
	Them_nguoi_dung_vao_duoi_ds(l, n);
}

void Dang_nhap_tai_khoan_GV()
{
	string Email, Password;
	char PASS;
	system("cls");
	goto_XY(34, 10);
	cout << "Email: ";
	cin >> Email;
	goto_XY(34, 11);
	cout << "Mat khau: ";

	// Mã hóa mật khẩu để xuất ra màn hình dấu *
	for (int i = 1; i <= 1000; i++)
	{
		PASS = _getch(); // Tìm hiểu cái getch này nha

		if (PASS == 13)
		{
			break;
		}
		Password += PASS;
		if (PASS == 127 || PASS == 8) {
			printf("\b \b");   // Cái này dùng để nếu khi nhập mật khẩu mình nhấn dấu xóa (backspace) thì trên màn hình cũng sẽ xóa bấy nhiêu dấu * 
		}
		else {
			cout << "*";
		}
	}
	//Kiểm tra email đăng nhập và mật khẩu trong file Luu_email_va_Mat_khau_Giang_vien.txt  
	ifstream check;
	check.open("Giao vu.txt");
	if (!check)
	{
		goto_XY(34, 12);
		cout << "Khong the mo file.\n";
		return;
	}
	List_nguoi_dung_hien_tai l;
	Tao_list_nguoi_dung_ht(l);
	while (check.eof() != true)
		Doc_nguoi_dung_tu_file(check, l);
	check.close();
	Nguoi_dung_hien_tai* nd = l.pHead;
	while (nd != nullptr)
	{
		if (nd->me == Email && nd->mat_khau == Password)
			break;
		nd = nd->pNext;
	}
	if (nd != nullptr)
	{
		Giao_vu(nd);
	}
	else
	{
		goto_XY(34, 12);
		cout << "Email hoac mat khau khong chinh xac. Vui long thu lai.";
		goto_XY(34, 13);
		cout << "Nhan bat ki phim nao de quay lai.";
		char g;
		g = _getch();
	}
}

void Giao_dien_giao_vu()
{
	system("cls");
	goto_XY(15, 8);
	cout << "1. Xem thong tin.";
	goto_XY(15, 9);
	cout << "2. Doi mat khau.";
	goto_XY(15, 10);
	cout << "3. Tao nam hoc moi.";
	goto_XY(15, 11);
	cout << "4. Thao tac voi cac lop";
	goto_XY(15, 12);
	cout << "5. Thao tac voi cac khoa hoc.";
	goto_XY(15, 13);
	cout << "6. Xem cac thong tin giao vu.";
	goto_XY(15, 14);
	cout << "7. Quan li ket qua hoc tap.";
	goto_XY(15, 15);
	cout << "8. DANG XUAT.";
}

void Thao_tac_voi_cac_lop()
{
	int chon;
	while (1)
	{
		char g;
		system("cls");
		goto_XY(15, 8);
		cout << "1. Tao lop cho sinh vien nam nhat.";
		goto_XY(15, 9);
		cout << "2. Them sinh vien nam nhat vao lop.";
		goto_XY(15, 10);
		cout << "3. Them sinh vien nam nhat vao lop (nhanh).";
		goto_XY(15, 11);
		cout << "4. Quay ve.";
		goto_XY(15, 12);
		cout << "Moi ban chon: ";
		cin >> chon;
		cin.ignore();
		switch (chon)
		{
		case 1:
			Tao_lop();
			goto_XY(34, 14);
			cout << "Nhan bat ki phim nao de tiep tuc.";
			g = _getch();
			break;
		case 2:
			Them_sv_vao_file();
			goto_XY(34, 2);
			cout << "Nhan bat ki phim nao de tiep tuc.";
			g = _getch();
			break;
		case 3:
			Them_sinh_vien_vao_file_nhanh();
			goto_XY(34, 2);
			cout << "Nhan bat ki phim nao de tiep tuc.";
			g = _getch();
			break;
		case 4:
			break;
		default: goto_XY(34, 14);
			cout << "Gia tri nhap khong hop le. Vui long nhap lai....";
			goto_XY(34, 15);
			cout << "Nhan bat ki phim nao de tiep tuc: ";
			g = getch();
		}
		if (chon == 4)
			break;
	}
}

void Thao_tac_voi_cac_khoa_hoc()
{
	int chon;
	while (1)
	{
		char g;
		system("cls");
		goto_XY(15, 8);
		cout << "1. Tao hoc ki.";
		goto_XY(15, 9);
		cout << "2. Them 1 khoa hoc vao hoc ki.";
		goto_XY(15, 10);
		cout << "3. Them sinh vien vao khoa hoc bang file (nhanh).";
		goto_XY(15, 11);
		cout << "4. Xem danh sach cac khoa hoc.";
		goto_XY(15, 12);
		cout << "5. Cap nhat thong tin khoa hoc.";
		goto_XY(15, 13);
		cout << "6. Them 1 sinh vien vao khoa hoc.";
		goto_XY(15, 14);
		cout << "7. Dua 1 sinh vien ra khoi khoa hoc.";
		goto_XY(15, 15);
		cout << "8. Xoa khoa hoc.";
		goto_XY(15, 16);
		cout << "9. Quay ve.";
		goto_XY(15, 17);
		cout << "Moi ban chon: ";
		cin >> chon;
		cin.ignore();
		switch (chon)
		{
		case 1:
			tao_hoc_ky();
			goto_XY(34, 16);
			cout << "Nhan bat ki phim nao de tiep tuc.";
			g = _getch();
			break;
		case 2:
			tao_khoa_hoc();
			goto_XY(34, 2);
			cout << "Nhan bat ki phim nao de tiep tuc.";
			g = _getch();
			break;
		case 3:
			Dang_danh_sach_sinh_vien_vao_khoa_hoc();
			goto_XY(34, 2);
			cout << "Nhan bat ki phim nao de tiep tuc.";
			g = _getch();
			break;
		case 4:
			xem_ds_khoa_hoc();
			goto_XY(34, 3);
			cout << "Nhan bat ki phim nao de tiep tuc.";
			g = _getch();
			break;
		case 5:
			Cap_nhat_khoa_hoc();
			goto_XY(34, 3);
			cout << "Nhan bat ki phim nao de tiep tuc.";
			g = _getch();
			break;
		case 6:
			Them_mot_sinh_vien_vao_khoa_hoc();
			goto_XY(34, 2);
			cout << "Nhan bat ki phim nao de tiep tuc.";
			g = _getch();
			break;
		case 7:
			Xoa_mot_sinh_vien_khoi_khoa_hoc();
			goto_XY(34, 2);
			cout << "Nhan bat ki phim nao de tiep tuc.";
			g = _getch();
			break;
		case 8:
			xoa_khoa_hoc();
			goto_XY(34, 2);
			cout << "Nhan bat ki phim nao de tiep tuc.";
			g = _getch();
			break;
		case 9:
			break;
		default: goto_XY(34, 14);
			cout << "Gia tri nhap khong hop le. Vui long nhap lai....";
			goto_XY(34, 15);
			cout << "Nhan bat ki phim nao de tiep tuc: ";
			g = getch();
		}
		if (chon == 9)
			break;
	}
}

void Xem_thong_tin_giao_vu()
{
	int chon;
	while (1)
	{
		char g;
		system("cls");
		goto_XY(15, 8);
		cout << "1. Xem danh sach cac lop.";
		goto_XY(15, 9);
		cout << "2. Xem danh sach sinh vien trong lop.";
		goto_XY(15, 10);
		cout << "3. Xem danh sach cac khoa hoc";
		goto_XY(15, 11);
		cout << "4. Xem danh sach sinh vien trong khoa hoc.";
		goto_XY(15, 12);
		cout << "5. Quay ve.";
		goto_XY(15, 13);
		cout << "Moi ban chon: ";
		cin >> chon;
		cin.ignore();
		switch (chon)
		{
		case 1:
			Xem_cac_lop();
			goto_XY(34, 2);
			cout << "Nhan bat ki phim nao de tiep tuc.";
			g = _getch();
			break;
		case 2:
			xem_dssv_trong_lop();
			goto_XY(34, 2);
			cout << "Nhan bat ki phim nao de tiep tuc.";
			g = _getch();
			break;
		case 3:
			xem_ds_khoa_hoc();
			goto_XY(34, 2);
			cout << "Nhan bat ki phim nao de tiep tuc.";
			g = _getch();
			break;
		case 4:
			xem_sv_trong_khoa_hoc();
			goto_XY(34, 2);
			cout << "Nhan bat ki phim nao de tiep tuc.";
			g = _getch();
			break;
		case 5:
			break;
		default: goto_XY(34, 14);
			cout << "Gia tri nhap khong hop le. Vui long nhap lai....";
			goto_XY(34, 15);
			cout << "Nhan bat ki phim nao de tiep tuc: ";
			g = getch();
		}
		if (chon == 5)
			break;
	}
}

void quan_li_ket_qua_hoc_tap()
{
	int chon;
	while (1)
	{
		char g;
		system("cls");
		goto_XY(15, 8);
		cout << "1. Dua bang diem vao khoa hoc";
		goto_XY(15, 9);
		cout << "2. Xem bang diem cua khoa hoc";
		goto_XY(15, 10);
		cout << "3. Cap nhat ket qua";
		goto_XY(15, 11);
		cout << "4. Quay ve.";
		goto_XY(15, 12);
		cout << "Moi ban chon: ";
		cin >> chon;
		cin.ignore();
		switch (chon)
		{
		case 1:
			Nhap_diem_khoa_hoc();
			goto_XY(34, 8);
			cout << "Nhan bat ki phim nao de tiep tuc.";
			g = _getch();
			break;
		case 2:
			xem_bang_diem_khoa_hoc();
			goto_XY(34, 3);
			cout << "Nhan bat ki phim nao de tiep tuc.";
			g = _getch();
			break;
		case 3:
			cap_nhat_ket_qua();
			goto_XY(34, 3);
			cout << "Nhan bat ki phim nao de tiep tuc.";
			g = _getch();
			break;
		case 4:
			break;
		default: goto_XY(34, 14);
			cout << "Gia tri nhap khong hop le. Vui long nhap lai....";
			goto_XY(34, 15);
			cout << "Nhan bat ki phim nao de tiep tuc: ";
			g = getch();
		}
		if (chon == 4)
			break;
	}
}

void Giao_vu(Nguoi_dung_hien_tai* nd)
{
	int chon;
	Thoi_gian_hien_tai t;
	while (1)
	{
		char g;
		Giao_dien_giao_vu();
		goto_XY (15, 16);
		cout << "Moi ban chon: ";
		cin >> chon;
		cin.ignore();
		switch (chon)
		{
		case 1:
			Xem_profile_GV(nd);
			goto_XY(34, 16);
			cout << "Nhan bat ki phim nao de tiep tuc.";
			g = _getch();
			break;
		case 2:
			Doi_mat_khau_GV(nd);
			break;
		case 3:
			system("cls");
			goto_XY(34, 10);
			if (t.thang == 9)
				cout << "Nam hoc " << nam_hoc_hien_tai << " da tao thanh cong.";
			else
				cout << "Hien tai khong phai la thoi gian de tao nam hoc moi.";
			goto_XY(34, 2);
			cout << "Nhan bat ki phim nao de tiep tuc.";
			g = _getch();
			break;
		case 4:
			Thao_tac_voi_cac_lop();
			break;
		case 5:
			Thao_tac_voi_cac_khoa_hoc();
			break;
		case 6:
			Xem_thong_tin_giao_vu();
			break;
		case 7:
			quan_li_ket_qua_hoc_tap();
			break;
		case 8:
			nd = nullptr;
			Menu_chinh();
			break;
		}
	}
}
void Xem_profile_GV(Nguoi_dung_hien_tai* nd)
{
	system("cls");
	goto_XY(34, 10);
	cout << "Email: " << nd->me;
	goto_XY(34, 11);
	cout << "Ho va ten: " << nd->hoten;
	goto_XY(34, 12);
	cout << "Gioi tinh: " << nd->gioi_tinh;
	goto_XY(34, 13);
	cout << "Sinh nhat: " << nd->sinh_nhat;
	goto_XY(34, 14);
	cout << "CCCD: " << nd->cccd;
	goto_XY(34, 15);
}

void Doi_mat_khau_GV(Nguoi_dung_hien_tai* nd)
{
	ifstream check;
	check.open("Giao vu.txt");
	if (!check)
	{
		goto_XY(34, 12);
		cout << "Khong the mo file.\n";
		return;
	}
	List_nguoi_dung_hien_tai l;
	Tao_list_nguoi_dung_ht(l);
	while (check.eof() != true)
		Doc_nguoi_dung_tu_file(check, l);
	check.close();

	Nguoi_dung_hien_tai* ng = l.pHead;
	while (ng->me != nd->me || ng->mat_khau != nd->mat_khau)
		ng = ng->pNext;
	string pass_cu, pass_moi;
	system("cls");
	goto_XY(34, 10);
	cout << "Nhap lai mat khau cu: ";
	getline(cin, pass_cu);
	if (pass_cu != ng->mat_khau)
	{
		goto_XY(34, 11);
		cout << "Mat khau cu khong dung. Vui long thu lai sau";
		char getch;
		goto_XY(34, 12);
		cout << "Nhan bat ki phim nao de quay lai.";
		getch = _getch();
		return;
	}
	goto_XY(34, 11);
	cout << "Nhap mat khau moi: ";
	getline(cin, pass_moi);
	goto_XY(34, 12);
	cout << "Doi mat khau thanh cong";
	ng->mat_khau = pass_moi;
	nd->mat_khau = pass_moi;

	Nguoi_dung_hien_tai* ndht = l.pHead;
	ofstream fout;
	fout.open("Giao vu.txt");
	while (ndht != nullptr)
	{
		fout << ndht->me << ","
			<< ndht->mat_khau << ","
			<< ndht->hoten << ","
			<< ndht->gioi_tinh << ","
			<< ndht->sinh_nhat << ","
			<< ndht->cccd << "\n";
		ndht = ndht->pNext;
	}
	char getch;
	goto_XY(34, 12);
	cout << "Nhan bat ki phim nao de quay lai.";
	getch = _getch();
}

// Dành cho Học sinh/Sinh viên (Tương tự chưa oke)
void Dang_nhap_tai_khoan_SV()
{
	string MSSV, Password;
	char PASS;
	system("cls");
	goto_XY(34, 10);
	cout << "MSSV: ";
	cin >> MSSV;
	goto_XY(34, 11);
	cout << "Mat khau: ";

	// Mã hóa mật khẩu để xuất ra màn hình dấu *
	for (int i = 1; i <= 1000; i++)
	{
		PASS = _getch(); // Tìm hiểu cái getch này nha

		if (PASS == 13)
		{
			break;
		}
		Password += PASS;
		if (PASS == 127 || PASS == 8) {
			printf("\b \b");   // Cái này dùng để nếu khi nhập mật khẩu mình nhấn dấu xóa (backspace) thì trên màn hình cũng sẽ xóa bấy nhiêu dấu * 
		}
		else {
			cout << "*";
		}
	}
	//Kiểm tra email đăng nhập và mật khẩu trong file Luu_email_va_Mat_khau_Giang_vien.txt
	int d = 0;
	ifstream check;
	check.open("Sinh vien.txt");
	if (!check)
	{
		goto_XY(34, 12);
		cout << "Khong the mo file.\n";
		return;
	}
	List_nguoi_dung_hien_tai l;
	Tao_list_nguoi_dung_ht(l);
	while (check.eof() != true)
		Doc_nguoi_dung_tu_file(check, l);
	check.close();
	Nguoi_dung_hien_tai* nd = l.pHead;
	while (nd != nullptr)
	{
		if (nd->me == MSSV && nd->mat_khau == Password)
			break;
		nd = nd->pNext;
	}
	if (nd != nullptr)
	{
		//Chuyen toi ham cho sinh vien
	}
	else
	{
		goto_XY(34, 12);
		cout << "MSSV hoac mat khau khong chinh xac. Vui long thu lai.";
		system("pause");
	}
	system("pause");
}

void Xem_profile_SV(Nguoi_dung_hien_tai*& nd)
{
	system("cls");
	goto_XY(34, 10);
	cout << "MSSV: " << nd->me;
	goto_XY(34, 11);
	cout << "Ho va ten: " << nd->hoten;
	goto_XY(34, 12);
	cout << "Gioi tinh: " << nd->gioi_tinh;
	goto_XY(34, 13);
	cout << "Sinh nhat: " << nd->sinh_nhat;
	goto_XY(34, 14);
	cout << "CCCD: " << nd->cccd;
	goto_XY(34, 15);
	system("pause");
}

void Menu_chinh()
{
	int ans;
	Tao_mot_nam_hoc();
	do
	{
		system("cls");
		goto_XY(34, 10);
		cout << "1. Ban la Admin.";
		goto_XY(34, 11);
		cout << "2. Ban la sinh vien.";
		goto_XY(34, 12);
		cout << "3. THOAT.";
		goto_XY(34, 13);
		cout << "Nhap lua chon cua ban :: ";
		cin >> ans;

		switch (ans)
		{
		case 1:
			Dang_nhap_tai_khoan_GV();//Hàm dành cho giáo vụ
			break;
		case 2: //Hàm dành cho sinh viên;
			Dang_nhap_tai_khoan_SV();
			break;
		case 3: exit(0);
		default: goto_XY(34, 14);
			cout << "Gia tri nhap khong hop le. Vui long nhap lai....";
			goto_XY(34, 15);
			cout << "Nhan bat ki phim nao de tiep tuc: ";
			char g;
			g = getch();
		}
	} while (1);
}