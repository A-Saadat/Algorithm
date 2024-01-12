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
#define err_dp(i, j, k) cout << "dp[" << i << "][" << j << "][" << k << "] = " << dp[i][j][k] << endl;
#define int long long 

const int MAX = 500 + 10; 
const int INF = 1e9 + 7; 

int a[MAX], dp[MAX][MAX][MAX]; 

main()
{IOS;

    int n, m, b, mod; cin >> n >> m >> b >> mod;
    for(int i = 1; i <= n; i++) cin >> a[i];

    // dp[1][1][a[1]] = 1;
    for(int i = 1; i <= n; i++) dp[i][0][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            for(int k = 0; k <= b; k++){
                dp[i][j][k] = dp[i][j][k] + dp[i - 1][j][k]; // % mod;
                if(k - a[i] >= 0) dp[i][j][k] = dp[i][j][k] + dp[i][j - 1][k - a[i]]; // % mod;
            }
        }
    }

    // int ans = 0;
    // for(int i = 1; i <= n; i++) {
    //     for(int k = 0; k <= b; k++){
    //         ans = ans + dp[i][m][k]; // % mod;
    //         // ans %= mod;
    //     }
    // }

    // cout << ans << endl;
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            for(int k = 0; k <= b; k++) 
                err_dp(i, j, k);
            cout << endl;
        }
        cout << "\n----------------\n";
    }
}