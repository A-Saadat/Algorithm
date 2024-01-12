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
const ll INF = 1LL * 1000 * 1000 * 1000 * 1000 * 1000 * 1000; 

ll a[MAX]; 
int n; 

bool check(ll x){
    ll sum = 0;
    for(int i = 1; i <= n; i++){
        sum += x - a[i];
        if(sum >= x) return 1;
    } 
    return 0;
}

main()
{IOS;

    cin >> n;
    ll maxi = 0;
    for(int i = 1; i <= n; i++) cin >> a[i], maxi = max(maxi, a[i]);

    ll L = maxi - 1, R = INF;
    while(R - L > 1){
        ll mid = (R + L) / 2;
        if(check(mid)) R = mid;
        else L = mid;
    }

    cout << R << endl;
}