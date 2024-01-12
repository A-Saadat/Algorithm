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
#define err_par(i, j) cout << "par[" << i << "][" << j << "] = {" << par[i][j].F << ", " << par[i][j].S << "}\n";
#define int long long 

const int MAX = 3e3 + 10; 
const int INF = 1e9 + 7; 

int dp[MAX][MAX]; 
pair<int, int> par[MAX][MAX];

main()
{IOS;

    string s, t; cin >> s >> t;
    int n1 = s.size(), n2 = t.size();
    for(int i = 1; i <= n1; i++){
        for(int j = 1; j <= n2; j++){
            if(s[i - 1] == t[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
                par[i][j] = {i - 1, j - 1};
            } 
            else{
                if(dp[i - 1][j] > dp[i][j - 1]){
                    dp[i][j] = dp[i - 1][j];
                    par[i][j] = {i - 1, j};
                }
                else{
                    dp[i][j] = dp[i][j - 1];
                    par[i][j] = {i, j - 1};
                }
            }
        }
    }

    string ans;
    pair<int, int> curr = {n1, n2};
    while(curr.F > 0 && curr.S > 0){
        pair<int, int> now = par[curr.F][curr.S];
        if(now.F + 1 == curr.F && now.S + 1 == curr.S) ans += s[now.F];
        
        curr = now;
    }

    reverse(all(ans));
    cout << ans;
}