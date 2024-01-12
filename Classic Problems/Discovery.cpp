// 57 54 46 
#include <bits/stdc++.h> 
using namespace std; 

#define forn(i,k,n) for(int i = k; i < n; i++) 
#define fort(itr,map) for(auto itr = map.begin(); itr != map.end(); ++itr) 
#define IOS ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0); 
#define pb push_back 
#define F first 
#define S second 
#define mp make_pair 
#define gcd __gcd 
#define bp __builtin_popcount 
#define elif else if 
#define all(v) v.begin(), v.end() 
#define uni(v) sort(all(v)), v.erase(unique(all(v)), v.end()) 
#define err(x) cout << '#' << x << ':' << ' ' << x << endl 
typedef long long int ll; 
typedef map<string, int> msi;  
typedef map<char, int> mci; 
typedef map<ll, ll> mll; 
typedef set<int> si;  
typedef int64_t i64; 
typedef vector<ll> vci;
typedef pair<int,int> pii; 
typedef vector<pii> vpii; 
typedef vector<string> vs; 
typedef vector<bool> vb; 
typedef vector<double> vd; 
typedef vector<char> vcc; 

const ll MaxN = 1e6; 
const ll INF = 1e9 + 7; 
const char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

vci adj[MaxN]; 
ll dsc[MaxN], beg[MaxN], term[MaxN], mark[MaxN];
ll a[MaxN], sum[MaxN];

ll t = 0;
void dfs(ll v){
    ++t; mark[v] = 1; beg[v] = t; dsc[t] = v;

    for(auto u: adj[v])
        if(!mark[u]) dfs(u);

    term[v] = t;
}

main ()
{IOS;

    ll n, q; cin >> n >> q;
    forn(i,1,n) {
        ll x, y; cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    dfs(1);
    
    while(q--){
        ll v, val; cin >> v >> val;

        a[ beg[v] ] = val;
        a[ term[v] + 1 ] = -val;
    }

    cout << endl;
    forn(i,1,n + 1) sum[i] = a[i] + sum[i - 1];
    forn(i,1,n + 1) cout << i << ": " << sum[i] << endl;
}