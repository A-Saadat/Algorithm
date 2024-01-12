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

main()
{IOS;

    int t; cin >> t;
    while(t--){
        int n; cin >> n; bool isT = 0;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            if(a[i] >= 0) isT = 1; 
        } 

        int ans = -INF, mx = 0;
        for(int i = 1; i <= n; i++){
            if(i > 1 && abs(a[i]) % 2 == abs(a[i - 1]) % 2) mx = 0;
            mx += a[i];
            ans = max(ans, mx);
            if(mx < 0) mx = 0;
        }

        if(!isT)
            for(int i = 1; i <= n; i++) ans = max(ans, a[i]);


        cout << ans << endl;
    }

}