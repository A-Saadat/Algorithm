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

const ll def = 1e7 + 10; 
const char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

vector< pair<ll, pair<ll, ll>> > a;
ll ans[def];
bool checker[def];

main ()
{IOS;

    ll n; cin >> n;
    forn(i,0,n){
        ll x, y; cin >> x >> y;
        a.pb(mp(y, mp(x, i)));
    }

    sort(a.begin(), a.end());
    forn(i,0,n){
        ll L = a[i].S.F;
        ll R = a[i].F;
        ll idx = a[i].S.S;
        forn(j,L,(R + 1))
            if(!checker[j]) {
                ans[idx] = j;
                checker[j] = 1;
                break;
            }
    }

    forn(i,0,def) 
        if(ans[i]) cout << ans[i] << ' ';

}