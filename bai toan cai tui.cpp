#include <iostream>
#include<iomanip>
using namespace std;

int Giai(int *trong_luong, int *gia_tri, int n, int m){
	int a[100][100]; 
	for(int j=0; j<=m; j++)
		for(int i=0; i<=n; i++)
			if(i==0 || j == 0)
				a[i][j] = 0;
			else	if(j < trong_luong[i])
				a[i][j] = a[i-1][j];
			else{
				if(a[i-1][j] > gia_tri[i] + a[i-1][j - trong_luong[i]])
					a[i][j] = a[i-1][j];
				else
					a[i][j] = gia_tri[i] + a[i-1][j - trong_luong[i]];
			}			
	return a[n][m];
}
int main(){
	int trong_luong[100], gia_tri[100];
	int n, m;
	cout << "Nhap n: ";	cin >> n;
	cout << "Nhap gia tri tuong ung:\n";
	trong_luong[0] = 0, gia_tri[0] = 0;
	for(int i=1; i<=n; i++)
		cin >> trong_luong[i] >> gia_tri[i];
	cout << "Nhap suc chua toi da: ";	cin >> m;
	cout << setw(10) << left << "vat" << setw(15) << "trong luong" << "gia tri" << endl;
	for(int i=1; i<=n; i++)
		cout << setw(10) << i << setw(15) << trong_luong[i] << gia_tri[i] << endl;

	cout << "Trong luong toi da: " << Giai(trong_luong, gia_tri, n, m) << endl;
	return 0;
}
