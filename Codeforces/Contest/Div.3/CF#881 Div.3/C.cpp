#include <bits/stdc++.h> 
using namespace std; 

#define forn(i,k,n) for(int i = k; i < n; i++) 
#define fort(itr,map) for(auto itr = map.begin(); itr != map.end(); ++itr) 
#define IOS ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0) 
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

int a[MaxN]; 

main()
{IOS;

    int t; cin >> t;
    while(t--){
        ll n; cin >> n;

        ll ans = n;
        while(n > 1){
            ans += n / 2;
            n /= 2;
        }

        cout << ans << endl;
    }

}