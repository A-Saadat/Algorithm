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

vector< pair<int, int> > adj[MaxN];
int hig[MaxN], mark[MaxN];

void bfs(ll v){
    deque<int> dq;

    dq.push_back(v); mark[v] = 1;
    while(!dq.empty()){
        ll h = dq.back();
        dq.pop_back();

        for(auto u: adj[h]){
            if(mark[u.F]) continue;

            if(u.S == 1){
                dq.push_front(u.F);
                hig[u.F] = hig[h] + 1;
            } 
            else{
                dq.push_back(u.F);
                hig[u.F] = hig[h];
            } 

            mark[u.F] = 1;
        }

    }

}

main()
{IOS;

    int n, m; cin >> n >> m;
    forn(i,0,m){
        ll x, y, val; cin >> x >> y >> val;
        adj[x].pb( {y, val} );
        adj[y].pb( {x, val} );
    }

    int l, r; cin >> l >> r;
    hig[l] = 0;
    bfs(l);
    
    cout << hig[r];
}