#include <bits/stdc++.h>

using namespace std; 

#define intl long long int
     
int main (void)
{
    intl a, b, count = 1, x;

    cin >> a >> b;

    if(a > b)
        x = b;
    else
        x = a;

    for(int i = 1; i <= x; i++)
    {
        count *= i;
    }

    cout << count;

    return 0;
}