// 57 54 46 
#include <bits/stdc++.h> 
using namespace std; 

#define forn(i,k,n) for(int i = k; i < n; i++) 
#define fort(itr,map) for(auto itr = map.begin(); itr != map.end(); ++itr) 
#define IOS ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0); 
#define pb push_back 
#define F first 
#define S second 
#define mp make_pair 
#define gcd __gcd 
#define elif else if 
#define all(v) v.begin(), v.end() 
#define uni(v) sort(all(v)), v.erase(unique(all(v)), v.end()) 
#define scan(a, n) for(int i = 0; i < n; i++) cin >> a[i]; 
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

const ll MaxN = 1e6; 
const ll INF = 1e9 + 7; 
const char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

ll a[MaxN], fact[MaxN] = {0, 1}; 

ll cu_pow(ll a, ll b){
    if(b == 0) return 1;
    ll ans = cu_pow(a, b / 2) % INF;
    ans = (ans * ans) % INF;

    if(b % 2) ans = (ans * a) % INF;
    
    return ans;
}

ll Combination(ll k, ll n){
    ll num = fact[n];
    ll den = (fact[k] * fact[n - k]) % INF;

    return (num * cu_pow(den, INF - 2)) % INF;
}


main ()
{IOS;

    ll a, b; cin >> a >> b;
    ll maxi = max(a, b);

    forn(i,2,maxi + 1) fact[i] = fact[i - 1] * i;
    
    cout << Combination(a, b);
}