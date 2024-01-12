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

const int MAX = 2e5 + 10; 
const int INF = 1LL * 1000 * 1000 * 1000 * 1000 * 1000 * 1000; 

vector<pair<int, int>> adj[MAX];
int n, m; 

int dis[MAX][3][3]; 
set< pair< int, array<int, 3> >> s;
int mark[MAX][3][3];

inline void update(int d, int v, int mx, int mn){
    s.erase({dis[v][mx][mn], {v, mx, mn} });
    dis[v][mx][mn] = d;
    s.insert({d, {v, mx, mn} });
}

inline void Dijkstra(){
    for(int i = 1; i <= n; i++) dis[i][0][0] = INF, dis[i][1][0] = INF, dis[i][0][1] = INF, dis[i][1][1] = INF;

    dis[1][0][0] = 0;
    s.insert( {dis[1][0][0], {1, 0, 0} } );
    while(!s.empty()){
        auto [v, mx, mn] = s.begin()->S; 
        s.erase(s.begin());

        for(auto [u, w]: adj[v]){
            if(dis[u][mx][mn] > dis[v][mx][mn] + w) update(dis[v][mx][mn] + w, u, mx, mn);

            if(mx == 0)
                if(dis[u][1][mn] > dis[v][mx][mn]) update(dis[v][mx][mn], u, 1, mn);

            if(mn == 0)
                if(dis[u][mx][1] > dis[v][mx][mn] + w + w) update(dis[v][mx][mn] + w + w, u, mx, 1);

            if(mx == 0 && mn == 0)
                if(dis[u][1][1] > dis[v][mx][mn] + w) update(dis[v][mx][mn] + w, u, 1, 1);

        }
    }
}

main()
{IOS;

    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int x, y, w; cin >> x >> y >> w;
        adj[x].pb({y, w});
        adj[y].pb({x, w});
    }    

    Dijkstra();

    for(int i = 2; i <= n; i++) cout << dis[i][1][1] << ' ';
}