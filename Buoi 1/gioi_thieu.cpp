// #include <iostream>

// using namespace std;

// int main()
// {
//     int a, b, c;
//     char dau;
// cout << "Nhap 2 so: ";
// cin >> a >> b;
// cout << a << " + " << b << " = " << a + b << endl;
// printf("%d - %d = %d\n", a, b, a - b);
// cout << a << " * " << b << " = " << a * b << endl;
// cout << a << " / " << b << " = " << a / b << endl;
// cout << a << " % " << b << " = " << a % b << endl;

// 25 / 2
// 1 + 2
// cout << "Nhap bieu thuc: ";
// cin >> a >> dau >> b;
// switch (dau)
// {
// case '+':
// {
//     c = a + b;
//     break;
// }
// case '-':
// {
//     c = a - b;
//     break;
// }
// case '*':
// {
//     c = a * b;
//     break;
// }
// case '/':
// {
//     c = a / b;
//     break;
// }
// default:
//     cout << "Bieu thuc khong hop le!";
//     return 0;
// }
// cout << a << " " << dau << " " << b << " = " << c;

// int n;
// cout << "Nhap so n: ";
// cin >> n;
// if (n % 2 == 0)
// {
//     cout << n << " la so chan.\n";
// }
// else
// {
//     cout << n << " la so le.\n";
// }
// if (n > 0)
// {
//     cout << n << " la duong.\n";
// }
// else if (n < 0)
// {
//     cout << n << " la am.\n";
// }

// #include <iostream>
// using namespace std;

// int main()
// {
//     int a, b, c, d, e;
//     cin >> a >> b >> c >> d >> e;
//     int max;
//     max = a;
//     if (a == b && b == c && b == d && b == e)
//     {
//         cout << "Khong co so lon nhat!";
//     }
//     else if (b > max)
//     {
//         max = b;
//     }
//     else if (c > max)
//     {
//         max = c;
//     }
//     else if (d > max)
//     {
//         max = d;
//     }
//     else if (e > max)
//     {
//         max = e;
//     }
//     cout << max;

//     return 0;
// }

// #include <iostream>
// using namespace std;

// int main()
// {
//     int thang, nam;
//     cin >> thang >> nam;
//     // 1, 3, 5, 7, 8, 10, 12 = 31
//     // 4, 6, 9, 11 = 30
//     // 2: 28/29
//     switch (thang)
//     {
//     case 1:
//     case 3:
//     case 5:
//     case 7:
//     case 8:
//     case 10:
//     case 12:
//     {
//         cout << 31;
//         break;
//     }
//     case 2:
//     {
//         if (nam % 400 == 0 || (nam % 4 == 0 && nam % 100 != 0))
//             cout << 29;
//         else
//             cout << 28;
//         break;
//     }
//     default:
//         cout << 30;
//         break;
//     }

//     return 0;
// }

// #include <iostream>
// using namespace std;

// int main()
// {
//     int n, sum = 0;
//     cout << "Nhap n: ";
//     cin >> n;
//     sum += n % 10; // sum = sum + n%10;
//     n /= 10;

//     sum += n % 10;
//     n /= 10;

//     sum += n % 10;
//     n /= 10;

//     sum += n % 10;
//     n /= 10;

//     sum += n % 10;
//     n /= 10;
//     cout << sum;
//     return 0;
// }

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    // float avg = (float)(a + b + c) / 3;
    // float avg = (a + b + c) * 1.0 / 3;
    float avg = float(a + b + c) / 3;
    // làm tròn: fixed << setprecision(2) <<
    cout << fixed << setprecision(2) << avg << "\t" << avg << endl;
    // setw(n)
    cout << setw(10) << fixed << setprecision(2) << avg << setw(10) << avg << endl;
    // left, right
    cout << left << setw(10) << fixed << setprecision(2) << avg << setw(10) << avg << endl;
    /*
    acs 1
        1
    */
    return 0;
}
