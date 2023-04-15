#include <iostream>
#include <stdlib.h>

using namespace std;

struct Node{
	int data;
	Node* next;
};
void Xuat(Node* head){
	Node* i = head;
	while(i != NULL){
		cout << i->data << " ";
		i = i->next;
	}
	cout << endl;
}
void KhoiTao(Node *&head, int i, int n, int max){
	if(i < n){
		int x = rand() % max;
		Node* p = new Node;
		p->data = x;
		p->next = head;
		head = p;
		KhoiTao(head, i + 1, n, max);
	}
}
void Delete(Node *head){
	Node* i = head;
	while(i->next != NULL){
		Node* j = i;
		while(j->next != NULL){
			if(j->next->data == i->data)
				j->next = j->next->next;
			else
				j = j->next;
		}
		i = i->next;
	}
}
int main(){
	int n, max;
	cout << "Nhap so gia tri toi da: "; cin >> n;
	cout << "Nhap gia tri toi da: "; cin >> max;
	Node* head = NULL;
	KhoiTao(head, 0, n, max);
	cout << "Mang da tao:\n\t";
	Xuat(head);
	Delete(head);
	cout << "Mang da loc:\n\t";
	Xuat(head);
}
