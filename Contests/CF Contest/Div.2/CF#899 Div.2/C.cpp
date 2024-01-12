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
#define err_dp(i) cout << "dp[" << i << "] = " << dp[i] << endl;
typedef vector<int> vi;

const int MAX = 2e5 + 100; 
const int INF = 1e9 + 7; 

int a[MAX], dp[MAX]; 
int n; 

inline void Update_dp(){
    for(int i = 1; i <= n + 20; i++) dp[i] = 0;
    dp[n] = max(a[n], 1LL * 0);
    for(int i = n - 1; i >= 1; i--){
        dp[i] = max( max(dp[i + 1] + a[i], dp[i + 2] + a[i]), max(dp[i + 2], dp[i + 3]));
        dp[i] = max(dp[i], 1LL * 0);
    }
}

main()
{IOS;

    int t; cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1; i <= n + 20; i++) a[i] = 0;
        for(int i = 1; i <= n; i++) cin >> a[i];
        Update_dp();
        cout << dp[1] << endl;
    }

}