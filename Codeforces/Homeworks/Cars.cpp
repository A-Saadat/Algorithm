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

int n, m; 

int a[MAX]; 
vector<int> adj[MAX], rev_adj[MAX];
struct que{int t; int v; int u;};
vector<que> q;

int st[MAX], ft[MAX], mark[MAX], ori[MAX];
bool isBipar = 1;
vector<int> tout;

bool isFrs = 1; // ? it's determining whether is this the first time that we running dfs or not

int t;
void dfs(int v, int c){
    mark[v] = 1; st[v] = ++t; 
    if(isFrs) ori[v] = c;
    for(int u: adj[v]){
        if(ori[u] == c) isBipar = 0;
        if(mark[u]) continue;

        dfs(u, 3 - c);
    }

    ft[v] = t;
    tout.pb(v);
}

void sfd(int v){
    mark[v] = 1;
    for(int u: rev_adj[v]){
        if(mark[u]) continue;
        sfd(u);
    }
}

inline void clear(){
    for(int i = 0; i <= n + 6; i++) adj[i].clear();
    for(int i = 0; i <= n + 6; i++) mark[i] = 0;
    t = 0;
    tout.clear();
}

main()
{IOS;

    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int t, x, y; cin >> t >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
        q.pb({t, x, y});
    }

    for(int i = 1; i <= n; i++) if(!mark[i]) dfs(i, 1);  

    if(!isBipar) {puts("NO"); return 0;}

    clear();

    for(auto x: q){
        int t = x.t, v = x.v, u = x.u;
        if(t == 1){
            if(ori[v] == 1) adj[v].pb(u), rev_adj[u].pb(v);
            else adj[u].pb(v), rev_adj[v].pb(u); 
        }
        else{
            if(ori[v] == 2) adj[v].pb(u), rev_adj[u].pb(v);
            else adj[u].pb(v), rev_adj[v].pb(u);
        }
    }

    isFrs = 0;

    tout.clear();
    for(int i = 1; i <= n; i++) if(!mark[i]) dfs(i, 0);

    reverse(all(tout));

    for(int i = 1; i <= n; i++) mark[i] = 0;

    int mlf = 0;
    for(int i = 0; i < tout.size(); i++) if(!mark[tout[i]]){
        ++mlf;
        sfd(tout[i]);
    }

    vector<pair<int, int>> ans(MAX + 10);

    if(mlf < n) cout << "NO\n";
    else{
        cout << "YES\n";
        for(int i = 0; i < tout.size(); i++){
            ans[tout[i]] = {ori[tout[i]], i + 1};
        }

        for(int i = 1; i <= n; i++){
            char dir = (ans[i].F == 1 ? 'L' : 'R');
            int pos = ans[i].S;
            cout << dir << " " << pos << endl;
        }
    }

}