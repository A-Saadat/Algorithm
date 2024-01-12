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

const int MAX = 1e6; 
const int INF = 1e9 + 7; 

vector<int> adj[MAX];
bool mark[MAX];
int dp[MAX], dep[MAX]; // ? dp[v] = the minimum depth of a vertex which at least one of the vertices in the subtree of v, is connected to 
map< pair<int, int>, int > isBri;

void dfs(int v, int p){
    dp[v] = dep[v]; mark[v] = 1;
    for(int u: adj[v]){
        if(!mark[u]){
            dep[u] = dep[v] + 1;
            dfs(u, v);
            dp[v] = min(dp[v], dp[u]);
        }
        else{
            if(u == p) continue;

            dp[v] = min(dp[v], dep[u]);
        }
    }

    if(v != 1 && dep[v] <= dp[v]) isBri[ {v, p} ] = 1;
}

main()
{IOS;

    int n, m; cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int x, y; cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    dep[1] = 1;
    dfs(1, 0);

    fort(itr, isBri) cout << "[" << itr->F.F << ", " << itr->F.S << "] = " << itr->S << endl;

}