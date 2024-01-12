///** اقای مهندس وارد میشود
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
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")

const int MAX = 1e5 + 10;
const int M = 447 + 10; 
const int MOD = 1e9 + 7; 

int c[MAX], l[MAX], r[MAX], sub[MAX]; 
vector<pair<int, int>> adj[MAX];
int n, k; 

void dfs(int v, int p){
    sub[v] = 1;
    for(auto [u, idx]: adj[v]){
        if(u == p) continue;

        dfs(u, v);
        sub[v] += sub[u];
        c[idx] = sub[u] * (n - sub[u]);
    }
}

int dp[M][MAX];

signed main()
{IOS;

    cin >> n >> k;
    for(int i = 1; i < n; i++){
        int x, y, L, R; cin >> x >> y >> L >> R;
        l[i] = L;
        r[i] = R;
        adj[x].pb({y, i});
        adj[y].pb({x, i});
    }

    dfs(1, 0);

    if(n > 447) return puts("0\n");

    vector<int> pre(n + 4);
    for(int i = 1; i < n; i++) pre[i] = pre[i - 1] + l[i];

    dp[0][0] = 1;
    for(int i = 1; i < n; i++){
        for(int j = pre[i]; j <= k; j++){
            int sum = 0;
            for(int t = l[i]; t <= r[i] && t * c[i] <= j; t++){
                if(j - t * c[i] < 0) continue;

                sum += dp[i - 1][j - (t * c[i])]; 
                sum = sum % MOD;
            }
            dp[i][j] = sum;
        }
    }

    int ans = 0;
    for(int i = 1; i <= k; i++){
        ans = ans + dp[n - 1][i];
        ans = ans % MOD;
    }

    cout << ans << endl;


}