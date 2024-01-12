/// ? ربات
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

const int MAX = 500 + 10; 
const int INF = 1LL * 1000 * 1000 * 1000 * 1000 * 1000 * 1000; 

int r[MAX][MAX], d[MAX][MAX], l[MAX][MAX], u[MAX][MAX], mini[MAX][MAX]; 
vector<pair< pair<int, int> , int>> adj[MAX][MAX];
int dis[MAX][MAX];
int n, m;

int ans = 0;

set<pair<int, pair<int, int>>> s;
inline void Dijkstra(){
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) dis[i][j] = INF;

    dis[1][1] = 0;
    s.insert({dis[1][1], {1, 1}});

    while(!s.empty()){
        auto [i, j] = s.begin()->S;
        s.erase(s.begin());


        for(auto x: adj[i][j]){
            auto [u1, v1] = x.F;
            int w = x.S;

            if(dis[u1][v1] > dis[i][j] + w){
                s.erase({ dis[u1][v1], {u1, v1} });
                dis[u1][v1] = dis[i][j] + w;
                s.insert({ dis[u1][v1], {u1, v1} });
            }
        }

    }
}

signed main()
{IOS;

    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) cin >> r[i][j], mini[i][j] = r[i][j];

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) cin >> d[i][j], mini[i][j] = min(mini[i][j], d[i][j]);

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) cin >> l[i][j], mini[i][j] = min(mini[i][j], l[i][j]);

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) cin >> u[i][j], mini[i][j] = min(mini[i][j], u[i][j]);

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            r[i][j] -= mini[i][j];
            d[i][j] -= mini[i][j];
            l[i][j] -= mini[i][j];
            u[i][j] -= mini[i][j];
            ans += mini[i][j];

            adj[i][j].pb( {{i, j + 1}, r[i][j]} );
            adj[i][j].pb( {{i + 1, j}, d[i][j]} );
            adj[i][j].pb( {{i, j - 1}, l[i][j]} );
            adj[i][j].pb( {{i - 1, j}, u[i][j]} );
        }
    }

    Dijkstra();

    cout << ans + dis[n][m];

}