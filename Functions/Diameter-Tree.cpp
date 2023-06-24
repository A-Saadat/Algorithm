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

const ll MaxN = 1e6; 
const ll INF = 1e9 + 7; 
const char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

vci adj[MaxN]; 
int mark[MaxN], hig[MaxN];
int n, m;

void dfs(int v){
    mark[v] = 1;
    for(auto u: adj[v]){
        if(!mark[u]){
            hig[u] = hig[v] + 1;
            dfs(u);
        }
    }
}

int Diameter(){
    // * Find the Furthest leaf
    int HIG = 0, L = 0;
    dfs(1);
    forn(i,1,n + 1) 
        if(HIG < hig[i]) L = i, HIG = hig[i];

    memset(mark, 0, sizeof(mark));
    memset(hig, 0, sizeof(hig));
    // cout << L;
    dfs(L);
    int Dia = 0;
    forn(i,1,n + 1) Dia = max(Dia, hig[i]);

    return Dia;
}

main ()
{IOS;

    cin >> n >> m;
    forn(i,0,m){
        int x, y; cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    
    cout << Diameter();
}