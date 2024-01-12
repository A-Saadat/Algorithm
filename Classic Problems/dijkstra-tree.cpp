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
const ll INF = 1LL * 1000 * 1000 * 1000 * 1000 * 1000 * 1000; 

vector< pair<int, int> > adj[MAX]; 
set< pair<ll, int> > s;
map< pair<int, int>, int > edg;
ll dis[MAX];
int par[MAX], vv[MAX], n, m;

inline void Dijkstra(int root){
    for(int i = 1; i <= n; i++) dis[i] = INF;

    dis[root] = 0; s.insert( {dis[root], root} );
    while(!s.empty()){
        auto itr = s.begin();
        s.erase(itr);
        int v = itr->S;
        ll d = itr->F;

        for(auto x: adj[v]){
            ll w = x.S;
            int u = x.F;

            if(dis[u] > w + d){
                par[u] = v;
                s.erase( {dis[u], u} );
                dis[u] = w + d;
                s.insert( {dis[u], u} );
            }
        }
    }
}

main()
{IOS;

    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int x, y, val; cin >> x >> y >> val;
        adj[x].pb( {y, val} );
        adj[y].pb( {x, val} );
        edg[ {x, y} ] = i;
        edg[ {y, x} ] = i;
        vv[i] = val;

    }
    int u; cin >> u;

    Dijkstra(u);

    int sum = 0;
    for(int i = 1; i <= n; i++){
        if(!par[i]) continue;
        int x = edg[ {i, par[i]} ];
        sum += vv[x];
    } 
    cout << sum << endl;

    for(int i = 1; i <= n; i++){
        if(!par[i]) continue;
        cout << edg[ {i, par[i]} ] << ' ';
    } 
}