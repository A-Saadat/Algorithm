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
#define err_dp(i, j) cout << "dp[" << i << "][" << (1 << j) << "] = " << dp[i][j] << endl;
typedef long long int ll; 
typedef vector<int> vi;

const int MAX = 1e6; 
const int INF = 1e9 + 7; 

int a[MAX], dp[MAX][50]; 
int n; 

inline void Update_dp(){
    for(int i = 1; i < n; i++) 
        dp[i][0] = min(a[i], a[i + 1]); // ? Base of dp

    for(int k = 1; k <= 22; k++)
        for(int i = 1; (i + (1 << k) <= n); i++)
            dp[i][k] = min(dp[i][k - 1], dp[i + (1 << (k - 1))][k - 1]);
}

inline int Solve(int l, int r){
    int ans = INF;
    for(int k = 22; k >= 0; k--)
        if(l + (1 << k) <= r){
            ans = min(ans, dp[l][k]);
            l = l + (1 << k);
        }
    
    return ans;
}

main()
{IOS;

    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    Update_dp();

    int q; cin >> q;
    while(q--){
        int l, r; cin >> l >> r;
        ++l, ++r;
        if(l == r) cout << a[l] << endl;
        else cout << Solve(l, r) << endl;
    }
}