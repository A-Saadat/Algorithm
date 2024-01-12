#include <bits/stdc++.h> 
using namespace std; 

#define forn(i,k,n) for(int i = k; i < n; i++) 
#define fort(itr,map) for(auto itr = map.begin(); itr != map.end(); ++itr) 
#define IOS ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0) 
#define pb push_back 
#define F first 
#define S second 
#define gcd __gcd 
#define elif else if 
#define all(v) v.begin(), v.end() 
#define uni(v) sort(all(v)), v.erase(unique(all(v)), v.end()) 
#define err(x) cout << '#' << x << ':' << ' ' << x << endl 
typedef long long int ll; 
typedef vector<int> vi;

const ll MaxN = 1e6; 
const ll MOD = 1e9 + 7; 

vector<ll> adj[MaxN]; 
ll mark[MaxN];
ll sum[MaxN];

void dfs(ll v){
    mark[v] = 1;

    for(ll u: adj[v]){
        if(!mark[u]){
            dfs(u);
            sum[v] += sum[u];
        } 
    }
}

main()
{IOS;

    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;

        forn(i,1,n){
            ll x, y; cin >> x >> y;
            adj[x].pb(y);
            adj[y].pb(x);
        }

        forn(i,2,n + 1)
            if(adj[i].size() == 1) sum[i] = 1;
        
        dfs(1);

        ll q; cin >> q;
        while(q--){
            ll a, b; cin >> a >> b;
            cout << sum[a] * sum[b] << endl;
        }   

        forn(i,1, n + 1000) mark[i] = 0, sum[i] = 0;
        forn(i,1, n + 1000) adj[i].clear();
    }

}