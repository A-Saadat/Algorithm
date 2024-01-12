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

vector< pair<int, int> > adj[MaxN];
ll s[MaxN]; // ? s[i] = the cost for getting to the city i from city 1 

void dfs(int v, int par, int sum){
    for(auto u: adj[v]){
        if(u.F == par) continue;

        dfs(u.F, v, sum + u.S);
    }

    if(adj[v].size() == 1) s[v] = sum;
}

main()
{IOS;

    int n; cin >> n;

    ll ans = 0;
    for(int i = 1; i < n; i++){
        int x, y, val; cin >> x >> y >> val;
        adj[x].pb( {y, val} );
        adj[y].pb( {x, val} );

        ans += val * 2;
    }

    dfs(1, 0, 0);

    ll maxi = 0;
    for(int i = 1; i <= n; i++) maxi = max(maxi, s[i]);


    cout << ans - maxi << endl;

}