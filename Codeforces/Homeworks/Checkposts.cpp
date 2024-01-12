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
const int MOD = 1e9 + 7; 

vector<int> adj[MAX], rev_adj[MAX], mini(MAX, MOD); 
int a[MAX], mark[MAX];
int n, m, now;
map<int, int> cnt[MAX];

vector<int> v;
void dfs(int x){
    mark[x] = 1;
    for(int u: adj[x]) if(!mark[u]) dfs(u);
    v.pb(x);
}

void sfd(int x){
    mark[x] = 1; cnt[now][a[x]]++; mini[now] = min(mini[now], a[x]);
    for(int u: rev_adj[x]) if(!mark[u]) sfd(u);
}

main()
{IOS;

    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i]; 
    cin >> m;
    for(int i = 1; i <= m; i++){
        int x, y; cin >> x >> y;
        adj[x].pb(y);
        rev_adj[y].pb(x);   
    }

    for(int i = 1; i <= n; i++) if(!mark[i]) dfs(i);
    reverse(all(v));

    memset(mark, false, sizeof mark);
    for(int u: v) if(!mark[u]) now++, sfd(u);

    int cost = 0, ways = 1;
    for(int i = 1; i <= now; i++){
        ways = 1LL * ways * cnt[i][mini[i]];
        ways = ways % MOD;
        cost += mini[i];
    }

    cout << cost << " " << ways << endl;

}