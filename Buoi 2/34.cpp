#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    float sum = 0;
    for (int i = 1; i <= n; i++)
        sum = sqrt(i + sum);
    cout << "S(" << n << ") = " << sum;
    return 0;
}
