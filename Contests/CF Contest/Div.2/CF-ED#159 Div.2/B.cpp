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

int cu_ceil(int x, int y){
    return ((x / y) + min(1LL * 1, x % y));
}

main()
{IOS;

    int t; cin >> t;
    while(t--){

        int n, p, l, t; cin >> n >> p >> l >> t;
        int k = (n - 1) / 7 + 1;
        int ans = k / 2;
        int sum = (k / 2) * (l + (2 * t));
        if(p == sum) ans = k / 2;
        elif(p < sum){
            ans = cu_ceil(p, (l + 2 * t));
        }
        else{
            if(k % 2) sum += (l + t), ans++;
            if(p > sum){
                ans += cu_ceil((p - sum), l);
            }
        }

        cout << n - ans << endl;
    }

}