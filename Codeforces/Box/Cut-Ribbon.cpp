#include <bits/stdc++.h> 
using namespace std; 

#define def 10000000 
#define forn(i,k,n) for(int i = k; i < n; i++) 
#define fort(itr,map) for(auto itr = map.begin(); itr != map.end(); ++itr) 
#define IOS ios_base::sync_with_stdio(false) 
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

ll x[def];

int main (void)
{IOS;


    // if(a == b && a == c && b == c & a == n) { cout << 1 << endl; return 0; } 

    // ll ans = 0;
    // for(ll i = 0; n - (i * a) >= 0; i++){
    //     ll cnt = i;
    //     ll ribbon = n - (i * a);
        
    //     // cout << ribbon << ' ' << i * a << endl;

    //     for(ll j = 0; ribbon - (j * b) >= 0; j++){

    //         ribbon = n - (j * b);

    //         cnt += j;

    //         cnt += ribbon / c;
            
    //         ans = max(cnt, ans);
    //     }

    // }

    // cout << ans << endl;

    ll n, a, b, c; cin >> n >> a >> b >> c;

    x[0] = 0;
    for(ll i = 1; i <= n; i++){
        ll ans1 = (i < a) ? -1 : x[i - a];
        ll ans2 = (i < b) ? -1 : x[i - b];
        ll ans3 = (i < c) ? -1 : x[i - c];
        x[i] = max(ans1, max(ans2, ans3));
        if(x[i] > -1) x[i]++;

        cout << ans1 << ' ' << ans2 << ' ' << ans3 << endl;
    }
    cout << x[n];

}