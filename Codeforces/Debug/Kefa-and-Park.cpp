// 57 54 46 
#include <bits/stdc++.h> 
using namespace std; 

#define forn(i,k,n) for(int i = k; i < n; i++) 
#define fort(itr,map) for(auto itr = map.begin(); itr != map.end(); ++itr) 
#define IOS ios_base::sync_with_stdio(false) 
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

const ll def = 1e6; 
const ll INF = 1e9 + 7; 
const char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

ll Mark[def], Cats[def]; 
vci G[def];
ll cnt, ans;
ll n, m; 

void dfs(ll v){
    Mark[v] = 1;
    if(Cats[v]) cnt++;

    forn(i,0,G[v].size()){
        ll u = G[v][i];

        cout << v << ' ' << cnt << endl;
        if(!Mark[u]){
            if(Cats[u] && !Cats[v]) cnt = 0;


            // Mark[u] = 1;
            // if(cnt > m) return; 
            dfs(u);
        }
        else {
            if(cnt <= m) cout << "ans++ " << v << endl, ans++;
            if(Cats[u]) cnt--;
        }

    }
}

main ()
{IOS;

    cin >> n >> m;
    forn(i,1,n + 1) cin >> Cats[i];
    forn(i,1,n){
        ll x, y; cin >> x >> y;
        G[x].pb(y);
        G[y].pb(x);
    }

    cout << endl;
    dfs(1);
    // cout << ans;
}