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

vci adj[MaxN], cc[MaxN]; 
ll mark[MaxN];
bool isOk = 1;

void dfs(ll v, ll c){
    mark[v] = c, cc[c].pb(v);
    for(ll u: adj[v]){
        if(mark[v] == mark[u]) { isOk = false; return; }
        if(!mark[u]) dfs(u, 3 - c);
    }
}

main ()
{IOS;

    ll n, m; cin >> n >> m;
    forn(i,0,m){
        ll x, y; cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    ll cnt = 0;

    forn(i,1,n + 1)
        if(!mark[i] && adj[i].size()) dfs(i, 1);
    
    if(!isOk) cout << " -1" << endl;

    else{
        forn(i,1,3){
            cout << cc[i].size() << endl;
            for(ll u: cc[i]) cout << u << ' ';
            cout << endl;
        }
    }   
}