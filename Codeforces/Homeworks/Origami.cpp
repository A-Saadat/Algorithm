#include <bits/stdc++.h>
 
using namespace std; 

#define intl long long int 
 
int main (void)
{

    intl n, k, a, b, c;
    cin >> n >> k;
    a = n * 2;
    b = n * 5;
    c = n * 8;

    if (a % k == 0 && b % k == 0 && c % k == 0)
    {
        cout << (a / k) + (b / k) + (c / k);

    } else if (a % k != 0 && b % k == 0 && c % k == 0)
    {
        cout << ((a / k) + 1) + (b / k) + (c / k);

    } else if (a % k == 0 && b % k != 0 && c % k == 0)
    {
        cout << (a / k) + ((b / k) + 1) + (c / k);

    } else if (a % k == 0 && b % k == 0 && c % k != 0)
    {
        cout << (a / k) + (b / k) + ((c / k) + 1);

    } else if (a % k != 0 && b % k != 0 && c % k == 0)
    {
        cout << ((a / k) + 1) + ((b / k) + 1) + (c / k);

    } else if (a % k != 0 && b % k == 0 && c % k != 0)
    {
        cout << ((a / k) + 1) + (b / k) + ((c / k) + 1);

    } else if (a % k == 0 && b % k != 0 && c % k != 0)
    {
        cout << (a / k) + ((b / k) + 1) + ((c / k) + 1);

    } else if (a % k != 0 && b % k != 0 && c % k != 0)
    {
        cout << ((a / k) + 1) + ((b / k) + 1) + ((c / k) + 1);

    }

    return 0;

}