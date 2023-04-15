#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
using namespace std;

string Call(int a)
{
    string word;
    switch (a)
    {
    case 1:
        word = "Mot";
        break;
    case 2:
        word = "Hai";
        break;
    case 3:
        word = "Ba";
        break;
    case 4:
        word = "Bon";
        break;
    case 5:
        word = "Nam";
        break;
    case 6:
        word = "Sau";
        break;
    case 7:
        word = "Bay";
        break;
    case 8:
        word = "Tam";
        break;
    case 9:
        word = "Chin";
        break;
    }
    return word;
}
void Msg2(int n, bool check) // check = true: muoi, mot
{
    switch (n)
    {
    case 1:
    {
        if (check)
        {
            cout << "muoi ";
            return;
        }
        else
            cout << "mot";
        break;
    }
    case 2:
    {
        cout << "hai ";
        break;
    }
    case 3:
    {
        cout << "ba ";
        break;
    }
    case 4:
    {
        cout << "bon ";
        break;
    }
    case 5:
    {
        cout << "nam ";
        break;
    }
    case 6:
    {
        cout << "bon ";
        break;
    }
    case 7:
    {
        cout << "bay ";
        break;
    }
    case 8:
    {
        cout << "tam ";
        break;
    }
    case 9:
    {
        cout << "chin ";
        break;
    }
    }
    if (check)
        cout << "muoi ";
}
void Msg(int n)
{
    // kiểm tra cái số 10 trc
    if (n == 10)
    {
        cout << "muoi";
        return;
    }
    Msg2(n / 10, true);
    Msg2(n % 10, false);
}
int main()
{
    int num;
    do
    {
        cout << "Nhap so n: ";
        cin >> num;
    } while (num < 10 || num > 99);

    Msg(num);
    // int n = num;
    // if (num / 10 == 1)
    // {
    //     cout << "Muoi " << Call(n % 10);
    // }
    // else
    // { // t = num / 10
    //     cout << Call(num / 10) << " muoi " << Call(n % 10);
    // }
}
