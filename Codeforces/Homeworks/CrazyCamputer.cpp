#include <bits/stdc++.h>
 
using namespace std; 

#define intl long long int 
#define def 1000000

int main ()
{   
    intl n, c;

    cin >> n >> c;

    intl a[def];

    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    intl ans = 0;

    for(int i = 0; i < n; i++)
    {
        intl count = 0;

        if (a[i + 1] - a[i] <= c)
        {
            count++;
            ans += count;
        }
        else
        {
            ans = 1;
        }
    }

    cout << ans << endl; 

}