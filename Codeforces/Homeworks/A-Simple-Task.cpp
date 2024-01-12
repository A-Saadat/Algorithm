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
#define int long long 

const int MAX = (1 << 19) + 10;
const int INF = 1e9 + 7; 

vector<int> adj[30];
int dp[MAX][30]; 
int ans;

main()
{IOS;

    int n, m; cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v; cin >> u >> v;
        --u, --v;
        int mask = 0;
        mask ^= (1 << u);
        mask ^= (1 << v);
        if(u > v) swap(u, v);
        dp[mask][u] = 1;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    for(int mask = 0; mask < (1 << n); mask++){
        if(__builtin_popcount(mask) < 3) continue;

        vector<int> O;
        int tmp = mask;
        for(int i = 0; tmp > 0; i++){
            if(tmp & 1) O.pb(i);
            tmp >>= 1;
        }
        int v = O.back();

        for(int j: O){
            for(int u: adj[j]){
                if(v == u || v == j) continue;
                dp[mask][j] += dp[mask ^ (1 << j)][u];
            }
        }

        for(int u: adj[v])
            ans += dp[mask][u];
    }

    cout << ans / 2 << endl;

}