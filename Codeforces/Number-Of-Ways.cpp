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
ll a[def], sum[def];

int main (void)
{
    ll n; cin >> n;
    forn(i,0,n) cin >> a[i];
    forn(i,0,n) sum[i] = sum[i - 1] + a[i];

    ll cnt = 0, ans = 0, k = sum[n - 1] / 3;
    if((k * 3) % 3 != 0) {cout << 0; return 0;}
    forn(i,0,n){
        if(sum[i] == k) cnt++;
        if(sum[i] == 2 * k) ans += cnt;    
    }

    cout << ans;
}   