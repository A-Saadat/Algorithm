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

const int MAX = 1e6 + 10; 
const int INF = 1e9 + 7; 

struct edg{int l; int r; int w;};

int cmp[MAX], mark[MAX], dp[MAX], sum[MAX], tri_sum[MAX]; 
vector<edg> edges;
vector<pair<int, int>> adj[MAX];
vector<int> order, rev_adj[MAX];

int now = 0;
void dfs(int v){
    mark[v] = 1;
    for(auto u: adj[v]) if(!mark[u.F]) dfs(u.F);
    order.pb(v);
}

void sfd(int v){
    mark[v] = 1; cmp[v] = now;
    for(int u: rev_adj[v]) if(!mark[u]) sfd(u);
}

int BS(int x){
    int L = 1, R = 1e8;
    while(R - L > 1){
        int mid = (R + L) / 2;
        int res = (mid * (mid - 1)) / 2;
        if(x >= res) L = mid;
        else R = mid;
    }

    return L;
}

void DFS_SOLVE(int v){
    int maxi = 0;
    for(auto x: adj[v]){
        int u = x.F, w = x.S;
        dfs(u);
        maxi = max(maxi, dp[u] + w);
    }
    dp[v] = sum[v] + maxi;
}

main()
{IOS;

    int n, m; cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int x, y, w; cin >> x >> y >> w;
        edges.pb( {x, y, w} );
        adj[x].pb( {y, w} );
        rev_adj[y].pb(x);
    }
    int str; cin >> str;

    for(int i = 1; i <= n; i++) if(!mark[i]) dfs(i);
    reverse(all(order));
    memset(mark, 0, sizeof(mark));
    for(int u: order) if(!mark[u]) now++, sfd(u);

    for(int i = 1; i <= 5000; i++) tri_sum[i] = tri_sum[i - 1] + ((i * (i - 1)) / 2);
    // for(int i = 1; i <= 100; i++) cout << tri_sum[i] << " ";

    for(int i = 1; i <= n; i++) adj[i].clear();

    for(auto u: edges){
        int l = u.l, r = u.r, w = u.w;
        if(cmp[l] == cmp[r]){
            int idx = BS(w);

            sum[cmp[l]] = sum[cmp[l]] + (w * idx) - tri_sum[idx];
            // cout << "{" << l << ", " << r << ", " << w << "} -> " << w * idx - tri_sum[idx] << endl;
            
        }
        else adj[cmp[l]].pb({cmp[r], w});
    }

    // for(int i = 1; i <= now; i++){// cout << "sum[" << i << "] = " << sum[i] << endl;
    //     cout << i << ": ";
    //     for(auto u: adj[i]) cout << "{" << u.F << ", " << u.S << "} ";
    //     cout << "\n-------------\n";
    // }    
    

    // dp[now] = sum[now];
    DFS_SOLVE(1);
    // for(int i = now - 1; i >= 1; i--){
    //     int maxi = 0;
    //     for(auto x: adj[i]){
    //         int u = x.F, w = x.S;
    //         maxi = max(maxi, dp[u] + w);
    //         // dp[i] = sum[i] + 
    //     }
    //     dp[i] = sum[i] + maxi;
    //     // cout << "dp[" << i << "] = " << dp[i] << endl;
    // }

    cout << dp[cmp[str]] << endl;
}