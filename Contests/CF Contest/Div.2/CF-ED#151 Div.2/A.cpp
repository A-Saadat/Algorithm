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

const int MaxN = 1e3; 
const int MOD = 1e9 + 7; 

int par[MaxN], dp[MaxN]; 
vector<int> v;

main()
{IOS;

    int t; cin >> t;
    while(t--){
        int n, k, x; cin >> n >> k >> x;
        for(int i = 1; i <= k; i++){
            if(i == x) continue;

            dp[i] = 1, par[i] = 0;
        }

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= min(i, k); j++){
                if(!dp[i - j] || j == x) continue;

                par[i] = j;
                dp[i] = 1;

            }

        }

        if(!dp[n]) cout << "NO\n";
        else{

            cout << "YES\n";

            while(par[n] > 0){
                v.pb(par[n]);
                n = n - par[n];
            }

            v.pb(n);

            cout << v.size() << endl;
            for(int u: v) cout << u << ' ';
            cout << endl;
        }

        memset(dp, 0, sizeof(dp));
        memset(par, 0, sizeof(par));
        v.clear();
    }

}