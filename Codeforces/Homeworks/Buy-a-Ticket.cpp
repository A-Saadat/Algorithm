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

ll a[MAX], dis[MAX]; 
vector< pair<int, ll> > adj[MAX];
set< pair<ll, int> > s;
bool mark[MAX];

int n, m; 
inline void dijkstra(){
    for(int i = 1; i <= n + 1; i++) dis[i] = INF;

    dis[n + 1] = 0;
    s.insert( {dis[n + 1], n + 1} );
    while(!s.empty()){
        auto itr = s.begin();
        int v = itr->S;
        ll d = itr->F;
        s.erase(itr);

        for(auto x : adj[v]){
            int u = x.F;
            ll w = x.S;
            
            if(dis[u] > d + w){
                s.erase( {dis[u], u} );
                dis[u] = d + w;
                s.insert( {dis[u], u} );
            }
        }
        
    }
}

main()
{IOS;

    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int x, y; cin >> x >> y;
        ll val; cin >> val;
        adj[x].pb( {y, (val * 2)} );
        adj[y].pb( {x, (val * 2)} );
    }

    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int i = 1; i <= n; i++){ // ? FAKE VERTIX
        adj[n + 1].pb( {i, a[i]} );
        adj[i].pb( {n + 1, a[i]} );
    }

    dijkstra();

    for(int i = 1; i <= n; i++) cout << dis[i] << ' ';
}