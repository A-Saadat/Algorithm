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
#define err_dp(i) cout << "dp[" << i << "] = " << dp[i] << endl;
#define int long long 

const int MAX = 1e6; 
const int INF = 1e9 + 7; 

set<int> s; 
map<int, int> cnt, dp;  
vector< pair<int, int> > v; 
int tt;

main()
{IOS;

    int S, n; cin >> S >> n;
    for(int i = 1; i <= n; i++){
        cin >> tt;
        s.insert(tt);
        cnt[tt]++;
    }
    int d = 0;
    fort(itr, s) {
        int x = *itr;
        dp[x] = d + cnt[x];
        d = dp[x];

        v.pb( {dp[x], x} );
    }
    sort(all(v));

    int q; cin >> q;
    while(q--){
        int x; cin >> x;
        pair<int, int> p = make_pair(x, 0);
        auto itr = upper_bound(all(v), p);
        if(itr == v.end()) cout << S << endl;
        else{
            int i = itr->S - 1;
            cout << max(i, 1LL* 0) << endl;
        }
    }

}