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

const ll MaxN = 1e3 + 10; 
const ll INF = 1e9 + 7; 
const char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

string a[MaxN]; 
ll mark[MaxN][MaxN], cnt[MaxN * MaxN], cc[MaxN][MaxN]; 

ll G[] = {-1, 1, 0, 0};
ll H[] = {0, 0, -1, 1};

ll n, m, k; 

void dfs(ll x, ll y, ll c){
    mark[x][y] = 1;
    cc[x][y] = c;

    forn(i,0,4){    
        ll nx = x + G[i];
        ll ny = y + H[i];

        if(nx >= 0 && ny >= 0 && nx < n && ny < m && !mark[nx][ny])   
            if(a[nx][ny] == '*') cnt[c]++; 
            else dfs(nx, ny, c);

    }
}

main ()
{IOS;

    cin >> n >> m >> k;
    forn(i,0,n) cin >> a[i];

    ll c = 0;
    forn(i,0,n)
        forn(j,0,m)
            if(!mark[i][j] && a[i][j] == '.') dfs(i, j, ++c); 

    while(k--){
        ll x, y; cin >> x >> y;
        cout << cnt[ cc[--x][--y] ] << endl;
    }

}