#include <iostream>

using namespace std;
int UCLN(int a, int b){
	while(b != 0){
		int t = b;
		b = a % b;
		a = t;
	}
	return a;
}
class PhanSo{
		int tu;
		int mau;
	public:
		PhanSo(){
			tu = 0;
			mau = 1;
		}
		void nhap(){
			cin >> tu;
			do{
				cin >> mau;
			} while(mau == 0);
		}
		void xuat(){
			int uc = UCLN(tu, mau);
			tu /= uc;
			mau /= uc;
			cout << tu << " / " << mau;
		}
		PhanSo operator+(PhanSo a){
			PhanSo c;
			c.tu = this->tu*a.mau + this->mau*a.tu;
			c.mau = this->mau*a.mau;
			return c;
		}
		PhanSo operator-(PhanSo a){
			PhanSo c;
			c.tu = this->tu*a.mau - this->mau*a.tu;
			c.mau = this->mau*a.mau;
			return c;
		}
		PhanSo operator*(PhanSo a){
			PhanSo c;
			c.tu = this->tu*a.tu;
			c.mau = this->mau*a.mau;
			return c;
		}
		PhanSo operator/(PhanSo a){
			PhanSo c;
			c.tu = this->tu*a.mau;
			c.mau = this->mau*a.tu;
			return c;
		}
};
class mangPhanSo{
	int n;
	PhanSo *a;
	public:
		void KhoiTao(int n){
			a = new PhanSo[n];
		}
		mangPhanSo operator+(mangPhanSo x){
			int max = n > x.n ? n : x.n;
			mangPhanSo c;
			c.KhoiTao(max);
			for(int i=0; i<max; i++)
				c.a[i] = a[i]*(i < n) + x.a[i]*(i < x.n) ;
			return c;
		}
		mangPhanSo operator-(mangPhanSo x){
			int max = n > x.n ? n : x.n;
			mangPhanSo c;
			c.KhoiTao(max);
			for(int i=0; i<max; i++)
				c.a[i] = a[i]*(i < n) - x.a[i]*(i < x.n) ;
			return c;
		}
		mangPhanSo operator*(mangPhanSo x){
			int max = n > x.n ? n : x.n;
			mangPhanSo c;
			c.KhoiTao(max);
			for(int i=0; i<max; i++)
				c.a[i] = a[i]*(i < n) - x.a[i]*(i < x.n) ;
			return c;
		}
		mangPhanSo operator-(mangPhanSo x){
			int max = n > x.n ? n : x.n;
			mangPhanSo c;
			c.KhoiTao(max);
			for(int i=0; i<max; i++)
				c.a[i] = a[i]*(i < n) - x.a[i]*(i < x.n) ;
			return c;
		}
};
int main(){
	PhanSo a, b, c;
	a.nhap();
	b.nhap();
	c = a + b;
	c.xuat();
	
}
