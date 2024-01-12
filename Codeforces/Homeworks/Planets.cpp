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

int a[MAX];
vector< pair<int, ll> > intr[MAX], adj[MAX];
ll dis[MAX];
set< pair<ll, int> > s;
int n, m; 

inline void find_intr(int k, int id){
    if(k == 0) return;

    for(int i = 1; i <= k; i++) cin >> a[i];
    intr[id].pb( {a[1], a[1]} );
    for(int i = 2; i <= k; i++){
        int R = intr[id].back().S;

        if(a[i] - 1 == R) intr[id].back().S = a[i];
        else intr[id].pb( {a[i], a[i]} );
    }
}

ll BS(int v){
    ll d = dis[v];
    if(intr[v].size() == 0) return d;

    ll L = 0, R = intr[v].size();
    while(R - L > 1){
        int mid = (R + L) / 2;
        ll x = intr[v][mid].F;

        if(x <= dis[v]) L = mid;
        else R = mid;
    }

    ll str = intr[v][L].F;
    ll fin = intr[v][L].S;

    if(str <= d && fin >= d) return fin + 1;
    else return d;
}

inline void Dijkstra(){
    for(int i = 2; i <= n; i++) dis[i] = INF;
    
    s.insert( {dis[1], 1} );
    while(!s.empty()){
        auto itr = s.begin();
        int v = itr->S;
        ll d = BS(v);

        s.erase(itr);

        for(auto x: adj[v]){
            int u = x.F;
            ll w = x.S;

            if(dis[u] > d + w){
                s.erase({dis[u], u});
                dis[u] = d + w;
                s.insert({dis[u], u});
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
    }

    for(int i = 1; i <= n; i++){
        int k; cin >> k;
        find_intr(k, i);
    }   

    Dijkstra();
    cout << (dis[n] < INF ? dis[n] : -1);
}