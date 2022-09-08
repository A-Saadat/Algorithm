#include <bits/stdc++.h> 
using namespace std; 

#define intl long long int 
#define def 10000

int main (void)
{
    int n, h;
    cin >> n >> h;

    int a[def];
    for(int i = 0; i < n; i++)
        cin >> a[i];

    intl cnt = 0;
    for(int i = 0; i < n; i++){
        if(a[i] <= h)
            cnt++;
        else
            cnt += 2;
    }

    cout << cnt;
}