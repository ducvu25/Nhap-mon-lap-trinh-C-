#include <iostream>
using namespace std;

int main()
{
	int n;
	float sum = 1;
	do
	{
		cin >> n;
	} while (n < 0);
	for (int i = 0; i < n; i++)
	{
		sum = 1 + 1 / sum;
	}
	cout << "S(" << n << ") = " << sum;
	return 0;
}
