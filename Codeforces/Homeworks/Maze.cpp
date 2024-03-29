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

const ll MaxN = 5e2 + 100; 
const ll INF = 1e9 + 7; 
const char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

vci adj[MaxN]; 
char a[MaxN][MaxN]; 
ll Mark[MaxN][MaxN];
ll G[] = {1, -1, 0, 0};
ll H[] = {0, 0, 1, -1};
ll cnt, n, m, k, s; 

void dfs(ll x, ll y){
    if(cnt >= (s - k)) a[x][y] = 'X';
    // cout << x + 1 << ' ' << y + 1 << endl;
    Mark[x][y] = 1;
    forn(i,0,4){
        ll nx = x + G[i];
        ll ny = y + H[i];
        if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
        if(Mark[nx][ny] || a[nx][ny] == '#') continue;
        
        // cout << nx + 1 << " " << ny + 1 << endl;

        ++cnt; 
        dfs(nx, ny);
    }
}

main ()
{IOS;
    cin >> n >> m >> k;
    forn(i,0,n)
        forn(j,0,m){
            cin >> a[i][j];
            if(a[i][j] == '.') s++; 
        }
        
    ll x, y; bool flag = false;
    forn(i,0,n)
        forn(j,0,m) 
            if(a[i][j] == '.' && !flag) { x = i, y = j; flag = true; }

    dfs(x, y);

    forn(i,0,n){
        forn(j,0,m) cout << a[i][j]; 
        cout << endl;
    }
}