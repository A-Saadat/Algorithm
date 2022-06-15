#include <bits/stdc++.h>
 
using namespace std; 

#define intl long long int 
#define def 10000

int main(void)
{
    intl n, k, f[def], tmp[def], t[def];
    cin >> n >> k;

    for(int i = 0; i < n; i++){
        cin >> f[i] >> tmp[i];

        // set the main t array 
        if(t[f[i]] == 0) 
            t[f[i]] = tmp[i]; // exmp => i = 2; f = 7; t[f[i]] = t[7]
        else if(t[f[i]] != 0 and tmp[i] < t[f[i]])
            t[f[i]] = tmp[i]; 
        else
            continue;
    }
    
    sort(f, f + 1);
    intl ans = 0, rest = f[n] - (t[f[n]] - k);

    while(n--){
        if(t[f[n]] > k and ans < rest) // t > k
            ans = rest;
        else if(t[f[n]] <= k and ans < f[n]) // t < k
            ans = f[n];
    }

    cout << ans;
}

