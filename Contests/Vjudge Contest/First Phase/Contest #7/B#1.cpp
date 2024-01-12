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

const int MAX = 1e5 + 10; 
const int INF = 1e9 + 7; 

vector<int> adj[MAX]; 
int mark[MAX];

int cnt;
void dfs(int v, int p){
    cnt++; mark[v] = 1;
    for(int u: adj[v]){
        if(mark[u]) continue;

        dfs(u, v);
    }
}

main()
{IOS;

    int n, m; cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int x, y; cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    for(int i = 1; i <= n; i++){
        if(mark[i]) continue;
        dfs(i, 0);
        cnt--;
    }

    cout << m - cnt << endl;
}