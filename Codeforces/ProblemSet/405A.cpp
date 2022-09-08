#include <bits/stdc++.h> 
using namespace std; 

#define intl long long int 
#define def 1000

int main (void)
{
    intl n, a[def];
    cin >> n;

    for(intl i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n);

    for(intl i = 0; i < n; i++)
        cout << a[i] << ' ';

}