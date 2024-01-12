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
#define err(x) cout << '#' << x << ':' << ' ' << x << endl 
typedef long long int ll; 
typedef vector<int> vi;

const int MaxN = 120; 
const int INF = 1e9 + 7; 

int a[MaxN], dp[MaxN][MaxN]; 

main()
{IOS;

    int n, cnt = 0; cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i], (a[i] ? cnt++ : 0);

    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++) {
            dp[i][j] = dp[i][j - 1] + (a[j] == 0 ? 1 : -1);

            // cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << endl;
        }

        // cout << "\n---------------\n";
    }


    int maxi = -INF;
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++) {
            maxi = max(maxi, dp[i][j]);
        }

    }

    cout << cnt + maxi << endl;
    

}