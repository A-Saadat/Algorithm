#include <bits/stdc++.h> 
using namespace std; 

#define def 10000000 
#define forn(i,k,n) for(int i = k; i < n; i++) 
#define fort(itr,map) for(auto itr = map.begin(); itr != map.end(); ++itr) 
#define IOS ios_base::sync_with_stdio(false) 
#define msi map<string, int> 
#define mci map<char, int> 
#define mll map<ll, ll> 
#define si set<int> 
#define pb push_back 
#define F first 
#define S second 
#define mp make_pair 
#define gcd __gcd 
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

const ll LIMIT = 1e5 + 10; 
const char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

ll a[def], distinct[def];
bool isNew[def];

int main (void)
{IOS;
    forn(i,0,LIMIT) isNew[i] = 1;

    ll n, m; cin >> n >> m;
    forn(i,0,n) cin >> a[i];
    reverse(a, a + n);
    forn(i,0,n) distinct[i] = distinct[i - 1] + isNew[ a[i] ], isNew[ a[i] ] = 0;

    while(m--){
        ll x; cin >> x;

        x = n - x;
        cout << distinct[x] << endl;
    }

}