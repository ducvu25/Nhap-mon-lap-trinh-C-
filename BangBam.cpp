#include <iostream>
#include <fstream>
#include <string.h>
#define HASH_SIZE 50

using namespace std;

struct ThongTin{
	string name;
	int phone;
};

ThongTin hash_table[HASH_SIZE];

int hashCode(string name){
	int k = 0;
	for(int i=0; i<name.size(); i++)
		k += (name[i]*10 + i + 1);
	return k % HASH_SIZE;
}

void Add(string name, int phone){
	int index = hashCode(name);
	while(hash_table[index].name != ""){
		index = (index + 1) % HASH_SIZE;
	}
	hash_table[index].name = name;
	hash_table[index].phone = phone;
}

int Index(string name){
	int index = hashCode(name);
	while(hash_table[index].name != name && hash_table[index].name != "")
		index = (index + 1) % HASH_SIZE;
	return hash_table[index].name.compare(name) == 0 ? index : -1;		
}
void Delete(string name){
	int index = Index(name);
	if(index == -1)
		cout << "\nTen khong co trong danh sach!\n";
	else{
		hash_table[index].name = "";
		hash_table[index].phone = 0;
		cout << "\nXoa thanh cong!";
	}
}
void Update(string name, int phone){
	int index = Index(name);
	if(index == -1)
		cout << "\nTen khong co trong danh sach!\n";
	else{
		hash_table[index].phone = phone;	
	}
}
int Find(string name){
	int index = Index(name);
	if(index == -1)
		return -1;
	else
		return hash_table[index].phone;	
}
int DocFile(){
	ifstream input;
	input.open("./phonebook.txt");
	if(!input)
		return 0;
	string s, enter;
	int phone;
	while(!input.eof()){
		getline(input, s);
		input >> phone;
		Add(s, phone);
		getline(input, enter);
	}
	return 1;
}

int main(){

	if(DocFile() == 0){
		cout << "Kiem tra lai duong dan!";
		return 0;
	}
	int k;
	do{
		cout << "\n\tMENU\n";
		cout << "\t1. Them thong tin\n";
		cout << "\t2. Xoa quai vat\n";
		cout << "\t3. Cap nhat\n";
		cout << "\t4. Tim kiem\n";
		cout << "\t0. Thoat\n";
		cout << "\tChuc nang: ";
		cin >> k;
		cin.ignore();
		switch(k){
			case 1:{
				string _name;
				int _phone;
				cout << "\n\tNhap ten: ";
				getline(cin, _name);
				cout << "\tNhap sdt: ";
				cin >> _phone;
				Add(_name, _phone);
				break;
			}
			case 2:{
				string _name;
				int _phone;
				cout << "\n\tNhap ten: ";
				getline(cin, _name);
				Delete(_name);
				break;
			}
			case 3:{
				string _name;
				int _phone;
				cout << "\n\tNhap ten: ";
				getline(cin, _name);
				cout << "\tNhap sdt moi: ";
				cin >> _phone;
				Update(_name, _phone);
				break;
			}
			case 4:{
				string _name;
				int _phone;
				cout << "\n\tNhap ten: ";
				getline(cin, _name);
				int phone = Find(_name);
				if(phone == -1)
					cout << "\tTen khong co trong danh sach!\n";
				else
					cout << "\tSDT: " << phone;
				break;
			}
		}
	}while(k != 0);
}
