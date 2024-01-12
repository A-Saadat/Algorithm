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
// #define int long long 

const int MAX = 3e3 + 10; 
const int INF = 1e9 + 7; 

double dp[MAX][MAX], p[MAX]; 

main()
{IOS;

    cout.precision(10); cout.setf(ios::fixed);

    int n; cin >> n;
    for(int i = 1; i <= n; i++) cin >> p[i];

    dp[0][0] = 1.0;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= n; j++){
            dp[i][j] = ((1 - p[i]) * dp[i - 1][j]);
            if(j > 0) dp[i][j] = dp[i][j] + (p[i] * dp[i - 1][j - 1]);
        }
    }

    double ans = 0.0;
    for(int i = 0; i <= n; i++){
        if(i > n - i)
            ans += dp[n][i];
    } 

    cout << ans << endl;

}