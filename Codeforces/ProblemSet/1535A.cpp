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

const ll LIMIT = 1e8; 
const char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

ll a[def], b[def];

int main (void)
{IOS;

    ll t; cin >> t;
    while(t--){
        forn(i,0,4) cin >> a[i], b[i] = a[i];

        ll MAX1 = 0, MAX2 = 0;
        forn(i,0,4) MAX1 = max(MAX1, a[i]);

        forn(i,0,4)
            if(a[i] == MAX1) b[i] = 0;
        
        forn(i,0,4) MAX2 = max(MAX2, b[i]);

        bool isOk = true;
        // cout << MAX1 << ' ' << MAX2 << endl;
        if((a[0] == MAX1 && a[1] == MAX2) || (a[0] == MAX2 && a[1] == MAX1)) isOk = false;
        if(a[2] == MAX1 && a[3] == MAX2 || a[2] == MAX2 && a[3] == MAX1) isOk = false;

        if(isOk) cout << "YES" << endl;
        else cout << "NO" << endl;
        

    }

}