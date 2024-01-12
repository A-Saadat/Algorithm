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

const int MaxN = 4e3; 
const int MAX = 5e4 + 10; 
const int INF = 1e9 + 7; 

pair<int, vector<char>> dp[MaxN][MaxN]; 
int n;
char c[MaxN];
string s; 
// ? acbbdcea

inline void fdm_dp(){ // ? Base of the dp
    for(int i = 0; i < n; i++) c[i + 1] = s[i];

    for(int i = 1; i <= n; i++) dp[i][i] = {1, { c[i] } };

    for(int l = 1; l + 1 <= n; l++){
        int r = l + 1;
        if(c[l] == c[r]){
            dp[l][r].F = 2;
            dp[l][r].S = {c[l]};
        }
        dp[l][r].F = (c[l] == c[r] ? 2 : 1);
        dp[l][r].S = {c[l]};
    }
}

main()
{IOS;

    cin >> s;
    n = s.size();
    fdm_dp();


    for(int k = 2; k < n; k++){
        for(int l = 1; (l + k) <= n; l++){
            int r = l + k;
            dp[l][r].F = max(dp[l + 1][r].F, max(dp[l][r - 1].F, dp[l + 1][r - 1].F + (c[l] == c[r] ? 1 : 0)));

            // if(c[l] == c[r]) {
            //     dp[l][r].S = dp[l + 1][r - 1].S;
            //     dp[l][r].S.pb(c[l]);
            // }
            if(dp[l + 1][r].F > max(dp[l][r - 1].F, dp[l + 1][r - 1].F)) dp[l][r].S = dp[l + 1][r].S;
            elif(dp[l][r - 1].F > max(dp[l + 1][r].F, dp[l + 1][r - 1].F)) dp[l][r].S = dp[l][r - 1].S;
            else{
                dp[l][r].S = dp[l + 1][r].S;
                if(c[l] == c[r]) dp[l][r].S.pb(c[l]);
            }
        }
    }
    for(int k = 0; k < n; k++){
        for(int l = 1; (l + k) <= n; l++){
            int r = l + k;
            cout << "dp[" << l << "][" << r << "] = {" << dp[l][r].F << ", <";
            for(auto u: dp[l][r].S) cout << u << ' ';
            cout << ">}\n";
        }
        cout << "\n---------------------\n";
    }
}