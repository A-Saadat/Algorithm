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

int a[MAX], b[MAX]; 

main()
{IOS;

    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        vector<int> pre(n + 3), prmx(n + 3);
        for(int i = 1; i <= n; i++) cin >> a[i], pre[i] = pre[i - 1] + a[i];
        for(int i = 1; i <= n; i++) cin >> b[i], prmx[i] = max(prmx[i - 1], b[i]);

        int ans = 0;
        for(int i = 1; i <= min(n, k); i++) {
            ans = max(ans, pre[i] + max(k - i,1LL*  0) * prmx[i]);
            // cout << pre[i] << " " << max(k - i,1LL*  0) * prmx[i] << endl;
        }
        cout << ans << endl;
    }

}