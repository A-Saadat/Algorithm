// 57 54 46 
#include <bits/stdc++.h> 
using namespace std; 

#pragma GCC optimize("03,no-stack-protector,unroll-loops")

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

const ll def = 3e5 + 100; 
const ll INF = 1e9 + 7; 
const ll MOD = 998244353;
const char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

ll col[def], cnt[def], Pow[def]; 
vci adj[def];
bool flag;

void dfs(ll v, ll c){
    col[v] = c;
    cnt[c]++;
    for(auto u: adj[v]){
        if(col[u] == col[v]) { flag = false; return; }
        elif(!col[u]) dfs(u, 3 - c);
    }
}

main ()
{IOS;

    // ? Processing the Powers of 2
    Pow[0] = 1;
    forn(i,1, 3e5 + 10)
        Pow[i] = (Pow[i - 1] * 2) % MOD;

    ll t; cin >> t;
    while(t--){
        ll n, m; cin >> n >> m;
        
        forn(i,0,n + 10) adj[i].clear();
        forn(i,0,n + 10) col[i] = 0;
        /// --------------------------- ///
        forn(i,0,m){
            ll x, y; cin >> x >> y;
            adj[x].pb(y);
            adj[y].pb(x);
        }

        ll ans = 1; 
        forn(i,1,n + 1){
            cnt[1] = 0, cnt[2] = 0;
            flag = true;
            if(!col[i]) dfs(i, 1);
            else continue;
            if(!flag) { ans = 0; continue; }
            // cout << cnt[1] << ' ' << cnt[2] << endl;
            ans = ans * (Pow[ cnt[1] ] + Pow[ cnt[2] ]) % MOD;

        }

        cout << ans << '\n';
    }  




}