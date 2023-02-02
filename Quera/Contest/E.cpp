// 57 54 46 
#include <bits/stdc++.h> 
using namespace std; 

#define forn(i,k,n) for(int i = k; i < n; i++) 
#define fort(itr,map) for(auto itr = map.begin(); itr != map.end(); ++itr) 
#define IOS ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0); 
#define pb push_back 
#define F first 
#define S second 
#define mp make_pair 
#define gcd __gcd 
#define elif else if 
#define all(v) v.begin(), v.end() 
#define uni(v) sort(all(v)), v.erase(unique(all(v)), v.end()) 
#define scan(a, n) for(int i = 0; i < n; i++) cin >> a[i]; 
typedef int64_t ll; 
typedef map<string, int> msi;  
typedef map<char, int> mci; 
typedef map<ll, ll> mll; 
typedef set<int> si;  
typedef vector<ll> vci;
typedef pair<int,int> pii; 
typedef vector<pii> vpii; 
typedef vector<string> vs; 
typedef vector<bool> vb; 
typedef vector<double> vd; 
typedef vector<char> vcc; 

const ll MaxN = 1e6; 
const ll INF = 1e9 + 7; 
const char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

ll cu_mult(ll a, ll b, ll c){
    ll m = a, ans = 0;
    while(b > 0){
        if((b & 1)){
            if((ans + m) < (c + c) && ans + m > c) ans = ans + m - c;
            elif(ans + m > c) ans = (ans + m) % c;
            else ans = ans + m;
        }
        if((m + m) < (c + c) && m + m > c) m = m + m - c;
        elif(m + m > c) m = (m + m) % c;
        else m = m + m;
        
        b >>= 1;
    }

    return ans;
}

ll cu_pow(ll a, ll b, ll c){
    ll ans = 1, p = a;

    ll idx = 0;
    while(b > 0){
        if((b & 1)) ans = cu_mult(ans, p, c);
        
        p = cu_mult(p, p, c);
        b >>= 1;
        ++idx;
        cout << idx << endl;
    }

    return ans;
}


int main ()
{IOS;

    ll t; cin >> t;
    while(t--){
        ll a, b, c; cin >> a >> b >> c;
        ll ans = cu_pow(a, b, c);
        cout << ans << endl;
    }

}