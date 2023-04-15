#include "setUp.h"
#include "admin.h"

// mot so ham nhu left: can trao, right: can phai, setw(n) tao n khoang trong de viet ki tu
using namespace std;
struct date{
	int ngay;
	int thang;
	int nam;
	void layThoiGian(){
		time_t hientai = time(0);
		tm *t = localtime(&hientai);
		nam = 1900 + t->tm_year;
		thang = 1 + t->tm_mon;
		ngay = t->tm_mday;
	}
};


class QuanLyAdmin{
	private:
		Admin *headAD;
	public:
		void KhoiTao(){
			headAD = NULL;
		}
		Admin* Add(string _User, string _Pass){ // them du lieu vao dau
			Admin* p = new Admin;
			p->Tao(_User, _Pass, headAD);
			return p;
		}
		void Nhap(){ // nhap file
			ifstream input;
			input.open("./admin.txt");
			int n;
			input >> n; // so luong admin
			string _User, _Pass;
			while(n > 0){
				input >> _User >> _Pass;
				headAD = this->Add(_User, _Pass); // them vao dau
				n--;
			}
		}
		void Xuat(){
			Admin* i = headAD;
			while(i != NULL){
				cout << i->user() << endl;
				i = i->next;
			}
		}
		int KiemTra(string _User, string _Pass){ // kiem tra trong danh sach
			Admin* i = headAD;
			while(i != NULL){
				if(i->KiemTra(_User, _Pass) == 1){
					return 1;	
				}
				i = i->next;
			}
			return 0;	
		}
};


int DangNhap(QuanLyAdmin quanLy); // dang nhap thanh cong thi tra ve 1

class Sach{
	private:
		string ma;
		string tenSach;
		string tacGia;
		string nhaXuatBan;
		int gia;
		int namPhatHanh;
		int soTrang;
		date ngayNhapKho;
		int tinhTrangSach;
	public:
		Sach* next;
		string Ma(){
			return ma;
		}
		int TinhTrangSach(int capNhat){ // ham tra ve tinh trang sach hien tai khi cap nhat = -1, con nguoc lai dung de cap nhat lai tinh trang sach
			if(capNhat != -1)
				tinhTrangSach = capNhat;
			return tinhTrangSach;
		}
		int KiemTra(string _ma){
			if(ma.compare(_ma) == 0)
				return 1;
			return 0;
		}
		void Nhap(){
			string s;
			char c;
			TextColor(mauTieuDe);
			gotoXY(2*xx, yy);
			cout << "Nhap thong tin sach:";
			gotoXY(2*xx, yy + 2);	cout << "Nhap ma: ";
			cin >> ma;
			getline(cin, s); // doc ki hieu enter 
			gotoXY(2*xx, yy + 3);		cout << "Nhap ten sach: ";
			getline(cin, tenSach);
			gotoXY(2*xx, yy + 4);		cout << "Nhap ten tac gia: ";
			getline(cin, tacGia);
			gotoXY(2*xx, yy + 5);		cout << "Nhap nha xuat ban: ";
			getline(cin, nhaXuatBan);
			gotoXY(2*xx, yy + 6);		cout << "Nhap gia ban: ";
			cin >> gia;
			gotoXY(2*xx, yy + 7);		cout << "Nhap nam phat hanh: "; 
			cin >> namPhatHanh;
			gotoXY(2*xx, yy + 8);		cout << "Nhap so trang: ";
			cin >> soTrang;
			gotoXY(2*xx, yy + 9);		cout << "Nhap ngay nhap kho(dd/mm/yyyy): "; 
			cin >> ngayNhapKho.ngay >> c >> ngayNhapKho.thang >> c >> ngayNhapKho.nam ;
			gotoXY(2*xx, yy + 10);		cout << "Nhap tinh trang sach: ";
			cin >> tinhTrangSach;
		}
		int NhapFile(ifstream &input){
			string s;
			char c;
			if(!(input >> ma)) // kiem tra xem doc file thanh cong hay khong
				return 0;
			getline(input, s); // doc enter
			getline(input, tenSach);
			getline(input, tacGia);
			getline(input, nhaXuatBan);
			input >> gia >> namPhatHanh >> soTrang >> ngayNhapKho.ngay >> c >> ngayNhapKho.thang >> c >> ngayNhapKho.nam >> tinhTrangSach;
			return 1;
		}
		void XuatFile(ofstream &out){
			out << ma << endl;
			out << tenSach << endl;
			out << tacGia << endl;
			out << nhaXuatBan << endl;
			out << gia << endl;
			out << namPhatHanh << endl;
			out << soTrang << endl;
			out << ngayNhapKho.ngay << "/" << ngayNhapKho.thang << "/" << ngayNhapKho.nam << endl;
			out << tinhTrangSach << endl;
		}
		void Xuat(int x, int y, int color){
			TextColor(color); // cai dat mau
			gotoXY(x, y);
			cout << left << setw(10) << ma << setw(30) << tenSach << setw(20) << tacGia << setw(20) << nhaXuatBan 
					 << setw(10) <<	gia << setw(20) << namPhatHanh << setw(15) << soTrang 
					 << setw(2) << right << ngayNhapKho.ngay << "/" << setw(2) << ngayNhapKho.thang << "/" << left << setw(10) << ngayNhapKho.nam
					 << setw(10) << tinhTrangSach << endl;
		}
};
class BanDoc{
	private:
		string ma;
		string name;
		date ngayDK;
	public:
		BanDoc* next;
		string Ma(){
			return ma;
		}
		void NhapFile(ifstream &input){
			char c;
			string enter;
			getline(input, ma);
			getline(input, name);
			input >> ngayDK.ngay >> c >> ngayDK.thang >> c >> ngayDK.nam;
			getline(input, enter);
		}	
};
class PhieuMuon{
	private:
		int soPhieuMuon = 1;
		string maBanDoc;
		string maSach;
		date ngayMuon;
		date ngayTra;
		int tinhTrangPhieuMuon = 1;
	public:
		PhieuMuon* next;
		int SPM(){
			return soPhieuMuon;
		}
		string MaSach(){
			return maSach;
		}
		void Tao(string _maSach, string _maBanDoc, int _soPhieuMuon){
			soPhieuMuon = _soPhieuMuon;
			maSach = _maSach;
			maBanDoc = _maBanDoc;
			ngayMuon.layThoiGian(); // lay moc thoi gian hien tai
			ngayTra = ngayMuon;
			ngayTra.ngay += 7;
		}
		int NhapFile(ifstream &in){
			char c;
			string enter;
			if(!(in  >> soPhieuMuon)) // neu doc file khong thanh cong thi tra ve 0
				return 0;
				in >> maBanDoc
				>> maSach
				>> ngayMuon.ngay >> c >> ngayMuon.thang >> c >> ngayMuon.nam
				>> ngayTra.ngay >> c >> ngayTra.thang >> c >> ngayTra.nam;
		}
		void HienThi(int x, int y, int color){
			TextColor(color);
			gotoXY(x, y);
			cout<< left << setw(15) << soPhieuMuon << setw(15)  << maBanDoc << setw(15) << maSach
				<< setw(2) << right << ngayMuon.ngay << "/" << setw(2) << ngayMuon.thang << "/" << setw(9) << left << ngayMuon.nam
				<< setw(2) << right << ngayTra.ngay << "/" << setw(2) << ngayTra.thang << "/" << setw(9) << left << ngayTra.nam
				<< setw(10)<< tinhTrangPhieuMuon << endl;
		}
		void GhiFile(ofstream &out){
			out << soPhieuMuon << endl;
			out << maBanDoc << endl;
			out << ngayMuon.ngay << "/" << ngayMuon.thang << "/" << ngayMuon.nam << endl;
			out << ngayTra.ngay << "/" << ngayTra.thang << "/" << ngayTra.nam << endl;
			out << tinhTrangPhieuMuon << endl;
		}
		
};
class QuanLySach{
	private:
		Sach* headS;
		BanDoc* headB; 
		PhieuMuon* headP;
	public:
		void KhoiTao(){
			headS = NULL;
			headB = NULL;
			headP = NULL;
		}
		int KiemTra(string _ma, int tinhTrang){
			Sach* i = headS;
			while(i != NULL){
				if(i->KiemTra(_ma) == 0){
					i->TinhTrangSach(tinhTrang);
					return 1;
				}
				i = i->next;
			}
			return 0;
		}
		void ThemSach(){
			Sach* p = new Sach;
			p->Nhap();
			p->next = NULL;
			if(this->KiemTra(p->Ma(), -1) == 1){ // kiem tra ma sach co ton tai khong
				gotoXY(3*xx, yy + 10);
				cout << "Ma sach da co trong kho vui long kiem tra lai!";
				return;
			} 
			// them vao cuoi
			Sach* i = headS;
			while(i->next != NULL)
				i = i->next;
			i->next = p;
			gotoXY(3*xx, yy + 13);
			cout << "Da them vao kho thanh cong!";
			this->XuatFileS(); // cap nhap file
		}	
		void DocFileS(){
			Sach* i;
			ifstream input;
			input.open("./sach.txt");
			while(!input.eof()){
				Sach* p = new Sach;
				if(!p->NhapFile(input))
					return;
				if(headS == NULL){
					headS = p;
					i = p;
				}
				else{
					i->next = p;
					i = i->next;
				}
			}
		}
		void XuatFileS(){
			ofstream out;
			out.open("./sach.txt");
			Sach* i = headS;
			while(i->next != NULL){
				i->XuatFile(out);
				i = i->next;
			}
		}
		void XuatS(){
			Sach* i = headS;
			int x = 2;
			if(i != NULL){
				TextColor(mauKhung);
				for(int ii=0; ii<=10 + 30 + 20 + 20 + 10 + 20 + 15 + 15 + 10; ii++){ // khung
					gotoXY(xx + ii, yy - 1);		cout << char(196);
					gotoXY(xx + ii, yy + 1);		cout << char(196);
					gotoXY(xx + ii, yy + 3);		cout << char(196);
				}
				TextColor(mauTieuDe);
				gotoXY(4*xx, yy);		cout << "DANH SACH\n";
				gotoXY(xx, yy + 2);
				cout << left << setw(10) << "Ma" << setw(30) << "Ten sach" << setw(20) << "Tac gia" << setw(20) << "Nha xuat ban"
							 << setw(10) <<	"Gia" << setw(20) << "Nam phat hanh" << setw(15) << "So trang" << setw(15) << "Ngay nhap" 
							 << setw(10) << "Tinh trang\n";
							 
				while(i != NULL){
					i->Xuat(xx, yy + 2*x++, mauChu);
					TextColor(mauKhung);
					for(int ii=0; ii<=10 + 30 + 20 + 20 + 10 + 20 + 15 + 15 + 10; ii++){ // khung
						gotoXY(xx + ii, yy + 2*x - 1);		cout << char(196); 
					}
					i = i->next;
				}
			}
		}
		void XoaS(string _ma){
			Sach* i = headS;
			if(i->KiemTra(_ma) == 1){
				if(i->TinhTrangSach(-1) == 1){ // kiem tra co trong kho khong va tinh trang sach voi phan tu dau tien
					headS = headS->next;
					gotoXY(3*xx, yy + 13);
					cout << "Da xoa sach khoi danh sach!";
				}else{
					gotoXY(3*xx, yy + 13);
					cout << "Khong the xoa vi sach da duoc muon!";
				}
				return;
			}
			// kiem tra co trong kho khong va tinh trang sach voi phan tu tiep theo
			while(i->next != NULL){
				if(i->next->KiemTra(_ma) == 1){
					if(i->TinhTrangSach(-1) == 1){
						i->next = i->next->next;
						gotoXY(3*xx, yy + 13);
						cout << "Da xoa sach khoi danh sach!";
						this->XuatFileS();
					}else{ // do sach da duoc muon
						gotoXY(3*xx, yy + 13);
						cout << "Khong the xoa vi sach da duoc muon!";
					}
					return; // ket thuc 
				}
				i = i->next;
			}
			gotoXY(3*xx, yy + 13);
			cout << "Ma khong co trong danh sach!";
		}
		int KiemTraB(string _ma){ // kiem tra ma ban doc
			BanDoc* i = headB;
			while(i != NULL){
				if(i->Ma() == _ma)
					return 1;
				i = i->next;
			}
			return 0;
		}
		int KiemTraTT(string _ma, string _maBanDoc){ // keim tra thong tin ban doc
			Sach* i = headS;
			while(i != NULL){
				if(i->KiemTra(_ma) == 1 && i->TinhTrangSach(-1) == 1 && KiemTraB(_maBanDoc) == 1){
					i->TinhTrangSach(0);// cap nhat lai tinh trang sach
					return 1;
				}
				i = i->next;
			}
			return 0;
		}
		void DocFileB(){
			BanDoc* i;
			ifstream input;
			input.open("./Bandoc.txt");
			while(!input.eof()){
				BanDoc* p = new BanDoc;
				p->NhapFile(input);
				p->next = NULL;
				if(headB == NULL){
					headB = p;
					i = p;
				}
				else{
					i->next = p;
					i = i->next;
				}
			}
		}
		void DocFileP(){
			PhieuMuon* i;
			ifstream input;
			input.open("./PhieuMuon.txt");
			while(!input.eof()){
				PhieuMuon* p = new PhieuMuon;
				p->NhapFile(input);
				p->next = NULL;
				if(headP == NULL){
					headP = p;
					i = headP;
				}
				else{
					i->next = p;
					i = i->next;
				}
			}
		}
		void ThemPhieuMuon(){
			string _maSach;
			string _maBanDoc;
			gotoXY(2*xx, yy + 2); cout << "Nhap ma sach: "; cin >> _maSach;
			gotoXY(2*xx, yy + 4); cout << "Nhap ma ban doc: "; cin >> _maBanDoc;
			if(this->KiemTraTT(_maSach, _maBanDoc) == 1){ // neu sach ma sach va ma ban doc dung
				PhieuMuon* i = headP;
				while(i->next != NULL)
					i = i->next;
				PhieuMuon* p = new PhieuMuon;
				p->Tao(_maSach, _maBanDoc, i->SPM() + 1); // tao phieu muon moi
				p->next = NULL;
				i->next = p;
				gotoXY(2*xx, yy + 6);
				cout << "Them thanh cong";
			}
			else{
				gotoXY(2*xx, yy + 6);
				cout << "Them phieu muon that bai do ma sach khong ton tai hoac ban doc chua dang ky!";
			}
		}
		void HienThiPhieu(){
			PhieuMuon* i = headP;
			int x = 2;
			if(i != NULL){
				TextColor(mauKhung);
				for(int ii=0; ii<=15 + 15 + 15 + 15 + 15 + 10; ii++){
					gotoXY(xx + ii, yy - 1);		cout << char(196);
					gotoXY(xx + ii, yy + 1);		cout << char(196);
					gotoXY(xx + ii, yy + 3);		cout << char(196);
				}
				TextColor(mauTieuDe);
				gotoXY(3*xx, yy);		cout << "DANH SACH\n";
				gotoXY(xx, yy + 2);
				cout << left << setw(15) << "So phieu" << setw(15) << "Ma ban doc" << setw(15) << "Ma sach" << setw(15) << "Ngay muon" 
							 << setw(15) << "Ngay tra" << setw(10) << "Tinh trang\n";
				while(i != NULL){
					i->HienThi(xx, yy + 2*x++, mauChu);
					TextColor(mauKhung);
					for(int ii=0; ii<=15 + 15 + 15 + 15 + 15 + 10; ii++){
						gotoXY(xx + ii, yy + 2*x - 1);		cout << char(196);
					}
					i = i->next;
				}
			}
		}
		void XoaPhieu(){
			int _ma;
			gotoXY(2*xx, yy + 2); cout << "Nhap so phieu muon: ";
			cin >> _ma;
			PhieuMuon* i= headP;
			if(i->SPM() == _ma){ // kiem tra phan tu dau tien
				this->KiemTra(i->MaSach(), 1);
				headP = headP->next;
				gotoXY(2*xx, yy + 6);
				cout << "Xoa thanh cong";
				return;
			}
			while(i->next != NULL){ // kiem tra cac phan tu tiep theo
				if(i->next->SPM() == _ma){
					this->KiemTra(i->next->MaSach(), 1);
					 i->next = i->next->next;
					 gotoXY(2*xx, yy + 6);
					 cout << "Xoa thanh cong";
					 return;
				}
				i = i->next;
			}
			gotoXY(2*xx, yy + 6);
			cout << "Phieu khong ton tai";
		}
	 	
};
int DangNhap(QuanLyAdmin quanLy){
	int num = 3; 	// so lan dang nhap
	int x = 2; 		// toa do hang bat dau cua khung
	int y = 45;		// toa do cot bat dau cua khung
	int m = 50; 	// do rong cua khung
	int n = 10; 	//
	Khung(y, x, m, n);	
	Khung(y, x, m, n - 8);
	TextColor(10);
	gotoXY(y + m/2 - 5, x  + 1); cout << "DANG NHAP";
	gotoXY(y + 5, x  + 3); cout << "User: ";
	gotoXY(y + 5, x  + 6); cout << "Password: ";
	while(num > 0){
		TextColor(7);
		string tk, mk;
		char c;			// ki tu de lay mat khau
		gotoXY(y + 5, x  + 4);	cin >> tk;
		gotoXY(y + 5 + mk.size(), x + 7);
		while(1){
			if(kbhit()){
				c = getch();
				switch(c){
					case 13:{ // khi bam esc
						goto Out;
						break;
					}
					case 8:{// khi bam backspace
						if(mk.size() > 0){
							gotoXY(y + 5 + mk.size(), x + 7);
							mk.erase(mk.size() - 1, 1);
							cout << " ";
						}
						break;
					}
					default:{
						mk.push_back(c);
						gotoXY(y + 5 + mk.size(), x + 7);
						cout << "*";
						break;
					}
				}	
			}
		}
		Out:
		if(quanLy.KiemTra(tk, mk) == 0){ // kiem tra tk, mk
			TextColor(4);
			gotoXY(y - 3, x + n + 3);
			cout << "Tai khoan hoac mat khau khong chinh xac! Vui long kiem tra lai.";	
			Sleep(1000);	// dung chuong trinh 1s
			gotoXY(y - 3, x + n + 3);
			cout << "                                                               "; //  Xoa dong thong bao
			for(int i=1; i<m; i++){
				gotoXY(y + i, x + 4); cout << " ";
				gotoXY(y + i, x + 7); cout << " ";
			}
			num--;	
		}else{
			system("cls");
			return 1;	// dang nhap thanh cong
		}	
	}
	system("cls");
	return 0;	// dang nhap that bai
}	
