#include <bits/stdc++.h>
 
using namespace std; 

#define intl long long int 
#define def 10000

int main (void)
{
    intl n, k;
    cin >> n >> k;

    intl f[def], t[def], joy[def];

    for(int i = 0; i < n; i++)
    {
        cin >> f[i] >> t[i];
    }


    for(int i = 0; i < n + 10; i++)
    {
        if(t[i] > k)
            joy[i] = f[i] - (t[i] - k);
        else if(t[i] <= k)
            joy[i] = f[i];
    }

    intl max = -100;

    for(int i = 0; i < n; i++)
    {
        if(joy[i] > max)
            max = joy[i];
    }

    cout << max << endl;

}

