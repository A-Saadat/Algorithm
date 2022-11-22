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

const ll def = 1e6; 
const char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};


ll f(ll t[], ll n, ll x){
    ll L = 0, R = n - 1, cnt = 0;

    while(R - L > 0){
        if(t[R] + t[L] > x) R--;
        else L++, cnt++;
    }

    return cnt;
}

ll a[def], b[def];
ll ans;

int main (void)
{IOS;

    ll n; cin >> n;
    forn(i,0,n) cin >> a[i];

    forn(k,0,25){

        forn(i,0,n)
            b[i] = a[i] % (1 << (k + 1));
        sort(b, b + n);

        ll P = f(b, n, (1 << (k + 2)) - 2) - f(b, n, (1 << k) + (1 << (k + 1)));
        ll N = f(b, n, (1 << (k + 1)) - 1) - f(b, n, (1 << k));

        // cout << P << ' ' << N << endl;

        if((P + N) % 2 == 0 && P + N > 0) ans += (1 << k);
    }

    cout << ans;
    
}