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

const int MaxN = 5e3 + 100; 
const int MOD = 1e9 + 7; 

int mark[MaxN], dp[MaxN][MaxN]; 
vector<int> cc, adj[MaxN];
int sum, n;
set<int> ans;

void dfs(int v){
    ++sum; mark[v] = 1;
    for(int u : adj[v]) {
        if(mark[u]) continue;

        dfs(u);
    }
}

inline void Solve(){

    dp[1][cc[1 - 1]] = 1;
    int sz = cc.size();
    for(int i = 2; i <= sz; i++){
        for(int j = 1; j <= n; j++){
            
            if(j > cc[i - 1]) dp[i][j] = dp[i - 1][j] + dp[i - 1][j - cc[i - 1]];
            else dp[i][j] = dp[i - 1][j];

            
            if(dp[i][j] && j < n - 1) ans.insert(j);
        }
    }
    
}

inline void clear(){
    for(int i = 0; i <= cc.size(); i++)
        for(int j = 0; j <= n; j++) dp[i][j] = 0;
    
    memset(mark, 0, sizeof(mark));
    cc.clear();
}

main()
{IOS;

    cin >> n;
    for(int i = 1; i < n; i++){
        int x, y; cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    for(int i = 1; i <= n; i++){
        if(adj[i].size() == 1) continue;

        mark[i] = 1;
        for(int k = 1; k <= n; k++){
            if(mark[k]) continue;
            
            dfs(k);
            cc.pb(sum);
            sum = 0;
        }

        Solve();
        clear();
    }

    fort(itr, ans) ans.insert(n - 1 - *itr);

    cout << ans.size() << endl;
    fort(itr, ans) cout << *itr << ' ' << n - *itr - 1 << endl;

}