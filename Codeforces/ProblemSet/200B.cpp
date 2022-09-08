#include <bits/stdc++.h> 
using namespace std; 

#define intl long long int 
#define def 100

int main (void)
{
    intl n;
    cin >> n;

    intl a[def];
    float ans = 0;
    
    for(intl i = 0; i < n; i++){
        cin >> a[i];
        ans += a[i];
    }

    cout << ((ans / 100) / n) * 100;
}