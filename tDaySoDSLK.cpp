#include <iostream>
#include <fstream>

using namespace std;

struct Node{
	int value;
	Node* next;
};
void Add(Node* &head, int x){
		Node* p = new Node;
		p->value = x;
		p->next = NULL;
		if(head == NULL)
			head = p;
		else{
			Node* i = head;
			while(i->next != NULL){
				i = i->next;
			}
			i->next = p;
		}
}
int DocFile(Node* &head){
	ifstream input;
	input.open("./inputDaySoDSLK.txt");
	if(!input){
		return 0;
	}
	int x;
	while(input >> x){
		Add(head, x);	
	}
	input.close();
	return 1;
}
int XuatFile(Node* head){
	ofstream output;
	output.open("./outputDaySoDSLK.txt");
	if(!output){
		return 0;
	}
	Node* i = head;
	while(i != NULL){
		output << i->value << " ";
		i = i->next;
	}
	output.close();
	return 1;
}
void Xuat(Node* head){
	Node* i = head;
	while(i->next != NULL){
		cout <<	i->value << " ";
		i = i->next;
	}
	cout << endl;
}
void Sort(Node* &head){
	Node* i = head;
	while(i->next != NULL){
		Node* j = i->next;
		while(j != NULL){
			if(i->value > j->value){
				int t = i->value;
				i->value = j->value;
				j->value = t;
			}
			j = j->next;
		}
		i = i->next;
	}
}
int Search(Node* head, int x){
	Node* i = head;
	while(i->next != NULL){
		if(i->value == x)
			return 1;
		i = i->next;
	}
	return 0;
}
int main(){
	Node* head = NULL;
	if(DocFile(head) == 0){
		cout <<"\n\tFile khong ton tai!";
	}else{
		cout << "Du lieu vua nhap:\n\t";
		Xuat(head);
		Sort(head);
		cout << "Du lieu sau khi da sap xep tang dan:\n\t";
		Xuat(head);
		int x;
		cout << "Nhap gia tri can tim: "; cin >> x;
		if(Search(head, x) == 1){
			cout << "Gia tri " << x << " co trong day.\n";
		}else{
			cout << "Gia tri " << x << " khong co trong day.\n";
		}
		if(XuatFile(head) == 0)
			cout <<"\n\tFile khong ton tai!";
		else
			cout << "Du lieu da duoc nap vao file.";
	}
	return 0;
}
