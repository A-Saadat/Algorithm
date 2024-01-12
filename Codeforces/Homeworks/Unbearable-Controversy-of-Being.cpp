#include <bits/stdc++.h> 
using namespace std; 

#define forn(i,k,n) for(int i = k; i < n; i++) 
#define fort(itr,map) for(auto itr = map.begin(); itr != map.end(); ++itr) 
#define IOS ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)  
#define elif else if
#define pb push_back
typedef long long int ll;

const int MaxN = 3e3 + 10; 
const int MOD = 1e9 + 7; 

vector<int> adj[MaxN];
int adj_r[MaxN][MaxN]; // ? adj_r will make any edge, reversed! 
ll fact[MaxN];

ll cu_pow(int a, int b){
    ll sum = 1, p = a;
    while(b > 0){
        if( (b & 1) ) sum = sum * p % MOD;

        p = (p * p) % MOD;
        b >>= 1; 
    }
    
    return sum;
}

ll Combination(int r, int n){
    if(n < r) return 0; 
    if(n == r) return 1;

    ll nm = fact[n] % MOD;
    ll dn = (fact[r] * fact[n - r]) % MOD;

    return ((nm * cu_pow(dn, MOD - 2)) % MOD);
}

main()
{IOS;

    fact[1] = 1;
    for(int i = 2; i <= MaxN; i++) fact[i] = (fact[i - 1] * i) % MOD;

    int n, m; cin >> n >> m;
    forn(i,0,m){
        int x, y; cin >> x >> y;
        adj[x].pb(y);
        adj_r[y][x] = 1;
    }

    ll ans = 0;
    for(int a = 1; a <= n; a++){

        for(int c = 1; c <= n; c++){
            if(a == c) continue;

            int cnt = 0;
            for(int u: adj[a]){
                if(adj_r[c][u]) cnt++;
            }

            ans += Combination(2, cnt);
        }

    }

    cout << ans << endl;

}