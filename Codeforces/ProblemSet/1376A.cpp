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
vcc a; vcc tmp; 

int main (void)
{
    ll n; cin >> n;

    forn(i,0,n){
        // string s; s.clear(); cin >> s;
        // a.clear(); tmp.clear();

        // for(ll i = 0; i < 2; i++) a.pb(s[i]);

        // if(s.size() > 6){
        //     for(ll i = 3; i < s.size() - 3; i++) tmp.pb(s[i]);
        //     for(ll i = 0; i < tmp.size() - 1; i+=2) a.pb(tmp[i]);
        // }

        // tmp.clear();
        // for(ll i = s.size(); i > s.size() - 3; i--) tmp.pb(s[i]);
        // reverse(tmp.begin(), tmp.end()); forn(i,0,tmp.size()) a.pb(tmp[i]);

        // string ans; 
        // forn(i,0,a.size()) ans += a[i];
        // cout << ans << endl;
        // ans.clear();

        string s; cin >> s;
        string ans = s.substr(0, 2);
        
        for(ll i = 3; i < s.size(); i += 2) ans += s[i];
        cout << ans << endl;
    }
}