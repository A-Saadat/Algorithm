#include <bits/stdc++.h>
 
using namespace std; 

#define intl long long int
#define def 100


int main ()
{
    intl n, a[def][def];
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i == 0 or j == 0)
                a[i][j] = 1;
            else
                a[i][j] = a[i - 1][j] + a[i][j - 1];
        }
        
    }

    cout << a[n - 1][n - 1];

}