#include <bits/stdc++.h>

using namespace std; 

#define intl long long int
#define def 10000
     
int main (void)
{
    intl n, k, a[def], b[def];

    cin >> n >> k;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];

        if(a[i] > 0)
            b[i] = a[i];
        else
            n--;

    }

    intl x = b[k], count = 0;

    for(int i = 1; i < n; i++)
    {   
        if (b[i] > 0)
        {
            if(b[i] >= x)
            count++;
        }
    }

    cout << count;

    return 0;
}