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
#define ll long long int 
typedef vector<int> vi;

const int MAX = 1e6; 
const ll INF = 1e9; 

ll a[MAX]; 
ll n, c, tc; 

bool check(int w){
    ll sum = 0;
    forn(i,0,n) {
        ll x = a[i] + (2 * w);
        
        if(tc - (x * x) <= 0) return 1;

        tc -= (x * x);
    } 
    
    return 0;

}

main()
{IOS;

    int t; cin >> t;
    while(t--){
        cin >> n >> c;
        forn(i,0,n) cin >> a[i];

        ll L = 0, R = INF;
        while(R - L > 1){
            tc = c;
            ll mid = (R + L) / 2;

            if(check(mid)) R = mid;
            else L = mid;

        }

        cout << R << endl;
    }

}