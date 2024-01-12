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
typedef long long int ll; 
typedef vector<int> vi;

const int MAX = 1e6; 
const int INF = 1e9 + 7; 

int sz[MAX], par[MAX], mark[MAX]; 
int n, m, q, col;
vector<int> adj[MAX];

int Find_par(int v){
    if(par[v] == v) return v;

    return par[v] = Find_par( par[v] );
}

void merge(int A, int B){
    A = Find_par(A);
    B = Find_par(B);

    if(A == B) return;

    if(sz[A] > sz[B]) swap(A, B);

    sz[B] += sz[A];
    par[A] = B;
}

void dfs(int v){
    mark[v] = 1; sz[col]++;
    for(int u: adj[v]){
        if(mark[u]) continue;

        par[u] = v;
        dfs(u);
    }
}

main()
{IOS;

    cin >> n >> m >> q;
    for(int i = 1; i <= m; i++){
        int x, y; cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    for(int i = 1; i <= n; i++) par[i] = i;

    for(int i = 1; i <= n; i++){
        if(mark[i]) continue;

        col = i;
        dfs(i);
    }

    while(q--){
        int u, v; cin >> u >> v;
        merge(u, v);
    }
    
}