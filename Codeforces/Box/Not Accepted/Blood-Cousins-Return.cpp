#include <bits/stdc++.h> 
using namespace std; 
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")

#define IOS ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0) 
#define fort(itr,map) for(auto itr = map.begin(); itr != map.end(); ++itr) 
#define pb push_back 
#define elif else if 
#define F first 
#define S second 
#define all(v) v.begin(), v.end() 
#define uni(v) sort(all(v)), v.erase(unique(all(v)), v.end())

const int MAX = 1e5 + 1; 
const int INF = 1e9 + 7; 

map<int, set<int>> s[MAX];
map<string, int> mp;
set<int> s1, s2;

vector<int> adj[MAX];
vector<pair<int, int>> que[MAX];

int hig[MAX], ans[MAX], name[MAX];

void dfs(int v){
    int maxi = 0, id = 0;
    for(int u: adj[v]){
        hig[u] = hig[v] + 1;
        dfs(u);
        if(s[u].size() > maxi) maxi = s[u].size(), id = u;
    }

    for(int u: adj[v]){
        if(u == id) continue;
        for(auto itr: s[u]){
            int h = itr.F;
            auto it = s[id][h];
            
            s1 = itr.S, s2 = it;
            if(s1.size() > s2.size()) swap(s1, s2);
            for(auto iii: s1) s2.insert(iii);

            s[id][h] = s2;
        }
    }
    swap(s[v], s[id]);

    // s[v] = s[id];
    
    s[v][hig[v]] = {name[v]};

    for(auto x: que[v]){
        int idx = x.F, h = x.S + hig[v];
        ans[idx] = s[v][h].size();
    }
}
vector<int> roots;

main()
{IOS;

    int n; cin >> n; string str; int par; 
    for(int i = 1; i <= n; i++){
        cin >> str;
        cin >> par;

        if(!mp[str]) mp[str] = i;
        
        adj[par].pb(i);
        name[i] = mp[str];

        if(par == 0) roots.pb(i);
    }

    int q; cin >> q;
    for(int i = 1; i <= q; i++){
        int v, k; cin >> v >> k;
        que[v].pb({i, k});
    }

    // fort(itr, mp) cout << itr->F << ", " << itr->S << endl;
    for(int u: roots) dfs(u);
    for(int i = 1; i <= q; i++) cout << ans[i] << '\n';
}