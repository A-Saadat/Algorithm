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

const int MAX = 1e3 + 10; 
const int MOD = 1e9 + 7; 

char a[MAX][MAX];
int dp[MAX][MAX]; 

main()
{IOS;

    int n; cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) 
            cin >> a[i][j];

    dp[n][n] = 1;

    if(a[n][n] == '*'){
        cout << 0 << endl;
        return 0;
    }

    for(int i = n; i >= 1; i--){
        for(int j = n; j >= 1; j--){
            if( (j == n && i == n) || a[i][j] == '*' ) continue;

            dp[i][j] = (dp[i + 1][j] + dp[i][j + 1]) % MOD;
        }
    }

    cout << dp[1][1] % MOD << endl;
}