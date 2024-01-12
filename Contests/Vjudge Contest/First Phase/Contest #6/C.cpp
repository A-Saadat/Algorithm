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


// ? -------------------- SUBTASK-1 -------------------- ? \\

int hig[MAX], val[MAX]; 
vector<int> adj[MAX];
int a, b, c, ro;
int ans = 0;

void _dfs(int v){
    for(int u: adj[v]){
        hig[u] = hig[v] + 1;
        _dfs(u);
    }
}

void dfs_upd(int v){
    for(int u: adj[v]){
        if(hig[u] >= a && hig[u] <= b) 
            val[u] += c * (hig[u] - hig[ro]);
        dfs_upd(u);
    }
}

void dfs_ans(int v){
    if(hig[v] >= a && hig[v] <= b) ans += val[v];
    for(int u: adj[v])
        dfs_ans(u);
}

main()
{IOS;

    int n, q; cin >> n >> q;
    for(int i = 2; i <= n; i++){
        int x; cin >> x; ++x;
        adj[x].pb(i);
    }

    _dfs(1);

    while(q--){
        string type; cin >> type;
        if(type == "UPDATE"){
            cin >> ro >> a >> b >> c;
            ++ro;
            dfs_upd(ro);
        }
        else{
            cin >> ro >> a >> b;
            ++ro;
            ans = 0;
            dfs_ans(ro);
            cout << ans << endl;
        }

    }

}