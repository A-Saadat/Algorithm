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
typedef vector<int> vi;

const int MAX = 1e6 + 10; 
const int INF = 1e9 + 7; 

int dp[MAX]; 
int n;

inline void Update_dp(int x){
    int mini = INF;
    
    int tmp = x;
    while(tmp){
        int k = tmp % 10;
        mini = min(mini, dp[x - k]);
        tmp /= 10;
    }

    dp[x] = mini + 1;
}

main()
{IOS;

    cin >> n;
    fill(dp, dp + MAX, INF);
    for(int i = 1; i <= 9; i++) dp[i] = 1; // ? initial values

    for(int i = 10; i <= n; i++)
        Update_dp(i);

    cout << dp[n];
}