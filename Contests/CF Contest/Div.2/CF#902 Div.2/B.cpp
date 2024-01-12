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

const int MAX = 1e5 + 10; 
const int INF = 1e9 + 7; 

vector<pair<int, int>> v; 
int a[MAX], b[MAX];

main()
{IOS;

    int t; cin >> t;
    while(t--){
        v.clear();
        int n, q; cin >> n >> q;
        for(int i = 1; i <= n; i++) cin >> a[i];
        for(int i = 1; i <= n; i++) cin >> b[i];

        for(int i = 1; i <= n; i++)
            v.pb( {b[i], a[i]} );

        sort(all(v));

        int ans = q * n, c = 1; // ? c = the index of last person that i made better
        for(int i = 0; i < n && c < n; i++){
            int cnt = min(v[i].S, n - c), cost = v[i].F;

            if(cost >= q) break;
            if(cnt <= 0) continue;

            ans -= cnt * q;
            ans += cnt * cost;
            c += cnt;
        }    

        cout << ans << endl;
    }    

}