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
#define err_hig(i) cout << "hig[" << i << "] = " << hig[i] << endl;

const int MAX = 2e5 + 10; 
const int INF = 1e9 + 7; 

int n;
vector<int> adj[MAX];
int mark[MAX];

struct Diameter{
    int hig[MAX], par[MAX]; 

    void dfs(int v, int p){
        for(int u: adj[v]){
            if(u == p) continue;
            hig[u] = hig[v] + 1;
            par[u] = v;
            dfs(u, v);
        }
    }

    pair<int, int> Find_dia(){
        dfs(1, 0); 
        pair<int, int> maxi = {0, 0};
        for(int i = 1; i <= n; i++) maxi = max(maxi, {hig[i], i});

        int v = maxi.S;
        for(int i = 1; i <= n; i++) par[i] = 0, hig[i] = 0;
        dfs(v, 0);

        maxi = {0, 0};
        for(int i = 1; i <= n; i++) maxi = max(maxi, {hig[i], i});
        int u = maxi.S;

        return {v, u};
    }

} diam;

int par[MAX][30], hig[MAX];
vector<int> d_mem;
int deg[MAX];

struct r{ int v; int u; int x; };
vector<r> ans;

void dfs(int v, int p){
    for(int i = 1; i <= 22; i++)
        par[v][i] = par[ par[v][i - 1] ][i - 1];
    
    for(int u: adj[v]){
        if(u == p) continue;

        hig[u] = hig[v] + 1; 
        par[u][0] = v;  
        dfs(u, v);
    }
}

int lca(int u, int v){
    if(hig[u] < hig[v]) swap(u, v);

    for(int i = 22; i >= 0; i--){
        int x = par[u][i];
        if(hig[x] < hig[v]) continue;

        u = x;
    }

    if(u == v) return v;

    for(int i = 22; i >= 0; i--){
        int x = par[v][i];
        int y = par[u][i];

        if(x == y) continue;

        v = x, u = y;
    }

    return par[v][0];
}

main()
{IOS;

    cin >> n;
    for(int i = 2; i <= n; i++){
        int x, y; cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
        deg[x]++;
        deg[y]++;
    }

    auto x = diam.Find_dia();
    int fr = x.F, sc = x.S;
    hig[fr] = 1;
    dfs(fr, 0);

    int curr = sc;
    while(curr != fr){
        mark[curr] = 1;
        d_mem.pb(curr);
        curr = par[curr][0];
    }
    mark[curr] = 1;

    int res = 0;

    set<int> s;
    for(int i = 1; i <= n; i++){
        if(mark[i]) continue;

        if(deg[i] == 1) s.insert(i);        
    }   

    while(!s.empty()){
        int i = *s.begin();
        s.erase(s.begin());

        int d1 = hig[fr] + hig[i] - 2 * (hig[lca(fr, i)]);
        int d2 = hig[sc] + hig[i] - 2 * (hig[lca(sc, i)]);

        if(d1 > d2) ans.pb({fr, i, i}); 
        else ans.pb({sc, i, i});

        deg[i] = 0;
        deg[par[i][0]]--;

        if(deg[par[i][0]] == 1 && !mark[par[i][0]]) s.insert(par[i][0]);

        res += max(d1, d2);
    }

    int sz = d_mem.size();
    res += ((sz * (sz + 1)) / 2);
    cout << res << endl;  
    
    for(int u: d_mem)
        ans.pb({u, fr, u});

    for(auto g: ans) cout << g.v << " " << g.u << " " << g.x << endl;
}