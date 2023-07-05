#include "yeu_cau_2.h"

void tao_hoc_ky() //LƯU Ý: PHẢI KIỂM TRA TẠO NĂM HỌC TRƯỚC THÌ MỚI ĐƯỢC TỚI HÀM TẠO HỌC KỲ
{
	system("cls");
	int hk;
	//Nhập học kì bạn muốn tạo, lưu ý là chỉ có học kì 1,2,3
	goto_XY(34, 10);
	cout << "Nhap hoc ki ban muon tao: ";
	cin >> hk;
	while (hk != 1 && hk != 2 && hk != 3)
	{
		goto_XY(34, 9);
		cout << "Hoc ki co the duoc tao chi la cac Hoc ki 1, 2, 3. Vui long tao lai.";
		Xoa_dong(10);
		goto_XY(34, 10);
		cout << "Nhap hoc ki ban muon tao: ";
		cin >> hk;
	}
	goto_XY(34, 11);
	hoc_ki = nam_hoc_hien_tai + "/Hoc ki " + to_string(hk); //Mục đích là để lưu folder học kì vào folder năm học, tuy nhiên CÓ THỂ CHƯA ĐÚNG
	//Kiểm tra xem học kì đã được khởi tạo chưa
	if (Kiem_tra_folder(hoc_ki))
	{
		cout << "Hoc ki nay da duoc tao.\n"; //Chỉnh đồ họa nha
		return;
	}
	string file_hoc_ki;
	file_hoc_ki = nam_hoc_hien_tai + "/Thong tin hoc ki " + to_string(hk) + ".txt"; //Dùng để tạo ra file được lưu trong folder năm học, file này ghi thông tin năm học, ngày bắt đầu, ngày kết thúc
	string ngay_bat_dau, ngay_ket_thuc;
	cout << "Ngay bat dau hoc ki (dd/mm/yyyy): ";
	cin.ignore();
	getline(cin, ngay_bat_dau);
	goto_XY(34, 12);
	cout << "Nhap ngay ket thuc hoc ki (dd/mm/yyyy): ";
	getline(cin, ngay_ket_thuc);
	goto_XY(34, 13);
	ofstream fout;
	fout.open(file_hoc_ki);
	fout << nam_hoc_hien_tai << "\n"
		<< ngay_bat_dau << "\n"
		<< ngay_ket_thuc << "\n";
	fout.close();
	if (Tao_folder(hoc_ki))
		cout << "Hoc ki da duoc tao xong.\n"; 
	else
		cout << "Co loi khi tao hoc ki nay. Vui long thu lai.\n"; 
	//Tạo một file csv lưu tất cả các thông tin của các khóa học
	thong_tin_cac_khoa_hoc = hoc_ki + "/Thong tin cac khoa hoc.csv";
	ofstream info_courses;
	info_courses.open(thong_tin_cac_khoa_hoc);
	info_courses << "Ma mon hoc,Ten khoa hoc,Ten lop,Ten giang vien,So tin chi,So luong sinh vien toi da,Buoi hoc,Khung gio hoc\n";
	info_courses.close();
}

void Nhap_khoa_hoc_vao_file(fstream& f, khoa_hoc*k)
{
	f << k->ma_mon_hoc << ","
		<< k->ten_khoa_hoc << ","
		<< k->ten_lop << ","
		<< k->ten_giang_vien << ","
		<< k->so_tin_chi << ","
		<< k->sinh_vien_toi_da << ","
		<< k->buoi_hoc << ","
		<< k->khung_gio<<"\n";
}

void tao_khoa_hoc()
{
	system("cls");
	if (hoc_ki == "")
	{
		goto_XY(34, 14);
		cout << "Ban can tao hoc ki truoc.";
		return;
	}
	khoa_hoc* k;
	k = new khoa_hoc;
	goto_XY(34, 10);
	cout << "Ma mon hoc: ";
	getline(cin, k->ma_mon_hoc);
	goto_XY(34, 11);
	cout << "Ten khoa hoc: ";
	getline(cin, k->ten_khoa_hoc);
	goto_XY(34, 12);
	cout << "Ten lop: ";
	getline(cin, k->ten_lop);
	goto_XY(34, 13);
	cout << "Ten giang vien: ";
	getline(cin, k->ten_giang_vien);
	goto_XY(34, 14);
	cout << "So tin chi: ";
	cin >> k->so_tin_chi;
	goto_XY(34, 15);
	cout << "So luong sinh vien toi da: ";
	cin >> k->sinh_vien_toi_da;

	int buoihoc;
	goto_XY(34, 17);
	cout << "Buoi hoc se la mot ngay tu thu hai den thu bay. Vui long nhap mot so nguyen tu 2 den 7.";
	goto_XY(34, 16);
	cout << "Buoi hoc: Thu ";
	cin >> buoihoc;
	while (buoihoc < 2 || buoihoc>7)
	{
		goto_XY(34, 18);
		cout << "Buoi hoc ban nhap khong chinh xac. Vui long nhap lai.";
		Xoa_dong(16);
		goto_XY(34, 16);
		cout << "Buoi hoc: Thu ";
		cin >> buoihoc;
	}
	k->buoi_hoc = "Thu " + to_string(buoihoc);
	Xoa_dong(17);
	Xoa_dong(18);

	goto_XY(34, 17);
	cout << "Khung gio: ";
	goto_XY(34, 18);
	cout << "Khung gio hoc co cac khung gio sau.";
	goto_XY(34, 19);
	cout << "S1(07:30).";
	goto_XY(34, 20);
	cout << "S2(09:30).";
	goto_XY(34, 21);
	cout << "S3(13:30).";
	goto_XY(34, 22);
	cout << "S4(15:30).";

	goto_XY(45, 17);
	getline(cin, k->khung_gio);

	k->pNext = nullptr;
	for (int i = 18; i <= 22; i++)
		Xoa_dong(i);
	string course;
	//Tên khóa học này sẽ là tên của khóa học đã tạo sẵn + tên lớp
	course = k->ten_khoa_hoc + " " + k->ten_lop;
	string Khoa_hoc = hoc_ki + "/" + course;
	if (Tao_folder(Khoa_hoc))
	{
		goto_XY(34, 18);
		cout << "Khoa hoc da duoc tao xong.";
	}
	string INFO; //Đây là để tạo file txt chứa thông tin khóa học
	INFO = Khoa_hoc + "/Thong tin khoa hoc.txt";
	fstream nhap_info;
	nhap_info.open(INFO,ios_base::out);
	Nhap_khoa_hoc_vao_file(nhap_info, k);
	nhap_info.close();

	//Nhập thông tin khóa học vừa có vào file thông tin các khóa học
	fstream nhap_info_csv;
	nhap_info_csv.open(thong_tin_cac_khoa_hoc, ios_base::app);
	Nhap_khoa_hoc_vao_file(nhap_info_csv, k);
	nhap_info_csv.close();

	//Tạo một file csv lưu danh sách sinh viên + điểm trong khóa học đó
	string ds = Khoa_hoc + "/Danh sach Sinh vien.csv";
	ofstream dssv;
	dssv.open(ds);
	dssv << "STT,MSSV,Ho,Ten,Gioi tinh,Ngay sinh,CCCD/CMND\n";
	dssv.close();
}

void Dang_danh_sach_sinh_vien_vao_khoa_hoc()
{
	//Nhập tên khóa học muốn thêm sinh viên
	string course;
	goto_XY(34, 10);
	cout << "Nhap ten khoa hoc: ";
	getline(cin, course);
	string lop;
	goto_XY(34, 11);
	cout << "Nhap ten lop: ";
	getline(cin, lop);
	course = hoc_ki + "/" + course + " " + lop;
	while (Kiem_tra_folder(course) != true)
	{
		goto_XY(34, 9);
		cout << "Khoa hoc nay chua duoc khoi tao. Vui long nhap khoa hoc khac.";
		Xoa_dong(10);
		Xoa_dong(11);
		goto_XY(34, 10);
		cout << "Nhap ten khoa hoc: ";
		getline(cin, course);
		goto_XY(34, 11);
		cout << "Nhap ten lop: ";
		getline(cin, lop);
		course = hoc_ki + "/" + course + " " + lop;
	}
	string info_course = course + "/Thong tin khoa hoc.txt";
	ifstream fin_info;
	fin_info.open(info_course);
	string Info_course;
	getline(fin_info, Info_course, '\n');
	fin_info.close();

	ifstream fin;
	string link;
	goto_XY(34, 12);
	cout << "\nNhap lien ket chua danh sach sinh vien ban muon them vao: ";
	goto_XY(34, 13);
	getline(cin, link);
	fin.open(link);
	while (!fin)
	{
		goto_XY(34, 9);
		cout << "Lien ket ban vua nhap khong dan den danh sach phu hop. Vui long nhap lai.";
		Xoa_dong(13);
		goto_XY(34, 13);
		getline(cin, link);
		fin.open(link);
	}
	Xoa_dong(9);
	List_sinh_vien dssv;
	Tao_danh_sach(dssv);
	while (fin.eof() != true)
	{
		sinh_vien* sv = new sinh_vien;
		Doc_sinh_vien_tu_file(fin, sv);
		if (sv->mssv == "")
			break;
		sv->pNext = nullptr;
		Them_sv_vao_duoi_danh_sach(dssv, sv);
		string mssv_namhoc = "Sinh vien/" + sv->mssv + "/" + nam_hoc_hien_tai;
		if (Kiem_tra_folder(mssv_namhoc) == false)
			bool tao_folder1 = Tao_folder(mssv_namhoc);
		string mssv_hocki= "Sinh vien/" + sv->mssv + "/" + hoc_ki;
		string mssv_hocki_khoahoc = mssv_hocki + "/Thong tin khoa hoc.csv";
		if (Kiem_tra_folder(mssv_hocki) == false)
		{
			bool tao_folder2 = Tao_folder(mssv_hocki);
			ofstream fout_inf;
			fout_inf.open(mssv_hocki_khoahoc);
			fout_inf << "Ma mon hoc,Ten khoa hoc,Ten lop,Ten giang vien,So tin chi,So luong SV toi da,Buoi hoc,Khung gio\n";
			fout_inf.close();
		}
		fstream foutsv;
		foutsv.open(mssv_hocki_khoahoc, ios_base::app);
		foutsv << Info_course << "\n";
		foutsv.close();
	}
	fin.close();

	string ds = course + "/Danh sach Sinh vien.csv";
	int dem = 0;
	fstream fout;
	fout.open(ds, ios_base::app);
	sinh_vien* n = dssv.pHead;
	while (n != nullptr)
	{
		dem++;
		fout << dem << ","
			<< n->mssv << ","
			<< n->ho << ","
			<< n->ten << ","
			<< n->gioi_tinh << ","
			<< n->ngay_sinh << ","
			<< n->cccd << "\n";
		n = n->pNext;
	}
	fout.close();
	goto_XY(34, 14);
	cout << "Nhap danh sach thanh cong.";
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

void Menu_cap_nhat_khoa_hoc(khoa_hoc*& k)
{
	system("cls");
	goto_XY(34, 10);
	cout << "Ma mon hoc: ";
	getline(cin, k->ma_mon_hoc);
	goto_XY(34, 11);
	cout << "Ten khoa hoc: ";
	getline(cin, k->ten_khoa_hoc);
	goto_XY(34, 12);
	cout << "Ten lop: ";
	getline(cin, k->ten_lop);
	goto_XY(34, 13);
	cout << "Ten giang vien: ";
	getline(cin, k->ten_giang_vien);
	goto_XY(34, 14);
	cout << "So tin chi: ";
	cin >> k->so_tin_chi;
	goto_XY(34, 15);
	cout << "So luong sinh vien toi da: ";
	cin >> k->sinh_vien_toi_da;

	int buoihoc;
	goto_XY(34, 17);
	cout << "Buoi hoc se la mot ngay tu thu hai den thu bay. Vui long nhap mot so nguyen tu 2 den 7.";
	goto_XY(34, 16);
	cout << "Buoi hoc: Thu ";
	cin >> buoihoc;
	while (buoihoc < 2 || buoihoc>7)
	{
		goto_XY(34, 18);
		cout << "Buoi hoc ban nhap khong chinh xac. Vui long nhap lai.";
		Xoa_dong(16);
		goto_XY(34, 16);
		cout << "Buoi hoc: Thu ";
		cin >> buoihoc;
	}
	k->buoi_hoc = "Thu " + to_string(buoihoc);
	Xoa_dong(17);
	Xoa_dong(18);

	goto_XY(34, 17);
	cout << "Khung gio: ";
	goto_XY(34, 18);
	cout << "Khung gio hoc co cac khung gio sau.";
	goto_XY(34, 19);
	cout << "S1(07:30).";
	goto_XY(34, 20);
	cout << "S2(09:30).";
	goto_XY(34, 21);
	cout << "S3(13:30).";
	goto_XY(34, 22);
	cout << "S4(15:30).";

	goto_XY(45, 17);
	getline(cin, k->khung_gio);
	for (int i = 18; i <= 22; i++)
		Xoa_dong(i);
}

//Việc cập nhật tên khóa học có thể phải đổi luôn tên file khóa học, do đó cần có 1 hàm đổi tên
bool Doi_ten_file(const string& ten_cu, const string& ten_moi)
{
	if (rename(ten_cu.c_str(), ten_moi.c_str()) == 0)
		return true;
	else
		return false;
}

void Cap_nhat_khoa_hoc()
{
	ifstream fin;
	fin.open(thong_tin_cac_khoa_hoc);
	if (!fin)
	{
		cout << "Ban chua khoi tao hoc ki. Vui long thu lai";
		return;
	}
	string temp;
	getline(fin, temp, '\n'); //Đọc dòng đầu tiên trong file
	List_khoa_hoc l;
	Tao_list_khoa_hoc(l);
	while (fin.eof() != true) //Trích xuất các thông tin khóa học vào danh sách liên kết
	{
		Lay_list_khoa_hoc(fin, l);
	}
	fin.close();

	//Hỏi xem người dùng muốn cập nhật thông tin của khóa học nào
	string ten, lop, course;
	goto_XY(34, 10);
	cout << "Nhap ten khoa hoc ban muon cap nhat: ";
	getline(cin, ten);
	goto_XY(34, 11);
	cout << "Nhap lop: ";
	getline(cin, lop);
	khoa_hoc* a = l.pHead;
	while (a != nullptr)
	{
		if (a->ten_khoa_hoc == ten && a->ten_khoa_hoc == lop)
			break;
		a = a->pNext;
	}
	if (a != nullptr)
		Menu_cap_nhat_khoa_hoc(a);
	else
	{
		cout << "Khoa hoc ban muon cap nhat khong ton tai.\n";
		return;
	}

	 //Nhập lại các thông tin khóa học vào file thông tin các khóa học
	fstream info_courses;
	info_courses.open(thong_tin_cac_khoa_hoc,ios_base::out);
	info_courses << "Ma mon hoc,Ten khoa hoc,Ten lop,Ten giang vien,So tin chi,So luong sinh vien toi da,Buoi hoc,Khung gio hoc\n";
	khoa_hoc* kh = l.pHead;
	while (kh != nullptr)
	{
		Nhap_khoa_hoc_vao_file(info_courses, kh);
		kh = kh->pNext;
	}
	info_courses.close();

	//Kiểm tra xem folder của khóa học đó có cần đổi tên hay không
	if ((a->ten_khoa_hoc != ten || a->ten_lop != lop) && a != nullptr)
	{
		ten = hoc_ki + "/" + ten + " " + lop;
		string ten_moi = hoc_ki + "/" + a->ten_khoa_hoc + " " + a->ten_lop;
		bool doitenfile = Doi_ten_file(ten, ten_moi);
	}
	goto_XY(34, 18);
	cout << "Cap nhat thong tin khoa hoc thanh cong.";
}

void Them_mot_sinh_vien_vao_khoa_hoc()
{
	system("cls");
	int x = 6;
	int y = 4;
	int w = 105;
	int h = 3;
	ve_cau_truc_them_sv_vao_lop(x, y + 1);
	ve_hop(x, y, w, h);
	sinh_vien* sv;
	Nhap_1_sinh_vien(sv, x, y + h - 1, 1);
	string ten_khoa_hoc, ten_lop, course;
	goto_XY(34, 10);
	cout << "Nhap ten khoa hoc: ";
	getline(cin, ten_khoa_hoc);
	goto_XY(34, 11);
	cout << "Nhap ten lop: ";
	getline(cin, ten_lop);
	string course = hoc_ki + "/" + ten_khoa_hoc + " " + ten_lop;
	ten_khoa_hoc = hoc_ki + "/" + ten_khoa_hoc + " " + ten_lop + "/Danh sach Sinh vien.csv";
	ifstream fin;
	fin.open(ten_khoa_hoc);
	if (!fin)
	{
		goto_XY(34, 12);
		cout << "Khoa hoc nay chua duoc tao.\n";
		fin.close();
		return;
	}
	string temp;
	getline(fin, temp, '\n');
	List_sinh_vien l;
	Tao_danh_sach(l);
	while (fin.eof() != true)
	{
		sinh_vien* sv1 = new sinh_vien;
		string thu_tu;
		getline(fin, thu_tu, ',');
		Doc_sinh_vien_tu_file(fin, sv1);
		if (sv1->mssv == "")
			break;
		if (sv1->mssv == sv->mssv)
		{
			goto_XY(34, 12);
			cout << "Sinh vien nay da co trong lop.";
			fin.close();
			return;
		}
		Them_sv_vao_duoi_danh_sach(l, sv1);
	}
	fin.close();
	Them_sv_vao_duoi_danh_sach(l, sv);
	string info_course = course + "/Thong tin khoa hoc.txt";
	ifstream fin_info;
	fin_info.open(info_course);
	string Info_course;
	getline(fin_info, Info_course, '\n');
	fin_info.close();
	string mssv_namhoc = "Sinh vien/" + sv->mssv + "/" + nam_hoc_hien_tai;
	if (Kiem_tra_folder(mssv_namhoc) == false)
		bool tao_folder1 = Tao_folder(mssv_namhoc);
	string mssv_hocki = "Sinh vien/" + sv->mssv + "/" + hoc_ki;
	string mssv_hocki_khoahoc = mssv_hocki + "/Thong tin khoa hoc.csv";
	if (Kiem_tra_folder(mssv_hocki) == false)
	{
		bool tao_folder2 = Tao_folder(mssv_hocki);
		ofstream fout_inf;
		fout_inf.open(mssv_hocki_khoahoc);
		fout_inf << "Ma mon hoc,Ten khoa hoc,Ten lop,Ten giang vien,So tin chi,So luong SV toi da,Buoi hoc,Khung gio\n";
		fout_inf.close();
	}
	fstream foutsv;
	foutsv.open(mssv_hocki_khoahoc, ios_base::app);
	foutsv << Info_course << "\n";
	foutsv.close();
	
	ofstream fout;
	fout.open(ten_khoa_hoc);
	fout << temp << "\n";
	int i = 0;
	sinh_vien* b = l.pHead;
	while (b != nullptr)
	{
		i++;
		Ghi_1_sinh_vien_vao_file(fout, b, i);
		b = b->pNext;
	}
	fout.close();
	goto_XY(34, 12);
	cout << "Da them sinh vien thanh cong.";
}


void Xoa_mot_sinh_vien_khoi_khoa_hoc()
{
	system("cls");
	string mssv;
	goto_XY(34, 10);
	cout << "Nhap MSSV ban muon xoa: ";
	getline(cin, mssv);
	string ten_khoa_hoc, ten_lop;
	goto_XY(34, 11);
	cout << "Nhap ten khoa hoc: ";
	getline(cin, ten_khoa_hoc);
	goto_XY(34, 12);
	cout << "Nhap ten lop: ";
	getline(cin, ten_lop);
	ten_khoa_hoc = hoc_ki + "/" + ten_khoa_hoc + " " + ten_lop + "/Danh sach Sinh vien.csv";
	ifstream fin;
	fin.open(ten_khoa_hoc);
	if (!fin)
	{
		goto_XY(34, 13);
		cout << "Khoa hoc nay chua duoc tao.\n";
		fin.close();
		return;
	}
	string temp;
	getline(fin, temp, '\n');
	List_sinh_vien l;
	Tao_danh_sach(l);
	while (fin.eof() != true)
	{
		sinh_vien* sv1 = new sinh_vien;
		string thu_tu;
		getline(fin, thu_tu, ',');
		Doc_sinh_vien_tu_file(fin, sv1);
		if (sv1->mssv == "")
			break;
		Them_sv_vao_duoi_danh_sach(l, sv1);
	}
	fin.close();
	xoa_sv_bat_ki(l, mssv);
	ofstream fout;
	fout.open(ten_khoa_hoc);
	fout << temp << "\n";
	int i = 0;
	sinh_vien* b = l.pHead;
	while (b != nullptr)
	{
		i++;
		Ghi_1_sinh_vien_vao_file(fout, b, i);
		b = b->pNext;
	}
	fout.close();
}

void xoa_khoa_hoc()
{
	ifstream fin;
	fin.open(thong_tin_cac_khoa_hoc);
	if (!fin)
	{
		cout << "Ban chua khoi tao hoc ki. Vui long thu lai";
		return;
	}
	string temp;
	getline(fin, temp, '\n'); //Đọc dòng đầu tiên trong file
	List_khoa_hoc l;
	Tao_list_khoa_hoc(l);
	while (fin.eof() != true) //Trích xuất các thông tin khóa học vào danh sách liên kết
	{
		Lay_list_khoa_hoc(fin, l);
	}
	fin.close();

	//Hỏi xem người dùng muốn cập nhật thông tin của khóa học nào
	string ten, lop;
	cout << "Nhap ten khoa hoc ban muon xoa: ";
	getline(cin, ten);
	cout << "Nhap lop: ";
	getline(cin, lop);
	khoa_hoc* a = l.pHead;
	khoa_hoc* b = nullptr;
	while (a != nullptr)
	{
		if (a->ten_khoa_hoc == ten && a->ten_khoa_hoc == lop)
			break;
		b = a;
		a = a->pNext;
	}
	if (a != nullptr)
	{
		if (a == l.pHead)
			Xoa_khoa_hoc_khoi_dau_danh_sach(l);
		else
			xoa_khoa_hoc_bat_ki_khoi_danh_sach(l, a, b);
		string xoa_folder = hoc_ki + "/" + ten + " " + lop;
		xoa_tep_tin(xoa_folder);
		cout << "Da xoa thanh cong.\n";
	}
	else
	{
		cout << "Khoa hoc ban muon cap nhat khong ton tai.\n";
		return;
	}
	
	fstream fout;
	fout.open(thong_tin_cac_khoa_hoc,ios_base::out);
	fout << temp << "\n";
	khoa_hoc* kh = l.pHead;
	while (kh != nullptr)
	{
		Nhap_khoa_hoc_vao_file(fout, kh);
		kh = kh->pNext;
	}
	fout.close();
}