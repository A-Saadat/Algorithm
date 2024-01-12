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

const int MAX = 500 + 100; 
const ll INF = 1LL * 1000 * 1000 * 1000 * 1000 * 1000 * 1000; 

vector< pair<int, int> > adj[MAX]; 
set< pair<int, int> > s;
int mark[MAX];
ll dis[MAX][MAX];
int n;

inline void Dijkstra(int v){
    for(int i = 1; i <= n; i++)
        dis[v][i] = INF;

    dis[v][v] = 0;
    s.insert( {dis[v][v], v} );
    while(!s.empty()){
        auto itr = s.begin();
        int vv = itr->S;
        ll d = itr->F;
        s.erase(itr);

        for(auto x: adj[vv]){
            int u = x.F;
            ll w = x.S;
            if(mark[u]) continue;

            if(dis[v][u] > d + w){
                s.erase( {dis[v][u], u} );
                dis[v][u] = d + w;
                s.insert( {dis[v][u], u} );
            }

            // cout << "{" << u << ", " << w << "}\n";
        }
    }

}

main()
{IOS;

    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int x; cin >> x;
            if(i == j) continue;
            adj[i].pb( {j, x} );
        }
    }    

    for(int id = 1; id <= n; id++){
        int x; cin >> x;
        
        for(int v = 1; v <= n; v++){
            if(mark[v]) continue;
            Dijkstra(v);
        } 

        ll sum = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(mark[i] || mark[j]) continue;

                sum += dis[i][j];
                // err_dis(i, j);
            }
            // cout << endl;
        }

        mark[x] = 1;
        // cout << "\n------------------------------------------\n";
        cout << sum << " ";
    }
    // for(int i = 1; i <= n; i++){
    //     cout << "\n-----------------\n";
    //     for(int j = 1; j <= n; j++) err_dis(i, j);
    // }
}

// for(int i = 1; i <= n; i++){
//     cout << i << ": ";
//     for(auto u: adj[i]) cout << "{" << u.F << ", " << u.S << "}, ";
//     cout << endl;
// }