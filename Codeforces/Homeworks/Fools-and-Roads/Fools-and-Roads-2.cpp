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

vector< pair<int, int> > ans[MAX];
vector<int> adj[MAX], flr[MAX]; 
map< pair<int, int>, int > mp;
pair<int, int> edg[MAX];
pair<int, int> qq[MAX];

int par[MAX], hig[MAX], a[MAX];
int str[MAX], fin[MAX];

int t = 0, n, q; 
void dfs_lca(int v, int p){
    ++t; str[v] = t; par[v] = p;
    for(int u: adj[v]){
        if(u == p) continue;
        hig[u] = hig[v] + 1;

        dfs_lca(u, v);
    }
    fin[v] = t;
}

pair<bool, int> check(int fl, int v, int u){
    int L = 0, R = flr[fl].size();

    while(R - L > 1){
        int mid = (R + L) / 2;
        int x = flr[fl][mid];
        bool st = (str[x] <= str[v] && str[x] <= str[u]);
        bool fn = (fin[x] >= fin[v] && fin[x] >= fin[u]);

        if(st && fn) L = mid;
        else R = mid;
    }

    int x = flr[fl][L];

    bool st = (str[x] <= str[v] && str[x] <= str[u]);
    bool fn = (fin[x] >= fin[v] && fin[x] >= fin[u]);    

    if(L != flr[fl].size() && fn && st) return {1, x};
    else return {0, 0};
}

inline void Find_LCA(int v, int u){
    int h = max(hig[v], hig[u]);
    int L = 0, R = h + 1;
    while(R - L > 1){
        int mid = (R + L) / 2;
        pair<bool, int> res = check(mid, v, u);

        if(res.F) L = mid;
        else R = mid;
    }

    auto res = check(L, v, u);
    ans[v].pb( {u, res.S} );
}

inline void LCA(){
    dfs_lca(1, 0);

    for(int i = 1; i <= n; i++)
        flr[ hig[i] ].pb(i);

    for(int i = 1; i <= q; i++){
        int v = qq[i].F, u = qq[i].S;
        Find_LCA(v, u);
    }
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

    cin >> n;
    for(int i = 1; i < n; i++){
        int x, y; cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
        edg[i] = {x, y};
    }

    cin >> q;
    for(int i = 1; i <= q; i++){
        int v, u; cin >> v >> u;
        qq[i] = {v, u};
    }

    LCA();

    // for(int i = 1; i <= n; i++){
    //     for(auto u: ans[i]) cout << "The LCA of " << i << " and " << u.F << " = " << u.S << endl;
    // }

    for(int i = 1; i <= n; i++) {
        for(auto u: ans[i]){
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