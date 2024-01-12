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
typedef vector<int> vi;

const int MAX = 2e5 + 10; 
const int INF = 1e9 + 7; 

int dp[MAX], id[MAX]; 
map< pair<int, int>, int > edg;
vector<int> adj[MAX];
int n; 

void dfs(int v, int p){
    for(int u: adj[v]){
        if(u == p) continue;

        if(edg[ {u, v} ] >= id[v]) dp[u] = dp[v];
        else dp[u] = dp[v] + 1;

        id[u] = edg[ {u, v} ];

        dfs(u, v);
    }
}

inline void clear_arr(){
    memset(dp, 0, sizeof(dp));
    memset(id, 0, sizeof(id));
    edg.clear();
    for(int i = 1; i <= n; i++) adj[i].clear();
}

main()
{IOS;

    int t; cin >> t;
    while(t--){
        cin >> n;
        clear_arr();
        for(int i = 1; i < n; i++){
            int x, y; cin >> x >> y;
            adj[x].pb(y);
            adj[y].pb(x);
            edg[ {x, y} ] = i;
            edg[ {y, x} ] = i;
        }
        dp[1] = 1; id[1] = 0;
        dfs(1, 0);

        int ans = 0;
        for(int i = 1; i <= n; i++) ans = max(ans, dp[i]);
        cout << ans << endl;
    }

}