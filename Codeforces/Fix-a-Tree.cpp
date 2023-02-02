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

vci adj[MaxN]; 
ll a[MaxN], mark[MaxN];
vpii cc;

ll x, y; bool mk = false;
void dfs(ll v){
    // cout << v << ' ';
    mark[v] = 1;
    for(ll u: adj[v]){
        if(!mark[u]) dfs(u);
        elif(u == v && !mk){
            x = v, y = v;
            mk = true;
        } 
        elif(mark[u] && !mk) x = u, y = v;
    }
}

void input(ll i){
    ll x = a[i];
    adj[x].pb(i);
    adj[i].pb(x);
}

main ()
{IOS;
    bool isCir = false; ll root = 0;
    ll n; cin >> n;
    forn(i,1,n + 1){
        cin >> a[i];
        input(i);
        if(a[i] == i && !isCir) { isCir = true; root = i; }
    }

    ll ans = 0;
    if(!isCir){
        forn(i,1,n + 1){
            uni(adj[i]);
            if(adj[i].size() >= 2) {
                ++ans;
                root = i;
                a[i] = i;
                break;
            }
        }
    }

    forn(i,1,n + 1) adj[i].clear();

    forn(i,1,n + 1) input(i);

    forn(i,1,n + 1){
        x = 0, y = 0;
        if(!mark[i]){
            mk = false;
            dfs(i);
            ans++;
            a[x] = root;
        } 

    }

    cout << ans - 1 << endl;
    forn(i,1,n + 1) cout << a[i] << ' ';


}