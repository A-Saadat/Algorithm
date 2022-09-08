#include <bits/stdc++.h>
 
using namespace std; 

#define intl long long int 
 
int main (void)
{
    // intl n, x, y, a, b;
    
    // cin >> n;
    // a = n / 3;
    // x = 2 * (n / 3);
    // y = 
    // b = n - x;

    // if ((n / 3) % 3 == 0)
    // {
    //     a = n / 3 - 1;
    //     b += 1;
    // }
 
 
    // if (n % 3 == 0)
    // { 
    //     cout << a << " " << a << " " << a;
    
    // } else if (n == 5)
    // {
    //     cout << "1 2 2";

    // } else if (n % 3 != 0)
    // {
    //     cout << a << " " << a << " " << b;

    // }


    intl n;
    cin >> n;

    if ((n - 2) % 3 == 0)
        cout << "1 2 " << n - 3 << endl;
    else
        cout << "1 1 "<< n - 2 << endl;

 
    return 0;
}