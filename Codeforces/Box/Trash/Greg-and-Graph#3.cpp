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
const int MX = 1e9 + 7;

vector< pair<int, int> > adj[MAX]; 
ll dis[MAX][MAX];
int edg[MAX][MAX];
int qu[MAX], mark[MAX];
vector<ll> ans;
set< pair<ll, int> > s;

int n;

void Dijkstra(int v){

    dis[v][v] = 0;
    s.insert( {dis[v][v], v} );
    while(!s.empty()){
        auto itr = s.begin();
        int v = itr->S;
        ll d = itr->F;
        s.erase(itr);
        
        for(auto x: adj[v]){
            int u = x.F;
            int w = x.S;
            if(!mark[u]) continue;

            if(dis[v][u] > d + w){
                s.erase( {dis[v][u], u} );
                dis[v][u] = d + w;
                s.insert( {dis[v][u], u} );
            }
        }
    }
}

inline int Slv(int v){
    ll sum = 0;
    Dijkstra(v);

    for(int i = 1; i <= n; i++){ // ? dis[i][v]

        if(!mark[i] || i == v) continue;

        int mini = MAX;

        for(int j = 1; j <= n; j++){

            if(!mark[j] || j == v) continue;

            int dd = dis[i][j] + edg[j][v];
            mini = min(mini, dd);

            // cout << "the dis[" << i << "][" << v << "] = " << dis[i][v] << " might pass through " << j;  
            // cout << " if dis[" << i << "][" << j << "] = " << dis[i][j] << " + edg[" << j << "][" << v << "] = " << edg[j][v] << " is min\n";
        }

        dis[i][v] = mini;
        // err_dis(i, v);
        // cout << "\n--------------\n";

    }

    for(int i = 1; i <= n; i++){ // ? dis[i][j]
        if(!mark[i] || i == v) continue;

        for(int j = 1; j <= n; j++){
            if(!mark[j] || j == v) continue;

            dis[i][j] = min(dis[i][j], dis[i][v] + dis[v][j]);
            // err_dis(i, j);

            // cout << "dis[" << i << "][" << j << "] = " << dis[i][j] << " might Update from dis[" << i << "][" << v << "] = ";
            // cout << dis[i][v] << " + dis[" << v << "][" << j << "] = " << dis[v][j] << endl; 
        }
        // cout << "\n-------------\n";
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            sum += (dis[i][j] < INF ? dis[i][j] : 0);
        }
    }

    return sum;
}

main()
{IOS;

    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> edg[i][j];
            if(i == j) continue;
            adj[i].pb( {j, edg[i][j]} );
            dis[i][j] = INF;
        }
    }

    for(int i = 1; i <= n; i++) cin >> qu[i];
    mark[ qu[n] ] = 1; ans.pb(0);

    // dis[2][3] = 400;
    // mark[2] = 1;

    for(int i = n - 1; i >= 1; i--) {
        mark[ qu[i] ] = 1;
        ans.pb( Slv( qu[i] ) );
        // cout << Slv( qu[i] ) << endl;
        // break;

        // for(int j = 1; j <= n; j++) err_dis( qu[i], j );
        // cout << "\n--------------**************---------------------\n";

        // if(i == n - 2)
        //     break;

    }

    reverse(all(ans));
    for(int u: ans) cout << u << ' ';

}
    // for(int i = 1; i <= n; i++){
    //     cout << i << ": ";
    //     for(auto u: adj[i]) cout << "{" << u.F << ", " << u.S << "} ";
    //     cout << "\n---------------\n"; 
    // }