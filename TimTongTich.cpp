#include <iostream>
#include <string.h>

using namespace std;

int KQ(string c, int n, int *a){
	int kq = 0;
	for(int i=0; i<n; i++){
		if(c[i] == '*'){
			kq += a[i]*a[i+1];
			i++;
		}else
			kq += a[i];
	}
	return kq;
}

int main(){
	int sum = 0;
	int n;
	cout << "Nhap n: "; cin >> n;
//	int a[n];
//	for(int i=0; i<n; i++)
//		cin >> a[i];
		
	string s[100];
	int dem1 = 1, dem2 = 1;
	int dem3;
	for(int i=1; i<n; i++){
		for(int j=0; j<dem2; j++)
			s[j + dem2] = s[j] + "*"; // j = 0 , dem2 =1 ->s[1] = s[0] + "*"
		for(int j=0; j<dem2; j++)
			s[j] += "+"	; // s[0] += "+"
		dem3 = dem1 + dem2;
		dem1 = dem2;
		dem2 = dem3;
	}	
	
	for(int i=0; i<dem3; i++){
		cout << s[i] << endl;
//		int kq = KQ(s[i], n, a);
//		if(sum < kq)
//			sum = kq;
	}
//	cout <<"Tong tich = " << sum;
}
