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

vector<int> adj[MAX], comp[MAX]; 
int cc[MAX];
int n, m, q, col; // ? cpl = the color of component

void dfs(int v){
    cc[v] = col; comp[col].pb(v);
    for(int u: adj[v]){
        if(cc[u]) continue;

        dfs(u);
    }
}

inline void merge(int A, int B){
    if(comp[A].size() > comp[B].size()) swap(A, B);

    for(int u: comp[A]){
        cc[u] = B;
        comp[B].pb(u);
    }

    comp[A].clear();
}

main()
{IOS;

    int n, m; cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int x, y; cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    for(int i = 1; i <= n; i++)
        if(!cc[i]) ++col, dfs(i);

    int q; cin >> q;
    while(q--){
        int u, v; cin >> u >> v;
        if(cc[u] == cc[v]) continue;

        merge(cc[u], cc[v]);
    }
}

// for(int i = 1; i <= col; i++){
//     cout << i << ": ";
//     for(int u: comp[i]) cout << u << ' ';
//     cout << "\n--------------\n"; 
// }
