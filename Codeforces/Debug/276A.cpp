#include <bits/stdc++.h> 
using namespace std; 

#define def 10000000 
#define forn(i,k,n) for(int i = k; i < n; i++) 
#define forb(i,n,k) for(int i = (n - 1); i < k; i--) 
#define fort(itr,map) for(auto itr = map.begin(); itr != map.end(); ++itr) 
#define msi map<string, int> 
#define mci map<char, int> 
#define mll map<ll, ll> 
#define si set<int> 
#define pb push_back 
#define F first 
#define S second 
#define mp make_pair 
#define elif else if 
typedef long long int ll; 
typedef int64_t i64; 
typedef vector<ll> vci;
typedef pair<int,int> pii; 
typedef vector<pii> vpii; 
typedef vector<string> vs; 
typedef vector<bool> vb; 
typedef vector<double> vd; 
typedef vector<char> vcc; 

const ll LIMIT = 1e8; 
const char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

vpii x;
vpii y;

int main (void)
{
    ios_base::sync_with_stdio(false);

    ll n, k; cin >> n >> k;
    forn(i,0,n){
        ll a, b; cin >> a >> b;
        if(b > k) x.pb(mp(a, b));
        elif(b <= k) y.pb(mp(a, b));
    }

    if(x.size() > 0) sort(x.begin(), x.end()); 
    if(y.size() > 0) (y.begin(), y.end());
    cout << y[y.size() - 1].F << ' ' << y[y.size() - 1].S  << endl << x[x.size() - 1].F << ' ' << x[x.size() - 1].S ;

    ll joy1 = x.size() > 0 ? x[x.size() - 1].F - ((x[x.size() - 1].S) - k) : -999;
    ll joy2 = y.size() > 0 ? y[y.size() - 1].F : -999;

    cout << max(joy1, joy2);

}