#include <iostream>

using namespace std;

int main()
{
    // int n;
    // cout << "Nhap kich thuoc: ";
    // cin >> n;
    // int d = 0;
    // for (int i = 0; i < 2 * n + 1; i++)
    // {
    //     for (int j = 0; j <= n + d; j++)
    //         if (j == n - d || j == n + d)
    //             cout << "*";
    //         else
    //             cout << " ";
    //     if (i < n)
    //         d++;
    //     else
    //         d--;
    //     cout << endl;
    // }

    int n;
    cout << "Nhap kich thuoc: ";
    cin >> n;
    int d = 0;
    for (int i = 0; i < 2 * n + 1; i++)
    {
        for (int j = 0; j <= n + d; j++)
            if (j == n || i == n || j == n - d || j == n + d)
                cout << "*";
            else
                cout << " ";
        if (i < n)
            d++;
        else
            d--;
        cout << endl;
    }
    return 0;
}