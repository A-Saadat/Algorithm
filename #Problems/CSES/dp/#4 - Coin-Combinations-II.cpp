#include <bits/stdc++.h> 
using namespace std; 

#define IOS ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0) 
#define fort(itr,map) for(auto itr = map.begin(); itr != map.end(); ++itr) 
#define pb push_back 
#define elif else if 
#define F first 
#define S second 
#define all(v) v.begin(), v.end() 
#define uni(v) sort(all(v)), v.erase(unique(all(v)), v.end()) 
typedef vector<int> vi;

const int MAX = 1e6 + 100; 
const int MOD = 1e9 + 7; 

int dp[200][MAX], a[MAX]; 

main()
{IOS;

    int n, x; cin >> n >> x;
    for(int i = 1; i <= n; i++) cin >> a[i];

    dp[0][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int k = 0; k <= x; k++){
            dp[i][k] = dp[i - 1][k] % MOD;
            int l = k - a[i];
            if(l < 0) continue;

            dp[i][k] += dp[i][l];
            dp[i][k] %= MOD;
        }
    }
    
    cout << dp[n][x] % MOD << endl;
}