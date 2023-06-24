// 57 54 46 
#include <bits/stdc++.h> 
using namespace std; 

#define forn(i,k,n) for(int i = k; i < n; i++) 
#define IOS ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0); 
#define elif else if

const int MaxN = 1e6; 
const int MOD = 1e9 + 7; 

int dp[MaxN]; 

main()
{IOS;
    int r, g; cin >> r >> g;

    int hM = 0;
    forn(i,1,1000) // ? Finding the maximum height of <The Tower>
        if( ( i * (i + 1) / 2 ) <= r + g ) hM = i;

    dp[0] = 1;
    forn(h,1,hM + 1){
        // cout << h << ": \n";
        for(int i = r; i - h >= 0; i--){
            dp[i] += dp[i - h];
            dp[i] %= MOD;
            // cout << "dp[" << i << "] = " << dp[i] << endl;
        }
        // cout << "\n-----------\n";
    }
    // cout << hM;
    int ans = 0;
    forn(i,0,r + 1) //cout << i << ": " << dp[i] << endl;
        if( ((hM * (hM + 1)) / 2) - i <= g) ans = (ans +  dp[i]) % MOD;

    cout << ans;
}