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
#define err_pre(i, j) cout << "pre[" << i << "][" << j << "] = " << pre[i][j] << endl;
#define err_suf(i, j) cout << "suf[" << i << "][" << j << "] = " << suf[i][j] << endl;
#define int long long 

const int MAX = 1500 + 10; 
const int INF = 1e9 + 7; 

int a[MAX][MAX], pre[MAX][MAX], suf[MAX][MAX];
int ps[MAX][MAX], dp[MAX][MAX];

main()
{IOS;

    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
            ps[i][j] = ps[i][j - 1] + a[i][j];
        }
    }

    for(int i = 0; i <= n + 1; i++){
        for(int j = 0; j <= m + 1; j++){
            pre[i][j] = -INF;
            suf[i][j] = -INF;
        }
    }

    for(int j = 1; j <= m; j++) dp[1][j] = ps[1][j];
    for(int j = 1; j <= m; j++) pre[1][j] = max(pre[1][j - 1], dp[1][j]);
    for(int j = m; j >= 1; j--) suf[1][j] = max(suf[1][j + 1], dp[1][j]);

    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(i % 2)
                dp[i][j] = pre[i - 1][j - 1];
            else
                dp[i][j] = suf[i - 1][j + 1];

            dp[i][j] += ps[i][j];
        }

        for(int j = 1; j <= m; j++) pre[i][j] = max(pre[i][j - 1], dp[i][j]);
        for(int j = m; j >= 1; j--) suf[i][j] = max(suf[i][j + 1], dp[i][j]);
    }

    int ans = -INF;
    for(int j = 1; j <= m; j++) ans = max(ans, dp[n][j]);

    cout << ans << endl;

}