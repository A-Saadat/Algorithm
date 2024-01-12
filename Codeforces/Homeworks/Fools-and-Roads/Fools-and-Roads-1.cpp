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

const int MaxN = 1e6; 
const int INF = 1e9 + 7; 

vector<int> adj[MaxN], act; 
vector< pair<int, int> > qu[MaxN]; // ? qu[i][j] = {j-th vertix, the LCA of i and j-th vertix}
int str[MaxN], fin[MaxN];
int a[MaxN], par[MaxN];
map< pair<int, int>, int > mp;
pair<int, int> edg[MaxN];

bool onc = 0;
int t = 0;

void find_LCA(int v, int u, int id){
    int L = 0, R = act.size();
    
    while(R - L > 1){
        int mid = (R + L) / 2;
        int curr = act[mid];

        bool st = (str[curr] <= str[v] && str[curr] <= str[u]);
        bool fn = (fin[curr] >= fin[v] && fin[curr] >= fin[u]);

        if(st && fn) L = mid;
        else R = mid;
    }

    qu[v][id].S = act[L];
}

void dfs_lca(int v, int p){
    par[v] = p;
    ++t; str[v] = t;
    act.pb(v);

    for(int u: adj[v]){
        if(u == p) continue;

        dfs_lca(u, v);
    }

    fin[v] = t;
    
    int id = 0;
    if(onc){
        int r = act.back();
        for(auto u: qu[r]){
            find_LCA(r, u.F, id);
            ++id;
        }
    }


    act.pop_back();
}

inline void LCA(){
    dfs_lca(1, 0);
    onc = 1; t = 0;
    dfs_lca(1, 0);
}

int dfs(int v, int p){
    int sum = 0;
    for(int u: adj[v]){
        if(u == p) continue;

        sum += dfs(u, v);
    }

    sum += a[v];
    mp[ {v, par[v]} ] = sum;
    mp[ {par[v], v} ] = sum;

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
    for(int i = 1; i <= q; i++) {
        int v, u; cin >> v >> u;
        qu[v].pb( {u, i} );
    }

    LCA();

    for(int i = 1; i <= n; i++) {
        for(auto u: qu[i]){
            int lc = u.S;

            a[lc] -= 2; // ? LCA
            a[i] += 1; // ? Origin 
            a[u.F] += 1; // ? destination
        }
    }

    dfs(1, 0);

    for(int i = 1; i < n; i++){
        int v = edg[i].F, u = edg[i].S;
        cout << mp[ {v, u} ] << ' ';
    }

} 