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

int dp[MAX], h[MAX]; 

main()
{IOS;

    int n; cin >> n;
    for(int i = 1; i <= n; i++) cin >> h[i];
    dp[n] = 0;
    dp[n - 1] = abs(h[n - 1] - h[n]);
    for(int i = n - 2; i >= 1; i--){
        int r1 = abs(h[i] - h[i + 1]) + dp[i + 1];
        int r2 = abs(h[i] - h[i + 2]) + dp[i + 2];
        dp[i] = min(r1, r2);
    }
    cout << dp[1] << endl;
}