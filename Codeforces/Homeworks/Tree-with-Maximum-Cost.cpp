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

const int MAX = 2e5 + 10; 
const int INF = 1e9 + 7; 

int sub[MAX], dp[MAX], a[MAX], hig[MAX];
vector<int> adj[MAX]; 

int sum;

void dfs(int v, int p){
    sub[v] = a[v];
    for(int u: adj[v]){
        if(u == p) continue;

        hig[u] = hig[v] + 1;
        dfs(u, v);
        sub[v] += sub[u];
    }
}

void dfs_2(int v, int p){
    for(int u: adj[v]){
        if(u == p) continue;

        dp[u] = dp[v] - sub[u] + (sum - sub[u]);
        dfs_2(u, v);
    }
}

main()
{IOS;

    int n; cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i], sum += a[i];

    for(int i = 1; i < n; i++){
        int x, y; cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    dfs(1, 0);
    for(int i = 1; i <= n; i++)
        dp[1] += hig[i] * a[i];

    dfs_2(1, 0);

    int ans = 0;
    for(int i = 1; i <= n; i++)
        ans = max(ans, dp[i]);

    cout << ans << endl;
}