#include <bits/stdc++.h> 
using namespace std; 

#define intl long long int 
#define def 100

int main (void)
{
    intl n;
    cin >> n;

    intl a[n + 1], b[n + 1];
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        b[a[i]] = i;
    }

    for(int i = 1; i <= n; i++)
        cout << b[i] << ' ';
}