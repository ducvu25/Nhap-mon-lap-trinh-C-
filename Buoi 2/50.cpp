#include <iostream>
using namespace std;

int main()
{
    int n, m = 0;
    cin >> n;
    int x = n;
    cout << "So nghich dao la: ";
    while (x != 0)
    {
        m = m * 10 + x % 10;
        x /= 10;
    }
    cout << "Nghich dao cua " << n << " la: " << m << endl;
    /*
    1234
    m = 0*10 + 4 = 4
    m = 4*10 + 3 = 43
    m = 43*10 + 2 = 432 => 4321
    */
    return 0;
}
