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

const int MAX = 1e5 + 10; 
const int INF = 1e9 + 7; 

int pos[MAX], ans[MAX];
vector<int> adj[MAX]; 
int n, q; 

struct Query{int l; int r; int idx;};
vector<Query> que[MAX];

set<int> dfs(int v, int p){ // ? YOHO!, Say Hello To GOONI
    set<int> s;
    s.insert(pos[v]);
    for(int u: adj[v]){
        if(u == p) continue;

        auto t = dfs(u, v);
        if(s.size() < t.size()) swap(s, t);
        for(int x: t) s.insert(x);
    }

    for(auto u: que[v])
        ans[u.idx] = (s.lower_bound(u.l) != s.upper_bound(u.r));

    return s;
}

inline void clearA(){
    for(int i = 1; i <= n; i++) adj[i].clear();
    for(int i = 1; i <= n; i++) que[i].clear();
}

main()
{IOS;

    int t; cin >> t;
    while(t--){
        cin >> n >> q;
        clearA();
        for(int i = 1; i < n; i++){
            int x, y; cin >> x >> y;
            adj[x].pb(y);
            adj[y].pb(x);
        }

        for(int i = 1; i <= n; i++) {
            int x; cin >> x;
            pos[x] = i;
        }

        for(int i = 1; i <= q; i++){
            int l, r, x; cin >> l >> r >> x;
            que[x].pb( {l, r, i} );
        }

        dfs(1, 0);

        for(int i = 1; i <= q; i++) cout << (ans[i] ? "YES" : "NO") << endl;
        cout << endl;
    }

}