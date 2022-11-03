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

const ll def = 1e6 + 1000; 
const char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
const ll MOD = 1073741824;

ll dev[def];

void findDevisor(ll n){
    forn(i,2,n){
        dev[i] += 2;
        for(ll j = i * 2; j <= n; j += i) dev[j]++;
    }
}

main (void)
{IOS;
    findDevisor(def);
    ll a, b, c; cin >> a >> b >> c;
    ll ans = 1;
    forn(i,1,(a + 1)){

        forn(j,1,(b + 1)){

            forn(k, 1, (c + 1)){
                ll x = (i * j * k) % MOD;
                ans += dev[x];
            }

        }

    }

    cout << ans;

}