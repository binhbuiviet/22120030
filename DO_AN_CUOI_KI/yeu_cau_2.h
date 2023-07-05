#include "yeu_cau_1.h"

string hoc_ki = ""; //Mục đích của string này là để tạo folder học kì, gán nó trong folder năm học đã tạo trước đó
string thong_tin_cac_khoa_hoc;

void tao_hoc_ky();
void Nhap_khoa_hoc_vao_file(fstream& f, khoa_hoc* k);
void tao_khoa_hoc();
void Dang_danh_sach_sinh_vien_vao_khoa_hoc();
void Lay_list_khoa_hoc(ifstream& fin, List_khoa_hoc& l);
void Menu_cap_nhat_khoa_hoc(khoa_hoc*& a);
bool Doi_ten_file(const string& ten_cu, const string& ten_moi);
void Cap_nhat_khoa_hoc();
void Them_mot_sinh_vien_vao_khoa_hoc();
void Xoa_mot_sinh_vien_khoi_khoa_hoc();
void xoa_khoa_hoc();
