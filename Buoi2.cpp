/*
#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace std;
int* Doc(int &n, char *s){
	ifstream fileIn;
	fileIn.open(s);
	fileIn >> n;
	int *a = new int[n];
	for(int i=0; i<n; i++)
		fileIn >> a[i];
	return a;
}
int *Doc2(int &n, char *s){
	FILE *input = fopen(s, "r");
	fscanf(input, "%d", &n);
	int *a = new int[n];
	for(int i=0; i<n; i++)
		fscanf(input, "%d", &a[i]);
	return a;
}
void Xuat(int *a, int n){
	for(int i=0; i<n; i++)
		cout << a[i] << " ";
	cout << endl;
}
void XuatFile(int *a, int n, char *s){
	ofstream fileOut;
	fileOut.open(s);
	for(int i=0; i<n; i++)
		fileOut << a[i] << " ";
}
void Sort(int *a, int n){
	for(int i=0; i<n-1; i++)
		for(int j=i+1; j<n; j++)
			if(a[i] > a[j]){
				int t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
}
int Sum(int *dau, int *cuoi){
	int sum = 0;
	for(int *i = dau; i<cuoi; i++)
		sum += *i;
	return sum;
}
int main(){
	int n;
	char s[] = "D:\\C++\\On tap\\Input1_1.txt";
	int *a = Doc2(n, s);
//	Sort(a, n);
	Xuat(a, n);
//	XuatFile(a, n, "D:\\C++\\On tap\\Output1_1.txt");
	cout << Sum(a +1, a + 3);
}


#include <iostream>

using namespace std;

//struct PhanSo{
//	int Tu;
//	int Mau;
//	void Doc3(){
//		cout << "Nhap tu: "; cin >> Tu;
//		cout << "Nhap mau: "; cin >> Mau;
//	}
//	void Xuat(){
//		cout << Tu << " / " << Mau;
//	}
//};

int UCLN(int a, int b){
	while(b != 0){
		int t = b;
		b = a % b;
		a = t;
	}
	return a;
}
typedef struct PhanSo{
	int Tu;
	int Mau;
	void Doc3(){
		cout << "Nhap tu: "; cin >> Tu;
		cout << "Nhap mau: "; cin >> Mau;
	}
	void Xuat(){
		if(Tu == 0)	
			cout << 0;
		else
			cout << Tu << " / " << Mau;
	}
	PhanSo Tong(PhanSo b){
		PhanSo c;
		c.Tu = Tu*b.Mau + b.Tu*Mau;
		c.Mau = Mau*b.Mau;
		int uc = UCLN(c.Tu, c.Mau);
		c.Tu /= uc;
		c.Mau /= uc;
		return c;
	}
	PhanSo Hieu(PhanSo b){
		PhanSo c;
		c.Tu = Tu*b.Mau - b.Tu*Mau;
		c.Mau = Mau*b.Mau;
		int uc = UCLN(c.Tu, c.Mau);
		c.Tu /= uc;
		c.Mau /= uc;
		return c;
	}
	PhanSo Tich(PhanSo b){
		PhanSo c;
		c.Tu = Tu*b.Tu;
		c.Mau = Mau*b.Mau;
		int uc = UCLN(c.Tu, c.Mau);
		c.Tu /= uc;
		c.Mau /= uc;
		return c;
	}
	PhanSo Thuong(PhanSo b){
		PhanSo c;
		c.Tu = Tu*b.Mau;
		c.Mau = Mau*b.Tu;
		int uc = UCLN(c.Tu, c.Mau);
		c.Tu /= uc;
		c.Mau /= uc;
		return c;
	}
}PS;
PS Doc(){
	PhanSo a;
	cout << "Nhap tu: "; cin >> a.Tu;
	cout << "Nhap mau: "; cin >> a.Mau;
	return a;
}
void Doc2(PS &a){
	cout << "Nhap tu: "; cin >> a.Tu;
	cout << "Nhap mau: "; cin >> a.Mau;
}
void Xuat(PS a){
	cout << a.Tu << " / " << a.Mau;
}
PS Tong(PS a, PS b){
	PS c;
	c.Tu = a.Tu*b.Mau + b.Tu*a.Mau;
	c.Mau = a.Mau*b.Mau;
	int uc = UCLN(c.Tu, c.Mau);
	c.Tu /= uc;
	c.Mau /= uc;
	return c;
}
int main(){
	PS a, b, c;
	a.Doc3();
	b.Doc3();
//	c = Tong(a, b);
//	Doc2(a);
	c = a.Tong(b);
	c.Xuat();
	cout << endl;
	c = a.Hieu(b);
	c.Xuat();
	cout << endl;
	c = a.Tich(b);
	c.Xuat();
	cout << endl;
	c = a.Thuong(b);
	c.Xuat();
	cout << endl;
}


#include <iostream>
#include <math.h>

using namespace std;

struct SoPhuc{
	float Thuc;
	float Ao;
	void Nhap(){
		cout << "Nhap phan thuc: "; cin >> Thuc;
		cout << "Nhap phan ao: "; cin >> Ao;
	}
	void Xuat(){
		if(Thuc == Ao && Thuc == 0)
			cout << 0;
//		else	if(Thuc == 0)
//			cout << Ao << "i";
//		else	if(Ao == 0)
//			cout << Thuc;
//		else	if(Ao > 0){
//			cout << Thuc << "+" << Ao << "i";
//		}else
//			cout << Thuc << Ao << "i";
			
		if(Thuc > 0)
			cout << Thuc;
		else	if(Thuc < 0)
			cout << "(" << Thuc << ")";
		
		if(Ao > 0)
			cout << " + " << Ao << "i";
		else	if(Ao < 0)
			cout << " - " << -1*Ao << "i";	
	}
	void Tong(SoPhuc a){
		SoPhuc b;
		b.Thuc = Thuc + a.Thuc;
		b.Ao = Ao + a.Ao;
		Xuat(); cout << " + "; a.Xuat(); cout << " = "; b.Xuat();
	//	return b;
	}
	void Hieu(SoPhuc a){
		SoPhuc b;
		b.Thuc = Thuc - a.Thuc;
		b.Ao = Ao - a.Ao;
		Xuat(); cout << " - "; a.Xuat(); cout << " = "; b.Xuat();
	//	return b;
	}
	SoPhuc Tich(SoPhuc a){
		SoPhuc b;
		b.Thuc = Thuc*a.Thuc - Ao*a.Ao;
		b.Ao = Ao*a.Thuc + a.Ao*Thuc;
	//	cout << "("; Xuat(); cout << ") * ("; a.Xuat(); cout << ") = "; b.Xuat();
		return b;
	}
	SoPhuc LienHop(){
		SoPhuc b;
		b.Thuc = Thuc;
		b.Ao = -Ao;
		return b;
	}
	float MoDun(){
		return sqrt(Thuc*Thuc + Ao*Ao);
	}
	SoPhuc Thuong(SoPhuc a){
		SoPhuc A = a.LienHop();
		SoPhuc b;
		b.Thuc = Thuc;
		b.Ao = Ao;
		SoPhuc c = b.Tich(A);
		c.Thuc /= a.MoDun()*a.MoDun();
		c.Ao   /= a.MoDun()*a.MoDun();
		return c;
	}
};

int main(){
	SoPhuc a, b, c;
	a.Nhap();
	a.Xuat();
	cout << endl;
	b.Nhap();
	b.Xuat();
	cout << endl;
	a.Tong(b);
	cout << endl;
	a.Hieu(b);
	cout << endl;
//	a.Tich(b);
	c = a.Thuong(b);
	c.Xuat();
}
*/
#include <iostream>
#include <string.h>

using namespace std;

struct NgaySinh{
	int d;
	int m;
	int y;
};
struct SinhVien{
	string ID;
	string name;
	NgaySinh date;
	float diem;
};

void Nhap(SinhVien &a){
	char c;
	cout << "Nhap ID: "; cin >> a.ID;
	cout << "Nhap ten: "; cin.ignore(); getline(cin, a.name);
	cout << "Nhap ngay sinh: "; cin >> a.date.d >> c >> a.date.m >> c >> a.date.y;
	cout << "Nhap diem: "; cin >> a.diem;
}
void Xuat(SinhVien a){
	cout << a.ID << "\t" << a.name << "\t" << a.date.d << "/" << a.date.m << "/" << a.date.y << "\t" << a.diem << endl; 
}
void NhapDSSV(SinhVien *a, int n){
	for(int i=0; i<n; i++)
		Nhap(a[i]);
}
void XuatDSSV(SinhVien *a, int n){
	for(int i=0; i<n; i++)
		Xuat(a[i]);
}
SinhVien Search(SinhVien *a, int n){
	SinhVien KetQua = a[0];
	float max = a[0].diem;
	for(int i=1; i<n; i++)
		if(a[i].diem > max){
			max = a[i].diem;
			KetQua = a[i];
		}
	return KetQua;
}
int main(){
	int n;
	cin >> n;
	SinhVien *a = new SinhVien[n];
	SinhVien b;
	NhapDSSV(a, n);
	b = Search(a, n);
	Xuat(b);
}






