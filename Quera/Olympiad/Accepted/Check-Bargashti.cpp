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

const int MAX = 5e4 + 10; 
const int INF = 1e9 + 7; 

int dis[MAX];
int n, m, t, k; 
vector<pair<int, int>> adj[MAX];
int ans;

set<pair<int, int>> s;
inline void Dijkstra(int r){
    if(dis[r] >= k) ans--;
    dis[r] = 0;
    
    s.insert({0, r});
    while(!s.empty()){
        auto [d, v] = *s.begin();
        s.erase(s.begin());
        
        for(auto [u, w]: adj[v]){
            if(dis[u] > d + w && d + w < k){
                if(dis[u] >= k) ans--;
                s.erase({dis[u], u});
                dis[u] = d + w;
                s.insert({dis[u], u});
            }
        }
    }
}

signed main()
{IOS;

    cin >> n >> m >> t >> k; ans = n;
    for(int i = 1; i <= m; i++){
        int x, y, w; cin >> x >> y >> w;
        adj[x].pb({y, w});
        adj[y].pb({x, w});
    }

    for(int i = 1; i <= n; i++) dis[i] = INF;

    for(int i = 1; i <= t; i++){
        int a; cin >> a;
        Dijkstra(a);
        cout << ans << endl;
    }

}