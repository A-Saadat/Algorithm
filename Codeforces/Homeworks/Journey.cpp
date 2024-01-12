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
// #define int long long 

const int MAX = 1e6; 
const int INF = 1e9 + 7; 

vector<int> adj[MAX]; 
double dp[MAX];
int hig[MAX];

void dfs(int v, int p){
    double sz = adj[v].size() - (p > 0);
    for(int u: adj[v]){
        if(u == p) continue;

        dp[u] = dp[v] / sz;
        hig[u] = hig[v] + 1;
        // cout << sz << endl;
        dfs(u, v);
    }
}

main()
{IOS;
    cout.precision(12); cout.setf(ios::fixed);

    int n; cin >> n;
    for(int i = 1; i < n; i++){
        int x, y; cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }    
    dp[1] = 1.0;
    dfs(1, 0);

    double ans = 0.0;
    for(int i = 1; i <= n; i++){
        if(adj[i].size() > 1) continue;
        
        ans += (hig[i] * dp[i]);
        // cout << "dp[" << i << "] = " << dp[i] << endl;
    }

    cout << ans << endl;

}