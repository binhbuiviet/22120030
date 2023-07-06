#include "chung.h"


Thoi_gian_hien_tai tght;
string nam_hoc_hien_tai = "";
string hoc_ki = ""; //Mục đích của string này là để tạo folder học kì, gán nó trong folder năm học đã tạo trước đó
string thong_tin_cac_khoa_hoc = "";
//Lấy thời gian hiện tại
void Lay_thoi_gian_hien_tai()
{
	time_t bay_gio = time(0); //Lấy số giây đã trôi qua tính từ ngày 1/1/1970 đến thời gian hiện tại trên hệ thống
	tm* temp = localtime(&bay_gio);
	string wday;
	switch (temp->tm_wday)
	{
	case 0:
		wday = "Chu nhat";
		break;
	case 1:
		wday = "Thu hai";
		break;
	case 2:
		wday = "Thu ba";
		break;
	case 3:
		wday = "Thu tu";
		break;
	case 4:
		wday = "Thu nam";
		break;
	case 5:
		wday = "Thu sau";
		break;
	case 6:
		wday = "Thu bay";
		break;
	}
	tght.ngay = temp->tm_mday;
	tght.thang = 1 + temp->tm_mon;
	tght.nam = 1900 + temp->tm_year;
	tght.wday = wday;
}

bool Kiem_tra_folder(string& ten_folder)
{
	DWORD ton_tai_folder = GetFileAttributesA(ten_folder.c_str());
	//DWORD là kiểu dữ liệu của thư viện <windows.h> để đại diện cho giá trị trả về từ hàm GetFileAttributesA
	//GetFileAttributesA là hàm có sẵn trong thư viện <windows.h> dùng để xác định thuộc tính của thư mục đã có hay chưa
	if (ton_tai_folder == INVALID_FILE_ATTRIBUTES)
		return false; //Nếu folder chưa có thì ton_tai_folder sẽ có giá trị là invalid_file_attributes

	if (ton_tai_folder & FILE_ATTRIBUTE_DIRECTORY)
		return true; //Nếu có rồi thì sẽ có giá trị FILE_ATTRIBUTE_DIRECTORY 

	return false;
}

bool Tao_folder(string& ten_folder)
{
	if (CreateDirectoryA(ten_folder.c_str(), NULL) || GetLastError() == ERROR_ALREADY_EXISTS)
		return true; //Nếu việc tạo folder bằng hàm CreateDirectoryA trả về true hoặc hàm xác định folder tồn tại GetLastError() = error_already_exists thì tức là folder đc tạo xong
	return false;
	//2 hàm CreateDirectoryA và GetLastError() là 2 hàm có sẵn trong thư viện <windows.h>
}
//Lưu ý, 2 hàm bool này chỉ chạy được trên hệ điều hành Window

void Tao_folder_lop()
{
	string lop = "LOP";
	if (Kiem_tra_folder(lop) == false)
	{
		bool a = Tao_folder(lop);
		ofstream fout;
		fout.open("LOP/Danh sach cac lop.txt");
		fout.close();
	}
}

void Nhap_1_sinh_vien(sinh_vien*& sv, int x, int y, int stt)
{
	sv = new sinh_vien;
	goto_XY(x + 2, y);
	cout << stt;
	goto_XY(x + 7, y);
	cout << "|";
	goto_XY(x + 10, y);
	getline(cin, sv->mssv);
	goto_XY(x + 20, y);
	cout << "|";
	goto_XY(x + 23, y);
	getline(cin, sv->ho);
	goto_XY(x + 42, y);
	cout << "|";
	goto_XY(x + 45, y);
	getline(cin, sv->ten);
	goto_XY(x + 55, y);
	cout << "|";
	goto_XY(x + 58, y);
	getline(cin, sv->gioi_tinh);
	while (sv->gioi_tinh != "Nam" && sv->gioi_tinh != "Nu")
	{
		goto_XY(x + 58, y);
		cout << "   ";
		goto_XY(x + 58, y);
		getline(cin, sv->gioi_tinh);
	}
	goto_XY(x + 68, y);
	cout << "|";
	goto_XY(x + 71, y);
	getline(cin, sv->ngay_sinh);
	goto_XY(x + 82, y);
	cout << "|";
	goto_XY(x + 85, y);
	getline(cin, sv->cccd);
	sv->pNext = nullptr;
}

void Tao_list_khoa_hoc(List_khoa_hoc& l)
{
	l.pHead = nullptr;
	l.pTail = nullptr;
}

void Them_khoa_hoc_vao_duoi_danh_sach(List_khoa_hoc& l, khoa_hoc* k)
{
	if (l.pHead == nullptr)
	{
		l.pHead = k;
		l.pTail = k;
	}
	else
	{
		l.pTail->pNext = k;
		l.pTail = k;
	}
}

void Xoa_khoa_hoc_khoi_dau_danh_sach(List_khoa_hoc& l)
{
	if (l.pHead == nullptr)
		return;
	khoa_hoc* temp = l.pHead;
	l.pHead = l.pHead->pNext;
	delete temp;
}

void xoa_khoa_hoc_bat_ki_khoi_danh_sach(List_khoa_hoc& l, khoa_hoc* a, khoa_hoc* b)
{
	b->pNext = a->pNext;
	delete a;
}

void Tao_danh_sach(List_sinh_vien& l)
{
	l.pHead = nullptr;
	l.pTail = nullptr;
}

void Them_sv_vao_duoi_danh_sach(List_sinh_vien& l, sinh_vien* sv)
{
	if (l.pHead == nullptr)
	{
		l.pHead = sv;
		l.pTail = sv;
	}
	else
	{
		l.pTail->pNext = sv;
		l.pTail = sv;
	}
}

void ve_cau_truc_them_sv_vao_lop(int x, int y)
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
	cout << "Ho";
	goto_XY(x + 42, y);
	cout << "|";
	goto_XY(x + 45, y);
	cout << "Ten";
	goto_XY(x + 55, y);
	cout << "|";
	goto_XY(x + 58, y);
	cout << "Gioi tinh";
	goto_XY(x + 68, y);
	cout << "|";
	goto_XY(x + 71, y);
	cout << "Ngay sinh";
	goto_XY(x + 82, y);
	cout << "|";
	goto_XY(x + 85, y);
	cout << "CCCD/CMND";
}

void Doc_sinh_vien_tu_file(ifstream& fin, sinh_vien*& sv)
{
	string stt;
	getline(fin, stt, ',');
	getline(fin, sv->mssv, ',');
	if (sv->mssv == "")
		return;
	getline(fin, sv->ho, ',');
	getline(fin, sv->ten, ',');
	getline(fin, sv->gioi_tinh, ',');
	getline(fin, sv->ngay_sinh, ',');
	getline(fin, sv->cccd, '\n');
	sv->pNext = nullptr;
}

void Ghi_1_sinh_vien_vao_file(ofstream& fout, sinh_vien* n, int thu_tu)
{
	fout << thu_tu << ","
		<< n->mssv << ","
		<< n->ho << ","
		<< n->ten << ","
		<< n->gioi_tinh << ","
		<< n->ngay_sinh << ","
		<< n->cccd << "\n";
}

void xoa_sv_dau(List_sinh_vien& l)
{
	if (l.pHead == nullptr)
		return;
	sinh_vien* temp = l.pHead;
	l.pHead = l.pHead->pNext;
	delete temp;
}


void xoa_sv_bat_ki(List_sinh_vien& l, string mssv)
{
	if (l.pHead == nullptr)
	{
		cout << "Lop chua duoc khoi tao.\n";
		return;
	}
	if (l.pHead->mssv == mssv)
	{
		xoa_sv_dau(l);
		return;
	}
	sinh_vien* temp = l.pHead;
	sinh_vien* a = l.pHead;
	while (temp != nullptr && temp->mssv != mssv)
	{
		a = temp;
		temp = temp->pNext;
	}
	if (temp == nullptr)
	{
		cout << "Khong co sinh vien do trong lop nay.\n";
		return;
	}
	if (temp == l.pTail)
	{
		l.pTail = a;
		a->pNext = nullptr;
		delete temp;
		return;
	}
	a->pNext = temp->pNext;
	delete temp;
	cout << "Da xoa thanh cong sinh vien ra khoi lop.\n";
}

void xoa_tep_tin(const string& folder)
{
	const char* x_folder = folder.c_str();
	int xoa = remove(x_folder);
}

void Xuat_1_sv_cua_lop(sinh_vien* sv, int x, int y, int stt)
{
	goto_XY(x + 2, y);
	cout << stt;
	goto_XY(x + 7, y);
	cout << "|";
	goto_XY(x + 10, y);
	cout << sv->mssv;
	goto_XY(x + 20, y);
	cout << "|";
	goto_XY(x + 23, y);
	cout << sv->ho;
	goto_XY(x + 42, y);
	cout << "|";
	goto_XY(x + 45, y);
	cout << sv->ten;
	goto_XY(x + 55, y);
	cout << "|";
	goto_XY(x + 58, y);
	cout << sv->gioi_tinh;
	goto_XY(x + 68, y);
	cout << "|";
	goto_XY(x + 71, y);
	cout << sv->ngay_sinh;
	goto_XY(x + 82, y);
	cout << "|";
	goto_XY(x + 85, y);
	cout << sv->cccd;
}

void Nhap_khoa_hoc_vao_file(fstream& f, khoa_hoc* k)
{
	f << k->ma_mon_hoc << ","
		<< k->ten_khoa_hoc << ","
		<< k->ten_lop << ","
		<< k->ten_giang_vien << ","
		<< k->so_tin_chi << ","
		<< k->sinh_vien_toi_da << ","
		<< k->buoi_hoc << ","
		<< k->khung_gio << "\n";
}

void Lay_list_khoa_hoc(ifstream& fin, List_khoa_hoc& l)
{
	khoa_hoc* k = new khoa_hoc;
	string so_tin_chi, sinh_vien_toi_da;
	getline(fin, k->ma_mon_hoc, ',');
	if (k->ma_mon_hoc == "")
		return;
	getline(fin, k->ten_khoa_hoc, ',');
	getline(fin, k->ten_lop, ',');
	getline(fin, k->ten_giang_vien, ',');
	getline(fin, so_tin_chi, ',');
	k->so_tin_chi = stoi(so_tin_chi);
	getline(fin, sinh_vien_toi_da, ',');
	k->sinh_vien_toi_da = stoi(sinh_vien_toi_da);
	getline(fin, k->buoi_hoc, ',');
	getline(fin, k->khung_gio, '\n');
	k->pNext = nullptr;
	Them_khoa_hoc_vao_duoi_danh_sach(l, k);
}

bool Doi_ten_file(const string& ten_cu, const string& ten_moi)
{
	if (rename(ten_cu.c_str(), ten_moi.c_str()) == 0)
		return true;
	else
		return false;
}

void Doc_khoa_hoc_cua_sv(List_khoa_hoc& l, string mssv)
{
	Tao_list_khoa_hoc(l);
	string mssv_hocki = "Sinh vien/" + mssv + "/" + hoc_ki + "/Thong tin khoa hoc.csv";
	string temp;
	ifstream fin;
	fin.open(mssv_hocki);
	getline(fin, temp, '\n');
	while (fin.eof() != true)
	{
		Lay_list_khoa_hoc(fin, l);
	}
	fin.close();
}

void Xoa_1_khoa_hoc(List_khoa_hoc& l, string ten_khoa_hoc, string ten_lop)
{
	khoa_hoc* a = l.pHead;
	if (a->ten_khoa_hoc == ten_khoa_hoc && a->ten_lop == ten_lop)
	{
		Xoa_khoa_hoc_khoi_dau_danh_sach(l);
		return;
	}
	khoa_hoc* b = l.pHead;
	while (a->ten_lop != ten_lop && a->ten_khoa_hoc != ten_khoa_hoc && a != nullptr)
	{
		b = a;
		a = a->pNext;
	}
	if (a == nullptr)
	{
		goto_XY(34, 13);
		cout << "Sinh vien do khong co trong khoa hoc o lop nay.";
		return;
	}
	xoa_khoa_hoc_bat_ki_khoi_danh_sach(l, a, b);
	goto_XY(34, 13);
	cout << "Da xoa thanh cong.";
}

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
