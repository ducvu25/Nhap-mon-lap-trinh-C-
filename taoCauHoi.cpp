#include <iostream>
#include <string.h>

using namespace std;

int main(){
	string CauHoi;
	string DapAn[4];
	char Key, LuaChon;
	cout << "Nhap cau hoi: ";
	getline(cin, CauHoi);
	for(int i=0; i<4; i++){
		cout << "Nhap dap an " << char (65 + i) << " ";
		getline(cin, DapAn[i]);
	}
	cout << "Nhap dap an dung: "; cin >> Key;
	system("cls");
	cout << "Cau hoi: " << CauHoi << endl;
	for(int i=0; i<4; i++){
		cout << char (65 + i) << ". " << DapAn[i] << endl;
	}
	cout << "Dap an cua ban: ";
	cin >> LuaChon;
	if(LuaChon != Key || LuaChon != Key + 32)
		cout << "Dap an sai, dap an dung la: " << Key;
	else
		cout << "Dap an dung";
}
