#include <bits/stdc++.h> 
using namespace std; 

#define def 10000000 
#define forn(i,k,n) for(int i = k; i < n; i++) 
#define forb(i,n,k) for(int i = n; i >= k; i--) 
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
ll a[def], b[def];
mll x;

int main (void)
{
    ll n; cin >> n;
    forn(i,0,n){
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b, b + n);

    forn(i,0,n) x[b[i]] = i;
    forn(i,0,n) a[i] = x[a[i]];

    ll L = -1;
    forn(i,0,n) if(a[i] != i){ L = i; break; }
    ll R = -1;
    forb(i,(n - 1),0) if(a[i] != i) { R = i; break; }

    if(L == -1 or R == -1) cout << "yes" << endl << 1 << ' ' << 1;
    else{
        reverse(a + L, a + R + 1);
        forn(i,0,n)
            if(a[i] != i) { cout << "no"; return 0; }
        
        cout << "yes" << endl << L + 1 << ' ' << R + 1;
    }

}