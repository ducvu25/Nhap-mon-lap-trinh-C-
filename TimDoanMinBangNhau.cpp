#include <iostream>

using namespace std;

int main(){
	int SL;
	cin >> SL;
	for(int Test=1; Test <= SL; Test++){
		int n, i;
		cin >> Test >> n;
		int a[n];
		int A[n];
		for(i=0; i<n; i++){
			cin >> a[i];
			if(i == 0)
				A[i] = a[i];
			else
				A[i] = a[i] + A[i-1];
		}
		for(i=0; i<n; i++){
			if(i == n-1)
				break;
			int j = i + 1;
			int d = 2;
			while(1){
				if(j == n && d > 2){
					goto Out;
				}
				if(A[j] == d*A[i])
					d++;
				else if(A[j] > d*A[i])
					break;
				j++;
			}
		}
		Out:
		cout << Test << " " <<  A[i] << endl;
	}
	return 0;
}
/*
1 6
2 5 1 3 3 7
2 6
1 2 3 4 5 6
3 20
1 1 2 1 1 2 1 1 2 1 1 2 1 1 2 1 1 2 1 1
*/
