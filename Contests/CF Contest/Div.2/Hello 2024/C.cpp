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
        int n; cin >> n;
        for(int i = 0; i < n + 3; i++) a[i] = 0;
        for(int i = 1; i <= n; i++) cin >> a[i];

        int ans = 0, c1, c2, idx;
        for(idx = 1; idx < n; idx++){
            if(a[idx] >= a[idx + 1]) continue;
            c1 = a[idx]; c2 = a[idx + 1]; 
            break;
        }

        for(int i = idx + 2; i <= n; i++){
            if(a[i] <= c1) c1 = a[i];
            elif(a[i] > c2) c1 = a[i], ans++;
            else c2 = a[i];
    
            if(c1 > c2) swap(c1, c2);
        }

        cout << ans << endl;
        
    }

}