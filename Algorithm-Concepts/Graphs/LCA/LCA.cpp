#include <bits/stdc++.h> 
using namespace std; 

#define IOS ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0) 
#define forn(i,k,n) for(int i = k; i < n; i++) 
#define fort(itr,map) for(auto itr = map.begin(); itr != map.end(); ++itr) 
#define pb push_back 
#define elif else if 
#define F first 
#define S second 
#define gcd __gcd 
#define all(v) v.begin(), v.end() 
#define uni(v) sort(all(v)), v.erase(unique(all(v)), v.end()) 
#define err(x) cout << '#' << x << ':' << ' ' << x << endl 
typedef long long int ll; 
typedef vector<int> vi;

const int MAX = 1e6; 
const int INF = 1e9 + 7; 

vector<int> adj[MAX]; 
vector< pair< pair<int, int> , int> > qq;
int par[MAX][30], hig[MAX];

void dfs(int v, int p){

    for(int i = 1; i <= 20; i++){
        par[v][i] = par[ par[v][i - 1] ][i - 1];
    }

    for(int u: adj[v]){
        if(u == p) continue;

        par[u][0] = v;
        hig[u] = hig[v] + 1;
        dfs(u, v);
    }
}

inline int Find_LCA(int v, int u, int id){
    if(hig[v] > hig[u]) swap(v, u);
 
    for(int i = 20; i >= 0; i--){
        int x = par[u][i];
        if(hig[x] >= hig[v]) u = x;
    }

    if(v == u){
        qq[id].S = v;
        return v;
    }
    else{
        
        for(int i = 20; i >= 0; i--){
            int x = par[u][i];
            int y = par[v][i];

            if(x != y){
                u = par[u][i];
                v = par[v][i];
            }
        }

        qq[id].S = par[v][0];
        return par[v][0];
    }
}

main()
{IOS;

    int n; cin >> n;
    for(int i = 1; i < n; i++){
        int x, y; cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    int q; cin >> q;
    for(int i = 1; i <= q; i++){
        int v, u; cin >> v >> u;
        qq.pb( { {v, u}, (i - 1) } ); // ? the second value will be the lca, wait for it
    }   

    dfs(1, 0);

    hig[1] = 1;

    for(auto k: qq){
        int v = k.F.F, u = k.F.S, id = k.S;
        cout << Find_LCA(v, u, id) << endl;
    }

}