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

const int MAX = 1e5;
const int MX = sqrt(1e5); 
const int INF = 1e9 + 7; 

vector<int> adj[MAX];
vector< pair<int, int> > qq; 
int par[MAX][MX], hig[MAX];

int mxH = 0;
void dfs(int v, int p){
    for(int u: adj[v]){
        if(u == p) continue;

        par[u][0] = v;
        hig[u] = hig[v] + 1;
        mxH = max(mxH, hig[u]);
        dfs(u, v);
    }
}

void Find_LCA(int v, int u){
    // int hm = 

    // while(true){
    //     p = 
    // }
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
        qq.pb( {v, u} );
    }

    dfs(1, 0);

    cout << endl;

    int S = sqrt(mxH);
    for(int v = 1; v <= n; v++)
        for(int k = 1; k <= S; k++) par[v][k] = par[par[v][k - 1]][0];

    for(int v = 1; v <= n; v++){
        for(int k = 1; k <= S; k++) cout << "par[" << v << "][" << k << "] = " << par[v][k] << endl;
        cout << "\n------------------------\n";
    }

    // for(auto x: qq){
    //     int v = x.F, u = x.S;
    //     Find_LCA(v, u);
    // }


}