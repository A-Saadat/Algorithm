#include <bits/stdc++.h>
 
using namespace std; 

#define intl long long int 
#define def 10000

int main (void)
{
    intl t, tmp = 0;
    cin >> t;

    while(t--)
    {
        intl n = 0, tf = 1;
        cin >> n;
        
        string a = "";
        cin >> a;

        for(int i = 0; i < n / 2; i++)
        {
            int x = 0;
            x = abs(a[i] - a[n - i - 1]);

            if(x != 2 && x != 0)
                {tf = 0;
                break;}
            else
                tf = 1;
        }

        if(tf == 0)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;

    }

}