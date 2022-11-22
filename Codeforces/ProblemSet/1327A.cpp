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

ll sum[def + 100];

main ()
{IOS;
    ll idx = 1;
    for(ll i = 1; i <= def; i += 2) sum[idx] = sum[idx - 1] + i, idx++;

    ll t; cin >> t;
    while(t--){
        ll n, k; cin >> n >> k;
        if(((n % 2 == 0 && k % 2 == 0) || (n % 2 != 0 && k % 2 != 0)) && sum[k] <= n && sum[k] > 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}