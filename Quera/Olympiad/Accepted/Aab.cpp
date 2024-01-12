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

int a[MAX]; 
vector<int> pre, suf;

signed main()
{IOS;

    int n; cin >> n;
    pre.resize(n + 5), suf.resize(n + 5);
    for(int i = 1; i <= n; i++) cin >> a[i];
    
    for(int i = 1; i <= n; i++) pre[i] = max(pre[i - 1], a[i]);
    for(int i = n; i >= 1; i--) suf[i] = max(suf[i + 1], a[i]);

    int ans = 0;
    for(int i = 1; i <= n; i++){
        int x = min(pre[i - 1], suf[i + 1]);
        if(a[i] >= x) continue;
        ans += x - a[i];
    }

    cout << ans << endl;
}