#include "yeu_cau_2.h"

void tao_hoc_ky() //LƯU Ý: PHẢI KIỂM TRA TẠO NĂM HỌC TRƯỚC THÌ MỚI ĐƯỢC TỚI HÀM TẠO HỌC KỲ
{
	int hk;
	//Nhập học kì bạn muốn tạo, lưu ý là chỉ có học kì 1,2,3
	cin >> hk;
	while (hk != 1 && hk != 2 && hk != 3)
	{
		//Nhập lại các kiểu
		cin >> hk;
	}
	hoc_ki = nam_hoc_hien_tai + "/Hoc ki " + to_string(hk); //Mục đích là để lưu folder học kì vào folder năm học, tuy nhiên CÓ THỂ CHƯA ĐÚNG
	//Kiểm tra xem học kì đã được khởi tạo chưa
	if (Kiem_tra_folder(hoc_ki))
		cout << "Hoc ki nay da duoc tạo.\n"; //Chỉnh đồ họa nha
	else
	{
		if (Tao_folder(hoc_ki))
			cout << "Hoc ki da duoc tao xong.\n"; //Chỉnh đồ họa nha
		else
			cout << "Co loi khi tao hoc ki nay. Vui long thu lai.\n"; //Chỉnh đồ họa nha
	}
	string file_hoc_ki;
	file_hoc_ki = nam_hoc_hien_tai + "/Thong tin hoc ki " + to_string(hk) + ".txt"; //Dùng để tạo ra file được lưu trong folder năm học, file này ghi thông tin năm học, ngày bắt đầu, ngày kết thúc
	string ngay_bat_dau, ngay_ket_thuc;
	//Nhập ngày bắt đầu học kì
	cin.ignore();
	getline(cin, ngay_bat_dau);
	//Nhập ngày kết thúc học kì
	getline(cin, ngay_ket_thuc);
	ofstream fout;
	fout.open(file_hoc_ki);
	fout << nam_hoc_hien_tai << "\n"
		<< ngay_bat_dau << "\n"
		<< ngay_ket_thuc << "\n";
	fout.close();

	//Tạo một file csv lưu tất cả các thông tin của các khóa học
	thong_tin_cac_khoa_hoc = hoc_ki + "/Thong tin cac khoa hoc.csv";
	ofstream info_courses;
	info_courses.open(thong_tin_cac_khoa_hoc);
	info_courses << "Ma mon hoc,Ten khoa hoc,Ten lop,Ten giang vien,So tin chi,So luong sinh vien toi da,Buoi hoc,Khung gio hoc\n";
	info_courses.close();
}

void tao_khoa_hoc()
{
	//Nhớ chỉnh đồ họa khúc này nha
	khoa_hoc* k;
	k = new khoa_hoc;
	//Nhớ căn chỉnh đồ họa
	cout << "Ma mon hoc: ";
	getline(cin, k->ma_mon_hoc);
	cout << "Ten khoa hoc: ";
	getline(cin, k->ten_khoa_hoc);
	cout << "Ten lop: ";
	getline(cin, k->ten_lop);
	cout << "Ten giang vien: ";
	getline(cin, k->ten_giang_vien);
	cout << "So tin chi: ";
	cin >> k->so_tin_chi;
	cout << "So luong sinh vien toi da: ";
	cin >> k->sinh_vien_toi_da;
	while (k->sinh_vien_toi_da > 50 || k->sinh_vien_toi_da < 1)
	{
		//Nhập lại
		cin >> k->sinh_vien_toi_da;
	}

	int buoihoc;
	cout << "Buoi hoc se la mot ngay tu thu hai den thu bay. Vui long nhap mot so nguyen tu 2 den 7.\n";
	cout << "Buoi hoc: Thu ";
	cin >> buoihoc;
	while (buoihoc < 2 || buoihoc>7)
	{
		//Nhập lại
		cin >> buoihoc;
	}
	k->buoi_hoc = "Thu " + to_string(buoihoc);

	int khunggio;
	cout << "Khung gio hoc co cac khung gio sau.\n"
		<< "S1(07:30).\n"
		<< "S2(09:30).\n"
		<< "S3(13:30).\n"
		<< "S4(15:30).\n"
		<< "Vui long nhap mot so tu nhien tu 1 den 4.\n";
	cout << "Khung gio hoc: S";
	cin >> khunggio;
	while (khunggio < 1 || khunggio>4)
	{
		//Nhập lại;
		cin >> khunggio;
	}
	if (khunggio == 1)
		k->khung_gio = "S1(07:30)";
	else if (khunggio == 2)
		k->khung_gio = "S2(09:30)";
	else if (khunggio == 3)
		k->khung_gio = "S3(13:30)";
	else if (khunggio == 4)
		k->khung_gio = "S4(15:30)";

	k->pNext = nullptr;
	//Cần kiểm tra học kì đã được tạo hay chưa
	string course;
	//Tên khóa học này sẽ là tên của khóa học đã tạo sẵn + tên lớp
	course = k->ten_khoa_hoc + " " + k->ten_lop;
	string Khoa_hoc = hoc_ki + "/" + course;
	if (Tao_folder(Khoa_hoc))
	{
		//Tạo xong
	}
	string INFO; //Đây là để tạo file txt chứa thông tin khóa học
	INFO = Khoa_hoc + "/Thong tin khoa hoc.txt";
	ofstream nhap_info;
	nhap_info.open(INFO);
	nhap_info << k->ma_mon_hoc << ","
		<< k->ten_khoa_hoc << ","
		<< k->ten_lop << ","
		<< k->ten_giang_vien << ","
		<< k->so_tin_chi << ","
		<< k->sinh_vien_toi_da << ","
		<< k->buoi_hoc << ","
		<< k->khung_gio;
	nhap_info.close();

	//Nhập thông tin khóa học vừa có vào file thông tin các khóa học
	fstream nhap_info_csv;
	nhap_info_csv.open(thong_tin_cac_khoa_hoc, ios_base::app);
	nhap_info_csv << k->ma_mon_hoc << ","
		<< k->ten_khoa_hoc << ","
		<< k->ten_lop << ","
		<< k->ten_giang_vien << ","
		<< k->so_tin_chi << ","
		<< k->sinh_vien_toi_da << ","
		<< k->buoi_hoc << ","
		<< k->khung_gio << "\n";
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
	ifstream fin;
	string link;
	cout << "\nNhap lien ket chua danh sach sinh vien ban muon them vao: ";
	getline(cin, link);
	fin.open(link);
	while (!fin)
	{
		cout << "Lien ket ban vua nhap khong dan den danh sach phu hop. Vui long nhap lai.\n";
		cout << "\nNhap lien ket chua danh sach sinh vien ban muon them vao: ";
		getline(cin, link);
		fin.open(link);
	}
	//Lưu ý, nên đưa file có trong tệp tin lớp thì càng tốt ^.^ hahaha
	List_sinh_vien dssv;
	Tao_danh_sach(dssv);
	sinh_vien* sv;
	while (fin.eof() != true)
	{
		sv = new sinh_vien;
		string thu_tu;
		getline(fin, thu_tu, ',');
		getline(fin, sv->mssv, ',');
		if (sv->mssv == "")
			break;
		getline(fin, sv->ho, ',');
		getline(fin, sv->ten, ',');
		getline(fin, sv->gioi_tinh, ',');
		getline(fin, sv->ngay_sinh, ',');
		getline(fin, sv->cccd, '\n');
		sv->pNext = nullptr;
		Them_sv_vao_duoi_danh_sach(dssv, sv);
		sv = sv->pNext;
	}
	fin.close();

	//Nhập tên khóa học muốn thêm sinh viên
	string course;
	cout << "Nhap ten khoa hoc: ";
	getline(cin, course);
	string lop;
	cout << "Nhap ten lop: ";
	getline(cin, lop);
	course = hoc_ki + "/" + course + " " + lop;
	while (Kiem_tra_folder(course) != true)
	{
		cout << "Khoa hoc nay chua duoc khoi tao. Vui long nhap khoa hoc khac.\n";
		cout << "Nhap ten khoa hoc: ";
		getline(cin, course);
		cout << "Nhap ten lop: ";
		getline(cin, lop);
		course = hoc_ki + "/" + course + " " + lop;
	}

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
	khoa_hoc* k;
	List_khoa_hoc l;
	Tao_list_khoa_hoc(l);
	while (fin.eof() != true) //Trích xuất các thông tin khóa học vào danh sách liên kết
	{
		k = new khoa_hoc;
		string so_tin_chi, sinh_vien_toi_da;
		getline(fin, k->ma_mon_hoc, ',');
		if (k->ma_mon_hoc == "")
			break;
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
		k = k->pNext;
	}
	fin.close();

	//Hỏi xem người dùng muốn cập nhật thông tin của khóa học nào
	string ten, lop, course;
	int kiem_tra = 0;
	cout << "Nhap ten khoa hoc ban muon cap nhat: ";
	getline(cin, ten);
	cout << "Nhap lop: ";
	getline(cin, lop);
	for (khoa_hoc* a = l.pHead; a != nullptr; a = a->pNext)
	{
		if (a->ten_khoa_hoc == ten && a->ten_lop == lop)
		{
			kiem_tra = 1;
			system("cls"); //Đổi sang trang màn hình mới
			//MENU hỏi người dùng muốn cập nhật thông tin gì của khóa học
			cout << "Ban muon doi thong tin nao cua khoa hoc.\n";
			cout << "1. Ma mon hoc.\n"
				<< "2. Ten khoa hoc.\n"
				<< "3. Ten lop.\n"
				<< "4. Ten giang vien.\n"
				<< "5. So tin chi.\n"
				<< "6. So luong sinh vien toi da.\n"
				<< "7. Buoi hoc.\n"
				<< "8. Khung gio.\n";
			int choice;
			cout << "Moi ban chon: ";
			cin >> choice;
			while (choice < 1 || choice>8)
			{
				cout << "Lua chon khong hop le. Vui long nhap lai.\n";
				cout << "Moi ban chon: ";
				cin >> choice;
			}
			//Chưa biết làm MENU sao cho đẹp, huhuhu
		}
	}
}