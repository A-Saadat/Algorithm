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

vector< pair<int, int> > v; // ? strength 
int dp[MAX][(1 << 7) + 10]; 
int s[MAX][10];
 
inline string bin(int mask){
    string ans;
    while(mask > 0){
        if(mask & 1) ans += '1';
        else ans += '0'; 
        mask >>= 1;
    }
    reverse(all(ans));
    return ans;
}

main()
{IOS;

    int n, p, k; cin >> n >> p >> k;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        v.pb({x, i});
    }

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= p; j++)
            cin >> s[i][j];

    sort(v.rbegin(), v.rend());
    for(int i = 0; i < p; i++) dp[1][(1 << i)] = s[1][i + 1];
    dp[1][0] = v[0].F;
    for(int i = 2; i <= n; i++){
        int id = v[i - 1].S, val = v[i - 1].F;
        
        for(int mask = 0; mask < (1 << p); mask++){
            // ? if the number of people that we seen - the number of player that we picked is less than k, we can still pick an audience
            dp[i][mask] = dp[i - 1][mask] + (i - __builtin_popcount(mask) <= k ? val : 0); 
            for(int j = 0; j < p; j++)
                if(((mask >> j) & 1)) 
                    dp[i][mask] = max(dp[i][mask], dp[i - 1][mask ^ (1 << j)] + s[id][j + 1]);
            // cout << "dp[" << i << "][" << bin(mask) << "] = " << dp[i][mask] << endl;
        }
        // cout << "\n---------------------\n";
    }

    // for(int mask = 0; mask < (1 << p); mask++){
    //     for(int i = 1; i <= n; i++){
    //         // int id = v[i - 1].S, val = v[i - 1].F;
    //         // dp[i][mask] = dp[i - 1][mask] + (i - __builtin_popcount(mask) <= k && i - __builtin_popcount(mask) >= 0 ? val : 0); 
            
    //         // for(int j = 0; j < p; j++)
    //         //     if(((mask >> j) & 1) && i >= __builtin_popcount(mask)) 
    //                 // dp[i][mask] = max(dp[i][mask], dp[i - 1][mask ^ (1 << j)] + s[id][j + 1]);

    //         cout << "dp[" << i << "][" << bin(mask) << "] = " << dp[i][mask] << endl;
    //     }
    //     cout << "\n---------------------\n";

    // }

    cout << dp[n][(1 << p) - 1] << endl;

}