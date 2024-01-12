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
#define err_dp(i, j) cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << " || ";
typedef vector<int> vi;

const int MAX = 1e5 + 100; 
const int MAXK = 1e3 + 100; 
const int INF = 1e9 + 7; 

int dp[MAXK][MAX];
int page[MAXK], cost[MAXK]; 

main()
{IOS;

    int n, x; cin >> n >> x;
    for(int i = 1; i <= n; i++) cin >> cost[i];
    for(int i = 1; i <= n; i++) cin >> page[i];

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= x; j++){

            if(j - cost[i] >= 0) 
                dp[i][j] = max(dp[i - 1][j], (dp[i - 1][j - cost[i]] + page[i]));
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    cout << dp[n][x] << endl;
}