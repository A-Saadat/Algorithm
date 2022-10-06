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


vci a, b, c;

vci RepFor(ll n){
    vci v;
    forn(i,0,n) {
        ll x; cin >> x;
        v.pb(x);
    }

    sort(v.begin(), v.end());

    return v;
}

int main (void)
{
    ios_base::sync_with_stdio(false);

    ll n; cin >> n;
    
    a = RepFor(n); b = RepFor(n - 1); c = RepFor(n - 2);
    
    cout << endl;
    forn(i, 0, a.size())
        if(a[i] != b[i]) { cout << a[i] << endl; break; }

    forn(i, 0, b.size())
        if(b[i] != c[i]) { cout << b[i] << endl; break; }

}