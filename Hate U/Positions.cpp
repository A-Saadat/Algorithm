#include <bits/stdc++.h>

using namespace std; 

#define intl long long int
     
int main (void)
{

    intl n, a, b, ans = 1, count = 0;

    cin >> n;
    cin >> a;
    cin >> b;

    while (a > 0)
    {
        a--;
        count++;
        ans += count;
        count = 0;
    }

    cout << ans << endl;

}


