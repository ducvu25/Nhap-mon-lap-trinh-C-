/*
thực hiện tính biểu thức 5 + (3*4 - 2)/2
            +
        5       /
            -       2
        *       2
    3       4
Tiền tố: theo NLR: +, 5, /, -, *, 3, 4, 2, 2
Hậu tố: LRN: 5, 3, 4, *, 2, -, 2, /, +
*/
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;
struct Node{
    char value;
    Node* left;
    Node* right;
};
void Add(Node* &head, char &x){
    if(head == NULL){
        Node* p = new Node;
        p->value = x;
        x = 1;
        p->left = NULL;
        p->right = NULL;
        head = p;
        return;
    }
    if(!(head->value >= 48 && head->value <= 48 + 9)){
    	if(head->left == NULL || !(head->left->value >= 48 && head->left->value <= 48 + 9))
    		Add(head->left, x);
    	if(x != 1)
        	Add(head->right, x);
	}
}
void Xuat(Node* head){
    if(head != NULL){
        cout << head->value << " ";
        Xuat(head->left);
        Xuat(head->right);
    }
}
void Nhap(Node* &head){
    ifstream cin("./input tinh gia tri bieu thuc.txt");
    while(1){
        char c;
        if(!(cin >> c))
        	break;
        Add(head, c);
    }
    cin.close();
}
int Tinh(Node* head){
	if(head != NULL)
	switch(head->value){
		case '+':{
			return Tinh(head->left) + Tinh(head->right);
		}
		case '-':{
			return Tinh(head->left) - Tinh(head->right);
		}
		case '*':{
			return Tinh(head->left) * Tinh(head->right);
		}
		case '/':{
			return Tinh(head->left) / Tinh(head->right);
		}
		default:{
			return head->value - 48;
		}
	}	
}
int main(){
    Node* head = NULL;
	Nhap(head);
    Xuat(head);
    cout << "\n" << Tinh(head);
}
