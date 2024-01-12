#include <bits/stdc++.h> 
using namespace std; 

#define IOS ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0) 
typedef long long int ll;

const ll MaxN = 18; 

ll dp[ (1 << MaxN) ][MaxN], r[MaxN][MaxN], h[MaxN]; 
vector<ll> v;

main()
{IOS;

    ll n, m, k, mx = 0; cin >> n >> m >> k;
    for(ll i = 0; i < n; i++) cin >> h[i], mx = max(mx, h[i]);
    while(k--){
        ll x, y, w; cin >> x >> y >> w;
        r[--x][--y] = w;
    }

    if(m == 1) { cout << mx << endl; exit(0); }

    ll ans = 0;
    for(ll mask = 1; mask < (1 << n); mask++){
        ll cnt = __builtin_popcount(mask), sz = __builtin_ctz(mask); // ? sz = the first bits with the value of 1

        if(cnt == 1){
            dp[mask][sz] = h[sz];
            continue;
        }

        for(ll i = 0; i < n; i++){
            if( !((mask >> i) & 1) ) continue;
            
            ll tmp = mask ^ (1 << i);

            for(ll j = 0; j < n; j++){
                if( !((tmp >> j) & 1) ) continue;

                dp[mask][i] = max(dp[mask][i], dp[tmp][j] + h[i] + r[j][i]);
            }

            
            ans = max(ans, (cnt == m) * dp[mask][i]); // ? if cnt != m, it will return 0
        }

    }

    cout << ans << endl;

}