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
#define err(x) cout << '#' << x << ':' << ' ' << x << endl 
typedef long long int ll; 
typedef vector<int> vi;

const int MaxN = 1e6; 
const int MOD = 1e9 + 7; 

ll num[MaxN], n;
vector<ll> adj[MaxN]; 
pair<ll, ll> dp[MaxN]; // ? dp[x].F is for sum of increments and dp[x].S is for sum of decrements
 
inline void INPUT(){
    cin >> n;
    for(int i = 1; i < n; i++){
        int x, y; cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
 
    for(int i = 1; i <= n; i++) cin >> num[i];
}

void dfs(int v, int par){
    for(int u: adj[v]){
        if(u == par) continue;

        dfs(u, v);

        dp[v].F = max(dp[v].F, dp[u].F + (num[u] < 0 ? abs(num[u]) : 0) );
        dp[v].S = max(dp[v].S, dp[u].S + (num[u] > 0 ? num[u] : 0) );

    }
    num[v] = num[v] + (dp[v].F - dp[v].S);
}

main()
{IOS;

    INPUT();

    dfs(1, 0);

    cout << dp[1].F + dp[1].S + abs(num[1]) << endl;
}