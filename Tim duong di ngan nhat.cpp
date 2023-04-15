#include <iostream>
#include <fstream>
using namespace std;

void Initialization(int a[][100], int &n){
	ifstream cin ("./input.txt");
	cin >> n;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++){
			cin >> a[i][j];
		}
}
int S(int a[][100], int n, int destination){
	int value[n] = {0};
	int index[n] = {0};
	value[0] = -1;
	for(int i=0; i<n; i++)
		if(a[0][i] != 0)
			value[i] = a[0][i];

	while(1){
		int min = 100000;
		int x = 0;
		// tim min
		for(int i=0; i<n; i++)
			if(value[i] != -1 && value[i] != 0)
				if(min > value[i]){
					min = value[i];
					x = i;
				}
		// Neu tim duoc min tai destination can tim thi dung lai
		if(x == destination)
			return min;
		value[x] = -1;
		for(int i=1; i<n; i++)
			if(value[i] != -1){
				if(a[x][i] != 0){// tim quang duong ngan nhat
					if(a[x][i] + min < value[i] || value[i] == 0){
						value[i] = a[x][i] + min;
						index[i] = x;
					}
				}
			}
	}
	return 0;
}
int main(){
	int n;
	int a[100][100];
	n;
	Initialization(a, n);
	int destination;
	for(int i=1; i<n; i++)
		cout << S(a, n, i) << endl;
}
/*
test 1
5
0 1 2
0 2 3
1 2 15
1 3 2
3 4 5
2 4 15
-1
test 2
9
0 1 4
0 2 9
0 3 5
1 5 2
1 4 15
2 3 2
2 6 3
3 6 7
6 5 2
6 7 7
5 7 12
4 7 6
*/
