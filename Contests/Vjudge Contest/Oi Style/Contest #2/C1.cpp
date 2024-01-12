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
#define err_dis(i) cout << "Dis[" << i << "] = " << dis[i] << endl;

const int MAX = 1e5 + 10; 
const int INF = 1LL * 1000 * 1000 * 1000 * 1000 * 1000 * 1000; 

vector<pair<int, int>> adj[MAX]; 
vector<int> shops;
int dis[MAX];
int n, SS, q, e; 
pair<int, int> edg[MAX];

set<pair<int, int>> s;
void Dijkstra(int root, int x, int y){
    for(int i = 1; i <= n; i++) dis[i] = INF;

    dis[root] = 0;
    s.insert({dis[root], root});
    while(!s.empty()){
        auto [d, v] = *s.begin();
        s.erase(s.begin());
        for(auto [u, w]: adj[v]){
            if((u == x && v == y) || (u == y && v == x)) continue;

            if(dis[u] > d + w){
                s.erase({dis[u], u});
                dis[u] = d + w;
                s.insert({dis[u], u});
            }
        }
    }
}

int Find_par(int v) {
    if(v == par[v]) return v;
    return par[v] = Find_par(par[v]);
}

void merge(int A, int B){
    A = Find_par(A), B = Find_par(B);
    if(A == B) return;

    if(sz[A] > sz[B]) swap(A, B);
    par[A] = B;
    sz[B] += sz[A];
}

main()
{IOS;

    cin >> n >> SS >> q >> e;

    for(int i = 1; i <= n; i++) par[i] = i, sz[i] = i;

    for(int i = 1; i < n; i++){
        int x, y, w; cin >> x >> y >> w;
        adj[x].pb({y, w});
        adj[y].pb({x, w});
        edg[i] = {x, y};
        merge(x, y);
    }
    for(int i = 1; i <= SS; i++){
        int x; cin >> x;
        shops.pb(x);
    }

    // if(n )

    // while(q--){
    //     int l, r; cin >> l >> r;
    //     Dijkstra(r, edg[l].F, edg[l].S);
    //     if(dis[e] != INF) {cout << "escaped\n"; continue;}

    //     int mini = INF;
    //     for(int u: shops){
    //         mini = min(mini, dis[u]);
    //     }

    //     if(mini != INF) cout << mini << endl;
    //     else cout << "oo\n";
    // }

    while(q--){
        int l, r; cin >> l >> r;

        

    }
}