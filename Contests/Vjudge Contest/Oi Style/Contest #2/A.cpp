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

const int MAX = 1e6; 
const int INF = 1e9 + 7; 

vector<int> adj[MAX]; 

main()
{IOS;

    int n, m, k; cin >> n >> m >> k;
    for(int i = 1; i < n; i++){
        int p; cin >> p;
        adj[i].pb(p);
        adj[p].pb(i);
    }

    int ans = 0;
    for(int i = 1; i <= m; i++){
        int x, y, w; cin >> x >> y >> w;
        ans += w;
    }
    cout << ans << endl;

}