#include <iostream>
#include <string.h>

using namespace std;

class BankAccount{
	string ma;
	string ten;
	string cmnd;
	double soDu;
	public:
		BankAccount(){
			ma = "000000";
			ten = "No name";
			cmnd = "xxx";
			soDu = 50000;
		}
		BankAccount(string _ma, string _ten, string _cmnd, double _soDu){
			ma = _ma;
			ten = _ten;
			cmnd = _cmnd;
			soDu = _soDu;
		}
		string GetID(){
			return ma;
		}
		string GetCustomerName(){
			return ten;
		}
		string GetIDCardNumber(){
			return cmnd;
		}
		double GetBanlance(){
			return soDu;
		} 
		double GetWithdrawLimit(){
			return soDu - 50000 > 0 ? soDu - 50000 : 0;
		}
		bool Withdraw(double tienRut){
			if(soDu - tienRut > 50000){
				soDu -= tienRut;
				return true;
			}
			return false;
		}
		double Deposit(double tienGui){
			soDu += tienGui;
			return soDu;
		}
		friend istream &operator >> (istream &in, BankAccount &x){
			cout << "\nNhap ma khach: ";	in >> x.ma;
			cout << "Nhap ten khach: ";
			in.ignore(); getline(in, x.ten);
			cout << "Nhap so cccd/cmnd: "; in >> x.cmnd;
			cout << "Nhap so tien: "; in >> x.soDu;
			return in;
		}
		friend ostream &operator << (ostream &out, BankAccount &x){
			out << "\n\nTai khoan cua ban:\n";
			out << "Ma: " << x.ma << endl;
			out << "Ten: " << x.ten << endl;
			out << "CMND/CCCD: " << x.cmnd << endl;
			out << "So du: " << x.soDu << endl;
			return out;
		}
		BankAccount operator+ (int y){
			BankAccount x;
			x.ma = this->ma;
			x.ten = this->ten;
			x.cmnd = this->cmnd;
			if(this->soDu + y)
				x.soDu = this->soDu + y;
			return x;
		}
		BankAccount operator- (int y){
			BankAccount x;
			x.ma = this->ma;
			x.ten = this->ten;
			x.cmnd = this->cmnd;
			if(this->soDu - y)
				x.soDu = this->soDu - y;
			return x;
		}
		
};
int main(){
	int k;
	cout << "\nTen sinh vien: Duc";
	cout << "\nMa sinh vien: 210";
	cout << "\nKhoa: K55";
	do{
		cout << "\nNhap yc: ";
		cin >> k;
		switch(k){
			case 0:{
				return 0;
				break;
			}
			case 1:{
				string ma, ten, cmnd;
				double tien;
				cout << "\nNhap ma khach: ";	cin >> ma;
				cout << "Nhap ten khach: ";
				cin.ignore(); getline(cin, ten);
				cout << "Nhap so cccd/cmnd: "; cin >> cmnd;
				cout << "Nhap so tien: "; cin >> tien;
				BankAccount a(ma, ten, cmnd, tien);
				int n;
				cout << "Nhap so lan thao tac: ";	cin >> n;
				for(int i=0; i<n; i++){
					cout << "\n\nTai khoan cua ban:\n";
					cout << "Ma: " << a.GetID() << endl;
					cout << "Ten: " << a.GetCustomerName() << endl;
					cout << "CMND/CCCD: " << a.GetIDCardNumber() << endl;
					cout << "So du: " << a.GetBanlance() << endl;
					int x; 
					double y;
					cin >> x >> y;
					if(x == 1){
						a.Deposit(y);
						cout << "\nGui tien thanh cong!\n";
					}else{
						if(!a.Withdraw(y))
							cout << "\nRut tien that bai!\n";
						else
							cout << "\nRut tien thanh cong!\n";
					}
				}
				cout << "\n\nTai khoan cua ban:\n";
				cout << "Ma: " << a.GetID() << endl;
				cout << "Ten: " << a.GetCustomerName() << endl;
				cout << "CMND/CCCD: " << a.GetIDCardNumber() << endl;
				cout << "So du: " << a.GetBanlance() << endl;
				break;
			}
			case 2:{
				BankAccount a;
				cin >> a;
				int n;
				cout << "Nhap so lan thao tac: ";	cin >> n;
				for(int i=0; i<n; i++){
					cout << a;
					int x, y;
					cin >> x >> y;
					if(x == 1)
						a = a + y;
					else
						a = a - y;
				}
				cout << a;
				break;
			}
		}
	}while(k != 0);
}
