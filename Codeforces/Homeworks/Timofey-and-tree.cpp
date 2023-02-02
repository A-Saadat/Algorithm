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
#define scan(a, n) for(int i = 0; i < n; i++) cin >> a[i]; 
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

ll c[MaxN]; 
vci adj[MaxN];

ll root, isOk = true;
void dfs(ll v, ll par){
    for(ll u: adj[v])
        if(u != par) {
            if(c[u] != c[v] && v != root) isOk = false;
            dfs(u, v);
        }
}

main ()
{IOS;

    ll n; cin >> n;
    forn(i,1,n){
        ll x, y; cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    forn(i,1,n + 1) cin >> c[i];
    
    ll u = 0, v = 0;
    forn(i,1,n + 1)
        for(ll uv: adj[i])
            if(c[i] != c[uv]) v = i, u = uv; 

    if(!u || !v) { cout << "YES\n1" << endl; return 0; }

    root = u;
    dfs(u,u);
    if(isOk) { cout << "YES\n" << u << endl; return 0; }

    isOk = true; root = v;
    dfs(v, v);

    if(isOk) cout << "YES\n" << v << endl;
    else cout << "NO";
    
}