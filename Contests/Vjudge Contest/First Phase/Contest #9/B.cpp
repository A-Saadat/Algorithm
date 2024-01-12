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
#define err_dp(i, j, k) cout << "dp[" << i << "][" << j << "][" << k << "] = " << dp[i][j][k] << endl;
#define int long long 

const int MAX = 200 + 10; 
const int INF = 1e9 + 7; 

int dp[MAX][MAX][MAX]; 
struct nod{
    int p; int c; int x;
} a[MAX];

main()
{IOS;

    int n, A, B; cin >> n >> A >> B;
    for(int i = 1; i <= n; i++){
        int p, c, x; cin >> p >> c >> x;
        a[i] = {p, c, x};
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= A; j++){
            for(int k = 0; k <= B; k++){
                int maxi = 0;
                for(int w = 0; (w * a[i].x) <= k; w++){
                    if((j - a[i].c + w) < 0 || w > a[i].c) continue;
                    maxi = max(maxi, dp[i - 1][j - a[i].c + w][k - (w * a[i].x)] + a[i].p);
                }
                dp[i][j][k] = max(dp[i - 1][j][k], maxi);
                // err_dp(i, j, k);
            }
            // cout << endl;
        }
        // cout << "\n-----------------\n";
    }

    cout << dp[n][A][B] << endl;

}