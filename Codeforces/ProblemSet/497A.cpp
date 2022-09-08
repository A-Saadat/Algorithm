#include <bits/stdc++.h> 
using namespace std; 

#define intl long long int 
#define def 10

int main (void)
{
    intl a, b ,c;
    cin >> a >> b >> c;

    intl ans = 0;

    ans = max(ans, a + b + c);
    ans = max(ans, (a + b) * c);
    ans = max(ans, a + b * c);
    ans = max(ans, a * b * c);
    ans = max(ans, a * (b + c));
    ans = max(ans, a * b + c);

    cout << ans;
}