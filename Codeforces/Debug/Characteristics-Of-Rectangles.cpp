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

const ll def = 1e3 + 10; 
const ll INF = 1e9 + 7; 
const char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

ll a[def][def], b[def][def]; 
vci tmp;

main ()
{IOS;

    ll n, m; cin >> n >> m;
    forn(i,0,n)
        forn(j,0,m) cin >> a[i][j], tmp.pb(a[i][j]);
    
    sort(tmp.begin(), tmp.end());

    ll L = 0, R = 1e9 + 10;
    while(R - L > 1){
        ll MID = (R + L) / 2;
        auto ip = lower_bound(tmp.begin(), tmp.end(), MID);

        if(ip == tmp.end()) { R = MID; continue; }

        memset(b, 0, sizeof(b));
        
        forn(i,0,n)
            forn(j,0,m)
                if(a[i][j] >= MID) b[i][j] = 1;
                else b[i][j] = 0;

        bool isOk = false;
        
        forn(i,0,n)
            forn(j,0,m)
                if(b[i][j] && b[i + 1][j] && b[i][j + 1] && b[i + 1][j + 1]) { isOk = true; break; }

        if(isOk) L = MID;
        else R = MID;
    }

    cout << L << endl;
    
}