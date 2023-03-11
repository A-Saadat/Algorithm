// * Shortest Path in a Binary Weight Graph :)
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
typedef map<ll, ll> mll; 
typedef set<int> si;  
typedef pair<ll,ll> pii; 
typedef vector<ll> vci;
typedef vector<pii> vpii; 
typedef vector<string> vs; 
typedef vector<char> vcc; 

const ll MaxN = 1e6; 
const ll INF = 1e9 + 7; 

vpii adj[MaxN]; 
ll hig[MaxN], mark[MaxN];

void bfs(ll v){
    queue<ll> q;
    q.push(v);

    while(!q.empty()){
        ll h = q.front(); q.pop(); mark[h] = 1;

        for(auto u: adj[h]){
            if(mark[u.F]) continue;

            if(u.S) hig[u.F] = hig[h] + 1;
            else hig[u.F] = hig[h];

            q.push(u.F); mark[u.F] = 1;
        }
    }
}

main()
{IOS;

    ll n, m; cin >> n >> m;
    forn(i,0,m){
        ll x, y, val; cin >> x >> y >> val;
        adj[x].pb(mp(y, val));
        adj[y].pb(mp(x, val));
    }
    cout << endl;

    hig[1] = 0;
    bfs(1);    

    forn(i,1,n + 1){
        cout << i << ": " << hig[i] << endl;
    }
}