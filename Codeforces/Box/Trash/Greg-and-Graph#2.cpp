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

const int MAX = 5e2 + 100; 
const ll INF = 1LL * 1000 * 1000 * 1000 * 1000 * 1000 * 1000; 

vector< pair<int, ll> > adj[MAX];
ll edg[MAX][MAX];
int mark[MAX], add[MAX];
int n;
ll dis[MAX][MAX];
set< pair<ll, int> > s;


inline void Dijkstra(int v){
    for(int i = 1; i <= n; i++) 
        dis[v][i] = INF;
    
    dis[v][v] = 0;
    s.insert( {dis[v][v], v} );
    while(!s.empty()){
        auto itr = s.begin();
        int v = itr->S;
        ll d = itr->F;
        s.erase(itr);

        cout << "v = " << v << " - d = " << d << ": \n";
        for(auto x: adj[v]){
            int u = x.F;
            ll w = x.S;

            if(!mark[u]) continue;
            if(dis[v][u] > d + w){
                s.erase( {dis[v][u], u} );
                dis[v][u] = d + w;
                s.insert( {dis[v][u], u} );
            }
        }
    }

}

inline int Solve(int v){
    Dijkstra(v);
    // for(int i = 1; i <= n; i++){ // ? dis i -> v
    //     if(i == v || !mark[i]) continue;

    //     for(int j = 1; j <= n; j++){
    //         if(j == v || !mark[j] || i == j) continue;

    //         ll val = min(dis[i][j] + edg[j][v], edg[i][v]);
    //         dis[i][v] = min(dis[i][v], val);
    //     }

    //     // err_dis(i, v);
    //     // cout << "\n--------------------------\n";
    // }
    
}
main()
{IOS;

    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> edg[i][j];
            if(i == j) continue;
            adj[i].pb( {j, edg[i][j]} );
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++) dis[i][j] = INF;
    }

    for(int i = 1; i <= n; i++) cin >> add[i];

    // for(int i = n; i >= 1; i--) {
    //     int a = add[i];
    //     mark[a] = 1;
    //     Solve(a);

    //     // for(int j = 1; j <= n; j++) err_dis(a, j);
    //     // cout << "\n--------------------\n";
    // }

    mark[3] = 1;
    mark[2] = 1;
    mark[1] = 1;
    Solve(1);

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++) err_dis(i, j);
        cout << "\n-------------------\n";
    }

}
// for(int i = 1; i <= n; i++) {
//     cout << i << ": ";
//     for(auto u: adj[i]) cout << "{" << u.F << ", " << u.S << "} | ";
//     cout << endl;
// }