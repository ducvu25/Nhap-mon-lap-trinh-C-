#include <iostream>
#include <string.h>
#include <iomanip>

using namespace std;

class FixedProperty{
	string 	Location;
	bool	InCity;
	float	EstimateValue;
	public:
		void Nhap(){
			cin.ignore();
			cout << "\nNhap ten thanh pho: ";
			getline(cin, this->Location);
			cout << "Nhap vi tri: ";
			cin >> this->InCity;
			cout << "Nhap gia: ";
			cin >> this->EstimateValue;
		}
		void Xuat(){
			cout << "\nTen thanh pho: " << this->Location << endl;
			cout << "Vi tri: ";
			if(this->InCity)
				cout << "Noi thanh" << endl;
			else
				cout << "Ngoai o" << endl;
			cout << "Gia niem yet: " << this->EstimateValue << endl;
		}
		bool NoiThanh(){
			return this->InCity;
		}
		float Gia(){
			return this->EstimateValue;
		}
};

class Vehicle{
	private:
		string RegNumber;
		float MaxVelocity;
		float RootValue;
	public:
		void Nhap(){
			cin.ignore();
			cout << "\nNhap bien so xe: ";
			getline(cin, this->RegNumber);
			cout << "Nhap van toc toi da: ";
			cin >> this->MaxVelocity;
			cout << "Nhap gia: ";
			cin >> this->RootValue;
		}
		void Xuat(){
			cout << "\nBien so xe: " << this->RegNumber << endl;
			cout << "\nVan toc toi da: " << this->MaxVelocity << endl;
			cout << "\nGia: " << this->RootValue << endl;
		}
		float Gia(){
			return this->RootValue;
		}
};
class Hourse : public FixedProperty{
	private:
		float Area;
	public:
		void Nhap(){
			FixedProperty :: Nhap();
			cout << "Nhap dien tich: ";
			cin >> this->Area;
		}
		float Thue(){
			if(this->NoiThanh())
				return (this->Gia() / 1000 ) * 5 + 5*this->Area;
			return (this->Gia() / 1000 ) * 3;
		}
		float GiaBan(){
			return this->Gia() + this->Thue();
		}
		void Xuat(){
			FixedProperty :: Xuat();
			cout << "dien tich: " << this->Area << endl;
			cout << "Thue: " << this->Thue() << endl;
			cout << "Gia ban: " << this->GiaBan() << endl;
		}
};
class Bus : public Vehicle{
	private:
		int NumSeats;
	public:
		void Nhap(){
			Vehicle :: Nhap();
			cout << "Nhap so ghe: ";
			cin >> this->NumSeats;
		}
		float Thue(){
			if(this->NumSeats > 30)
				return this->Gia()*0.7;
			return this->Gia()*0.6;
		}
		float GiaBan(){
			return this->Gia() + this->Thue();
		}
		void Xuat(){
			Vehicle :: Xuat();
			cout << "So ghe: " << this->NumSeats << endl;
			cout << "Thue: " << this->Thue() << endl;
			cout << "Gia ban: " << this->GiaBan() << endl;
		}
};
class ItemCollection{
	public:
		Hourse* Nha;
		Bus*	Xe;
		int nha;
		int xe;
		int nhaMax;
		int xeMax;
		void KhoiTao(){
			cout << "\nNhap so nha: "; cin >> nhaMax;
			cout << "Nhap so xe: "; cin >> xeMax;
			Nha = new Hourse[nhaMax];
			Xe = new Bus[xeMax];
			nha = 0;
			xe = 0;
		}
		void Nhap(){
			cout << "\nBan muon nhap them bao nhieu nha: ";
			int x; cin >> x;
			for(int i=0; i<x; i++)
				Nha[nha++].Nhap();
			
			cout << "\nBan muon nhap them bao nhieu xe: ";
			cin >> x;
			for(int i=0; i<x; i++)
				Xe[xe++].Nhap();
		}
		void Xuat(){
			if(nha != 0){
				cout << "\nThong tin nha: ";
				for(int i=0; i<nha; i++)
					Nha[i].Xuat();
			}
			if(xe != 0){
				cout << "\n\tThong tin xe: ";
				for(int i=0; i<xe; i++)
					Xe[i].Xuat();
			}
		}
};
int main(){
	ItemCollection a;
	a.KhoiTao();
	a.Nhap();
	a.Xuat();
}

