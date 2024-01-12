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
#define err_par(i, j) cout << "par[" << i << "][" << (1 << j) << "] = " << par[i][j] << endl;
// #define int long long 
typedef vector<int> vi;

const int MAX = 1e5 + 10; 
const int INF = 1e9 + 7;
const int sq = 317; 

vector<int> adj[MAX], R; 
// ? R = the vector of all red colored vertex
// ? dep = the regular depht of any vertex from the root 
// ? dis[i] = the distance of vertex i from the closest red colored vertex
int dep[MAX], dis[MAX];
int par[MAX][30];

inline void MS_BFS(){
    queue<int> q;
    for(int u: R) q.push(u);
    
    while(!q.empty()){
        int fr = q.front(); q.pop();
        for(int u: adj[fr]){
            if(dis[u] <= dis[fr] + 1) continue;

            dis[u] = dis[fr] + 1;
            q.push(u);
        }
    }

    R.clear();
}

void dfs(int v, int p){
    par[v][0] = p;
    for(int i = 1; i <= 22; i++)
        par[v][i] = par[ par[v][i - 1] ][i - 1];

    for(int u: adj[v]){
        if(u == p) continue;
        
        dep[u] = dep[v] + 1;
        dfs(u, v);
    }
}

inline int LCA(int v, int u){
    if(dep[v] > dep[u]) swap(u, v);

    if(v == 1) return 1;

    for(int i = 22; i >= 0; i--){
        int x = par[u][i];
        if(dep[x] < dep[v]) continue;

        u = x;
    }

    if(u == v) return u;

    for(int i = 22; i >= 0; i--){
        int x = par[v][i];
        int y = par[u][i];

        if(x != y){
            v = x;
            u = y;
        }
    }

    return par[u][0];
}

inline int _get(int v){
    int ans = dis[v];

    for(int u: R)
        ans = min(ans, dep[v] + dep[u] - (2 * dep[ LCA(v, u) ]) );

    return ans;
}

main()
{IOS;

    int n, q; cin >> n >> q;
    for(int i = 1; i < n; i++){
        int x, y; cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    dfs(1, 0); R.pb(1); 
    for(int i = 1; i <= n; i++) dis[i] = dep[i];
    
    for(int i = 0; i < q; i++){
        if(i % sq == 0) MS_BFS();
        int type, v; cin >> type >> v;

        if(type == 1){
            R.pb(v);
            dis[v] = 0;
        }
        else cout << _get(v) << endl;

    }

}