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
const char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
ll y[def], x[def];
bool allow;

int main (void)
{
    ios_base::sync_with_stdio(false);

    ll t; cin >> t;
    while(t--){
        forn(i,0,3) cin >> x[i] >> y[i];
        ll ans = 0;

        ll a1 = x[0], a2 = y[0];
        ll b1 = x[1], b2 = y[1];
        ll f1 = x[2], f2 = y[2];

        ans += abs(a1 - b1) + abs(a2 - b2);
        if(a1 == b1 and a1 == f1 and f2 > min(a2, b2) and f2 < max(a2, b2) || 
           a2 == b2 and a2 == f2 and f1 > min(a1, b1) and f1 < max(a1, b1)
        ) ans += 2;

        cout << ans << endl;
    }
}

