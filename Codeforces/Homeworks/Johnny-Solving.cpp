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

const ll MaxN = 2e6 + 10; 
const ll INF = 1e9 + 7; 
const char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

ll par[MaxN], mark[MaxN];
vci adj[MaxN], path, lev, loops; 
ll n, m, k, isPath;

void dfs(ll v){
    mark[v] = 1; path.pb(v);

    bool isLeaf = 1;
    for(ll u: adj[v]){
        if(mark[u]) continue;
        isLeaf = 0;

        dfs(u);
        par[u] = v;
    }

    if(isLeaf) lev.pb(v);

    if(path.size() >= (n / k) && !isPath){
        isPath = 1; 
        cout << "PATH\n" << path.size() << endl;
        for(ll u: path) cout << u << ' ';
        return;
    }
    path.pop_back();
}

void print_loop(ll v){
    for(ll u: adj[v]){
        loops.clear();
        if(u == par[v]) continue;

        loops.pb(v); ll curr = par[v]; 
        while(u != curr){
            loops.pb(curr);
            curr = par[curr];
        }
        loops.pb(u);

        if(loops.size() % 3 != 0){
            cout << loops.size() << endl;
            for(ll y: loops) cout << y << ' ';
            cout << endl;
            return;
        }
    }

    ll ba1 = (adj[v][0] == par[v] ? adj[v][1] : adj[v][0]);
    ll ba2 = (adj[v][0] == par[v] ? adj[v][2] : adj[v][1]);

    ll tmp = ba1;
    ba1 = max(ba1, ba2);
    ba2 = min(tmp, ba2);

    loops.clear(); loops.pb(v);

    ll curr = ba1; 
    while(ba2 != curr){
        loops.pb(curr);
        curr = par[curr];
    }
    loops.pb(ba2);

    cout << loops.size() << endl;
    for(ll u: loops) cout << u << ' ';
    cout << endl;
    
}

main ()
{IOS;

    cin >> n >> m >> k;
    while(m--){
        ll x, y; cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    
    dfs(1);

    
    if(!isPath){
        ll cnt = 0;
        cout << "CYCLES\n";
        for(ll u: lev){
            cnt++;
            if(cnt <= k) print_loop(u);
        }
    }
}