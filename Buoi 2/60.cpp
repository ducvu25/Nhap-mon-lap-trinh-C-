#include <iostream>
using namespace std;

int main()
{
    int n, count2 = 0, count = 0;
    cin >> n;
    int a = n;
    int max = n % 10;
    while (n != 0)
    {
        n = n / 10;
        if (max < n % 10)
        {
            cout << a << " ko thoa man dk de bai.";
            return 0;
        }
    }
    cout << a << " la so co tang dan";
    return 0;
}
