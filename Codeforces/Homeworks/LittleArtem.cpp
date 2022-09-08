#include <bits/stdc++.h>
 
using namespace std; 

#define intl long long int 
 
int main (void)
{

    intl n, x, w;
    cin >> n;

    x = (n / 3) * 3;
    
    if ((n - x) == 1)
    {
        w = 1;
    }
    else if ((n - x) == 2)
    {
        w = 2;
    }

    
    if (n % 3 == 0)
    {
        cout << (n / 3) * 2 << endl;
    }
    else if (n % 3 != 0)
    {
        cout << ((n / 3) * 2) + 1 << endl;
    }

    return 0;
    

}