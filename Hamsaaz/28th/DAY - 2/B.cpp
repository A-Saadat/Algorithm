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

const int MaxN = 1e6; 
const int MOD = 93283; 

ll dp[MaxN], fact[MaxN]; 

main()
{IOS;

    int k = 4;

    fact[1] = 1;
    for(int i = 2; i <= 200; i++) fact[i] = (fact[i - 1] * i) % MOD;
    // for(int i = 2; i <= 200; i++) cout << i << ": " << fact[i] << endl;

    dp[1] = 1; dp[2] = 2; dp[3] = 3; dp[4] = 4;
    for(int i = 5; i <= 100; i++){
        int x = ((i - 1) / k) + (!((i - 1) % k) ? 0 : 1) + 1;
        dp[i] = dp[i - 1] + x % MOD;
        // cout << i << ": " << fact[i] << " -> " << x << endl; 
    }

    // cout << "\n----------------------\n";

    // for(int i = 1; i <= 100; i++) cout << "dp[" << i << "] = " << dp[i] << endl;

    cout << (fact[100] * dp[100]) % MOD;
}