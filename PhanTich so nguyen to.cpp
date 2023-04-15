// Phan tich n thanh tich cac thua so nguyen to

#include <iostream>
#include <math.h>

using namespace std;

int main(){
	int n;
	cout << "Nhap n: "; cin >> n;
	if(n < 1) 
		cout << "Gia tri khong thoa man!";
	else{
		int x = n;
		int nguyenTo = 2;
		
		while(x != 1){
			// kiem tra so nguyen to
			int kiemtra = 1; // la so nguyen to, 1: la so nt, 0: khong phai
			for(int i=2; i<=sqrt(nguyenTo); i++)
				if(nguyenTo % i == 0){
					kiemtra = 0; // khong phai so nguyen to
					break;
				}
			
			if(kiemtra == 1){
				while(x % nguyenTo == 0){
					x /= nguyenTo;
					if(x > 1)
						cout << nguyenTo << "x";
					else
						cout << nguyenTo;
				}
			}
			nguyenTo++;
		}
	}
}
// n = 4
// x = 4
// nguyenTo = 2
// 4  : 2 = 2
// 2 : 2 = 1;
//12
//2
//12 : 2 = 6
//6 : 2 = 3
//3 : 3 = 1
