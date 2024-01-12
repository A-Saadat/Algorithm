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

const int MAX = 1e2 + 10; 
const int INF = 1e9 + 7; 

struct dom{int u; int idx; char c;};

vector<dom> adj[10];
int mark[MAX], pnt[10];
vector<pair<int, char>> ans;

void dfs(int v){
    for(int i = pnt[v]; i < adj[v].size(); i++){
        int u = adj[v][i].u, idx = adj[v][i].idx; char c = adj[v][i].c;
        pnt[v]++;
        if(mark[idx]) continue;
        mark[idx] = 1;
        dfs(u);
        ans.pb( {idx, c} );
    }
}

main()
{IOS;

    int n; cin >> n;
    int def = 0;
    for(int i = 1; i <= n; i++){
        int x, y; cin >> x >> y;
        adj[x].pb( {y, i, '-'} );
        adj[y].pb( {x, i, '+'} );
        def = x;
    }

    vector<int> odd;
    for(int i = 0; i <= 6; i++){
        if(adj[i].size() % 2) odd.pb(i);
    }

    if(odd.size() == 0 || odd.size() == 2){
        dfs((odd.size() == 0 ? def : odd.back()));

        bool isOk = 1;
        for(int i = 1; i <= n; i++)
            if(!mark[i]) isOk = 0;

        if(!isOk) cout << "No solution\n";
        else for(auto u: ans) cout << u.F << " " << u.S << endl;
    } 
    else{
        cout << "No solution\n";
    }

}