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

const ll MaxN = 5e5 + 10; 
const ll INF = 1e9 + 7; 
const char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

ll a[MaxN], num[MaxN], par[MaxN];
ll ans[MaxN], sub[MaxN]; 
vci adj[MaxN];
ll cnt;

void dfs(ll v){
    sub[v] = 1;
    for(ll u: adj[v]){
        if(par[v] == u) continue;

        dfs(u);
        sub[v] += sub[u];

        if(num[v] == num[u]) ans[v] += ans[u];
        else ans[v] += sub[u] - ans[u];
    }
}

void clear(){
    cnt = 0;
    memset(a, 0, sizeof(a));
    memset(num, 0, sizeof(num));
    memset(par, 0, sizeof(par));
    memset(sub, 0, sizeof(sub));
    memset(ans, 0, sizeof(ans));
}

int main ()
{IOS;

    ll t; cin >> t;
    while(t--){
        clear();
        
        ll n; cin >> n;
        forn(i,1,n + 1) adj[i].clear();
        forn(i,1,n + 1) cin >> num[i];

        ll root;
        forn(i,1,n + 1){
            cin >> par[i];
            ll x = par[i];
            par[i] = x;
            adj[i].pb(x);
            adj[x].pb(i);
            if(x == 0) root = i;
        }

        forn(i, 1, n + 1)
            if(__builtin_popcountll(num[i]) % 2) num[i] = 1;
            else num[i] = 0;

        dfs(root);

        ll sum = 0;
        forn(i,1,n + 1) sum += ans[i];

        cout << sum << endl;
    }

}