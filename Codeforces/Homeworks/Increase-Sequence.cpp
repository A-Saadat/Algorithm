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

const int MAX = 2000 + 10; 
const int MOD = 1e9 + 7; 

int a[MAX], dp[MAX][MAX]; 

main()
{IOS;

    int n, h; cin >> n >> h;
    for(int i = 1; i <= n; i++) cin >> a[i];

    dp[1][1] = (a[1] == h - 1);
    dp[1][0] = (a[1] == h);

    for(int i = 2; i <= n; i++){
        for(int j = 0; j <= n + 10; j++){
            if(a[i] + j != h) dp[i][j] = 0;
            else{
                dp[i][j] = (dp[i - 1][j] + (dp[i - 1][j + 1] * (j + 1) % MOD)) % MOD; // ? none, ]
                if(j > 0){
                    dp[i][j] = dp[i][j] + dp[i - 1][j - 1] % MOD; // ? [, ][
                    dp[i][j] = dp[i][j] + (dp[i - 1][j] * j) % MOD;
                } 
            }
        }
    }

    cout << (dp[n][0] + dp[n][1]) % MOD << endl;
}