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
vci a;

int main (void)
{
    ll t; cin >> t;
    while(t--){

        ll n; cin >> n;
        if(n % 4 != 0) cout << "NO" << endl;
        else{
            for(ll i = 2; i <= n; i+=2) a.pb(i);
            cout << endl;
            for(ll i = 1; i <= n - 1; i+=2) a.pb(i);
            a[n - 1] += n / 2;
            
            cout << "YES" << endl;
            forn(i,0,n) cout << a[i] << ' ';
            cout << endl;
        }

        a.clear();
    }
}