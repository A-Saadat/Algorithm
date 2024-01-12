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

int a[MAX][5], dp[MAX][5]; 

main()
{IOS;

    int n; cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i][0] >> a[i][1] >> a[i][2];

    for(int i = 0; i < 3; i++)
        dp[n][i] = a[n][i];

    for(int i = n - 1; i >= 1; i--)
        for(int j = 0; j < 3; j++)
            dp[i][j] = max(dp[i + 1][((j + 1) % 3)], dp[i + 1][((j + 2) % 3)]) + a[i][j];

    int ans = 0;
    for(int i = 0; i < 3; i++) ans = max(ans, dp[1][i]);

    cout << ans << endl;
}