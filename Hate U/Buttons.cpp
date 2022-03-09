#include <bits/stdc++.h>
 
using namespace std; 

#define intl long long int

int main ()
{
    intl n, x = 0, tmp = 0, ans = 0;
    cin >> n;

    for(int i = 1; i <= n - 2; i++)
    {
    
    }

    for(int i = n; i >= n - 2; i--) // i = 4; i > 2; 
    {
        x += n - i;
    }

    for(int i = 1; i <= n; i++)
    {
        tmp += i;
    }

    ans = tmp + x;

    cout << x;


}