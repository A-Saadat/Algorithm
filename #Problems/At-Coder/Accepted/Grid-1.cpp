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

const int MAX = 1e3 + 10; 
const int MOD = 1e9 + 7; 

char a[MAX][MAX];
int dp[MAX][MAX]; 

main()
{IOS;

    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++)
            cin >> a[i][j];
    }

    dp[n][m] = 1;
    for(int i = n; i >= 1; i--){
        for(int j = m; j >= 1; j--){
            if(i == n && j == m) continue;
            if(a[i][j] == '#') continue;
            
            dp[i][j] = (dp[i + 1][j] + dp[i][j + 1]) % MOD;
        }
    }

    cout << dp[1][1] << endl;

}