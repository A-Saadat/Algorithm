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
#define err_dis(i, j) cout << "dis[" << i << "][" << j << "] = " << dis[i][j] << endl;
typedef long long int ll; 
typedef vector<int> vi;

const int MAX = 1e3 + 100; 
const ll INF = 1LL * 1000 * 1000 * 1000 * 1000 * 1000 * 1000; 

vector< pair<int, int> > adj[MAX], adj_2[MAX]; 
int n, m, uu, vv;
ll dis[MAX][MAX];
int tx[MAX], prc[MAX]; // ? tx[i] = the maximum distance that the taxi in vertix i can drive, prc[i] = the cost of the i-th ride
set< pair<ll, int> > s;
bool is;

inline void Dijkstra(int k){
    for(int i = 1; i <= n; i++)
        dis[k][i] = INF;
        
    dis[k][k] = 0;
    s.insert( {dis[k][k], k} );
    while(!s.empty()){
        auto itr = s.begin();
        int v = itr->S;
        ll d = itr->F;
        s.erase(itr);

        for(auto x: (!is ? adj[v] : adj_2[v])){
            int u = x.F;
            ll w = x.S;

            if(dis[k][u] > d + w){
                s.erase( {dis[k][u], u} );
                dis[k][u] = d + w;
                s.insert( {dis[k][u], u} );
            }
        }
    }
}

main()
{IOS;

    cin >> n >> m >> uu >> vv;
    for(int i = 1; i <= m; i++){
        int x, y, val; cin >> x >> y >> val;
        adj[x].pb( {y, val} );
        adj[y].pb( {x, val} );
    }

    for(int i = 1; i <= n; i++) cin >> tx[i] >> prc[i];

    for(int i = 1; i <= n; i++)
        Dijkstra(i);

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++) {
            if(i == j) continue;

            if(dis[i][j] <= tx[i]) 
                adj_2[i].pb( {j, prc[i]} );       
        }
    }
    is = 1;

    Dijkstra(uu);

    cout << (dis[uu][vv] < INF ? dis[uu][vv] : -1);
}