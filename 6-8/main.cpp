#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

typedef struct GiaoDich{
	char NGui[21];
	char NNhan[21];
	int  Money;
	string Time;
	char ATM[11];
}GD;

long long Y1(GD *a, int n){
	long long sum = 0;
	for(int i=0; i<n; i++)
		sum += a[i].Money;
	return sum;
}
long Y2(GD *a, int n, char *NGui){
	long sum = 0;
	for(int i=0; i<n; i++)
		if(strcmp(a[i].NGui, NGui) == 0){
			sum += a[i].Money;
		}
	return sum;
}
int Y3(GD *a, int n, char *NGui, int dodai){
	for(int i=0; i<n - dodai + 1; i++){
		if(strcmp(a[i].NGui, NGui) == 0 && strcmp(a[i+dodai-1].NNhan, NGui) == 0)
			return 1;
	}
	return 0;
}
long Y4(GD *a, int n, string time1, string time2){
	long sum = 0;
	for(int i=0; i<n; i++)
		if(a[i].Time >= time1 && a[i].Time <= time2 && a[i].Money > sum){
			sum = a[i].Money;
		}
	return sum;
}
// 
int main(){
	long n = 0;
	GD* a = new GD[10050];
	ifstream input;
	input.open("D:\\Nam 1\\C++\\Test bai\\6-8\\3-input.txt");
	
	ofstream output;
	output.open("D:\\Nam 1\\C++\\Test bai\\6-8\\out.txt");
	// doc du lieu
	while(1){
		char c[21];
		input >> c;
		if(strcmp(c, "#") == 0)
			break;
		strcpy(a[n].NGui, c);
		input >> a[n].NNhan >> a[n].Money >> a[n].Time >> a[n].ATM;
		n++;
		cout << n << endl;
	}
	string s;
	char c;
	int d = 1;
	do{
		if(d == 1)
			if(!(input >> s))
				return 0;
		if(s == "?total_money_transaction")
			output << Y1(a, n) << endl;	
		if(s == "?total_money_transaction_from"){
			char NGui[21];	
			input >> NGui;
			output << Y2(a, n, NGui) << endl;
			NGui[0] = '\0';
		}
		if(s == "?inspect_cycle"){
			char NGui[21];
			int m;
			input >> NGui;
			input >> m;
			output << Y3(a, n, NGui, m) << endl;
			NGui[0] = '\0';
		}
		if(s == "?max_money_period"){
			string time1, time2;
			input >> time1 >> time2;
			output << Y4(a, n, time1, time2) << endl;
		}
		input >> s;
		if(s == "#")
			d = 1;
		else
			d = 0;	
	}while(1);
	return 0;
}
