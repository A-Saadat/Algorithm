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
#define err_dp(i, j) cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << endl;
#define int long long 

const int MAX = 1e5 + 10; 
const int INF = 1e9 + 7; 

int val[MAX], wgt[MAX], dp[110][MAX]; 

main()
{IOS;

    int n, W; cin >> n >> W;
    for(int i = 1; i <= n; i++) cin >> wgt[i] >> val[i];

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= W; j++){
            dp[i][j] = dp[i - 1][j];
            if(j - wgt[i] >= 0) dp[i][j] = max(dp[i][j], dp[i - 1][j - wgt[i]] + val[i]);
        }
    }

    int ans = 0;
    for(int j = 1; j <= W; j++) ans = max(ans, dp[n][j]);

    cout << ans << endl;

}