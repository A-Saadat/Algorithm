#include <bits/stdc++.h>
 
using namespace std; 

#define intl long long int 
#define def 10000

int main (void)
{
    intl n, p, v, t, ans = 0;
    cin >> n;

    while(n--)
    {
        intl count = 0;

        cin >> p >> v >> t;
        if(p + v + t >= 2)
        {
            count++;
            ans += count;
        }
    }

    cout << ans;



   

}