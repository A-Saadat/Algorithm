#include <bits/stdc++.h> 
using namespace std; 

#define IOS ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0) 
#define forn(i,k,n) for(int i = k; i < n; i++) 
#define fort(itr,map) for(auto itr = map.begin(); itr != map.end(); ++itr) 
#define pb push_back 
#define elif else if 
#define F first 
#define S second 
#define gcd __gcd 
#define all(v) v.begin(), v.end() 
#define uni(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define err_par(i, j) cout << "par[" << i << "][" << (1 << j) << "] = " << par[i][j] << endl; 
#define err_dp(i, j) cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << endl; 
typedef long long int ll; 
typedef vector<int> vi;

const int MAX = 1e6; 
const int MAXLg = 22; 
const int INF = 1e9 + 7; 

vector<int> adj[MAX];
int par[MAX][MAXLg];
int hig[MAX], prd[MAX]; 
int dp[MAX][200];
bool isAvail[200];

int n, k, b, a, p;

void dfs(int v, int p){
    par[v][0] = p;
    for(int i = 1; i <= 20; i++)
        par[v][i] = par[ par[v][i - 1] ][i - 1];

    for(int u: adj[v]){
        if(u == p) continue;

        hig[u] = hig[v] + 1;
        dfs(u, v);

        for(int i = 1; i <= k; i++){ // ? Update_dp
            int dv = dp[v][i];
            int du = dp[u][i];

            if(dv > 0 && du > 0)
                dp[v][i] = min(dv, du);
            else    
                dp[v][i] = max(dv, du);
        }
    }
}

int Solve(){
    int curr = a;
    bool f = false;
    for(int i = 20; i >= 0; i--){
        int pr = par[curr][i];
        if(!pr) continue;   

        // cout << "dp[" << pr << "][" << p << "] = " << dp[pr][p] << endl;
        if(dp[pr][p] == -1) curr = pr, f = true;
    }
    if(!f) return dp[curr][p];
    if(f) return dp[par[curr][0]][p];
}

main()
{IOS;

    cin >> n >> k >> b;
    for(int i = 1; i < n; i++){
        int x, y; cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= k; j++) dp[i][j] = -1;

    for(int i = 1; i <= n; i++){
        cin >> prd[i]; isAvail[ prd[i] ] = 1;
        dp[i][prd[i]] = i;
    } 


    int q; cin >> q;
    while(q--){
        cin >> a >> p;
        if(!isAvail[p]) {
            cout << "-1" << endl;
            return 0;
        }
        else{
            dfs(b, 0);
            cout << Solve() << endl;
        }
    }

}
// for(int i = 1; i <= n; i++){
//     for(int j = 1; j <= k; j++) err_dp(i, j);
//     cout << "\n-------------------\n";
// }