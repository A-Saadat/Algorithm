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
#define err_dp(i, j) cout << "dp[" << i << "][" << (1 << j) << "] = " << dp[i][j] << endl; 
#define err_par(i, j) cout << "par[" << i << "][" << (1 << j) << "] = " << par[i][j] << endl; 
#define int long long 
typedef vector<int> vi;

const int MAX = 2e5 + 10; 
const int INF = 1e9 + 7; 

vector< pair<int, int> > adj[MAX];
vector< pair< pair<int, int>, int > > edg;
set< pair<int, pair<int, int>> > s;
set< pair<int, int> > MST_edg;

int dp[MAX][30], par[MAX][30];
int dep[MAX], sz[MAX], pp[MAX];
int MST;

void dfs(int v, int p){
    for(int i = 1; i <= 22; i++){
        par[v][i] = par[ par[v][i - 1] ][i - 1];
        dp[v][i] = max(dp[v][i - 1], dp[ par[v][i - 1] ][i - 1]);
    }

    for(auto x: adj[v]){
        int u = x.F;
        int w = x.S;
        
        if(u == p) continue;

        par[u][0] = v;
        dp[u][0] = w;
        dep[u] = dep[v] + 1;

        dfs(u, v);
    }
}

inline int Find_Heaviest_edge(int v, int u){
    if(dep[u] < dep[v]) swap(u, v);


    int maxi = 0;
    for(int i = 22; i >= 0; i--){
        int x = par[u][i];

        if(dep[x] < dep[v]) continue;

        maxi = max(maxi, dp[u][i]);
        u = par[u][i];
    }

    if(u == v) return maxi;

    for(int i = 22; i >= 0; i--){
        int x = par[u][i], y = par[v][i];

        if(x == y) continue;

        maxi = max(maxi, max(dp[u][i], dp[v][i]));
        u = x;
        v = y;
    }

    return max( maxi, max( dp[u][0], dp[v][0] ) );

}

int Find_par(int A){
    if(A == pp[A]) return A;
    return pp[A] = Find_par( pp[A] );
}

inline void merge(int A, int B){
    A = Find_par(A), B = Find_par(B);
    if(sz[A] > sz[B]) swap(A, B);

    pp[A] = B;
    sz[B] += sz[A];
}

main()
{IOS;

    int n, m; cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int x, y, val; cin >> x >> y >> val;
        edg.pb( {{x, y}, val} );
        s.insert( {val, {x, y}} );
    }

    for(int i = 1; i <= n; i++) pp[i] = i, sz[i] = 1;

    int k = 0;
    fort(itr, s){
        int v = itr->S.F, u = itr->S.S, val = itr->F;
        
        if(Find_par(v) == Find_par(u)) continue;
        merge(v, u);

        adj[v].pb( {u, val} );
        adj[u].pb( {v, val} );
        MST += val;
        MST_edg.insert( {v, u} );
        MST_edg.insert( {u, v} );

        ++k;
        if(k == n - 1) break;
    }

    dep[1] = 1;
    dfs(1, 0);
    
    for(auto x: edg){
        int v = x.F.F, u = x.F.S, val = x.S;
        if( MST_edg.count({v, u}) ) cout << MST << endl;
        else{
            int ww = Find_Heaviest_edge(v, u);
            cout << MST - ww + val << endl;
        }
    }


}