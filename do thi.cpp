#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

struct Node{
	string name;
	vector<Node*> node;
};
void Add(Node *&BTree, string nameCon, string nameCha){
	if(BTree->name == nameCha){
		Node *p = new Node;
		p->name = nameCon;
		BTree->node.push_back(p);
	}else if(BTree->node.size() > 0){
		for(int i = 0; i<BTree->node.size(); i++)
			Add(BTree->node[i], nameCon, nameCha);
	}
}
void TimTheHe(Node *Btree, int k){
	if(k == 0)
			cout << Btree->name << " ";
	else
		for(int i = 0; i<Btree->node.size(); i++)
			TimTheHe(Btree->node[i], k-1);
}	

int main(){
	Node *Btree = new Node;
	string con, cha;
	cout << "Nhap ten: "; cin >> Btree->name;
	do{
		cin >> cha >> con;
		if(con.compare("-1") == 0)	break;
		Add(Btree, con, cha);
	}while(1);
	int k;
	cout << "Nhap the he: "; cin >> k;
	cout << "Danh sach the he thu " << k << " la: ";
	TimTheHe(Btree, k);
}
