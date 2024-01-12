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

const int MAX = 1e6 + 10; 
const int INF = 1e9 + 7; 

pair<int, int> a[MAX]; 
vector<int> adj[MAX];
int par[MAX], sz[MAX];
int ans = 0;
int n; 

int Find_par(int v){
    if(par[v] == -1) return -1;
    if(par[v] == v) return v;
    return par[v] = Find_par(par[v]);
}

void merge(int A, int B){
    if(A == B) return;

    if(sz[A] > sz[B]) swap(A, B);
    par[A] = B;
    sz[B] += sz[A];
}

void DSU(int v, int val){
    par[v] = v; sz[v] = 1;
    for(int u: adj[v]){
        u = Find_par(u), v = Find_par(v);
        if(u == -1) continue;

        ans += 1LL * sz[u] * sz[v] * val;
        merge(v, u);
    }
}

inline void Solve(){
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++) {
        int v = a[i].S, val = a[i].F;
        DSU(v, val);
    }
}

main()
{IOS;

    cin >> n;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        a[i] = {x, i};
        par[i] = -1;
    }

    for(int i = 2; i <= n; i++){
        int x, y; cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    Solve();
    for(int i = 1; i <= n; i++){
        a[i].F = -a[i].F;
        par[i] = -1;
        sz[i] = 0;
    }
    Solve();

    cout << ans << endl;

}