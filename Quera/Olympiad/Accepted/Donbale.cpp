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
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")

const int MAX = 1e5 + 1; 
const int INF = 1e9 + 7; 

// int a[MAX]; 
vector<int> a, ps;

signed main()
{IOS;

    int n; cin >> n;
    a.resize(n + 2), ps.resize(n + 2);
    for(int i = 1; i <= n; i++) cin >> a[i], ps[i] = ps[i - 1] + a[i];

    int q; cin >> q;
    while(q--){
        int s, k; cin >> s >> k;
        if(k == 1) cout << ps[n] - ps[s - 1] << '\n';
        else{
            int ans = 0;
            for(int i = s; i <= n; i+=k) ans += a[i];
            cout << ans << '\n';
        }
    }

}