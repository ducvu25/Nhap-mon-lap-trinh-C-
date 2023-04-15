#include <iostream>

using namespace std;

int main()
{
    int a, b;
    cout << "Nhap kich thuoc: ";
    cin >> a >> b;
    for (int i = 0; i < 2 * a + 1; i++)
    {
        for (int j = 0; j < 2 * b + 1; j++)
            if (i == 0 || i == 2 * a || j == 0 || j == 2 * b || i == a || j == b)
                cout << "*";
            else
                cout << " ";
        cout << endl;
    }
    return 0;
}