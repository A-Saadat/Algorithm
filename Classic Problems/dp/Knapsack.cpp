// 57 54 46 
#include <bits/stdc++.h> 
using namespace std; 

#define forn(i,k,n) for(int i = k; i < n; i++) 
#define fort(itr,map) for(auto itr = map.begin(); itr != map.end(); ++itr) 
#define IOS ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0); 
#define pb push_back 
#define F first 
#define S second 
#define gcd __gcd 
#define elif else if 
#define all(v) v.begin(), v.end() 
#define uni(v) sort(all(v)), v.erase(unique(all(v)), v.end()) 
#define err(x) cout << '#' << x << ':' << ' ' << x << endl 
typedef long long int ll; 
typedef vector<int> vi;

const ll MaxN = 1e3; 
const ll INF = -(1e9 + 7); 

int dp[MaxN][MaxN]; 
int val[MaxN], wgh[MaxN];

main()
{IOS;

    int n, W; cin >> n >> W;
    forn(i,1,n + 1) cin >> val[i];
    forn(i,1,n + 1) cin >> wgh[i];

    forn(i,1,n + 1){

        forn(j,1,W + 1){
            if(j - wgh[i] >= 0)
                dp[i][j] = max(dp[i - 1][j], (dp[i - 1][ j - wgh[i] ] + val[i]) );
            else 
                dp[i][j] = dp[i - 1][j];
        } 

    }

    int ans = 0;
    forn(i,1,W + 1) ans = max(ans, dp[n][i]);


    cout << ans << endl;

}