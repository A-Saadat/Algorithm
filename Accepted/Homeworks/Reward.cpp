#include <bits/stdc++.h>
 
using namespace std; 

#define intl long long int 
 
int main (void)
{
    int a1, a2, a3 ,b1 , b2, b3, a, b, n, x, y, z, w, c, d;
    cin >> a1 >> a2 >> a3;
    cin >> b1 >> b2 >> b3;
    cin >> n;

    a = a1 + a2 + a3;
    b = b1 + b2 + b3;
    x = (a / 5) + (b / 10);

    if (a % 5 != 0 && b % 10 == 0)
    {
        x += 1;
    } 
    else if (a % 5 != 0 && b % 10 != 0)
    {
        x += 2;
    }
    else if (a % 5 == 0 && b % 10 != 0)
    {
        x += 1;
    }
    

    if (a != 0 and b != 0 and n == 1)
    {
        cout << "NO" << endl;

    } else if ((x <= n))
    {
        cout << "YES" << endl;
    }else
    {
        cout << "NO" << endl;
    }

    return 0;
}




    // x = a / 5;
    // y = n - x;
    // z = b / 5;
    // w = n - z;
    // c = (b / y) + x;
    // d = (a / w) + z;

    // if (a != 0 and b != 0 and n == 1)
    // {
    //     cout << "NO" << endl;
    // }
    // else if ((a == b && (a / 5) + (b / 10) / n) <= n)
    // {
    //     cout << "YES" << endl;
    // }
    // else if ((a == b && (a / 5) + (b / 10) / n) >= n)
    // {
    //     cout << "NO" << endl;
    // }
    // else if ((a % 5 == 0 && b % 10 != 0) && c <= n)
    // {
    //     cout << "YES" << endl;
    // } 
    // else if ((a % 5 != 0 && b % 10 == 0) && w >= n)
    // {
    //     cout << "NO" << endl;
    // }
    // else if ((a % 5 == 0 && b % 10 == 0) && c <= n)
    // {
    //     cout << "YES" << endl;
    // }
    // else 
    // {
    //     cout << "you suck" << endl;
    // }