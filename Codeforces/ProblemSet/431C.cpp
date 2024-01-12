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
#define int long long 
typedef vector<int> vi;

const int MAX = 1e6; 
const int MOD = 1e9 + 7; 

int dp[MAX][4]; 

main()
{IOS;

    int n, k, d; cin >> n >> k >> d;
    dp[0][0] = 1;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= d - 1 && i >= j; j++)
            dp[i][0] += dp[i - j][0] % MOD;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= k && i >= j; j++)
            dp[i][1] += dp[i - j][1] % MOD;
        for(int j = d; j <= k && i >= j; j++)
            dp[i][1] += dp[i - j][0] % MOD;
    }

    cout << dp[n][1] % MOD << endl;

}