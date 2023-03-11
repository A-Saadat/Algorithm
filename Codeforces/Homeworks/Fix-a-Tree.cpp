// 57 54 46 
#include <bits/stdc++.h> 
using namespace std; 

#define forn(i,k,n) for(int i = k; i < n; i++) 
#define fort(itr,map) for(auto itr = map.begin(); itr != map.end(); ++itr) 
#define IOS ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0); 
#define pb push_back 
#define F first 
#define S second 
#define gcd __gcd 
#define elif else if 
#define all(v) v.begin(), v.end() 
#define uni(v) sort(all(v)), v.erase(unique(all(v)), v.end()) 
#define err(x) cout << '#' << x << ':' << ' ' << x << endl 
typedef long long int ll; 
typedef vector<int> vi;

const ll MaxN = 1e6; 
const ll INF = 1e9 + 7; 

int par[MaxN], mark[MaxN], G_mark[MaxN]; 
vector<int> adj[MaxN], ver;
int n, root;

void dfs(int v){
    mark[v] = 1;
    for(int u: adj[v]){
        if(!mark[u]) dfs(u);
    }
}

main()
{IOS;

    cin >> n;
    forn(i,1,n + 1){
        cin >> par[i];
        adj[ par[i] ].pb(i);
        adj[i].pb( par[i] );

        if(par[i] == i) root = i;
    }

    forn(i,1,n + 1){
        if(mark[i]) continue;

        int v = i;
        while(!G_mark[v]) {
            G_mark[v] = 1;
            v = par[v];
        }

        ver.pb(v);
        dfs(v);

    }

    if(root){
        cout << ver.size() - 1 << endl;
        for(int u: ver) par[u] = root;
    }
    else{
        cout << ver.size() << endl;
        root = ver[0];

        for(int u: ver) par[u] = root;
    }

    forn(i,1,n + 1) cout << par[i] << ' ';

}