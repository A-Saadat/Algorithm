#include <bits/stdc++.h> 
using namespace std; 

#define forn(i,k,n) for(int i = k; i < n; i++) 
#define IOS ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0) 
#define pb push_back 
#define elif else if 
#define F first
#define S second 


const int MaxN = 1e6; 
const int MOD = 1e9 + 7; 

vector<int> adj[MaxN];
int beg[MaxN], endi[MaxN], S[MaxN]; // ? S = the number of vertices in the subtree of any vertex
int mark[MaxN];
vector< pair<int, int> > ans;

int t = 0;
void dfs(int v){
    ++t; beg[v] = t; mark[v] = 1;
    for(int u: adj[v]){
        if(mark[u]) continue;

        dfs(u);
    }

    endi[v] = t;
}

main()
{IOS;

    int n; cin >> n;
    forn(i,1,n){
        int x, y; cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    dfs(1);

    forn(i,1,n + 1) S[i] = endi[i] - beg[i];
    forn(i,1,n + 1){
        if(adj[i].size() == 2) cout << i << ": " << S[i] << endl;
            // ans.pb( {S[i], n - S[i] - 1} );
    }

    // cout << ans.size() << endl;
    // for(auto u: ans){
    //     cout << u.F << ' ' << u.S << endl;
    // }


}