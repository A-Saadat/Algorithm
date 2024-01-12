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

vector< pair<int, ll> > adj[MAX]; 
ll dis[MAX];
set< pair<ll, int> > s;
int n, m; 
vector<int> ans;
int par[MAX];

inline void Dijkstra(){
    for(int i = 1; i <= n; i++) dis[i] = INF;
    dis[n] = 0;

    s.insert( {dis[n], n} );
    while(!s.empty()){
        auto itr = s.begin();
        int v = itr->S;
        ll d = itr->F;
        s.erase(itr);

        for(auto x: adj[v]){
            int u = x.F;
            ll w = x.S;

            if(dis[u] > w + d){
                s.erase( {dis[u], u} );
                dis[u] = w + d;
                s.insert( {dis[u], u} );
                par[u] = v;
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

    Dijkstra();

    int p = 1;
    while(p != n){
        if(p == 0) { cout << -1 << endl; return 0; }
        
        ans.pb(p);
        p = par[p];
    }   

    ans.pb(n);
    for(int u: ans) cout << u << ' ';
}