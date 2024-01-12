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

const int MAX = 1e5 + 10; 
const int INF = 1e9 + 7; 

int dp[MAX], h[MAX]; 

main()
{IOS;

    int n, k; cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> h[i];
    dp[n - 1] = abs(h[n - 1] - h[n]);
    for(int i = n - 2; i >= 1; i--){
        int mini = INF;
        for(int j = i + 1; j <= min(i + k, n); j++) mini = min(mini, abs(h[i] - h[j]) + dp[j]);
        dp[i] = mini;
    }

    cout << dp[1] << endl;
}