#include <bits/stdc++.h> 
using namespace std; 

#define IOS ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0) 
#define pb push_back 
#define elif else if 
#define F first 
#define S second 
#define all(v) v.begin(), v.end() 
#define err_dp(i, j) cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << endl; 
#define err_dp2(i, j) cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << " || ";

const int MAX = 5e3 + 10;
int n, m, n1, n2, n3, a, b;

vector<int> adj[MAX];
vector< pair<int, int> > cc, ncc[MAX];
int col[MAX], dp[MAX][MAX];

bool isOk = 1;
int idx;
void dfs(int v, int c){
    ncc[idx].pb( {v, c} ); col[v] = c;
    if(c == 1) a++;
    else b++;

    for(int u: adj[v]){
        if(col[v] == col[u]) isOk = 0;
        if(col[u]) continue;
        dfs(u, 3 - c);
    }
}

main()
{IOS;
    cin >> n >> m;
    cin >> n1 >> n2 >> n3;
    for(int i = 1; i <= m; i++){
        int x, y; cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    for(int i = 1; i <= n; i++){
        if(col[i]) continue;
        a = 0, b = 0;
        dfs(i, 1);
        ++idx;
        cc.pb( {a, b} );
    }

    for(int i = 1; i <= idx; i++) {
        cout << i << ": \n";
        for(auto u: ncc[i]) cout << u.F << " with color " << u.S << endl;
        cout << "\n-------------------\n";
    }

}