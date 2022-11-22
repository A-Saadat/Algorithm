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

const ll def = 1e5 + 100; 
const ll INF = 1e9 + 7; 
const char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

ll dp[def], sum[def];

void DPF(ll k){
    forn(i,1,k) dp[i] = 1;
    dp[k] = 2;
    forn(i, k + 1, def) dp[i] = (dp[i - k] + dp[i - 1]) % INF;
}

main ()
{IOS;

    ll t, k; cin >> t >> k;
    DPF(k);
    forn(i,0,def) sum[i] = (sum[i - 1] + dp[i]);
    
    while(t--){
        ll L, R; cin >> L >> R;
        cout << (sum[R] - sum[L - 1]) % INF << endl;
    }
}