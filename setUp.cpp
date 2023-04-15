#include "setUp.h"

using namespace std;

void TextColor (int color){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , color);
}
void gotoXY (int column, int line){
	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void Khung(int cot, int hang, int m, int n){
	TextColor(14);
	for(int i=0; i<m; i+=2){
		gotoXY(cot + i, hang); cout << "*";
		gotoXY(cot + i, hang + n); cout << "*";
	}
	for(int i=0; i<=n; i++){
		gotoXY(cot, hang + i); cout << "*";
		gotoXY(cot + m, hang + i); cout << "*";
	}
	cout << endl;
}
int Menu(int k){ // xuat ra menu phu hop voi thong so chuyen vao
	int num = 3; 	// so lan dang nhap
	int x = 2; 		// toa do hang bat dau cua khung
	int y = 35;		// toa do cot bat dau cua khung
	int m = 50; 	// do rong cua khung
	int n = 10; 	// chieu cao cua khung
	int d = 1;		// bien chuc nang
	string menu[3][4] = {"MENU", "Quan ly sach", "Quan ly phieu muon", "Thoat", 
						"QUAN LY SACH", "Hien thi thong tin sach", "Them sach", "Xoa sach", 
						"QUAN LY PHIEU MUON", "Hien thi phieu muon", "Muon sach", "Tra sach"};
	char c;
	Khung(y, x, m, n);	
	Khung(y, x, m, n - 8);
	TextColor(10);
	gotoXY(y + m/2 - menu[k][0].size()/2, x  + 1); cout << menu[k][0];
	gotoXY(y + 5, x  + 5); cout << menu[k][2];
	gotoXY(y + 5, x  + 7); cout << menu[k][3];
	TextColor(11);
	gotoXY(y + 5, x  + 3); cout << menu[k][1];
	while(1){
		if(kbhit()){
			TextColor(10);
			gotoXY(y + 5, x  + 3); cout << menu[k][1];
			gotoXY(y + 5, x  + 5); cout << menu[k][2];
			gotoXY(y + 5, x  + 7); cout << menu[k][3];
			c = getch();
			switch(c){
				case 27:{
					system("cls");
					return 0;
				}
				case 13:{
					system("cls");
					return d;
				}
				case 'w':{
					d--;
					if(d == 0)
						d = 3;
					break;
				}
				case 'z':{
					d++;
					if(d == 4)
						d = 1;
					break;
				}
			}
			TextColor(11);
			gotoXY(y + 5, x  + 1 + 2*d);	cout << menu[k][d];
		}
	}
}
