#include "setUp.h"
#include "class.h"

using namespace std;


int main(){
	QuanLyAdmin quanLy;
	quanLy.KhoiTao();
	quanLy.Nhap();
//	cout << "Phong to man hinh roi bam phim bat ki de bat dau!";
//	getch();  
//	Sleep(500);
//	system("cls");
	QuanLySach quanLyS;
	quanLyS.KhoiTao();
	quanLyS.DocFileS();
	quanLyS.DocFileB();
	quanLyS.DocFileP();
	
//	if(DangNhap(quanLy) == 1){
	while(1){
		switch(Menu(0)){
			case 1:{
				while(1){
					switch(Menu(1)){
						case 1:{
							quanLyS.XuatS();
							break;
						}
						case 2:{
							quanLyS.ThemSach();
							break;
						}
						case 3:{
							string _ma;
							gotoXY(2*xx, yy);
							cout << "Nhap ma sach: ";	cin >> _ma;
							quanLyS.XoaS(_ma);
							break;
						}
						case 0:{
							goto Out1;
							break;
						}
					}
					getch();
					system("cls");
				}
				Out1:
				break;
			}
			case 2:{
				while(1){
					switch(Menu(2)){
						system("cls");  
						case 1:{
							quanLyS.HienThiPhieu();
							break;
						}
						case 2:{
							quanLyS.ThemPhieuMuon();
							break;
						}
						case 3:{
							quanLyS.XoaPhieu();
							break;
						}
						case 0:{
							goto Out2;
							break;
						}
					}
					getch();
					system("cls");
				}
				Out2:
				break;
			}
			case 3:
			case 0:{
				gotoXY(3*xx, yy); cout << "TAM BIET!"; 
				return 0;
			}
		}
//	}	
	}
}
