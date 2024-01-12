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

const int MAX = 5e3 + 10; 
const int INF = 1e18 + 10; 

int t[MAX], dp[MAX][MAX]; 

main()
{IOS;

    int n, k, w, s; cin >> n >> k >> w >> s;
    for(int i = 1; i <= n; i++) cin >> t[i];

    for(int i = 0; i <= n + 1; i++)
        for(int j = 0; j <= k; j++) dp[i][j] = INF; 

    dp[1][0] = t[1], dp[1][1] = w;
    for(int i = 2; i <= n; i++){
        for(int j = 0; j < k; j++){
            if(j == 0) dp[i][j] = min(dp[i - 1][k - 1], dp[i - 1][0] + t[i]);
            elif(j == 1) dp[i][j] = min(dp[i - 1][0] + w, dp[i - 1][1] + t[i] + s);
            else dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j] + t[i] + s * min(j, k - j));
        }
    }

    int ans = INF;
    for(int i = 0; i < k; i++) ans = min(ans, dp[n][i]);

    cout << ans << endl;
}