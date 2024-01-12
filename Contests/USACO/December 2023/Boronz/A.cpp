#include <bits/stdc++.h> 
using namespace std; 

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#define IOS ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0) 
#define fort(itr,map) for(auto itr = map.begin(); itr != map.end(); ++itr) 
#define pb push_back 
#define elif else if 
#define F first 
#define S second 
#define all(v) v.begin(), v.end() 
#define uni(v) sort(all(v)), v.erase(unique(all(v)), v.end()) 
#define int long long 

const int MAX = 2e5 + 10; 
const int INF = 1e9 + 7; 

int a[MAX], pre[MAX]; 

main()
{IOS;

    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i], pre[i] = max(pre[i - 1], a[i]);

    while(m--){
        int x; cin >> x;
        for(int i = 1; i <= n; i++){
            int h = min(x, a[i]);
            if(h < pre[i - 1]) continue;
            a[i] += h - pre[i - 1];
        }
        for(int i = 1; i <= n; i++) pre[i] = max(pre[i - 1], a[i]);
    }

    for(int i = 1; i <= n; i++) cout << a[i] << endl;

}