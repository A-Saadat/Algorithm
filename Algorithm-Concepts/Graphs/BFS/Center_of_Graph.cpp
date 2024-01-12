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
#define err(x, y) cout << '#' << y << ':' << ' ' << x << endl 
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

ll mark[MaxN]; 
vci adj[MaxN];
queue<ll> q, dep;
ll n, m; 

ll bfs(ll v){
    q.push(v), mark[v] = 1;
    dep.push(0);

    ll ans = 0;
    while(q.size()){
        ll h = q.front();
        ll far = dep.front();

        // err(v, far); err(v, h);
        // cout << "\n--------------\n";

        for(ll u: adj[h]){
            if(!mark[u]){
                q.push(u);
                mark[u] = 1;
                dep.push(far + 1);
            }
        }

        q.pop(), dep.pop();

        ans = far;
    }

    return ans;
}

ll find_the_center(){
    

    ll ans = (1 << 30);
    ll v = -1;
    forn(i,1,n + 1){
        memset(mark, 0, sizeof(mark));
        ll dis = bfs(i);
        
        // cout << "\nDepth STT: " << dep.empty() << " Queue is: " << q.empty() << endl; 
        cout << i << ": " << dis << endl;

        if(dis < ans){
            ans = dis;
            v = i;
        }
    }

    return v;
}

main ()
{IOS;

    cin >> n >> m;
    forn(i,0,m){
        ll x, y; cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    cout << find_the_center();

}