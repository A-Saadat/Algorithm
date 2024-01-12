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

set<int> adj[MAX];
int mark[MAX];

int cycle, path, n;
bool isCycle;

void dfs(int v, int p){
    mark[v] = 1;
    for(int u: adj[v]){
        if(u != p && mark[u]) isCycle = 1;
        if(!mark[u]) dfs(u, v); 
    }
}

inline void clear_arr(){
    cycle = 0;
    path = 0;
    isCycle = 0;
    memset(mark, 0, sizeof(mark));
    for(int i = 1; i <= n + 10; i++) adj[i].clear();
}

main()
{IOS;

    int t; cin >> t;
    while(t--){
        cin >> n; clear_arr();
        for(int i = 1; i <= n; i++){
            int x; cin >> x;
            adj[i].insert(x);
            adj[x].insert(i);
        }

        for(int i = 1; i <= n; i++){
            if(mark[i]) continue;

            dfs(i, 0);
            if(isCycle) cycle++;
            else path++;

            isCycle = 0;
        }

        cout << cycle + (path > 0) << " " << cycle + path << endl;
    }

}