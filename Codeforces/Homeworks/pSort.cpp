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

ll a[MaxN], d[MaxN], mark[MaxN];
// ? Graphs for indexes & values
vci adj_idx[MaxN], adj_val[MaxN];
// ? Cohesive Components for indexes & values 
vci cc_idx[MaxN], cc_val[MaxN];

void dfs_val(ll v, ll c){
    mark[v] = 1;
    cc_val[c].pb(v);
    for(auto u: adj_val[v])
        if(!mark[u]) dfs_val(u, c);
}

void dfs_idx(ll v, ll c){
    mark[v] = 1;
    cc_idx[c].pb(v);
    for(auto u: adj_idx[v])
        if(!mark[u]) dfs_idx(u, c);
}

main ()
{IOS;

    ll n; cin >> n;
    forn(i,1,n + 1) cin >> a[i];
    forn(i,1,n + 1) cin >> d[i];

    // ? Drawing a Graph For every Index & every value in those indexes
    forn(i,1,n + 1){
        if(i - d[i] > 0){
            adj_idx[i].pb(i - d[i]);
            adj_idx[i - d[i]].pb(i);
            
            adj_val[ a[i] ].pb( a[ i - d[i] ] );
            adj_val[ a[ i - d[i] ] ].pb( a[i] );
        } 
        if(i + d[i] <= n){
            adj_idx[i].pb(i + d[i]);
            adj_idx[i + d[i]].pb(i);
            
            adj_val[ a[i] ].pb( a[ i + d[i] ] );
            adj_val[ a[ i + d[i] ] ].pb( a[i] );
        }
        
    }

    // ? Number of Cohesive Components
    ll c_idx = 0, c_val = 0;

    // * Find the Cohesive Components For Graph of "Values"
    forn(i,1,n + 1)
        if(!mark[ a[i] ]) ++c_val, dfs_val(a[i], c_val);

    memset(mark, 0, sizeof(mark));

    // * Find the Cohesive Components For Graph of "Indexes"
    forn(i,1,n + 1)
        if(!mark[i]) c_idx++, dfs_idx(i, c_idx);

    forn(i,1,c_val + 1){
        sort( all( cc_idx[i] ) );
        sort( all( cc_val[i] ) );
    }

    bool isOk = true;
    forn(i,1,c_idx + 1)
        if( cc_idx[i] != cc_val[i] ) isOk = false;

    if(isOk) cout << "YES" << endl;
    else cout << "NO" << endl;

}