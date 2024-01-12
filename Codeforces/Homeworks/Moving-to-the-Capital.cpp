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
const int INF = 1e9 + 7; 

vector<int> adj[MAX]; 
int mark[MAX], dis[MAX], dp[MAX];
set< pair<int, int> > s;
int n, m; 

inline void bfs(){
    queue<int> q;
    q.push(1);

    while(!q.empty()){
        int v = q.front();
        mark[v] = 1;
        q.pop();

        for(int u: adj[v]){
            if(mark[u]) continue;

            dis[u] = dis[v] + 1;
            mark[u] = 1;
            q.push(u);
        }
    }
}

inline void clear_arr(){
    s.clear();
    for(int i = 1; i <= n; i++) mark[i] = 0;
    for(int i = 1; i <= n; i++) dp[i] = 0;
    for(int i = 1; i <= n; i++) dis[i] = 0;
    for(int i = 1; i <= n; i++) adj[i].clear();
}

main()
{IOS;

    int t; cin >> t;
    while(t--){
        cin >> n >> m;
        clear_arr();
        for(int i = 1; i <= m; i++){
            int x, y; cin >> x >> y;
            adj[x].pb(y);
        }

        bfs();
        for(int i = 1; i <= n; i++) s.insert( {-1 * dis[i], i} );
        fort(itr, s){
            int d = -1 * itr->F, v = itr->S;
            int mini = d;

            for(int u: adj[v]){
                if(dis[u] <= dis[v]) mini = min(mini, dis[u]);
                else mini = min(mini, dp[u]);
            }

            dp[v] = mini;
        }

        for(int i = 1; i <= n; i++) cout << dp[i] << ' ';
        cout << endl;
    }    

}