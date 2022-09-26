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

mll Home; mll Away;
ll x[def]; ll y[def];
vpii ans;

int main (void)
{
    ll n; cin >> n;
    forn(i,0,n){
        cin >> x[i] >> y[i];
        Home[x[i]]++; Away[y[i]]++;
    }

    ll d = n - 1;
    forn(i,0,n){
        ll a, b;
        a = d + Home[y[i]];
        b = d + (d - a);
        ans.pb(mp(a, b));
    }   

    forn(i,0,ans.size()) cout << ans[i].F << ' ' << ans[i].S << endl;
}