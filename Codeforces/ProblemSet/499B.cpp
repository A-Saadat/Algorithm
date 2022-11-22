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
vector< pair<string, string> > s;
vs ans;

main ()
{IOS;

    ll n, m; cin >> n >> m;
    while(m--){
        string a, b; cin >> a >> b;
        s.pb(mp(a, b));
    }

    forn(i,0,n){
        string x; cin >> x;
        forn(i,0,s.size()){
            if(s[i].F == x || s[i].S == x){
                if(s[i].F.size() <= s[i].S.size()) ans.pb(s[i].F);
                else ans.pb(s[i].S);
            }
        }
    }
    forn(i,0,n) cout << ans[i] << ' ';

}