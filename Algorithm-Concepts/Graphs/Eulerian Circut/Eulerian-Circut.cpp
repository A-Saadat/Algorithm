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

const int MAX = 1e6; 
const int INF = 1e9 + 7; 

vector< pair<int, int> > adj[MAX]; 
int mark[MAX], pnt[MAX];
vector<int> cir;

void dfs(int v){
    for(int i = pnt[v]; i < adj[v].size(); i++){
        int u = adj[v][i].F, edg = adj[v][i].S;
        pnt[v]++;
        if(mark[edg]) continue;
        mark[edg] = 1;   
        dfs(u);   
        cir.pb(edg); 
    }
}

main()
{IOS;

    int n, m; cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int x, y; cin >> x >> y;
        adj[x].pb( {y, i} );
        adj[y].pb( {x, i} );
    }

    dfs(1);

    for(int u: cir) cout << u << ' ';

}