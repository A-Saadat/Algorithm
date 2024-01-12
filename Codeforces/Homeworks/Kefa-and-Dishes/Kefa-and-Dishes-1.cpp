#include <bits/stdc++.h> 
using namespace std; 

#define IOS ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0) 

typedef long long int ll;

const int MaxN = 30;
const int MX = 262150;

ll dp[MX][MaxN], r[MaxN][MaxN], h[MaxN];

main()
{IOS;

    ll n, m, k; cin >> n >> m >> k;
    for(ll i = 0; i < n; i++) cin >> h[i];

    while(k--){
        ll x, y, z; cin >> x >> y >> z;

        r[--x][--y] = z;
    }

    for(ll S = 1; S < (1 << n); S++){

        for(ll i = 0; i < n; i++){

            if( !((S >> i) & 1) ) continue;
            
            ll sz = 31 - (__builtin_clz(S)); // ? the number of bits on binary form of S
            
            ll sum = 0;
            for(ll j = 0; j <= sz; j++){
                
                if( ((S >> j) & 1) ){

                    sum = max(sum,  dp[S ^ (1 << i)][j] + h[i] + r[j][i] );
                } 
            }

            dp[S][i] = sum;

        }
    }

    ll ans = 0;
    for(ll S = 1; S < (1 << n); S++){
        ll bt = __builtin_popcount(S);

        if(bt != m) continue;

        for(ll i = 0; i < n; i++){
            ans = max(ans, dp[S][i]);
        }
    }

    cout << ans;
}