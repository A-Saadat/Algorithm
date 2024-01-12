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
typedef vector<int> vi;

const int MAX = 2e5 + 10; 
const int INF = 1e9 + 7; 

vector<int> adj[MAX]; 
bool mark[MAX];
int entry_node, dep[MAX];
int n, a, b; 

void dfs(int v, int p){
    mark[v] = 1;
    for(int u: adj[v]){
        if(u != p && mark[u] && !entry_node) {entry_node = u; return;}
        if(u != p && !mark[u]) dfs(u, v);
    }
}

inline void bfs(){
    queue<int> q;
    q.push(entry_node); 
    while(!q.empty()){
        int v = q.front(); mark[v] = 1;
        for(int u: adj[v]){
            if(mark[u]) continue;
            dep[u] = dep[v] + 1;
            mark[u] = 1;
            q.push(u);
        }
        q.pop();
    }
}

inline void clear_arr(){
    memset(mark, 0, sizeof(mark));
    memset(dep, 0, sizeof(dep));
    for(int i = 1; i <= n; i++){
        adj[i].clear();
    }
    entry_node = 0;
}

main()
{IOS;

    int t; cin >> t;
    while(t--){
        cin >> n >> a >> b;
        clear_arr();

        for(int i = 1; i <= n; i++){
            int x, y; cin >> x >> y;
            adj[x].pb(y);
            adj[y].pb(x);
        }

        dfs(b, 0);
        memset(mark, 0, sizeof(mark));
        bfs();

        if(a == b || dep[a] <= dep[b]) puts("NO");
        else puts("YES"); 
    }

}