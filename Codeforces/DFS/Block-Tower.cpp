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

const ll MaxN = 1e3; 
const ll INF = 1e9 + 7; 
const char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

vci adj[MaxN]; 
char a[MaxN][MaxN]; 
ll mark[MaxN][MaxN];

ll n, m;
ll G[] = {1, -1, 0, 0};
ll H[] = {0, 0, 1, -1};

void dfs(ll x, ll y){
    mark[x][y] = 1;

    bool isBlue = false;
    forn(i,0,4){
        ll nnx = G[i] + x;
        ll nny = H[i] + y;

        if(nnx > n || nnx < 0 || nny > m || nny < 0) continue;
        if(a[nnx][nny] == 'B') isBlue = true;
    }

    if(isBlue) a[x][y] = 'R';
    elif(a[x][y] != 'R') a[x][y] = 'B';

    forn(i,0,4){
        ll nx = G[i] + x;
        ll ny = H[i] + y;

        if(nx > n || nx < 0 || ny > m || ny < 0) continue;
        if(mark[nx][ny] || a[nx][ny] == '#') continue;

        dfs(nx, ny);
    }
}



main ()
{IOS;

    cin >> n >> m;
    forn(i,0,n)
        forn(j,0,m) cin >> a[i][j];    

    forn(i,0,n)
        forn(j,0,m) 
            if(a[i][j] == '.' && !mark[i][j]) dfs(i, j);

    memset(mark, 0, sizeof(mark));
        
    forn(i,0,n)
        forn(j,0,m) 
            if(a[i][j] != '#' && !mark[i][j]) dfs(i, j);

    forn(i,0,n){
        forn(j,0,m) cout << a[i][j] << ' ';
        cout << endl;
    }
            // if(a[i][j] == 'R' || a[i][j] == 'B') cout << a[i][j] << ' ' << i + 1 << ' ' << j + 1 << endl;

}