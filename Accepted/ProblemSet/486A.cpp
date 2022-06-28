#include <bits/stdc++.h> 
using namespace std; 

#define intl long long int

int main (void)
{
    intl n;
    cin >> n;

    intl ans = 0;
    
    if(n % 2 == 0)
        ans = n / 2;
    else
        ans = ((n + 1) / 2) * (-1);

    cout << ans;
}