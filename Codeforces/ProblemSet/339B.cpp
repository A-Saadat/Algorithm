#include <bits/stdc++.h> 
using namespace std; 

#define def 1000000
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
ll a[def];
ll ans, maxi;

int main (void)
{
    ll n, m; cin >> n >> m;
    forn(i,1,(m + 1)) cin >> a[i];

    forn(i,1,(m + 1)){
        if(a[i] >= maxi) ans += a[i] - maxi;
        elif(a[i] < maxi) ans += a[i] + (n - maxi);
        
            

        maxi = a[i];
    }

    cout << ans - 1;
}