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
#define err_dp(i, j, x, y) cout << "dp[" << i << "][" << j << "][" << x << "][" << y << "] = " << dp[i][j][x] << endl;
#define int long long 

const int MAX = 300 + 10; 
const int INF = 1e9 + 7; 

int a[MAX][MAX]; 
int dp[MAX][MAX][MAX]; // ? FUCK, 3D dp

main()
{IOS;

    int n; cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> a[i][j];

    for(int i = 0; i <= n + 1; i++)
        for(int j = 0; j <= n + 1; j++) 
            for(int x = 0; x <= n + 1; x++)
                dp[i][j][x] = -INF;   

    dp[n][n][n] = a[n][n];

    for(int i = n; i >= 1; i--){
        for(int j = n; j >= 1; j--){
            for(int x = n; x >= 1; x--){
                if(i == n && j == n && x == n) continue;
                int y = i + j - x;
                if(y <= 0 || y > n) continue;

                int s1 = dp[i + 1][j][x];
                int s2 = dp[i + 1][j][x + 1];
                int s3 = dp[i][j + 1][x];
                int s4 = dp[i][j + 1][x + 1];

                dp[i][j][x] = max(max(s1, s2), max(s3, s4)) + a[i][j] + a[x][y];
                if(i == x || j == y) dp[i][j][x] -= a[i][j];
                }
            }
        }

    cout << dp[1][1][1] << endl;
}
