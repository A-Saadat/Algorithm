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
map< pair<int, int>, int > mp;
ll dis[MAX];
set< pair<int, int> > s; 
int n, m, a[MAX];
vector<int> v;

inline void Dijkstra(){
    for(int i = 1; i <= n; i++) dis[i] = INF;

    dis[1] = mp[ {1, 0} ]; s.insert( {dis[1], 1} );
    while(!s.empty()){
        auto itr = s.begin();
        s.erase(itr);
        int v = itr->S;
        ll d = itr->F;

        for(auto x: adj[v]){
            int u = x.F;
            ll w = x.S;

            ll m = mp[ {u, (d + w)} ];
            ll val = d + w;

            if(u == n){
                if(dis[u] > val){
                    s.erase( {dis[u], u} );
                    dis[u] = val;
                    s.insert( {dis[u], u} );
                }
            }
            else{
                if(dis[u] > val + m){
                    s.erase( {dis[u], u} );
                    dis[u] = val + m;
                    s.insert( {dis[u], u} );
                }
            }
        }
    }
}

inline void trv(){
    for(int i = 1; i <= n; i++){
        v.clear();
        int k; cin >> k;
        for(int j = 1; j <= k; j++) cin >> a[j];

        if(k == 0) continue;

        int id = a[1]; v.pb(id);
        for(int j = 2; j <= k; j++){
            if(abs(a[j] - a[j - 1]) > 1) id = a[j];
            v.pb(id);
        }

        // cout << i << ": ";
        for(int u: v) mp[ {i, u} ]++;
        // cout << "\n-------------------\n";
    }
}

main()
{IOS;

    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y, val; cin >> x >> y >> val;
        adj[x].pb( {y, val} );
        adj[y].pb( {x, val} );
    }

    trv();
    Dijkstra();

    // for(int i = 1; i <= n; i++) cout << i << ": " << dis[i] << endl;
    
    // fort(itr, mp) cout << itr->F.F << ", " << itr->F.S << " = " << itr->S << endl;

    // cout << "\n--------------\n";
    cout << (dis[n] < INF ? dis[n] : -1);

}