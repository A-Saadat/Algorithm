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

const int MAX = 50 + 10; 
const int INF = 1e10 + 10; 

int dp[MAX][MAX][MAX]; 
int n = 30, m = 30, W = 50;

inline void update(int i, int j, int k){
    dp[i][j][k] = INF;
    for(int x = 1; x < i; x++)
        for(int y = 0; y <= k; y++)
            dp[i][j][k] = min(dp[i][j][k], dp[i - x][j][k - y] + dp[x][j][y] + (j * j));

    for(int x = 1; x < j; x++)
        for(int y = 0; y <= k; y++)
            dp[i][j][k] = min(dp[i][j][k], dp[i][j - x][k - y] + dp[i][x][y] + (i * i));
}

main()
{IOS;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= W; k++){
                if(i * j < k) dp[i][j][k] = INF;
                elif(i * j == k) dp[i][j][k] = 0;
                else update(i, j, k);
            }
        }
    }

    int t; cin >> t;
    while(t--){
        int n, m, k; cin >> n >> m >> k;
        cout << dp[n][m][k] << endl;
    }

}