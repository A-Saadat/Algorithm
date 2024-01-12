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

const int MAX = 1000; 
const int INF = 1e9 + 7; 

int x[MAX]; 

main()
{IOS;

    int t; cin >> t;
    while(t--){
        int a, b, n; cin >> a >> b >> n;
        int ans = 0;
        for(int i = 1; i <= n; i++){
            cin >> x[i];
            ans += b - 1;
            b = min(a, x[i] + 1);
        }
        ans += b;
        cout << ans << endl;
    }    

}