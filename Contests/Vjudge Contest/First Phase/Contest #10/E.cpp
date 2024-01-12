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

const int MAX = 3e3 + 10; 
const int MOD = 1e9 + 7; 

int dp[MAX][MAX]; 

int cu_pow(int a, int b){
    if(b == 1) return a;
    int ans = cu_pow(a, b / 2);
    ans = 1LL * ans * ans; ans = ans % MOD;
    if(b % 2) ans = 1LL * ans * a; ans = ans % MOD;
    return ans % MOD;
}

int comb(int x){
    return 1LL * x * (x - 1) * cu_pow(2, MOD - 2) % MOD;
}

main()
{IOS;

    int n, m; cin >> n >> m;
    for(int i = 0; i <= n; i++) dp[i][0] = 1;
    for(int j = 0; j <= m; j++) dp[0][j] = 1;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            int res = 1LL * 4 * i * (dp[i - 1][j - 1]); res = res % MOD;
            res = res + (dp[i][j - 1]); res = res % MOD;
            if(i > 1)
                res = res + (1LL * comb(i) * dp[i - 2][j - 1]), res = res % MOD;
            if(j > 1)
                res = res + (1LL * (i * (j - 1))) * dp[i - 1][j - 2], res = res % MOD;

            dp[i][j] = res;
        }
    }

    cout << (dp[n][m] - 1 + MOD) % MOD << endl;

}