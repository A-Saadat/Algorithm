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

const int MAX = 2e5 + 10; 
const int INF = 1e9 + 7; 

int a[MAX], b[MAX]; 

inline int lcm(int x, int y){
    return x * y / __gcd(x, y);
}

main()
{IOS;

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        for(int i = 1; i <= n; i++) cin >> a[i] >> b[i];

        int GCD = 0, LCM = 1, ans = 1;
        for(int i = 1; i <= n; i++){
            GCD = __gcd(GCD, (b[i] * a[i]));
            LCM = lcm(LCM, b[i]);

            if(GCD % LCM){
                ans++;
                LCM = b[i];
                GCD = a[i] * b[i];
            }
        }

        cout << ans << endl;
    }

}