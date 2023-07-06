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
		//Ham danh cho sinh vien
	}
	else
	{
		goto_XY(34, 12);
		cout << "Email hoac mat khau khong chinh xac. Vui long thu lai.";
		system("pause");
	}
	system("pause");
}

void Giao_vu(Nguoi_dung_hien_tai* nd)
{

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
	system("pause");
}

void Doi_mat_khau_GV(Nguoi_dung_hien_tai& ng)
{
	/*
	* Có một ý tưởng là copy toàn bộ thông tin đăng nhập từ file cũ rồi ghi sang file mới, riêng với mật khẩu mới thì sẽ được thay thế bởi mật khẩu cũ
	* Rồi xóa file cũ rồi đổi tên file mới thành tên của file cũ rồi xóa file cũ
	* Tuy vậy phải luôn luôn tạo file mởi???
	* Có cách nào khác không???
	*/
	fstream check;
	check.open("Luu_email_va_Mat_khau_Giang_vien.txt", ios_base::in);
	fstream filetemp;
	filetemp.open("temp.txt", ios_base::out);
	string pass_cu = "";
	char pass;
	// Nhớ làm hình đẹp hoặc UI cho cái này nha 
	cout << "Nhap mat khau cu: ";
	// Mã hóa mật khẩu để xuất ra màn hình dấu *
	for (int i = 1; i <= 1000; i++)
	{
		pass = _getch(); // Tìm hiểu cái getch này nha

		if (pass == 13)
		{
			break;
		}
		pass_cu += pass;
		if (pass == 127 || pass == 8) {
			printf("\b \b");   // Cái này dùng để nếu khi nhập mật khẩu mình nhấn dấu xóa (backspace) thì trên màn hình cũng sẽ xóa bấy nhiêu dấu * 
		}
		else {
			cout << "*";
		}
	}
	while (pass_cu != ng.mat_khau)
	{
		// Nhớ làm hình đẹp hoặc UI cho cái này nha
		cout << "Mat khau cu chua chinh xac, vui long nhap lai.\n";
		pass_cu = "";
		cout << "Nhap mat khau cu: ";
		// Mã hóa mật khẩu để xuất ra màn hình dấu *
		for (int i = 1; i <= 1000; i++)
		{
			pass = _getch(); // Tìm hiểu cái getch này nha

			if (pass == 13)
			{
				break;
			}
			pass_cu += pass;
			if (pass == 127 || pass == 8) {
				printf("\b \b");   // Cái này dùng để nếu khi nhập mật khẩu mình nhấn dấu xóa (backspace) thì trên màn hình cũng sẽ xóa bấy nhiêu dấu * 
			}
			else {
				cout << "*";
			}
		}
	}
	string pass_moi;
	cout << "Nhap mat khau moi: ";
	for (int i = 1; i <= 1000; i++)
	{
		pass = _getch(); // Tìm hiểu cái getch này nha

		if (pass == 13)
		{
			break;
		}
		pass_moi += pass;
		if (pass == 127 || pass == 8) {
			printf("\b \b");   // Cái này dùng để nếu khi nhập mật khẩu mình nhấn dấu xóa (backspace) thì trên màn hình cũng sẽ xóa bấy nhiêu dấu * 
		}
		else {
			cout << "*";
		}
	}
	//Đạt lại màu với UI chỗ này
	if (!check)
	{
		cout << "Khong the mo file Luu_email_va_Mat_khau_Giang_vien.txt\n";
		return;
	}
	if (!filetemp)
	{
		cout << "Khong the mo file temp.txt\n";
		return;
	}
	while (check.eof() != true)
	{
		string email, password;
		string info;
		while (getline(check, info))
		{   // Tìm hiểu getline này nha ^^
			stringstream input(info);  // 
			input >> email >> password;
			if (pass_cu == password && email == ng.me)
			{
				filetemp << email << " " << pass_moi << "\n";
			}
			else
				filetemp << email << " " << pass_cu << "\n";
		}
	}
	ng.mat_khau = pass_moi;
	check.close();
	filetemp.close();


	fstream copy, copytemp;
	copy.open("Luu_email_va_Mat_khau_Giang_vien.txt", ios_base::out);
	copytemp.open("temp.txt", ios_base::in);
	while (copytemp.eof() != true)
	{
		string email, password;
		string info;
		while (getline(copytemp, info))
		{
			stringstream input(info);
			input >> email >> password;
			copy << email << " " << password << "\n";
		}
	}
	copy.close();
	copytemp.close();
	// Đã viết xong nhưng chưa ktra
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