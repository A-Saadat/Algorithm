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

int a[MAX], dp[5][MAX][MAX]; 
int ans;

main()
{IOS;

    int n, m, b, mod; cin >> n >> m >> b >> mod;
    for(int i = 1; i <= n; i++) cin >> a[i];

    dp[0][0][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= m; j++){
            for(int k = 0; k <= b; k++){
                int sum = dp[(i - 1) % 2][j][k];
                if(k - a[i] >= 0 && j > 0) sum = (sum + dp[i % 2][j - 1][k - a[i]]) % mod;
                dp[i % 2][j][k] = sum % mod;
            }
        }
    }

    int ans = 0;
    for(int k = 0; k <= b; k++)
        ans = (ans + dp[n % 2][m][k]) % mod;

    cout << ans % mod << endl;

}