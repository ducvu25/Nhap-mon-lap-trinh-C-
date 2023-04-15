#include<iostream>
#include<conio.h>
#include <fstream>

using namespace std;

#define MAX  100 
#define TRUE  1 
#define FALSE  0
int n;
int truoc[MAX], chuaxet[MAX], queue[MAX];
int A[MAX][MAX];// ma tr?n k? c?a d? th?.
int s;//d?nh d
int t;//d?nh cu?i. 

void Init(void){ 
	ifstream cin("D:\\Nam 1\\C++\\CTDL&GT\\input.txt"); 
	cin>>n; 
	for(int i=1; i<=n;i++){ 
		for(int j=1; j<=n;j++){ 
			cin>>A[i][j]; 
		}
	} 

	for(int i=1; i<=n;i++){ 
		chuaxet[i]=TRUE; 
		truoc[i]=0; 
	}
	cin.close();
}
void TrucTiep(int s){
	for(int i=1; i<=n; i++)
		if(A[s][i] == 1 && i != s)
			cout << i-1 << " ";
	cout << endl;
}

void BFS(int s) { 
	int dauQ, cuoiQ, u;
	dauQ=1;cuoiQ=1;//kh?i t?o queue.
	queue[dauQ]=s;chuaxet[s]=FALSE; //t?m d?nh d?u v?o queue.
	while (dauQ<=cuoiQ){//queue chua r?ng.
		u=queue[dauQ];//l?y d?nh u trong queue.
		dauQ=dauQ+1; 
		for (int p=1; p<=n;p++){ 
			if(A[u][p] && chuaxet[p]){ 
			cuoiQ=cuoiQ+1;
			queue[cuoiQ]=p; 
			chuaxet[p]=FALSE;
			truoc[p]=u; 
			} 
		} 
	} 
} 


int main(){ 
	Init();
	s = 1;
	cout << "Cac dinh di truc tiep tu 0 la: ";
	TrucTiep(1);
	BFS(s); 
	cout << "cac dinh tu diem 0 la: ";
	for(int i=1; i<=n; i++){
		t = i;
		if(truoc[i])
			cout << i << " ";
	}
}

