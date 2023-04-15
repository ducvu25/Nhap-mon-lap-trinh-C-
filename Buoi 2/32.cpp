#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int d = sqrt(n);
    if (d * d == n)
    {
        cout << n << " la so chinh phuong.";
    }
    else
    {
        cout << n << " ko phai so chinh phuong.";
    }
    return 0;
}
