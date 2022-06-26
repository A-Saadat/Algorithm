#include <bits/stdc++.h> 
using namespace std; 

#define intl long long int 
#define def 100000
#define forN(i,n) for(int i = 0; i < n; i++)

int main (void)
{
    intl n;
    cin >> n;

    intl a[def];
    forN(i,n)
        cin >> a[i];

    intl cnt = 0;
    forN(i,n){
        if(a[i] != a[i + 1])
            cnt++;
    }

    cout << cnt;
}