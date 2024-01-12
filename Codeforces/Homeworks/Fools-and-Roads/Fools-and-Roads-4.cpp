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
map< pair<int, int>, int > mp;
int par[MAX][30], hig[MAX];
int a[MAX], pp[MAX];
pair<int, int> edg[MAX];

void dfs_lca(int v, int p){

    for(int i = 1; i <= 20; i++){
        par[v][i] = par[ par[v][i - 1] ][i - 1];
    }

    pp[v] = p;

    for(int u: adj[v]){
        if(u == p) continue;

        par[u][0] = v;
        hig[u] = hig[v] + 1;
        dfs_lca(u, v);
    }
}

inline void Find_LCA(int v, int u, int id){
    if(hig[v] > hig[u]) swap(v, u);

    if(v == 1 || u == 1) {
        qq[id].S = 1;
        return;
    }
 
    for(int i = 20; i >= 0; i--){
        int x = par[u][i];
        if(hig[x] >= hig[v]) u = x;
    }

    if(v == u){
        qq[id].S = v;
        return;
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
    }
}

inline void LCA(){
    dfs_lca(1, 0);

    for(auto k: qq){
        int v = k.F.F, u = k.F.S, id = k.S;
        Find_LCA(v, u, id);
    }
}

int dfs(int v, int p){
    int sum = 0;
    for(int u: adj[v]){
        if(u == p) continue;

        sum += dfs(u, v);
    }

    sum += a[v];
    mp[ {v, pp[v]} ] = sum;
    mp[ {pp[v], v} ] = sum;

    return sum;
}

main()
{IOS;

    int n; cin >> n;
    for(int i = 1; i < n; i++){
        int x, y; cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
        edg[i] = {x, y};
    }
    int q; cin >> q;
    for(int i = 1; i <= q; i++){
        int v, u; cin >> v >> u;
        qq.pb( { {v, u}, (i - 1) } ); // ? the second value will be the lca, wait for it
    }   

    LCA();

    for(auto k: qq){
        int v = k.F.F, u = k.F.S, lc = k.S;
        a[v]++;
        a[u]++;
        a[lc] -= 2;
    }

    dfs(1, 0);

    for(int i = 1; i < n; i++){
        int v = edg[i].F, u = edg[i].S;
        cout << mp[ {v, u} ] << ' ';
    } 
}