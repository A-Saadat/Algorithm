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

const int MAX = 1e3 + 1; 
const int M = 499500 + 1;
const int INF = 1e9 + 7; 

int n, q, m;
pair<int, int> edg_num[M];
vector<pair<int, int>> edg, que;

pair<int, int> mlf[MAX];
vector< pair<int, int> > cmp[MAX];
int sz[MAX];

struct DSU{
    void change_color(int u){
        for(int i = 0; i < cmp[mlf[u].F].size(); i++){
            cmp[mlf[u].F][i].S = 3 - cmp[mlf[u].F][i].S;
        }
    }

    void merge(int v, int u){
        u = mlf[u].F, v = mlf[v].F;
        if(sz[u] > sz[v]) swap(u, v);
        
        for(auto x: cmp[u]){
            cmp[v].pb(x); 
            mlf[x.F] = {v, x.S};
            sz[v]++;
        }
        cmp[u].clear();
        sz[u] = 0;
    }

    int Main(){
        for(int i = 1; i <= n; i++) mlf[i] = {i, 1}, sz[i] = 1, cmp[i] = { {i, 1} };

        for(auto x: que){
            int ii = x.S, w = x.F;
            int v = edg_num[ii].F, u = edg_num[ii].S;

            if(sz[mlf[v].F] < sz[mlf[u].F]) swap(v, u);
            if(mlf[v].F != mlf[u].F){
                if(mlf[v].S == mlf[u].S) change_color(u);
                merge(v, u);
            }
            else
                if(mlf[v].S == mlf[u].S) return w;
        }

        return -1;
    }

} dsu;

main()
{IOS;

    cin >> n >> m >> q;    
    for(int i = 1; i <= m; i++){
        int x, y, w; cin >> x >> y >> w;
        edg_num[i] = {x, y};
        edg.pb({w, i});
    }
    sort(all(edg), greater<pair<int, int>>());

    for(int i = 1; i <= q; i++){
        int l, r; cin >> l >> r; que.clear();
        for(auto x: edg){
            int w = x.F, idx = x.S;
            if(idx >= l && idx <= r) que.pb({w, idx});
        }
        cout << dsu.Main() << endl;
    } 
}