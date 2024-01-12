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
const int MOD = 1e9 + 7; 

vector<int> adj[MAX];
int dp[MAX][5], c[MAX];

inline int cu_pow(int a, int b){
    int ans = 1;
    while(b > 0){
        if(b & 1) ans = (ans * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ans % MOD;
}

void dfs(int v){
    for(int u: adj[v]){
        dfs(u);
        if(c[v] == 1){
            dp[v][0] = 0;
            int val = dp[u][0] + dp[u][1] % MOD;
            dp[v][1] = dp[v][1] * val % MOD;
        }
        else{
            int val = dp[u][0] + dp[u][1] % MOD;
            dp[v][0] = dp[v][0] * val % MOD;
        }
    }
    if(c[v] == 1) return;

    for(int u: adj[v]){
        int x = dp[u][1] + dp[u][0] % MOD;
        int val = dp[v][0] * cu_pow(x, MOD - 2) % MOD;
        val = val * dp[u][1] % MOD;
        dp[v][1] = (dp[v][1] + val) % MOD;
    }
}

main()
{IOS;

    int n; cin >> n;
    for(int i = 1; i < n; i++){
        int x; cin >> x;
        adj[x].pb(i);
    }
    for(int i = 0; i < n; i++) cin >> c[i];
    for(int i = 0; i < n; i++) dp[i][c[i]] = 1;

    dfs(0);

    cout << dp[0][1] << endl;
}