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
#define err_dp(i, j) cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << endl;
typedef long long ll; 

const int MAXK = 2e3 + 10;
const ll MOD = 998244353; 

ll cu_ceil(ll x, ll y){
    return x / y + min(x % y, 1LL * 1);
}

ll dp[MAXK][MAXK]; 
ll fact[MAXK], rfact[MAXK], pre[MAXK];
ll n, m, k;

ll cu_pow(ll a, ll b){
    ll ans = 1;
    while(b > 0){
        if(b & 1) ans = 1LL * ans * a, ans = ans % MOD;
        a = 1LL * (a * a), a = a % MOD;
        b >>= 1;
    }
    
    return ans % MOD;
}

inline void init(){
    fact[1] = 1; 
    for(int i = 2; i <= 2000; i++){
        fact[i] = (i * fact[i - 1]) % MOD;
    } 

    for(int i = 1; i <= 2000; i++){
        for(int j = i; j <= 2000; j++){
            if(i == 1) dp[i][j] = 1;
            else{
                dp[i][j] = i * (dp[i][j - 1] + dp[i - 1][j - 1]);
                dp[i][j] = dp[i][j] % MOD;
            }
        }
    }

    for(int i = 1; i <= 2000; i++)
        pre[i] = cu_pow(fact[i], MOD - 2);
}

inline void build_fact(){
    rfact[1] = n;
    for(int i = 2; i <= min(n, k); i++){
        ll x = 1LL * rfact[i - 1] * ((n - i + 1) % MOD);
        x = x % MOD;
        rfact[i] = x;
    }
}


main()
{IOS;

    init();
    int t; cin >> t;
    while(t--){
        cin >> n >> m >> k;
        build_fact();
        
        ll ans = 0;
        for(int i = 1; i <= min(n, k); i++){
            ll x = 1LL * ( rfact[i] * pre[i] ) % MOD;

            ll fr = cu_pow(cu_ceil(m, 2), i);
            ll sc = cu_pow(m, n - i);
            ll sum = (1LL * fr * sc) % MOD;

            ll res = (x * dp[i][k]) % MOD;
            sum = (sum * res) % MOD;
            ans = (ans + sum) % MOD;
        }

        cout << ans << endl;
    }
}