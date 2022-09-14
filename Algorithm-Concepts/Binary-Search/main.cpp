#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    int L = 1;
    int R = m - n + 2;

    while(R - L > 1)
    {
        int x = (L + R) >> 1;

        int sum = x;

        if(k > x)
        {
            sum = sum + ((x - 1) * x) / 2 + k - x;
        }
        else
        {
            int y = x - k + 1; // k = 3 x = 5   3 4 5 ...
            sum = sum + ((y - x) * (y + x - 1)) / 2;
        }

        // az rast





        if(sum > m) // X
            R = x;
        else if(sum <= m) // Tik
            L = x;
    }
    cout << R - 1;

    return 0;
}
