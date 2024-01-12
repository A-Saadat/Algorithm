#include <bits/stdc++.h> 
using namespace std; 

#define IOS ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0) 
#define forn(i,k,n) for(int i = k; i < n; i++) 
#define fort(itr,map) for(auto itr = map.begin(); itr != map.end(); ++itr) 
#define pb push_back 
#define elif else if 
#define F first 
#define S second 
#define gcd __gcd 
#define all(v) v.begin(), v.end() 
#define uni(v) sort(all(v)), v.erase(unique(all(v)), v.end()) 
#define err_mx(i, j) cout << "mx[" << i << "][" << i + (1 << j) << "] = " << mx[i][j].F << " with index " << mx[i][j].S << endl;
typedef long long int ll; 
typedef vector<int> vi;

const int MAX = 1e6; 
const int INF = 1e9 + 7; 

int n;
ll sum = 1;
int dp[MAX], a[MAX];
pair<int, int> mx[MAX][30];

inline void Update_dp(){
    for(int i = n - 2; i >= 1; i--){
        mx[i][0] = max( make_pair(a[i], i) , make_pair(a[i + 1], i + 1) );

        for(int k = 1; k <= 22; k++){
            if(i + (1 << k) > n - 1) break;
            mx[i][k] = max( mx[i][k - 1], mx[i + (1 << (k - 1))][k - 1] );
        }
    }
}

inline int RMQ(int L, int R){
    if(L == R) return R;

    pair<int, int> ans = mx[L][0];
    for(int k = 22; k >= 0; k--){
        if(L + (1 << k) > n - 1) continue;

        ans = max(ans, mx[L][k]);
        L += (1 << k); 
    }

    return ans.S;
}

main()
{IOS;

    cin >> n;
    for(int i = 1; i < n; i++) cin >> a[i];
    
    Update_dp();
    dp[n] = 0, dp[n - 1] = 1;
    for(int i = n - 2; i >= 1; i--){
        int m = RMQ(i + 1, a[i]);

        dp[i] = dp[m] - (a[i] - m) + n - i;
        if(a[i] == n) dp[i] = n - i;

        sum += dp[i];
    }

    cout << sum << endl;
}