#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int max = n % 10;
    while (n != 0)
    {
        n = n / 10;
        if (max < n % 10)
        {
            max = n % 10;
        }
    }
    cout << "chu so lon nhat la: " << max;
    return 0;
}
