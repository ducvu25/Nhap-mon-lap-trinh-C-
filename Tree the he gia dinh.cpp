#include <iostream>
#include <string.h>
#include <vector>
#include <fstream>

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
void NguoiChuaCoCon(Node* Btree){
	if(Btree != NULL && Btree->node.size() == 0)
		cout << Btree->name << " ";
	if(Btree->node.size() != 0)
		for(int i=0; i<Btree->node.size(); i++)
			NguoiChuaCoCon(Btree->node[i]);
}	
void File(Node*& Btree){
	ifstream cin("./input.txt");
	string con, cha;
	cin >> Btree->name;
	do{
		cin >> cha >> con;
		if(con.compare("0") == 0)	break;
		Add(Btree, con, cha);
	}while(1);
}

int main(){
	Node *Btree = new Node;
	File(Btree);
	cout << "Danh sach nguoi chua co con: ";
	NguoiChuaCoCon(Btree);
}
/*
Test mau:
A
A B
A C
B D
B E
C 0

*/
