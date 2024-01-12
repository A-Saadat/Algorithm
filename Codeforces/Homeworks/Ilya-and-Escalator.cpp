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

const int MaxN = 2e3 + 100; 
const int MOD = 1e9 + 7; 

double dp[MaxN][MaxN]; 
int n, t;
double p;

main()
{IOS;

    cin >> n >> p >> t;

    dp[1][0] = (1 - p);
    dp[1][1] = p;

    for(int ti = 2; ti <= t; ti++){
        for(int ni = 0; ni <= n; ni++){
            if(ni == 0){
                dp[ti][ni] = dp[ti - 1][ni] * (1 - p);
            } 
            elif(ni == n){
                dp[ti][ni] = (p * dp[ti - 1][ni - 1]) + dp[ti - 1][ni];
            }
            else dp[ti][ni] = (p *  dp[ti - 1][ni - 1]) + ((1 - p) * dp[ti - 1][ni]);
        }
    }

    double ans = 0;
    for(int ni = 1; ni <= n; ni++){
        ans += dp[t][ni] * ni;
    }

    cout << setprecision(12) << ans;
}