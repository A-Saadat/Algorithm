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

const ll MaxN = 1e3; 
const ll INF = 1e9 + 7; 
const char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

vci adj[MaxN]; 
vpii a;
ll mark[MaxN], hig[MaxN];
ll n, ans, tmp;

void dfs(ll v);
void repair_edge(ll idx1, ll val1, ll idx2, ll val2, ll x, ll y);

ll Diameter(ll root);
vector< pair<ll, ll> > grap_spliter(pii s);

main ()
{IOS;

    cin >> n;
    forn(i,1,n) {
        ll x, y; cin >> x >> y;
        a.pb(mp(x, y));

        adj[x].pb(y);
        adj[y].pb(x);
    }
        cout << "\n-------\n";

    for(auto u: a){
        vector< pair<ll, ll> > ret;
        ret = grap_spliter(u);

        ll x = u.F, y = u.S;

        forn(i,1,n + 1){
            cout << i << ": ";
            for(ll u: adj[i]) cout << u << ' ';
            cout << endl;
        }
        repair_edge(ret[0].F, ret[0].S, ret[1].F, ret[1].S, x, y);

        cout << "\n-------\n";

        memset(mark, 0, sizeof(mark));
        memset(hig, 0, sizeof(hig));
    }
    
}

// ** Functions :)

void dfs(ll v){
    cout << v << " --> ";
    mark[v] = 1;
    for(auto u: adj[v])
        if(!mark[u] && u != -1){
            hig[u] = hig[v] + 1;
            dfs(u);
        }
}

ll Diameter(ll root){
    // * Find the Furthest leaf
    dfs(root);

    ll HIG = 0, L = -1;
    forn(i,1,n + 1)
        if(hig[i] > HIG) HIG = hig[i], L = i;

    memset(mark, 0, sizeof(mark));
    memset(hig, 0, sizeof(hig));

    dfs(L);

    ll Diameter = 0, R = -1;
    forn(i,1,n + 1)
        if(hig[i] > Diameter) Diameter = hig[i], R = i;

    return Diameter;
}

vector< pair<ll, ll> > grap_spliter(pii s){
    ll x = s.F;
    ll y = s.S;

    vector< pair<ll, ll> > ret;

    // ? remove the first vertix of the target edge
    ll idx1 = 0, val1 = 0;
    forn(i,0,adj[x].size()){
        ll u = adj[x][i];
        if(u == y){
            adj[x][i] = -1;
            idx1 = i; val1 = u;
            break;
        }
    }

    ret.pb(mp(idx1, val1));

    // ? remove the second vertix of the target edge
    ll idx2 = 0, val2 = 0;
    forn(i,0,adj[y].size()){
        ll u = adj[y][i];
        if(u == x){
            adj[y][i] = -1;
            idx2 = i; val2 = u;
            break;
        }
    }

    ret.pb(mp(idx2, val2));

    return ret;
}

void repair_edge(ll idx1, ll val1, ll idx2, ll val2, ll x, ll y){
    adj[x][idx1] = val1; 
    adj[y][idx2] = val2; 
}