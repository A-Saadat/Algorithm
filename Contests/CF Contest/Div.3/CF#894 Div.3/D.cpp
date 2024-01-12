#include <bits/stdc++.h> 
using namespace std; 

#define IOS ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0) 
#define forn(i,k,n) for(int i = k; i < n; i++) 
#define fort(itr,map) for(auto itr = map.begin(); itr != map.end(); ++itr) 
#define pb push_back 
#define elif else if 
#define F first 
#define S second 
#define gcd __gcd 
#define all(v) v.begin(), v.end() 
#define uni(v) sort(all(v)), v.erase(unique(all(v)), v.end()) 
typedef long long int ll; 
typedef vector<int> vi;

const int MAX = 1e6; 
const ll INF = 1LL * 3 * 1000 * 1000 * 1000 + 1000; 

ll n;

inline bool check(ll x){
    ll u = x * (x - 1) / 2;
    if(u > n) return 0;
    else return 1;
}

inline ll BS(){
    ll L = 2, R = INF;
    while(R - L > 1){
        ll mid = (R + L) / 2;
        if(check(mid)) L = mid;
        else R = mid;
    }
    return L;
}

main()
{IOS;

    int t; cin >> t;
    while(t--){
        cin >> n;
        ll ans = BS();
        ll x = n - (ans * (ans - 1) / 2);
        cout << ans + x << endl;
    }

}