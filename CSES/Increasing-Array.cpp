// ! I AM NOT INSANE 
#include <bits/stdc++.h> 
using namespace std; 

#define forn(i,k,n) for(int i = k; i < n; i++) 
#define fort(itr,map) for(auto itr = map.begin(); itr != map.end(); ++itr) 
#define IOS ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0); 
#define pb push_back 
#define F first 
#define S second 
#define gcd __gcd 
#define elif else if 
#define all(v) v.begin(), v.end() 
#define uni(v) sort(all(v)), v.erase(unique(all(v)), v.end()) 
#define err(x) cout << '#' << x << ':' << ' ' << x << endl 
typedef long long int ll; 
typedef vector<int> vi;

const int MaxN = 1e6; 
const int MOD = 1e9 + 7; 

ll a[MaxN]; 

main()
{IOS;

    int n; cin >> n;
    forn(i,0,n) cin >> a[i];

    ll ans = 0;
    forn(i,1,n){
        if(a[i] - a[i - 1] < 0){
            ll x = a[i - 1] - a[i]; 
            a[i] = a[i - 1]; ans += x;
        }
    }

    cout << ans;
}