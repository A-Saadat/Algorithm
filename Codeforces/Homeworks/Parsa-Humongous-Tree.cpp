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
typedef vector<int> vi;

const int MAX = 1e5 + 10; 
const int INF = 1e9 + 7; 

vector<int> adj[MAX];
int L[MAX], R[MAX]; 
int dp[MAX][5];

void dfs(int v, int p){
    for(int u: adj[v]){
        if(u == p) continue;

        dfs(u, v);
        dp[v][1] += max( abs(L[v] - L[u]) + dp[u][1], abs(L[v] - R[u]) + dp[u][2] );
        dp[v][2] += max( abs(R[v] - L[u]) + dp[u][1], abs(R[v] - R[u]) + dp[u][2] );
    }
}

inline void clear_Arr(int n){
    for(int i = 1; i <= n + 10; i++){
        dp[i][1] = 0; dp[i][2] = 0;
        L[i] = 0; R[i] = 0;
        adj[i].clear();
    } 
}

main()
{IOS;

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        clear_Arr(n);
        for(int i = 1; i <= n; i++)
            cin >> L[i] >> R[i];

        for(int i = 1; i < n; i++){
            int x, y; cin >> x >> y;
            adj[x].pb(y);
            adj[y].pb(x);
        }
        
        dfs(1, 0);

        cout << max(dp[1][1], dp[1][2]) << endl;
    }

}