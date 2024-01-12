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

const int MAX = 3e5 + 10; 
const int INF = 1e9 + 7; 

char a[MAX]; 
vector<pair<int, int>> adj[MAX];
int dp[MAX];
int n; 

void dfs(int v){
    for(auto u: adj[v]){
        dfs(u.F);
        if(u.S == 0) dp[v] = min(dp[v], dp[u.F] + !(a[v] == 'L'));
        else dp[v] = min(dp[v], dp[u.F] + !(a[v] == 'R'));
    } 
}

void clear_arr(){
    for(int i = 1; i <= n + 1; i++) dp[i] = INF;
    for(int i = 1; i <= n + 1; i++) adj[i].clear();
}

main()
{IOS;

    int t; cin >> t;
    while(t--){
        cin >> n;
        clear_arr();
        for(int i = 1; i <= n; i++) cin >> a[i];
        for(int i = 1; i <= n; i++){
            int lc, rc; cin >> lc >> rc;
            if(lc) adj[i].pb({lc, 0});
            if(rc) adj[i].pb({rc, 1});

            if(!lc && !rc) dp[i] = 0;
        }

        dfs(1);
        cout << dp[1] << endl;
    }

}