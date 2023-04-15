#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> adj[1001];
map<int, int> stime;
map<int, int> etime;
bool visited[1001];
vector <int> kq;
void inp(){
	ifstream cin("input.txt");
	cin >> n;
	char c;
	for(int i=0; i<n; i++){
		int x, m;
		cin >> x >> c >> m >> c >> c;
		for(int j=0; j<m; j++){
			int y;	cin >> y;
			adj[x].push_back(y);
		}
	}
	memset(visited, false, sizeof(visited));
}
void dfs(int x, int &time){
    kq.push_back(x);
	visited[x] = true;
	stime[x] = time;
	time += 1;
	for(int v : adj[x]){
		if(!visited[v]){
			cout << "Tree Edge: " << x << " --> " << v << endl; 
			dfs(v, time);
		}else{
			if (stime[x] > stime[v] && etime[x] < etime[v]) {
				cout << "Back Edge: " << x << " --> " << v << endl;
			}else if (stime[x] < stime[v] && etime[x] > etime[v]) {
				cout << "Forward Edge: " << x << " --> " << v << endl;
			}else if (stime[x] > stime[v] && etime[x] > etime[v]) {
				cout << "Cross Edge: " << x << " --> " << v << endl;
			}
		}
		etime[x] = time;
		time++;
	}
}
int main(){
    int time = 0;
	inp();
	dfs(0, time);
	for(int i=0; i<kq.size(); i++)
	    cout << kq[i] << " ";
}

/*
11
0  (4) : 1 6 8 10
1  (3) : 0 2 3
2  (5) : 1 3 4 5 6
3  (2) : 1 2
4  (2) : 2 5
5  (2) : 2 4
6  (3) : 0 2 7
7  (1) : 6
8  (2) : 0 9
9  (1) : 8
10 (1) : 0
*/
