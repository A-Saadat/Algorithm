// ! I AM NOT INSANE 
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

const int MaxN = 1e6; 
const int MOD = 1e9 + 7; 

ll a[MaxN], sum[MaxN], dp[MaxN]; 
ll mxNum = 0, mnNum = MaxN; // ? Minimum and Maximum number in the given array

main()
{IOS;

    ll n; cin >> n;
    forn(i,0,n) cin >> a[i];
    
    forn(i,0,n){
        sum[ a[i] ] += a[i]; 
        mxNum = max( a[i], mxNum );
        mnNum = min( a[i], mnNum );
    } 
    
    dp[mnNum] = sum[mnNum];
    forn( i, mnNum + 1, mxNum + 1 ){
        dp[i] = max(dp[i - 1], dp[i - 2] + sum[i]);
    }

    // forn(i, mnNum ,mxNum + 1) cout << "dp[" << i << "]: " << dp[i] << endl;

    cout << dp[mxNum] << endl;
    
}
