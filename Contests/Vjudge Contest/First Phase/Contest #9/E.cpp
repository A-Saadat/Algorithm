#include <bits/stdc++.h> 
using namespace std; 

#define IOS ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0) 
#define fort(itr,map) for(auto itr = map.begin(); itr != map.end(); ++itr) 
#define pb push_back 
#define elif else if 
#define F first 
#define S second 
#define all(v) v.begin(), v.end() 
#define uni(v) sort(all(v)), v.erase(unique(all(v)), v.end()) 
#define int long long 

const int MAX = 1e6; 
const int INF = 1e9 + 7; 

vector<int> v; 

main()
{IOS;

    int n; cin >> n; int maxi = 0;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        v.pb(x);
        maxi = max(maxi, x);
    } 
    sort(all(v));
    // for(int u: v) cout << u << ' ';
    // cout << endl;

    int ans = 0, cnt = 0;
    for(int i = 1; i <= maxi; i++){
        int x = v.end() - lower_bound(all(v), i);
        // cout << i << ": " << x << endl;

        if(ans < x * i){
            ans = x * i;
            cnt = i;
        }
        // ans = max(ans, x * i);
        // cnt = i;
    }

    cout << ans << " " << cnt << endl;

}