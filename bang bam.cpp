#include <iostream>
#include <string.h>
#include <fstream>
#define HASH_SIZE  100

using namespace std;

struct Node{
	int Phone;
	Node *next;	
};
Node* hash_table[HASH_SIZE];
int hashCode(string name){
	int k = 7;
	for(int i=0; i<name.size(); i++)
		k = (31*k + name[i]) % HASH_SIZE;
	return k;
}
void Add(string name, int p){
	int index = hashCode(name);
	Node* temp = new Node;
	temp->Phone = p;
	temp->next = NULL;
	if(hash_table[index] == NULL)
		hash_table[index] = temp;
	else{
		temp->next = hash_table[index];
		hash_table[index] = temp;
	}
}
void Delete(string name){
	int index = hashCode(name);
	if(hash_table[index] == NULL){
		cout << "\nQuai vat khong co ten trong danh sach!";
	}else{
		hash_table[index] = NULL;
	}
}
void Update(string name, int p){
	int index = hashCode(name);
	if(hash_table[index] == NULL){
		cout << "\nQuai vat khong co ten trong danh sach!";
	}else{
		hash_table[index]->Phone = p;
		hash_table[index]->next = NULL;
	}
}
void Find(string name){
	int index = hashCode(name);
	if(hash_table[index] == NULL){
		cout << "\nQuai vat khong co ten trong danh sach!";
	}else{
		Node* i = hash_table[index];
		cout << "\nSo dien thoai cua " << name << " :\n";
		while(i != NULL){
			cout << i->Phone << endl;
			i = i->next;
		}
	}
}
void DocFile(){
	ifstream input;
	input.open("./phonebook")
}
int main(){
	
} 
