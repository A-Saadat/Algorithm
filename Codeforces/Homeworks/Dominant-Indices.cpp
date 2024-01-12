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
// #define int long long 

const int MAX = 1e6 + 10; 
const int INF = 1e9 + 7; 

vector<int> adj[MAX]; 
set< pair<int, int> > s[MAX], rev_s[MAX]; // ? s = [h][cnt], rev_s = [cnt][h];
int hig[MAX];
int ans[MAX];

void dfs(int v, int par){
    for(int u: adj[v]){
        if(u == par) continue;
        hig[u] = hig[v] + 1;
        dfs(u, v);

        if(s[u].size() > s[v].size()){
            swap(s[u], s[v]);
            swap(rev_s[u], rev_s[v]);
        }   

        fort(itr, s[u]){
            int h = itr->F, cnt = itr->S;
            auto it = s[v].lower_bound({h, 0});
            pair<int, int> p = *it, rev_p = {p.S, p.F};
            s[v].erase(it);
            rev_s[v].erase(rev_s[v].lower_bound(rev_p));
            p.S += cnt;
            rev_p.F += cnt;
            s[v].insert(p);
            rev_s[v].insert(rev_p);
        }
    }

    s[v].insert({hig[v], 1});
    rev_s[v].insert({1, hig[v]});

    int cnt = rev_s[v].rbegin()->F;
    ans[v] = rev_s[v].lower_bound({cnt, 0})->S - hig[v];
}

main()
{IOS;

    int n; cin >> n;
    for(int i = 1; i < n; i++){
        int x, y; cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    hig[1] = 1;
    dfs(1, 0);

    for(int i = 1; i <= n; i++) cout << ans[i] << endl;
}