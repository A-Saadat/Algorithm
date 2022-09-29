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
mll x;
ll a[def];

int main (void)
{   
    ll n; cin >> n;
    forn(i,0,n){
        cin >> a[i];
        x[ a[i] ]++;
    }
    
    ll ans = 0;
    forn(i,1,5){
        if(i == 1){
            ll tmp = min( x[1], x[3] );
            ans += tmp;
            x[1] -= tmp; x[3] -= tmp;
            ans += x[3]; x[3] = 0;  
        }

        if(i == 2) ans += x[2] / 2, x[2] -= (x[2] / 2) * 2;

        if(i == 4) ans += x[4], x[4] = 0;
    }

    if(x[2] > 0 or x[1] > 0){
        ll t = (x[2] * 2) + x[1];
        if(t % 4 == 0) ans += t / 4;
        else ans += t / 4 + 1;
    }

    cout << ans << endl;
}