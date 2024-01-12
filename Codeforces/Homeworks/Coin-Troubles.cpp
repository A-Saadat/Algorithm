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

const int MAX = 300 + 10; 
const int M = 1e5 + 10;
const int MOD = 1e9 + 7; 

int a[MAX], mark[MAX], price[MAX], dp[MAX][M]; 
vector<int> adj[MAX];
int n, q, sum, cnt;

void dfs(int v, int p){
    mark[v] = 1; price[v] = price[p] + a[v];
    for(int u: adj[v]){
        dfs(u, v);
    }

    sum -= ++cnt * a[v];
}

main()
{IOS;

    cin >> n >> q >> sum;
    for(int i = 1; i <= n; i++) cin >> a[i];

    vector<bool> isFirst(n, 1);
    for(int i = 1; i <= q; i++){
        int b, c; cin >> b >> c;
        isFirst[c] = 0;
        adj[b].pb(c);
    }

    for(int i = 1; i <= n; i++){
        if(isFirst[i]){
            cnt = -1;
            dfs(i, 0);
        }
    }

    for(int i = 1; i <= n; i++){
        if(!mark[i] || sum < 0){
            cout << 0 << endl;
            exit(0);
        }
    }

    dp[0][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= sum; j++){
            dp[i][j] = dp[i - 1][j];
            if(j - price[i] >= 0) dp[i][j] = (dp[i][j] + dp[i][j - price[i]]) % MOD;
        }
    }    

    cout << dp[n][sum] << endl;

}