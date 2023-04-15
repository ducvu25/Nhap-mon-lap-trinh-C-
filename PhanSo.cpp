#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;

int UCLN(long a, long b){
	while(b != 0){
		int t = b;
		b = a % b;
		a = t;
	}
	return a;
}
struct PhanSo{
	long Tu;
	long Mau;
};
int SoSanh(PhanSo a, PhanSo b){
	return a.Tu*b.Mau >= a.Mau*b.Tu ? 1 : -1;
}
void RutGon(PhanSo &c){
	int ucln = UCLN(c.Tu, c.Mau);
	c.Tu /= ucln;
	c.Mau /= ucln;
}
void KhoiTao (PhanSo &a){
	do{
		a.Tu = rand() %19 + 1;
		a.Mau = rand() %(a.Tu - 1) + 1;
		RutGon(a);
	}while(1.0*a.Tu/a.Mau > 10 || 1.0*a.Tu/a.Mau < 1);
}
void XuatDS(PhanSo *a, int i){
	if(i < 20){
		cout << a[i].Tu << " / " << a[i].Mau << endl;
		XuatDS(a, i + 1);
	}
}
PhanSo Sum(PhanSo a, PhanSo b){
	PhanSo c;
	c.Tu = a.Tu*b.Mau + a.Mau*b.Tu;
	c.Mau = a.Mau*b.Mau;
	RutGon(c);
	return c;
}

PhanSo Max(PhanSo *a){
	PhanSo max = a[0];
	for(int i=1; i<20; i++)
		if(SoSanh(max, a[i]) == -1)
			max = a[i];
	return max;
}
void SelectionSort(PhanSo *a){
	for(int i=0; i<19; i++){
		int min = i;
		for(int j=i+1; j<20; j++)
			if(SoSanh(a[j], a[min]) == -1)
				min = j;
		PhanSo t = a[i];
		a[i] = a[min];
		a[min] = t;
	}
		
}
int main(){
	PhanSo a[20];
	PhanSo x;
//	srand(time(NULL));
	for(int i=0; i<20; i++){
		KhoiTao(a[i]);
	}
	XuatDS(a, 0);
	x = Max(a);
	cout << "\nPhan so lon nhat: " << x.Tu << " / " << x.Mau << endl;
	x = a[0];
	for(int i=1; i<20; i++){
		x = Sum(x, a[i]);
	}
	cout << "\nTong day phan so: " << x.Tu << " / " << x.Mau << endl;
	SelectionSort(a);
	XuatDS(a, 0);
}
