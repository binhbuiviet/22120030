#include "yeu_cau_1.h"

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
//Tạo một năm học mới
void Tao_mot_nam_hoc()
{
	Lay_thoi_gian_hien_tai();
	if (tght.thang >= 9)
		nam_hoc_hien_tai = to_string(tght.nam) + "-" + to_string(tght.nam + 1);
	else
		nam_hoc_hien_tai = to_string(tght.nam - 1) + "-" + to_string(tght.nam);
	//Kiểm tra xem đã có thư mục năm học đó chưa, nếu chưa thì tạo, nếu có rồi thì thôi =)))
	if (Kiem_tra_folder(nam_hoc_hien_tai))
		cout << "Nam hoc nay da duoc khoi tao.\n"; //Nhớ chỉnh đồ họa nha
	else
	{
		if (Tao_folder(nam_hoc_hien_tai))
			cout << "Da tao thanh cong nam hoc moi.\n"; //Nhớ chỉnh đồ họa nha
		else
			cout << "Co loi khi tao nam hoc moi. Vui long thu lai.\n"; //Nhớ chỉnh đồ họa nha
	}
}

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

void Tao_lop()
{
	string lop;
	cout << "Tao lop moi: ";//Nhớ chỉnh đồ họa nha
	getline(cin, lop);
	while (lop.substr(0, 2) != nam_hoc_hien_tai.substr(2, 2)) //Lớp tạo ra không phải của sinh viên năm nhất
	{
		cout << "Tao lai.\n";//Nhớ chỉnh đồ họa nha
		cout << "Tao lop moi: ";//Nhớ chỉnh đồ họa nha
		getline(cin, lop);
	}

	Tao_folder_lop();
	//Kiểm tra lớp này có đã được tạo chưa
	ifstream kiem_tra;
	kiem_tra.open("LOP/" + lop + ".csv");
	if (!kiem_tra)
	{
		ofstream tao_lop;
		tao_lop.open("LOP/" + lop + ".csv");
		tao_lop.close();
		fstream nhap_lop;
		nhap_lop.open("LOP/Danh sach cac lop.txt", ios_base::app);
		nhap_lop << lop << "\n";
		nhap_lop.close();
	}
	else
		cout << "Lop nay da duoc tao.\n";//Nhớ chỉnh đồ họa nha
	kiem_tra.close();
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

void ve_hop_them_sv_vao_lop(int x, int y)
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

void Them_sv_vao_file()
{
	string lop;
	int so_luong_sv;
	system("cls");
	goto_XY(34, 10);
	cout << "Nhap lop muon them sinh vien: ";
	getline(cin, lop);
	goto_XY(34, 11);
	cout << "So luong sinh vien trong lop: ";
	cin >> so_luong_sv;
	cin.ignore();
	lop = "LOP/" + lop + ".csv";
	ifstream check;
	check.open(lop);
	while (!check)
	{
		Xoa_dong(10);
		Xoa_dong(11);
		goto_XY(34, 10);
		cout << "Nhap lai lop muon them sinh vien: ";
		getline(cin, lop);
		goto_XY(34, 11);
		cout << "So luong sinh vien trong lop: ";
		cin >> so_luong_sv;
		cin.ignore();
		lop = "LOP/" + lop + ".csv";
		check.open(lop);
	}
	check.close();

	//Vẽ cấu trúc
	system("cls");
	int x = 6;
	int y = 4;
	int w = 105;
	int h = 3;
	ve_hop_them_sv_vao_lop(x, y + 1);


	List_sinh_vien l;
	Tao_danh_sach(l);
	int dem = 1;
	while (dem <= so_luong_sv)//Sau này sửa thành khi nhập xong thì nhấn xong
	{
		ve_hop(x, y, w, h);
		sinh_vien* sv;
		Nhap_1_sinh_vien(sv, x, y + h - 1, dem);
		Them_sv_vao_duoi_danh_sach(l, sv);
		if (dem != so_luong_sv)
			Xoa_dong(y + h);
		h++;
		dem++;
	}

	ofstream ghi_file;
	ghi_file.open(lop);
	ghi_file << "So thu tu,MSSV,Ho,Ten,Gioi tinh,Ngay sinh,CCCD/CMND\n";
	sinh_vien* n = l.pHead;
	int i = 0;
	while (n != nullptr)
	{
		i++;
		Ghi_1_sinh_vien_vao_file(ghi_file, n, i);
		n = n->pNext;
	}
	ghi_file.close();
}


void Them_sinh_vien_vao_file_nhanh()
{
	string lop;
	int so_luong_sv;
	system("cls");
	goto_XY(34, 10);
	cout << "Nhap lop muon them sinh vien: ";
	getline(cin, lop);
	goto_XY(34, 11);
	cout << "So luong sinh vien trong lop: ";
	cin >> so_luong_sv;
	cin.ignore();
	lop = "LOP/" + lop + ".csv";
	ifstream check;
	check.open(lop);
	while (!check)
	{
		Xoa_dong(10);
		Xoa_dong(11);
		goto_XY(34, 10);
		cout << "Nhap lai lop muon them sinh vien: ";
		getline(cin, lop);
		goto_XY(34, 11);
		cout << "So luong sinh vien trong lop: ";
		cin >> so_luong_sv;
		cin.ignore();
		lop = "LOP/" + lop + ".csv";
		check.open(lop);
	}
	check.close();

	goto_XY(34, 12);
	ifstream fin;
	string link;
	cout << "Nhap lien ket chua danh sach sinh vien ban muon them vao:";
	goto_XY(34, 13);
	getline(cin, link);
	fin.open(link);
	while (!fin)
	{
		goto_XY(34, 15);
		cout << "Lien ket ban vua nhap khong dan den danh sach phu hop. Vui long nhap lai.";
		Xoa_dong(12);
		goto_XY(34, 12);
		cout << "\nNhap lien ket chua danh sach sinh vien ban muon them vao:";
		goto_XY(34, 13);
		getline(cin, link);
		fin.open(link);
	}

	List_sinh_vien dssv;
	Tao_danh_sach(dssv);
	string temp;
	getline(fin, temp, '\n');
	int so_luong = 0;
	while (fin.eof() != true)
	{
		sinh_vien* sv;
		sv = new sinh_vien;
		Doc_sinh_vien_tu_file(fin, sv);
		if (sv->mssv == "")
			break;
		Them_sv_vao_duoi_danh_sach(dssv, sv);
		so_luong++;
		if (so_luong == so_luong_sv)
			break;
	}
	fin.close();

	//In danh sách sinh viên ra màn hình, sau đó hỏi người dùng có muốn nhập danh sách dô lớp hay không?
	//Xuat danh sach sinh vien ra man hinh
	system("cls");
	ve_hop_them_sv_vao_lop(6, 5);
	int x = 6;
	int y = 4;
	int w = 105;
	int h = 3;
	sinh_vien* a = dssv.pHead;
	ve_hop(x, y, w, h + so_luong - 1);
	int stt = 1;
	while (a != nullptr)
	{
		Xuat_1_sv_cua_lop(a, x, y + h - 1, stt);
		h++;
		stt++;
		a = a->pNext;
	}
	goto_XY(6, so_luong + 12);
	cout << "Ban co muon nhap nhung sinh vien nay khong?";
	goto_XY(6, so_luong + 13);
	cout << "Nhan 0 de khong nhap.";
	goto_XY(6, so_luong + 14);
	cout << "Nhan 1 de nhap.";
	char chon;
	goto_XY(6, so_luong + 15);
	cout << "Moi ban chon: ";
	cin >> chon;
	while (chon != '0' && chon != '1')
	{
		Xoa_dong(so_luong + 15);
		goto_XY(6, so_luong + 12);
		cout << "Lua chon khong hop le. Vui long nhap lai.";
		goto_XY(6, so_luong + 15);
		cout << "Moi ban chon: ";
		cin >> chon;
	}

	if (chon == '1')
	{
		ofstream ghi_file;
		ghi_file.open(lop);
		ghi_file << "So thu tu,MSSV,Ho,Ten,Gioi tinh,Ngay sinh,CCCD/CMND\n";
		sinh_vien* n = dssv.pHead;
		int i = 0;
		while (n != nullptr)
		{
			i++;
			Ghi_1_sinh_vien_vao_file(ghi_file, n, i);
			n = n->pNext;
		}
		ghi_file.close();
	}
}

void Tao_list_khoa_hoc(List_khoa_hoc& l)
{
	l.pHead = nullptr;
	l.pTail = nullptr;
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