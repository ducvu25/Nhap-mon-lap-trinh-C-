// Tạo đồng hồ bấm giờ hiển thị: hh:mm:ss
#include <iostream>

using namespace std;

int main()
{
    int h = 0, m = 0, s = 0;
    while (h < 24 || m < 60 || s < 60)
    {
        if (h < 10)
            cout << "0" << h << ":";
        else
            cout << h << ":";

        if (m < 10)
            cout << "0" << m << ":";
        else
            cout << m << ":";

        if (s < 10)
            cout << "0" << s;
        else
            cout << s;

        system("cls");
        s++;
        if (s > 60)
        {
            s = 0;
            m++;
        }
        if (m > 60)
        {
            m = 0;
            h++;
        }
    }
    return 0;
}