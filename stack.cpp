#include <iostream>
#include <stack>

using namespace std;

int main(){
	stack <int> a;
	a.push(1);
	a.push(2);
	while(a.size() > 0){
		cout << a.top();
		a.pop();
	}
}
