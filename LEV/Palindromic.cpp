#include <bits/stdc++.h>
 
using namespace std; 

#define intl long long int 
#define def 10000

int main (void)
{
    intl t, n, count = 0;
    string a;

    cin >> n;
    cin >> a;

    if(n == 2 or n % 2 != 0)
        cout << "NO" << endl;
    else
    {
        for(int i = 0; i < n; i++)
        {
            intl x = (i * -2) + 6;

            if(a[i] == a[x])
                count++;
            if(count == n / 2)
                cout << "YES";
        }
    }

    

}