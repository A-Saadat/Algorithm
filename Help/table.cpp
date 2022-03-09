#include <bits/stdc++.h>
 
using namespace std; 

#define intl long long int

int main ()
{
    int n, m;
    cin >> n >> m;

    int a[n + 1][m + 1]; // satr i , soton j -> a[i][j]

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            a[i][j] = 0;
        }
    }

    int k;
    cin >> k;

    for(int t = 1; t <= k; t++)
    {
        char c;
        cin >> c;

        int num;
        cin >> num;

        if(c == 'R')
        {
            for(int j = 1; j <= m; j++)
            {
                a[num][j] ++;
            }
        }
        else 
        {
            for(int i = 1; i <= n; i++)
            {
                a[i][num] ++;
            }
        }
    }

    int cnt = 0;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(a[i][j] % 2 == 1)
                cnt ++;
        }
    }

    cout << cnt;

}