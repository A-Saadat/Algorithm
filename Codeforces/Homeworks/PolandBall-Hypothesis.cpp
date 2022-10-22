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
const char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

si Prime;

void FindPrime(ll n){
    bool NotPrime[def];

    for(ll i = 2; i * i <= n; i++)
        for(ll j = i * i; j <= n; j += i)
            NotPrime[j] = 1;

    forn(i,2,(n + 1))
        if(NotPrime[i] == 0) Prime.insert(i);
}


int main (void)
{IOS;

    ll n; cin >> n;
    FindPrime(1e5);
    bool isOk = true;
    forn(i,1,(1e3 + 1)){
        ll m = i;
        ll x = n * m + 1;

        auto Find = Prime.find(x);
        

        if(Find == Prime.end()) { cout << m; break; }
    }

    
}