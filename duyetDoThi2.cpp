#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector <int> truoc, queue;
vector <bool> chuaxet;
int s, t;
int** Nhap(int &n){
	ifstream fileIn("D:\\Nam 1\\C++\\CTDL&GT\\input.txt");
	fileIn >> n;
	int **a = new int*[n];
	for(int i=0; i<n; i++)
		a[i] = new int[n];
		
	for(int i=0; i<n; i++){
		chuaxet.push_back(true);
		truoc.push_back(0);
		for(int j=0; j<n; j++){
			fileIn >> a[i][j];
		}
	}
	fileIn.close();
	return a;
}
void LinkK(int **a, int n, int k){
	cout << "Cac trang web tu " << k << " co the truc tiep di den la: ";
	for(int i=0; i<n; i++)
		if(a[k][i] == 1)
			cout << i << ", ";
	cout << endl;
}
void Xuat(int **a, int n){
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
}
void BFS(int**a, int s, int n) { 
	int dauQ, cuoiQ, u;
	dauQ = 0;
	cuoiQ = 0;
	queue[dauQ]=s;
	chuaxet[s]=false; 
	while (dauQ<=cuoiQ){
		u=queue[dauQ];
		dauQ=dauQ+1; 
		for (int p=0; p<n;p++){ 
			if(a[u][p] && chuaxet[p]){ 
				cuoiQ=cuoiQ+1;
				queue[cuoiQ]=p; 
				chuaxet[p]=false;
				truoc[p]=u; 
			} 
		} 
	} 
}
int main(){
	int n, k;
	int** a;
	a = Nhap(n);
//	LinkK(a, n, 0);
	Xuat(a, n);
	BFS(a, n, 0);
	for(int i=0; i<n; i++){
		if(truoc[i] == 1 && i != 0)
			cout << i << " ";
	}
	
	
	
}
