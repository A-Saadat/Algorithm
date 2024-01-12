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
typedef vector<int> vi;

const int MAX = 2e5 + 10; 
const int INF = 1e9 + 7; 

vector<int> v[50];
int a[MAX];

inline bool check(int L, int R, int k){
    int ans = 0;
    for(int i = 0; i < 32; i++){
        auto itr = lower_bound(all(v[i]), L);
        if(itr == v[i].end() || *itr > R)
            ans += (1 << i);
    }

    return (ans >= k);
}

main()
{IOS;

    int t; cin >> t;
    while(t--){
        for(int i = 0; i < 32; i++) v[i].clear();
        int n; cin >> n;
        for(int i = 1; i <= n; i++) cin >> a[i];
        for(int j = 0; j <= 31; j++){
            for(int i = 1; i <= n; i++){
                if(((a[i] >> j) & 1)) continue;

                v[j].pb(i);
            }
        }

        for(int i = 0; i < 32; i++) sort(all(v[i]));

        int q; cin >> q;
        while(q--){
            int l, k; cin >> l >> k;
            
            int L = l, R = n + 1;
            while(R - L > 1){
                int mid = (R + L) / 2;
                if(check(l, mid, k)) L = mid;
                else R = mid;
            }

            if(L == l) cout << (a[L] >= k ? L : -1) << ' ';
            else cout << L << ' ';
        }
    }

}