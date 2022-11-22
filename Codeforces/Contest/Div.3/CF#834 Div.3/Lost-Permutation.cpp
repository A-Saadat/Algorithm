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

const ll def = 1e6; 
const ll INF = 1e9 + 7; 
const char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

ll a[def]; 
bool check[def];

main ()
{IOS;

    ll t; cin >> t;
    while(t--){
        ll m, s; cin >> m >> s;

        memset(a, 0, sizeof(a)); memset(check, 0, sizeof(check));
        ll maxi = 0;
        forn(i,0,m) cin >> a[i], check[ a[i] ] = 1, maxi = max(a[i], maxi);
        forn(i,0,(maxi + 1)) 
            if(!check[i]) s -= i;

        if(s < 0) { cout << "NO" << endl; continue; }
        elif(s == 0) { cout << "YES" << endl; continue; }

        bool isOk = false;
        forn(i,maxi + 1, 10000){
            s -= i;
            if(s == 0) { isOk = true; break; }
            elif(s < 0) break;
        }

        if(isOk) cout << "YES" << endl;
        else cout << "NO" << endl;
        

    }

}