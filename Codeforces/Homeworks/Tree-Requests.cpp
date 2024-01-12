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

const int MAX = 5e5 + 10; 
const int INF = 1e9 + 7; 

int a[MAX], ans[MAX], mask[MAX], hig[MAX];
vector<int> adj[MAX];
vector<pair<int, int>> que[MAX];
 
void dfs(int v){
    for(auto u: que[v])
        ans[u.F] = mask[u.S];

    mask[hig[v]] ^= (1 << a[v]);
    for(int u: adj[v]){
        hig[u] = hig[v] + 1;
        dfs(u);
    }

    for(auto u: que[v])
        ans[u.F] ^= mask[u.S];
}

main()
{IOS;

    int n, q; cin >> n >> q;
    for(int i = 2; i <= n; i++){
        int p; cin >> p;
        adj[p].pb(i);
    }

    string s; cin >> s;
    for(int i = 0; i < n; i++)
        a[i + 1] = s[i] - 'a';

    for(int i = 1; i <= q; i++){
        int v, h; cin >> v >> h;
        que[v].pb( {i, h} );
    }

    hig[1] = 1;
    dfs(1);
    
    for(int i = 1; i <= q; i++) cout << (__builtin_popcount(ans[i]) > 1 ? "No" : "Yes") << endl;

}