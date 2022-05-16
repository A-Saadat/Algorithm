#include <bits/stdc++.h> 
using namespace std; 

#define intl long long int 
#define def 1000

int main (void)
{

    intl n, a, ans = 0;

    cin >> n;

    for(intl i = 1; i <= n * 3; i++)
    {
        cin >> a;
        ans += a;
    }

    if(ans == 0)
        cout << "YES" << endl;
    else if(ans != 0)
        cout << "NO" << endl;

    return 0;

}