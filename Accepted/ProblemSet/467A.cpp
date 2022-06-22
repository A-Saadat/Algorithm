#include <bits/stdc++.h> 
using namespace std; 

#define intl long long int 
#define def 100

int main (void)
{
    intl n; 
    cin >> n;

    intl q[def], p[def];
    for(int i = 0; i < n; i++)
        cin >> p[i] >> q[i];

    intl cnt = 0;
    for(int i = 0; i < n; i++){
        int sum = q[i] - p[i];
        
        if(sum >= 2)
            cnt++;
    }

    cout << cnt;
}