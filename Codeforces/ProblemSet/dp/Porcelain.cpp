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
#define err_dp_s(i, j) cout << "dp_s[" << i << "][" << j << "] = " << dp_s[i][j] << endl;
#define int long long 

const int MAX = 1e4 + 10;
const int M = 100 + 10; 
const int INF = 1e9 + 7; 

int a[M][M], dp_s[M][M], dp[M][MAX], ps[M][M]; 

main()
{IOS;

    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i][0];
        for(int j = 1; j <= a[i][0]; j++){
            cin >> a[i][j];
            ps[i][j] = ps[i][j - 1] + a[i][j];
        } 
    }    

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= a[i][0]; j++)
            for(int k = 0; k <= j; k++)
                dp_s[i][j] = max(dp_s[i][j], ps[i][k] + ps[i][a[i][0]] - ps[i][a[i][0] - j + k]);

    for(int j = 1; j <= min(a[1][0], m); j++)
        dp[1][j] = dp_s[1][j];

    for(int i = 2; i <= n; i++)
        for(int j = 1; j <= m; j++)
            for(int k = 0; k <= min(j, a[i][0]); k++)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - k] + dp_s[i][k]);

    cout << dp[n][m] << endl;

}