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
typedef long long int ll; 
typedef vector<int> vi;

const int MAX = 1e6 + 100; 
const int MOD = 1e9 + 7; 

int dp[MAX]; 

main()
{IOS;
    
    int n; cin >> n;

    dp[0] = 1, dp[1] = 1;
    for(int i = 2; i <= n; i++){
        ll sum = 0; int id = i - 1;

        while(id >= 0 && id >= i - 6){
            sum += dp[id];
            sum %= MOD;
            --id;
        }

        dp[i] = sum % MOD;
    }

    cout << dp[n] << endl;
}