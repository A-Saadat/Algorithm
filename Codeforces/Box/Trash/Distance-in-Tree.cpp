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
#define err_dp(i, j) cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << endl;
typedef long long int ll; 
typedef vector<int> vi;

const int MAX = 1e5 + 100; 
const int MX = 5e2 + 100;
const int INF = 1e9 + 7; 

vector<int> adj[MAX]; 
int dp[MAX][MX], hig[MAX]; // ? dp[i][j] = the number of vertix in the subtree of vertix i which has the height of j
int n, k, ans; 

void dfs(int v, int p){
    dp[v][0] = 1;
    for(int u: adj[v]){
        if(u == p) continue;
        
        dfs(u, v);

        dp[v][1]++;
        for(int i = 2; i <= k + 2; i++)
            dp[v][i] += dp[u][i - 1];
    }
}

// void Solve(int v){
//     // for(int i = 0; i <= k; i++){
//     //     err_dp(v, i);
//     // }
//     // cout << "\n-------------------\n";
//     for(int u: adj[v]){
//         for(int i = 0; i <= k - 2; i++){
//             ans += dp[u][i] * (dp[v][k - i - 1] - dp[u][k - i - 2]);
//         }
//         // cout << "\n-------------------\n";
//     }
// }

main()
{IOS;

    cin >> n >> k;
    for(int i = 1; i < n; i++){
        int x, y; cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    dfs(1, 0);

    for(int i = 1; i <= n; i++)
        ans += dp[i][k];

    // Solve(2);

    for(int i = 1; i <= n; i++) Solve(i);

    cout << ans;
}