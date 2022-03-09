#include <bits/stdc++.h>
 
using namespace std; 

#define intl long long int 
#define def 100000

int main ()
{   

    intl n, h[def], m[def], ans = 0;

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
        cin >> m[i];
    }

    for (int i = 1; i <= n; i++)
    {
        intl count = 1;
        
        for(int j = i + 1; j <= n; j++)
        {

            if (h[i] == h[j] && m[i] == m[j])
                count++;
            if(count > ans)
	            ans = count; 

        }
    }

    cout << ans << endl;




}