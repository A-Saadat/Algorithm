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

int par[MAX], hig[MAX];
int str[MAX], fin[MAX];
vector<int> adj[MAX], flr[MAX]; 
pair<int, int> qq[MAX];
vector< pair<int, int> > ans[MAX];

int t = 0;
void dfs(int v, int p){
    ++t; str[v] = t; par[v] = p;
    for(int u: adj[v]){
        if(u == p) continue;
        hig[u] = hig[v] + 1;

        dfs(u, v);
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
        qq[i] = {v, u};
    }

    dfs(1, 0);

    for(int i = 1; i <= n; i++)
        flr[ hig[i] ].pb(i);

    for(int i = 1; i <= q; i++){
        int v = qq[i].F, u = qq[i].S;
        Find_LCA(v, u);
    }
    
}