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
#define gcd __gcd 
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
const char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

bool Checker[def];
ll Sum[def];

int main (void)
{
    ios_base::sync_with_stdio(false);

    string s; cin >> s;
    ll n = s.size();

    forn(i,0,(n - 1))
        if(s[i] == s[i + 1]) Checker[i] = 1;
    
    forn(i,0,n) Sum[i] = Sum[i - 1] + Checker[i];  

    ll t; cin >> t;
    while(t--){
        ll L, R; cin >> L >> R;

        R -= 2; L -= 1;
        ll ans = Sum[R] - Sum[L - 1];

        cout << ans << endl;
    }
}