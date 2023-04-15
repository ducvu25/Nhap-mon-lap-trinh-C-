#include <iostream>

using namespace std;

struct phong{
	int sucChua; // suc chua toi da
	int soNguoi; // trong = 0 la phong trong, con lai la co ng
	int doiTuong; // 1 la uu tien, 0 la binh thuong
};
void Xuat(phong *Phong, int m){ // O(m) do phuc tap
	for(int i=0; i<m; i++){
		if(Phong[i].soNguoi > 0){ // kiem tra phong khong trong
			if(Phong[i].doiTuong == 0)	cout << "Doi tuong binh thuong: ";
			else cout << "Doi tuong uu tien: ";
			cout << "Suc chua " << Phong[i].sucChua << ", chua " << Phong[i].soNguoi << " nguoi\n";
		}
	}
}
void Sort(int *Nguoi, phong *Phong, int n, int m, int k){ // danh sach nguoi, danh sach phong, so lg ng, phong, so lg ng uu tien
	// Sap xep k nguoi dau theo thu tu tang dan
	// o(k^2)
	for(int i=0; i<k-1; i++)
		for(int j=i+1; j<k; j++)
			if(Nguoi[i] > Nguoi[j]){
				int t = Nguoi[i];
				Nguoi[i] = Nguoi[j];
				Nguoi[j] = t;
			}
	// Sap xep n - k nguoi tiep theo, theo thu tu tang dan
	// O((n-k)^2
	for(int i=k; i<n-1; i++)
		for(int j=i+1; j<n; j++)
			if(Nguoi[i] > Nguoi[j]){
				int t = Nguoi[i];
				Nguoi[i] = Nguoi[j];
				Nguoi[j] = t;
			}
	// => O(n^2)
	// Sap xep phong
	// O(m^2)
	for(int i=0; i<m-1; i++)
		for(int j=i+1; j<m; j++)
			if(Phong[i].sucChua > Phong[j].sucChua){
				phong t = Phong[i];
				Phong[i] = Phong[j];
				Phong[j] = t;
			}
}
// => O(n^2 + m^2)
int main(){
	int n, m, k;
	cout << "Nhan n: "; cin >> n;
	int Nguoi[n];
	for(int i=0; i<n; i++)
		cin >> Nguoi[i];
		
	cout << "Nhap m: "; cin >> m;
	phong Phong[m];
	for(int i=0; i<m; i++){
		cin >> Phong[i].sucChua;
		Phong[i].soNguoi = 0;
	}
		
	cout << "Nhap k: "; cin >> k;
	Sort(Nguoi, Phong, n, m, k); // O(m^2 + n^2)
	
	int soLuongPhongConLai = m;
	// k*m
	for(int i=0; i<k; i++){
		for(int j=0; j<m; j++)
			if(Phong[j].sucChua >= Nguoi[i] && Phong[j].soNguoi == 0){ // bj >= ai, phong phai trong
				Phong[j].soNguoi = Nguoi[i]; // ngan so luong ng trong phong
				Phong[j].doiTuong = 1;  // vi la k ng dau nen la uu tien
				soLuongPhongConLai --; // giam so lg phong trong
				if(soLuongPhongConLai <= 0)
					goto Out; // nhay dien diem out:
				break; // ket thuc vong for trong
			}
	}
	// (n-k)*m
	for(int i=n-1; i>=k; i--){
		for(int j=m-1; j>=0; j--)
			if(Phong[j].sucChua >= Nguoi[i] && Phong[j].soNguoi == 0){
				Phong[j].soNguoi = Nguoi[i];
				Phong[j].doiTuong = 0;
				soLuongPhongConLai --;
				if(soLuongPhongConLai <= 0)
					goto Out;
				break;
			}else if(Phong[j].sucChua < Nguoi[i])
				break;
	}
	Out:
	Xuat(Phong, m);
}
// chien luoc chia de tri
// m^2 + n^2 + m*n + m 
