#include <bits/stdc++.h>

using namespace std; 

#define intl long long int 
#define def 10000
     
     
int main (void)
{
    intl n, rec = 0, count = 0;
    cin >> n;

    for(int i = 1; i <= n; i++)
    {

        intl a;
        cin >> a;

        if(a > 0)
            rec += a;
        else 
        {
            if(rec < 1)
            {
                count++;
            }
            else if (rec >= 1)
                rec--;
        }
    }
    cout << count;

    return 0;
}