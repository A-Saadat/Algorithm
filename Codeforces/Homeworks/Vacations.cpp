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
#define err_dp(i, j) cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << endl;
#define int long long 

const int MAX = 100 + 10; 
const int INF = 1e9 + 7; 

int dp[MAX][4], a[MAX]; 

// ? 0 = none
// ? 1 = contest
// ? 2 = gym
// ? 3 = both

main()
{IOS;

    int n; cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];

    dp[n][0] = 1;
    if(a[n] == 0){
        dp[n][1] = INF;
        dp[n][2] = INF;
    }
    elif(a[n] == 1) dp[n][2] = INF;    
    elif(a[n] == 2) dp[n][1] = INF;

    for(int i = n - 1; i >= 1; i--){
        dp[i][0] = min(dp[i + 1][0], min(dp[i + 1][1], dp[i + 1][2])) + 1;

        if(a[i] == 0){
            dp[i][1] = INF;
            dp[i][2] = INF;
        }
        elif(a[i] == 1){
            dp[i][1] = min(dp[i + 1][0], dp[i + 1][2]);
            dp[i][2] = INF;
        }
        elif(a[i] == 2){
            dp[i][2] = min(dp[i + 1][0], dp[i + 1][1]);
            dp[i][1] = INF;
        }
        else{
            dp[i][1] = min(dp[i + 1][0], dp[i + 1][2]);
            dp[i][2] = min(dp[i + 1][0], dp[i + 1][1]);
        }
    }


    int ans = INF;
    for(int i = 0; i < 3; i++)
        ans = min(ans, dp[1][i]);

    cout << ans << endl;
    

}