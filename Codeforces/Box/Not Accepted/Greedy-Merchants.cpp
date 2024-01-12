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
#define int long long

const int MAX = 1e5 + 10; 
const int INF = 1e9 + 7; 

vector<int> adj[MAX]; 
set< pair<int, int> > bdg, edg;

int mark[MAX], dp[MAX], hig[MAX], par[MAX][30];
int mlf[MAX];

int n, m, num = 0;

void dfs2(int v, int p){
    mark[v] = 1; mlf[v] = num;
    for(int u: adj[v]){
        if(mark[u]) continue;

        dfs2(u, v);
    }
}

void dfs(int v, int p){ // ! Find_Bridge
    for(int i = 1; i <= 22; i++)
        par[v][i] = par[ par[v][i - 1] ][i - 1];

    mark[v] = 1; dp[v] = INF;
    for(int u: adj[v]){
        if(!mark[u]){
            hig[u] = hig[v] + 1;
            par[u][0] = v;
            dfs(u, v);
            dp[v] = min(dp[v], dp[u]);
        }
        else{
            if(u == p) continue;
            dp[v] = min(dp[v], hig[u]); // ? backedges
        }
    }

    if(v != 1 && dp[v] >= hig[v]) bdg.insert( {p, v} ), bdg.insert( {v, p} );
}

inline void clearArr(){
    for(int i = 1; i <= n; i++) mark[i] = 0;
    for(int i = 1; i <= n; i++) hig[i] = 0;
}

inline void Find_dis(int v, int u){
    int ans = 0;
    if(hig[v] > hig[u]) swap(u, v);
    for(int i = 22; i >= 0; i--){
        int x = par[u][i];
        if(hig[x] < hig[v]) continue;

        ans += (1 << i);
        u = par[u][i];
    }

    if(u == v){
        cout << ans << endl;
        return;
    }

    for(int i = 22; i >= 0; i--){
        int x = par[u][i], y = par[v][i];
        if(x == y) continue;

        ans += 2 * (1 << i);
    }

    ans += 2;
    cout << ans << endl;
}

main()
{IOS;

    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int x, y; cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
        edg.insert({x, y});
        edg.insert({y, x});
    }

    dfs(1, 0); // ? Finding Bridges
    for(int i = 1; i <= n; i++) mark[i] = 0;
    for(int i = 1; i <= n; i++) adj[i].clear();

    fort(itr, bdg){
        int v = itr->F, u = itr->S;
        edg.erase({v, u});
        edg.erase({u, v});
    }

    fort(itr, edg){
        int v = itr->F, u = itr->S;
        adj[v].pb(u);
    }

    for(int i = 1; i <= n; i++)
        if(!mark[i]) ++num, dfs2(i, 0);

    for(int i = 1; i <= n; i++) adj[i].clear();

    fort(itr, bdg){ // ? this is a new graph where every components are vertices and every bridges, are edges. note that this a tree
        int v = itr->F, u = itr->S;
        v = mlf[v], u = mlf[u];
        if(v == u) continue;

        adj[v].pb(u);
    }

    clearArr();
    hig[1] = 1;
    dfs(1, 0);

    int q; cin >> q;
    while(q--){
        int v, u; cin >> v >> u;
        v = mlf[v], u = mlf[u];

        if(u == v) cout << "0\n";
        else Find_dis(v, u);
    }
}