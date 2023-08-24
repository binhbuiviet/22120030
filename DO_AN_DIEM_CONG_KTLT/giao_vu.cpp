#include "giao_vu.h"

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

void Tao_lop()
{
	string lop;
	system("cls");
	goto_XY(34, 10);
	cout << "Tao lop moi: ";
	getline(cin, lop);
	while (lop.substr(0, 2) != nam_hoc_hien_tai.substr(2, 2)) //Lớp tạo ra không phải của sinh viên năm nhất
	{
		goto_XY(34, 11);
		cout << "Tao lop moi khong hop le. Vui long tao lai.";
		Xoa_dong(10);
		goto_XY(34, 10);
		cout << "Tao lop moi: ";//Nhớ chỉnh đồ họa nha
		getline(cin, lop);
	}
	Xoa_dong(11);
	goto_XY(34, 11);
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
	ve_cau_truc_them_sv_vao_lop(x, y + 1);

	string sinhv = "Sinh vien";
	if (Kiem_tra_folder(sinhv) == false)
		bool tao_sinhv = Tao_folder(sinhv);
	List_sinh_vien l;
	Tao_danh_sach(l);
	int dem = 1;
	while (dem <= so_luong_sv)
	{
		ve_hop(x, y, w, h);
		sinh_vien* sv;
		Nhap_1_sinh_vien(sv, x, y + h - 1, dem);
		string folder_sv = "Sinh vien/" + sv->mssv;
		string folder_sv_namhoc = folder_sv + "/" + nam_hoc_hien_tai;
		if (Kiem_tra_folder(folder_sv) == false)
		{
			bool tao_foldersv = Tao_folder(folder_sv);
			bool tao_foldersv_namhoc = Tao_folder(folder_sv_namhoc);
			//Viết tài khoản cho sinh viên đó nữa.
		}
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
		goto_XY(34, 9);
		cout << "Lop nay chua duoc khoi tao.";
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
	Xoa_dong(9);

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
		cout << "Nhap lien ket chua danh sach sinh vien ban muon them vao:";
		goto_XY(34, 13);
		getline(cin, link);
		fin.open(link);
	}

	string sinhv = "Sinh vien";
	if (Kiem_tra_folder(sinhv) == false)
		bool tao_sinhv = Tao_folder(sinhv);
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
		string folder_sv = "Sinh vien/" + sv->mssv;
		string folder_sv_namhoc = folder_sv + "/" + nam_hoc_hien_tai;
		if (Kiem_tra_folder(folder_sv) == false)
		{
			bool tao_foldersv = Tao_folder(folder_sv);
			bool tao_foldersv_namhoc = Tao_folder(folder_sv_namhoc);
		}
		Them_sv_vao_duoi_danh_sach(dssv, sv);
		so_luong++;
		if (so_luong == so_luong_sv)
			break;
	}
	fin.close();

	//In danh sách sinh viên ra màn hình, sau đó hỏi người dùng có muốn nhập danh sách dô lớp hay không?
	//Xuat danh sach sinh vien ra man hinh
	system("cls");
	ve_cau_truc_them_sv_vao_lop(6, 5);
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
	hoc_ki = nam_hoc_hien_tai + "/Hoc ki " + to_string(hk); //Mục đích là để lưu folder học kì vào folder năm học
	thong_tin_cac_khoa_hoc = hoc_ki + "/Thong tin cac khoa hoc.csv";
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
	ofstream info_courses;
	info_courses.open(thong_tin_cac_khoa_hoc);
	info_courses << "Ma mon hoc,Ten khoa hoc,Ten lop,Ten giang vien,So tin chi,So luong sinh vien toi da,Buoi hoc,Khung gio hoc\n";
	info_courses.close();
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
	cin.ignore();

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
	string INFO; //Đây là để tạo file csv chứa thông tin khóa học
	INFO = Khoa_hoc + "/Thong tin khoa hoc.csv";
	fstream nhap_info;
	nhap_info.open(INFO, ios_base::out);
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
	system("cls");
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
	string info_course = course + "/Thong tin khoa hoc.csv";
	ifstream fin_info;
	fin_info.open(info_course);
	string Info_course;
	getline(fin_info, Info_course, '\n');
	fin_info.close();

	ifstream fin;
	string link;
	goto_XY(34, 12);
	cout << "Nhap lien ket chua danh sach sinh vien ban muon them vao: ";
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
	cin.ignore();

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
	system("cls");
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
		if (a->ten_khoa_hoc == ten && a->ten_lop == lop)
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
	info_courses.open(thong_tin_cac_khoa_hoc, ios_base::out);
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
	course = hoc_ki + "/" + ten_khoa_hoc + " " + ten_lop;
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
	string info_course = course + "/Thong tin cac khoa hoc.csv";
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

	List_khoa_hoc lkh;
	Doc_khoa_hoc_cua_sv(lkh, mssv);
	Xoa_1_khoa_hoc(lkh, ten_khoa_hoc, ten_lop);
	string mssv_hocki = "Sinh vien/" + mssv + "/" + hoc_ki + "/Thong tin khoa hoc.csv";
	fstream fout_sv;
	fout_sv.open(mssv_hocki, ios_base::out);
	fout << "Ma mon hoc,Ten khoa hoc,Ten lop,Ten giang vien,So tin chi,So luong SV toi da,Buoi hoc,Khung gio\n";
	khoa_hoc* kh = lkh.pHead;
	while (kh != nullptr)
	{
		Nhap_khoa_hoc_vao_file(fout_sv, kh);
		kh = kh->pNext;
	}
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
		if (a->ten_khoa_hoc == ten && a->ten_lop == lop)
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
	fout.open(thong_tin_cac_khoa_hoc, ios_base::out);
	fout << temp << "\n";
	khoa_hoc* kh = l.pHead;
	while (kh != nullptr)
	{
		Nhap_khoa_hoc_vao_file(fout, kh);
		kh = kh->pNext;
	}
	fout.close();
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

void xem_ds_khoa_hoc()
{
	system("cls");
	goto_XY(34, 5);
	cout << "Chon nam hoc: ";
	goto_XY(34, 6);
	cout << "Hoc ki: (1/2/3) ";
	string nam_hoc;
	int hoc_ki;
	goto_XY(48, 5);
	getline(cin, nam_hoc);
	goto_XY(50, 6);
	cin >> hoc_ki;
	string ten = nam_hoc + "/Hoc ki " + to_string(hoc_ki);
	cin.ignore();
	while (Kiem_tra_folder(ten) == false)
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
		cin.ignore();
		string ten = nam_hoc + "/Hoc ki " + to_string(hoc_ki);
	}
	ifstream fin;
	fin.open(ten + "/Thong tin cac khoa hoc.csv");
	string temp;
	getline(fin, temp, '\n');
	List_khoa_hoc l;
	Tao_list_khoa_hoc(l);
	while (fin.eof() != true)
	{
		Lay_list_khoa_hoc(fin, l);
	}
	fin.close();
	system("cls");
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
	goto_XY(48, 5);
	getline(cin, nam_hoc);
	goto_XY(50, 6);
	cin >> hoc_ki;
	cin.ignore();
	goto_XY(48, 7);
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
		cin.ignore();
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

	system("cls");
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